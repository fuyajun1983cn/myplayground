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
;// Section 7.1: Signed and unsigned multiply routines

        AREA    ch07_1, CODE, READONLY

        EXPORT  mul_64to64
        EXPORT  umul_64to128_arm7m
        EXPORT  umul_64to128_arm9e
        EXPORT  smul_64to128

b_0     RN 0    ; b bits [31:00]  (b low)
b_1     RN 1    ; b bits [63:32]  (b high)
c_0     RN 2    ; c bits [31:00]  (c low)
c_1     RN 3    ; c bits [63:32]  (c high)
a_0     RN 4    ; a bits [31:00]  (a low-low)
a_1     RN 5    ; a bits [63:32]  (a low-high)
a_2     RN 12   ; a bits [95:64]  (a high-low)
a_3     RN lr   ; a bits [127:96] (a high-high)

        ; long long mul_64to64(long long b, long long c)
mul_64to64
        STMFD   sp!, {r4,r5,lr}
        ; 64-bit a = 64-bit b * 64-bit c
        UMULL   a_0, a_1, b_0, c_0      ; low*low
        MLA     a_1, b_0, c_1, a_1      ; low*high
        MLA     a_1, b_1, c_0, a_1      ; high*low
        ; return wrapper
        MOV     r0, a_0
        MOV     r1, a_1
        LDMFD   sp!, {r4,r5,pc}

        ; __value_in_regs struct { unsigned a0,a1,a2,a3; }
        ;   umul_64to128_arm7m(unsigned long long b,
        ;                      unsigned long long c)
umul_64to128_arm7m
        STMFD   sp!, {r4,r5,lr}
        ; unsigned 128-bit a = 64-bit b * 64-bit c
        UMULL   a_0, a_1, b_0, c_0      ; low*low
        UMULL   a_2, a_3, b_0, c_1      ; low*high
        UMULL   c_1, b_0, b_1, c_1      ; high*high
        ADDS    a_1, a_1, a_2
        ADCS    a_2, a_3, c_1
        ADC     a_3, b_0, #0
        UMULL   c_0, b_0, b_1, c_0      ; high*low
        ADDS    a_1, a_1, c_0
        ADCS    a_2, a_2, b_0
        ADC     a_3, a_3, #0
        ; return wrapper
        MOV     r0, a_0
        MOV     r1, a_1
        MOV     r2, a_2
        MOV     r3, a_3
        LDMFD   sp!, {r4,r5,pc}

        ; __value_in_regs struct { unsigned a0,a1,a2,a3; }
        ;   umul_64to128_arm9e(unsigned long long b,
        ;                      unsigned long long c)
umul_64to128_arm9e
        STMFD   sp!, {r4,r5,lr}
        ; unsigned 128-bit a = 64-bit b * 64-bit c
        UMULL   a_0, a_1, b_0, c_0      ; low*low
        MOV     a_2, #0
        UMLAL   a_1, a_2, b_0, c_1      ; low*high
        MOV     a_3, #0
        UMLAL   a_1, a_3, b_1, c_0      ; high*low
        MOV     b_0, #0
        ADDS    a_2, a_2, a_3
        ADC     a_3, b_0, #0
        UMLAL   a_2, a_3, b_1, c_1      ; high*high
        ; return wrapper
        MOV     r0, a_0
        MOV     r1, a_1
        MOV     r2, a_2
        MOV     r3, a_3
        LDMFD   sp!, {r4,r5,pc}

        MACRO
        USMLAL $al, $ah, $b, $c
        ; signed $ah.$al += unsigned $b * signed $c
        SMLAL   $al, $ah, $b, $c        ; a = (signed)b * c;
        TST     $b, #1<<31              ; if ((signed)b<0)
        ADDNE   $ah, $ah, $c            ;   a += (c<<32);
        MEND

        MACRO
        SUMLAL $al, $ah, $b, $c
        ; signed $ah.$al += signed $b * unsigned $c
        SMLAL   $al, $ah, $b, $c        ; a = b * (signed)c;
        TST     $c, #1<<31              ; if ((signed)c<0)
        ADDNE   $ah, $ah, $b            ;   a += (b<<32);
        MEND

        ; __value_in_regs struct { unsigned a0,a1,a2; signed a3; }
        ;   smul_64to128(long long b, long long c)
smul_64to128
        STMFD   sp!, {r4,r5,lr}
        ; signed 128-bit a = 64-bit b * 64-bit c
        UMULL   a_0, a_1, b_0, c_0      ; low*low
        MOV     a_2, #0
        USMLAL  a_1, a_2, b_0, c_1      ; low*high
        MOV     a_3, #0
        SUMLAL  a_1, a_3, b_1, c_0      ; high*low
        MOV     b_0, a_2, ASR#31
        ADDS    a_2, a_2, a_3
        ADC     a_3, b_0, a_3, ASR#31
        SMLAL   a_2, a_3, b_1, c_1      ; high*high
        ; return wrapper
        MOV     r0, a_0
        MOV     r1, a_1
        MOV     r2, a_2
        MOV     r3, a_3
        LDMFD   sp!, {r4,r5,pc}

        END
