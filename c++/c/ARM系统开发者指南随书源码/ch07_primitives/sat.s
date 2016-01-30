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
;// Section 7.7: Saturating operations

        AREA    ch07_7, CODE, READONLY

        EXPORT  qsat_16
        EXPORT  qshl_32
        EXPORT  qshr_32
        EXPORT  qadd_32
        EXPORT  qsub_32
        EXPORT  absa_32
        EXPORT  qabs_32

b       RN 0
c       RN 1
a       RN 2
m       RN 3

;=================================================================////

        ;// saturate

qsat_16 ; b=saturate16(b)
        LDR     m, =0x00007FFF      ; m = 0x7FFF maximum +ve
        MOV     a, b, ASR#15        ; a = (b>>15)
        TEQ     a, b, ASR#31        ; if (a!=sign(b))
        EORNE   b, m, b, ASR#31     ;   b = 0x7FFF ^ sign(b)
        MOV     pc, lr              ; return b

        ;// shift left and saturate

qshl_32 ; a=saturate32(b<<c)
        MOV     m, #0x7FFFFFFF      ; m = 0x7FFFFFFF max +ve
        MOV     a, b, LSL c         ; a = b<<c
        TEQ     b, a, ASR c         ; if (b != (a>>c))
        EORNE   a, m, b, ASR#31     ;   a = 0x7FFFFFFF^sign(b)
        MOV     r0, a               ; r0 = a
        MOV     pc, lr              ; return r0

        ;// shift right and round/saturate

qshr_32 ; a=round(b>>c)
        ADDS    b, b, #0            ; clear carry so works for c=0
        MOVS    a, b, ASR c         ; a = b>>c, carry=b bit c-1
        ADC     a, a, #0            ; if (carry) a++ to round
        MOV     r0, a               ; r0 = a
        MOV     pc, lr              ; return r0

        ;// add and saturate

qadd_32 ; QADD  a, b, c
        ; a = saturate32(b+c)
        MOV     m, #0x80000000      ; m = 0x80000000 max -ve
        ADDS    a, b, c             ; a = b+c, V records overflow
        EORVS   a, m, a, ASR#31     ; if (V) a=0x80000000^sign(a)
        MOV     r0, a               ; r0 = a
        MOV     pc, lr              ; return r0

qsub_32 ; QSUB  a, b, c
        ; a = saturate32(b-c)
        MOV     m, #0x80000000      ; m = 0x80000000 max -ve
        SUBS    a, b, c             ; a = b-c, V records overflow
        EORVS   a, m, a, ASR#31     ; if (V) a=0x80000000^sign(a)
        MOV     r0, a               ; r0 = a
        MOV     pc, lr              ; return r0

        ;// absolute

qabs_32
        ; a = saturate32(abs(b))
        SUB     a, b, b, LSR #31    ; a = b - (b<0)
        EOR     a, a, a, ASR #31    ; a = a ^ sign(a)
        MOV     r0, a               ; r0 = a
        MOV     pc, lr              ; return r0

absa_32
        ; a = b+abs(c)
        EORS    a, c, c, ASR#32     ; a = c^sign(c) = abs(c)-(c<0)
        ADC     a, b, a             ; a = b + a + (c<0)
        MOV     r0, a               ; r0 = a
        MOV     pc, lr              ; return r0


        END
