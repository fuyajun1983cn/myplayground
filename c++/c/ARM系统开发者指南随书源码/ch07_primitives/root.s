;// ____________________________________________________________________
;//
;// Copyright (c) 2003, Andrew N. Sloss, Dominic Symes, Chris Wright
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
;// Section 7.4: Square and cube root

        AREA    ch07_4, CODE, READONLY

        EXPORT  usqr_32
        EXPORT  ucbr_32
        EXPORT  rsqr_32

q       RN 0    ; input value, current square root estimate
r       RN 1    ; the current remainder
c       RN 2    ; scratch register

usqr_32 ; unsigned usqr_32(unsigned q)
        SUBS    r, q, #1<<30            ; is q>=(1<<15)^2?
        ADDCC   r, r, #1<<30            ; if not restore
        MOV     c, #3<<30               ; c is a constant
        ADC     q, c, #1<<31            ; set bit 15 of answer
        ; calculate bits 14..0 of the answer
        GBLA    N
N       SETA    14
        WHILE   N<>-1
          CMP   r, q, ROR #(30-2*N)     ; is r >= t<<N ?
          SUBCS r, r, q, ROR #(30-2*N)  ; if yes then r -= t<<N;
          ADC   q, c, q, LSL#1          ; insert next bit of answer
N         SETA  (N-1)
        WEND
        BIC     q, q, #3<<30            ; extract answer
        MOV     pc, lr

q0      RN 0    ; input value, current estimate
r       RN 1    ; current remainder
s       RN 2    ; current remainder
q1      RN 3    ; current estimate
c_1     RN 12   ; 1<<29
c_2     RN lr   ; 3<<30

        MACRO
        CBR_STEP $N, $q1, $q0
        SUBS    $q1, r, s, ROR #(30-3*$N)
        MOVCS   r, $q1
        ADC     $q1, c_2, $q0, LSL#1
        ADD     s, $q0, s, ROR #30
        EORCS   $q0, c_1, $q0, LSL #1
        SUB     s, s, $q0, ROR #30
        MEND

ucbr_32 ; unsigned ubcr_32(unsigned q)
        STR     lr, [sp, #-4]!
        MVN     c_1, #1<<29
        MOV     c_2, #3<<30
        ; calculate answer bit 10
        SUBS    r, q0, #1<<30
        MOVCC   r, q0
        ADC     q0, c_2, #1<<31
        MOVCC   s, #(1<<30)
        MOVCS   s, #(3<<30)+4
        ; calculate answer bits 9,8,...,1
        CBR_STEP 9, q1, q0
        CBR_STEP 8, q0, q1
        CBR_STEP 7, q1, q0
        CBR_STEP 6, q0, q1
        CBR_STEP 5, q1, q0
        CBR_STEP 4, q0, q1
        CBR_STEP 3, q1, q0
        CBR_STEP 2, q0, q1
        CBR_STEP 1, q1, q0
        ; calculate answer bit 0
        CMP     r, s, ROR #30
        ADC     q0, q1, q1
        BIC     r0, q0, #3<<30
        LDR     pc, [sp], #4
        
        
q       RN 0    ; input value, estimated reciprocal root
b       RN 1    ; scratch register
s       RN 2    ; normalization shift
d       RN 3    ; normalized input value
a       RN 12   ; scratch register/accumulator

        
rsqr_32 ; unsigned rsqr_32(unsigned q)
        CLZ     s, q                 ; choose shift s which is
        BIC     s, s, #1             ; even such that d=(q<<s)
        MOVS    d, q, LSL s          ; is 0.25<=d<1 at Q32
        ADDNE   q, pc, d, LSR#25     ; table lookup on top 7 bits
        LDRNEB  q, [q, #tab-base-32] ; of d in range 32 to 127
base    BEQ     div_by_zero          ; divide by zero trap
        ADD     q, q, #0x100         ; table stores only bottom 8 bits
        ; q is now a Q8, 9-bit estimate to 1/sqrt(d)
        SMULBB  a, q, q              ; a = q*q at Q16
        MOV     b, d, LSR #17        ; b = d   at Q15
        SMULWB  a, a, b              ; a = d*q*q at Q15
        MOV     b, q, LSL #7         ; b = q at Q15
        RSB     a, a, #3<<15         ; a = (3-d*q*q) at Q15
        MUL     q, a, b              ; q = q*(3-d*q*q)/2 at Q31
        ; q is now a Q31 estimate to 1/sqrt(d)
        UMULL   b, a, d, q           ; a = d*q at Q31
        MOV     s, s, LSR #1         ; square root halves the shift
        UMULL   b, a, q, a           ; a = d*q*q at Q30
        RSB     s, s, #15            ; reciprocal inverts the shift
        RSB     a, a, #3<<30         ; a = (3-d*q*q) at Q30
        UMULL   b, q, a, q           ; q = q*(3-d*q*q)/2 at Q31
        ; q is now a good Q31 estimate to 1/sqrt(d)
        MOV     q, q, LSR s          ; undo the normalization shift
        BX      lr                   ; return q
div_by_zero
        MOV     q, #0x7FFFFFFF       ; maxium positive answer
        BX      lr                   ; return q
        
tab     ; tab[k] = round(256.0/sqrt((k+32.3)/128.0)) - 256
        DCB  0xfe, 0xf6, 0xef, 0xe7, 0xe1, 0xda, 0xd4, 0xce
        DCB  0xc8, 0xc3, 0xbd, 0xb8, 0xb3, 0xae, 0xaa, 0xa5
        DCB  0xa1, 0x9c, 0x98, 0x94, 0x90, 0x8d, 0x89, 0x85
        DCB  0x82, 0x7f, 0x7b, 0x78, 0x75, 0x72, 0x6f, 0x6c
        DCB  0x69, 0x66, 0x64, 0x61, 0x5e, 0x5c, 0x59, 0x57
        DCB  0x55, 0x52, 0x50, 0x4e, 0x4c, 0x49, 0x47, 0x45
        DCB  0x43, 0x41, 0x3f, 0x3d, 0x3b, 0x3a, 0x38, 0x36
        DCB  0x34, 0x32, 0x31, 0x2f, 0x2d, 0x2c, 0x2a, 0x29
        DCB  0x27, 0x26, 0x24, 0x23, 0x21, 0x20, 0x1e, 0x1d
        DCB  0x1c, 0x1a, 0x19, 0x18, 0x16, 0x15, 0x14, 0x13
        DCB  0x11, 0x10, 0x0f, 0x0e, 0x0d, 0x0b, 0x0a, 0x09
        DCB  0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01

        END
