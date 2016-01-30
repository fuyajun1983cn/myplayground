;// ____________________________________________________________________
;//
;// Copyright (c) 2002, Andrew N. Sloss, Dominic Symes, Chris Wright
;// All rights reserved.
;// ____________________________________________________________________
;// 
;// NON-COMMERCIAL USE License
;// 
;// Redistribution and use in source and binary forms, with or without 
;// modification, are permitted provided that the following conditions 
;// are met: 
;//
;// 1. For NON-COMMERCIAL USE only.
;// 
;// 2. Redistributions of source code must retain the above copyright 
;//    notice, this list of conditions and the following disclaimer. 
;//
;// 3. Redistributions in binary form must reproduce the above 
;//    copyright notice, this list of conditions and the following 
;//    disclaimer in the documentation and/or other materials provided 
;//    with the distribution. 
;//
;// 4. All advertising materials mentioning features or use of this 
;//    software must display the following acknowledgement:
;//
;//    This product includes software developed by Andrew N. Sloss,
;//    Chris Wright and Dominic Symes. 
;//
;//  THIS SOFTWARE IS PROVIDED BY THE CONTRIBUTORS ``AS IS'' AND ANY 
;//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
;//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
;//  PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE CONTRIBUTORS BE 
;//  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, 
;//  OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
;//  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
;//  OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
;//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR 
;//  TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT 
;//  OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
;//  OF SUCH DAMAGE. 
;//
;// If you have questions about this license or would like a different
;// license please email : andrew@sloss.net
;//
;// Section 7.3: Division routines (ARM9E)

        AREA    ch07_3, CODE, READONLY

        EXPORT  udiv_32by32_arm9e
        EXPORT  udiv_q15_arm9e
        EXPORT  udiv_q31_arm9e

;=================================================================////

q       RN 0   ; input denominator d, output quotient q
r       RN 1   ; input numerator n, output remainder r
s       RN 2   ; scratch register
m       RN 3   ; scratch register
a       RN 12  ; scratch register

        ; __value_in_regs struct { unsigned q, r; }
        ;   udiv_32by32_arm9e(unsigned d, unsigned n)
