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
;// Section 7.5: Transcendental functions

        AREA    ch07_5, CODE, READONLY

        EXPORT  ulog2_32
        EXPORT  uexp2_32
        EXPORT  sin_32
        EXPORT  cos_32

n       RN 0    ; Q0 input, Q26 log2 estimate
d       RN 1    ; normalise input Q32
r       RN 2
q       RN 3
t       RN 12

        ; int ulog2_32(unsigned n)
ulog2_32
        CLZ     r, n
        MOV     d, n, LSL#1
        MOV     d, d, LSL r       ; 1<=d<2 at Q32
        RSB     n, r, #31         ; integer part of the log
        MOV     r, d, LSR#27      ; estimate a=1+(r+0.5)/32
        ADR     t, ulog2_table
        LDR     r, [t, r, LSL#3]! ; r=log2(a) at Q26
        LDR     q, [t, #4]        ; q=1/a     at Q32
        MOV     t, #0
        UMLAL   t, r, d, r        ; r=(d/a)-1 at Q32
        LDR     t, =0x55555555    ; round(2^32/3)
        ADD     n, q, n, LSL#26   ; n+log2(a) at Q26
        SMULL   t, q, r, t        ; q = r/3   at Q32
        LDR     d, =0x05c551d9    ; round(2^26/ln(2))
        SMULL   t, q, r, q        ; q = r^2/3 at Q32
        MOV     t, #0
        SUB     q, q, r, ASR#1    ; q = -r/2+r^2/3 at Q32
        SMLAL   t, r, q, r        ; r - r^2/2 + r^3/3 at Q32
        MOV     t, #0
        SMLAL   t, n, d, r        ; n += r/log(2) at Q26
        MOV     pc, lr

ulog2_table
        ; table[2*i]  =round(2^32/a)     where a=1+(i+0.5)/32
        ; table[2*i+1]=round(2^26*log2(a)) and 0<=i<32
        DCD 0xfc0fc0fc, 0x0016e797, 0xf4898d60, 0x0043ace2
        DCD 0xed7303b6, 0x006f2109, 0xe6c2b448, 0x0099574f
        DCD 0xe070381c, 0x00c2615f, 0xda740da7, 0x00ea4f72
        DCD 0xd4c77b03, 0x0111307e, 0xcf6474a9, 0x0137124d
        DCD 0xca4587e7, 0x015c01a4, 0xc565c87b, 0x01800a56
        DCD 0xc0c0c0c1, 0x01a33761, 0xbc52640c, 0x01c592fb
        DCD 0xb81702e0, 0x01e726aa, 0xb40b40b4, 0x0207fb51
        DCD 0xb02c0b03, 0x0228193f, 0xac769184, 0x0247883b
        DCD 0xa8e83f57, 0x02664f8d, 0xa57eb503, 0x02847610
        DCD 0xa237c32b, 0x02a20231, 0x9f1165e7, 0x02bef9ff
        DCD 0x9c09c09c, 0x02db632d, 0x991f1a51, 0x02f7431f
        DCD 0x964fda6c, 0x03129ee9, 0x939a85c4, 0x032d7b5a
        DCD 0x90fdbc09, 0x0347dcfe, 0x8e78356d, 0x0361c825
        DCD 0x8c08c08c, 0x037b40e4, 0x89ae408a, 0x03944b1c
        DCD 0x8767ab5f, 0x03acea7c, 0x85340853, 0x03c52286
        DCD 0x83126e98, 0x03dcf68e, 0x81020408, 0x03f469c2

n       RN 0    ; input, integer part
d       RN 1    ; fractional part
r       RN 2
q       RN 3
t       RN 12

        ; unsigned uexp2_32(int n)
uexp2_32
        MOV     d, n, LSL#6      ; d = fractional part at Q32
        MOV     q, d, LSR#27     ; estimate a=(q+0.5)/32
        LDR     r, =0xb17217f8   ; round(2^32*log(2))
        BIC     d, d, q, LSL#27  ; d = d - (q/32) at Q32
        UMULL   t, d, r, d       ; d = d*log(2)   at Q32
        LDR     t, =0x55555555   ; round(2^32/3)
        SUB     d, d, r, LSR#6   ; d = d - log(2)/64 at Q32
        SMULL   t, r, d, t       ; r = d/3   at Q32
        MOVS    n, n, ASR#26     ; n = integer part of exponent
        SMULL   t, r, d, r       ; r = d^2/3 at Q32
        BMI     negative         ; catch negative exponent
        ADD     r, r, d          ; r = d+d^2/3
        SMULL   t, r, d, r       ; r = d^2+d^3/3
        ADR     t, uexp2_table
        LDR     q, [t, q, LSL#2] ; q = exp2(a) at Q31
        ADDS    r, d, r, ASR#1   ; r = d+d^2/2+d^3/6 at Q32
        UMULL   t, r, q, r       ; r = exp2(a)*r     at Q31 if r<0
        RSB     n, n, #31        ; 31-(integer part of exponent)
        ADDPL   r, r, q          ; correct if r>0
        MOV     n, r, LSR n      ; result at Q0
        MOV     pc, lr
negative
        MOV     r0, #0           ; 2^(-ve)=0
        MOV     pc, lr

uexp2_table
        ; table[i]=round(2^31*exp2(a)) where a=(i+0.5)/32
        DCD 0x8164d1f4, 0x843a28c4, 0x871f6197, 0x8a14d575
        DCD 0x8d1adf5b, 0x9031dc43, 0x935a2b2f, 0x96942d37
        DCD 0x99e04593, 0x9d3ed9a7, 0xa0b05110, 0xa43515ae
        DCD 0xa7cd93b5, 0xab7a39b6, 0xaf3b78ad, 0xb311c413
        DCD 0xb6fd91e3, 0xbaff5ab2, 0xbf1799b6, 0xc346ccda
        DCD 0xc78d74c9, 0xcbec14ff, 0xd06333db, 0xd4f35aac
        DCD 0xd99d15c2, 0xde60f482, 0xe33f8973, 0xe8396a50
        DCD 0xed4f301f, 0xf281773c, 0xf7d0df73, 0xfd3e0c0d

n       RN 0    ; the input angle in revolutions at Q32, result Q30
s       RN 1    ; the output sign
r       RN 2
q       RN 3
t       RN 12

cos_32  ; int cos_32(int n)
        EOR     s, n, n, LSL#1    ; cos is -ve in quadrants 1,2
        MOVS    n, n, LSL#1       ; angle in revolutions at Q33
        RSBMI   n, n, #0          ; in range 0-1/4 of a revolution
        CMP     n, #1<<30         ; if angle < 1/8 of a revolution
        BCC     cos_core          ; take cosine
        SUBEQ   n, n, #1          ; otherwise take sine of
        RSBHI   n, n, #1<<31      ; (1/4 revolution)-(angle)
sin_core                          ; take sine of Q33 angle n
        MOV     q, n, LSR#25      ; approximation a=(q+0.5)/32
        SUB     n, n, q, LSL#25   ; n = n-(q/32) at Q33
        SUB     n, n, #1<<24      ; n = n-(1/64) at Q33
        LDR     t, =0x6487ed51    ; round(2*PI*2^28)
        MOV     r, n, LSL#3       ; r = n at Q36
        SMULL   t, n, r, t        ; n = (x-a)*PI/2^31 at Q32
        ADR     t, cossin_tab
        LDR     q, [t, q, LSL#3]! ; c(a) at Q30
        LDR     t, [t, #4]        ; s(a) at Q30
        EOR     q, q, s, ASR#31   ; correct c(a) sign
        EOR     s, t, s, ASR#31   ; correct s(a) sign
        SMULL   t, r, n, n        ; n^2      at Q32
        SMULL   t, q, n, q        ; n*c(a)   at Q30
        SMULL   t, n, r, s        ; n^2*s(a) at Q30
        LDR     t, =0xd5555556    ; round(-2^32/6)
        SUB     n, s, n, ASR#1    ; n = s(a)*(1-n^2/2) at Q30
        SMULL   t, s, r, t        ; s=-n^2/6    at Q32
        ADD     n, n, q           ; n += c(a)*n        at Q30
        MOV     t, #0
        SMLAL   t, n, q, s        ; n += -c(a)*n^3/6   at Q30
        MOV     pc, lr            ; return n

sin_32  ; int sin_32(int n)
        AND     s, n, #1<<31      ; sin is -ve in quadrants 2,3
        MOVS    n, n, LSL#1       ; angle in revoluations at Q33
        RSBMI   n, n, #0          ; in range 0-1/4 of a revolution
        CMP     n, #1<<30         ; if angle < 1/8 revolution
        BCC     sin_core          ; take sine
        SUBEQ   n, n, #1          ; otherwise take cosine of
        RSBHI   n, n, #1<<31      ; (1/4 revolution)-(angle)
cos_core                          ; take cosine of Q33 angle n
        MOV     q, n, LSR#25      ; approximation a=(q+0.5)/32
        SUB     n, n, q, LSL#25   ; n = n-(q/32) at Q33
        SUB     n, n, #1<<24      ; n = n-(1/64) at Q33
        LDR     t, =0x6487ed51    ; round(2*PI*2^28)
        MOV     r, n, LSL#3       ; r = n at Q26
        SMULL   t, n, r, t        ; n = (x-a)*PI/2^31 at Q32
        ADR     t, cossin_tab
        LDR     q, [t, q, LSL#3]! ; c(a) at Q30
        LDR     t, [t, #4]        ; s(a) at Q30
        EOR     q, q, s, ASR#31   ; correct c(a) sign
        EOR     s, t, s, ASR#31   ; correct s(a) sign
        SMULL   t, r, n, n        ; n^2      at Q32
        SMULL   t, s, n, s        ; n*s(a)   at Q30
        SMULL   t, n, r, q        ; n^2*c(a) at Q30
        LDR     t, =0x2aaaaaab    ; round(+2^23/6)
        SUB     n, q, n, ASR#1    ; n = c(a)*(1-n^2/2) at Q30
        SMULL   t, q, r, t        ; n^2/6       at Q32
        SUB     n, n, s           ; n += -sin*n at Q30
        MOV     t, #0
        SMLAL   t, n, s, q        ; n += sin*n^3/6 at Q30
        MOV     pc, lr            ; return n

cossin_tab
        ; table[2*i]  =round(2^30*cos(a)) where a=(PI/4)*(i+0.5)/32
        ; table[2*i+1]=round(2^30*sin(a)) and 0 <= i < 32
        DCD 0x3ffec42d, 0x00c90e90, 0x3ff4e5e0, 0x025b0caf
        DCD 0x3fe12acb, 0x03ecadcf, 0x3fc395f9, 0x057db403
        DCD 0x3f9c2bfb, 0x070de172, 0x3f6af2e3, 0x089cf867
        DCD 0x3f2ff24a, 0x0a2abb59, 0x3eeb3347, 0x0bb6ecef
        DCD 0x3e9cc076, 0x0d415013, 0x3e44a5ef, 0x0ec9a7f3
        DCD 0x3de2f148, 0x104fb80e, 0x3d77b192, 0x11d3443f
        DCD 0x3d02f757, 0x135410c3, 0x3c84d496, 0x14d1e242
        DCD 0x3bfd5cc4, 0x164c7ddd, 0x3b6ca4c4, 0x17c3a931
        DCD 0x3ad2c2e8, 0x19372a64, 0x3a2fcee8, 0x1aa6c82b
        DCD 0x3983e1e8, 0x1c1249d8, 0x38cf1669, 0x1d79775c
        DCD 0x3811884d, 0x1edc1953, 0x374b54ce, 0x2039f90f
        DCD 0x367c9a7e, 0x2192e09b, 0x35a5793c, 0x22e69ac8
        DCD 0x34c61236, 0x2434f332, 0x33de87de, 0x257db64c
        DCD 0x32eefdea, 0x26c0b162, 0x31f79948, 0x27fdb2a7
        DCD 0x30f8801f, 0x29348937, 0x2ff1d9c7, 0x2a650525
        DCD 0x2ee3cebe, 0x2b8ef77d, 0x2dce88aa, 0x2cb2324c

        END