udiv_32by32_arm9e ; instruction   number : comment
        CLZ     s, q                ; 01 : find normalizing shift
        MOVS    a, q, LSL s         ; 02 : perform a lookup on the
        ADD     a, pc, a, LSR#25    ; 03 : most significant 7 bits
        LDRNEB  a, [a, #t32-b32-64] ; 04 : of divisor
b32     SUBS    s, s, #7            ; 05 : correct shift
        RSB     m, q, #0            ; 06 : m = -d
        MOVPL   q, a, LSL s         ; 07 : q approx (1<<32)/d
        ; 1st Newton iteration follows
        MULPL   a, q, m             ; 08 : a = -q*d
        BMI     udiv_by_large_d     ; 09 : large d trap
        SMLAWT  q, q, a, q          ; 10 : q approx q-(q*q*d>>32)
        TEQ     m, m, ASR#1         ; 11 : check for d=0 or d=1
        ; 2nd Newton iteration follows
        MULNE   a, q, m             ; 12 : a = -q*d
        MOVNE   s, #0               ; 13 : s = 0
        SMLALNE s, q, a, q          ; 14 : q = q-(q*q*d>>32)
        BEQ     udiv_by_0_or_1      ; 15 : trap d=0 or d=1
        ; q now accurate enough for a remainder r, 0<=r<3*d
        UMULL   s, q, r, q          ; 16 : q = (r*q)>>32
        ADD     r, r, m             ; 17 : r = n-d
        MLA     r, q, m, r          ; 18 : r = n-(q+1)*d
        ; since 0 <= n-q*d < 3*d, thus -d <= r < 2*d
        CMN     r, m                ; 19 : t = r-d
        SUBCS   r, r, m             ; 20 : if (t<-d || t>=0) r=r+d
        ADDCC   q, q, #1            ; 21 : if (-d<=t && t<0) q=q+1
        ADDPL   r, r, m, LSL#1      ; 22 : if (t>=0) { r=r-2*d
        ADDPL   q, q, #2            ; 23 :             q=q+2 }
        BX      lr                  ; 24 : return {q, r}
udiv_by_large_d
        ; at this point we know d >= 2^(31-6)=2^25
        SUB     a, a, #4            ; 25 : set q to be an
        RSB     s, s, #0            ; 26 : underestimate of
        MOV     q, a, LSR s         ; 27 : (1<<32)/d
        UMULL   s, q, r, q          ; 28 : q = (n*q)>>32
        MLA     r, q, m, r          ; 29 : r = n-q*d
        ; q now accurate enough for a remainder r, 0<=r<4*d
        CMN     m, r, LSR#1         ; 30 : if (r/2 >= d)
        ADDCS   r, r, m, LSL#1      ; 31 : { r=r-2*d;
        ADDCS   q, q, #2            ; 32 :   q=q+2; }
        CMN     m, r                ; 33 : if (r >= d)
        ADDCS   r, r, m             ; 34 : { r=r-d;
        ADDCS   q, q, #1            ; 35 :   q=q+1; }
        BX      lr                  ; 36 : return {q, r}
udiv_by_0_or_1
        ; carry set if d=1, carry clear if d=0
        MOVCS   q, r                ; 37 : if (d==1) { q=n;
        MOVCS   r, #0               ; 38 :             r=0; }
        MOVCC   q, #-1              ; 39 : if (d==0) { q=-1;
        MOVCC   r, #-1              ; 40 :             r=-1; }
        BX      lr                  ; 41 : return {q,r}

        ; table for 32 by 32 bit Newton Raphson divisions
        ; table[0] = 255
        ; table[i] = (1<<14)/(64+i)  for i=1,2,3,...,63
t32     DCB 0xff, 0xfc, 0xf8, 0xf4, 0xf0, 0xed, 0xea, 0xe6
        DCB 0xe3, 0xe0, 0xdd, 0xda, 0xd7, 0xd4, 0xd2, 0xcf
        DCB 0xcc, 0xca, 0xc7, 0xc5, 0xc3, 0xc0, 0xbe, 0xbc
        DCB 0xba, 0xb8, 0xb6, 0xb4, 0xb2, 0xb0, 0xae, 0xac
        DCB 0xaa, 0xa8, 0xa7, 0xa5, 0xa3, 0xa2, 0xa0, 0x9f
        DCB 0x9d, 0x9c, 0x9a, 0x99, 0x97, 0x96, 0x94, 0x93
        DCB 0x92, 0x90, 0x8f, 0x8e, 0x8d, 0x8c, 0x8a, 0x89
        DCB 0x88, 0x87, 0x86, 0x85, 0x84, 0x83, 0x82, 0x81

;=================================================================////

q       RN 0    ; input denominator d, quotient estimate q
r       RN 1    ; input numerator n, remainder r
s       RN 2    ; normalisation shift, scratch
d       RN 3    ; Q15 normalised denominator 2^14<=d<2^15

        ; unsigned udiv_q15_arm9e(unsigned d, unsigned q)
udiv_q15_arm9e ; instruction       number : comment
        CLZ     s, q                 ; 01 : choose a shift s to
        SUB     s, s, #17            ; 02 : normalize d to the
        MOVS    d, q, LSL s          ; 03 : range 0.5<=d<1 at Q15
        ADD     q, pc, d, LSR#7      ; 04 : look up q, a Q8
        LDRNEB  q, [q, #t15-b15-128] ; 05 : approximation to 1//d
b15     MOV     r, r, LSL s          ; 06 : normalize numerator
        ADD     q, q, #256           ; 07 : part of table lookup
        ; q is now a Q8, 9-bit estimate to 1//d
        SMULBB  s, q, q              ; 08 : s = q*q at Q16
        CMP     r, d                 ; 09 : check for overflow
        MUL     s, d, s              ; 10 : s = q*q*d at Q31
        MOV     q, q, LSL#9          ; 11 : change q to Q17
        SBC     q, q, s, LSR#15      ; 12 : q = 2*q-q*q*d at Q16
        ; q is now a Q16, 17-bit estimate to 1//d
        SMULWB  q, q, r              ; 13 : q approx n//d at Q15
        BCS     overflow_15          ; 14 : trap overflow case
        SMULBB  s, q, d              ; 15 : s = q*d at Q30
        RSB     r, d, r, LSL#15      ; 16 : r = n-d at Q30
        CMP     r, s                 ; 17 : if (r>=s)
        ADDPL   q, q, #1             ; 18 :   q++
        BX      lr                   ; 19 : return q
overflow_15
        LDR     q, =0x7FFF           ; 20 : q = 0x7FFF
        BX      lr                   ; 21 : return q

        ; table for fractional Newton Raphson division
        ; table[a] = (int)((511*(128-a))/(257+2*a)) 0<=a<128
t15     DCB 0xfe, 0xfa, 0xf6, 0xf2, 0xef, 0xeb, 0xe7, 0xe4
        DCB 0xe0, 0xdd, 0xd9, 0xd6, 0xd2, 0xcf, 0xcc, 0xc9
        DCB 0xc6, 0xc2, 0xbf, 0xbc, 0xb9, 0xb6, 0xb3, 0xb1
        DCB 0xae, 0xab, 0xa8, 0xa5, 0xa3, 0xa0, 0x9d, 0x9b
        DCB 0x98, 0x96, 0x93, 0x91, 0x8e, 0x8c, 0x8a, 0x87
        DCB 0x85, 0x83, 0x80, 0x7e, 0x7c, 0x7a, 0x78, 0x75
        DCB 0x73, 0x71, 0x6f, 0x6d, 0x6b, 0x69, 0x67, 0x65
        DCB 0x63, 0x61, 0x5f, 0x5e, 0x5c, 0x5a, 0x58, 0x56
        DCB 0x54, 0x53, 0x51, 0x4f, 0x4e, 0x4c, 0x4a, 0x49
        DCB 0x47, 0x45, 0x44, 0x42, 0x40, 0x3f, 0x3d, 0x3c
        DCB 0x3a, 0x39, 0x37, 0x36, 0x34, 0x33, 0x32, 0x30
        DCB 0x2f, 0x2d, 0x2c, 0x2b, 0x29, 0x28, 0x27, 0x25
        DCB 0x24, 0x23, 0x21, 0x20, 0x1f, 0x1e, 0x1c, 0x1b
        DCB 0x1a, 0x19, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12
        DCB 0x10, 0x0f, 0x0e, 0x0d, 0x0c, 0x0b, 0x0a, 0x09
        DCB 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01

;=================================================================////

q       RN 0    ; input denominator d, quotient estimate q
r       RN 1    ; input numerator n, remainder high r
s       RN 2    ; normalisation shift, scratch register
d       RN 3    ; Q31 normalised denominator 2^30<=d<2^31
a       RN 12   ; scratch

        ; unsigned udiv_q31_arm9e(unsigned d, unsigned q)
udiv_q31_arm9e ;       instruction number : comment
        CLZ     s, q                 ; 01 : choose a shift s to
        CMP     r, q                 ; 02 : normalize d to the
        MOVCC   d, q, LSL s          ; 03 : range 0.5<=d<1 at Q32
        ADDCC   q, pc, d, LSR#24     ; 04 : look up q, a Q8
        LDRCCB  q, [q, #t15-b31-128] ; 05 : approximation to 1//d
b31     MOVCC   r, r, LSL s          ; 06 : normalize numerator
        ADDCC   q, q, #256           ; 07 : part of table lookup
        ; q is now a Q8, 9-bit estimate to 1//d
        SMULBBCC a, q, q             ; 08 : a = q*q at Q16
        MOVCS   q, #0x7FFFFFFF       ; 09 : overflow case
        UMULLCC s, a, d, a           ; 10 : a = q*q*d at Q16
        BXCS    lr                   ; 11 : exit on overflow
        RSB     q, a, q, LSL#9       ; 12 : q = 2*q-q*q*d at Q16
        ; q is now a Q16, 17-bit estimate to 1//d
        UMULL   a, s, q, q           ; 13 : [s,a] = q*q at Q32
        MOVS    a, a, LSR#1          ; 14 : now halve [s,a] and
        ADC     a, a, s, LSL#31      ; 15 : round so [N,a]=q*q at
        MOVS    s, s, LSL#30         ; 16 : Q31, C=0
        UMULL   s, a, d, a           ; 17 : a = a*d at Q31
        ADDMI   a, a, d              ; 18 : if (N) a+=2*d at Q31
        RSC     q, a, q, LSL#16      ; 19 : q = 2*q-q*q*d at Q31
        ; q is now a Q31 estimate to 1/d
        UMULL   s, q, r, q           ; 20 : q approx n//d at Q31
        ; q is now a Q31 estimate to num/den, remainder<3*d
        UMULL   s, a, d, q           ; 21 : [a,s] = d*q at Q62
        RSBS    s, s, #0             ; 22 : [r,s] = n-d*q
        RSC     r, a, r, LSR#1       ; 23 :  at Q62
        ; [r,s]=(r<<32)+s is now the positive remainder<3*d
        SUBS    s, s, d              ; 24 : [r,s] = n-(d+1)*q
        SBCS    r, r, #0             ; 25 :  at Q62
        ADDPL   q, q, #1             ; 26 : if ([r,s]>=0) q++
        SUBS    s, s, d              ; 27 : [r,s] = [r,s]-d
        SBCS    r, r, #0             ; 28 :  at Q62
        ADDPL   q, q, #1             ; 29 : if ([r,s]>=0) q++
        BX      lr                   ; 30 : return q

        END
