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
;// Section 8.3: FIR Filters

        AREA    ch08_3, CODE, READONLY

        EXPORT  fir_16by16_arm7m
        EXPORT  fir_16by16_arm9m
        EXPORT  fir_16by16_arm9e
        EXPORT  fir_32by16_arm9e
        EXPORT  fir_32by32

;// Example 8.9

a       RN 0    ; array for output samples a[]
x       RN 1    ; array of input samples x[]
c       RN 2    ; array of coefficients c[]
N       RN 3    ; number of outputs (a multiple of 4)
M       RN 4    ; number of coefficients (a multiple of 3)
c_0     RN 3    ; coefficient registers
c_1     RN 12
c_2     RN 14
x_0     RN 5    ; data registers
x_1     RN 6
x_2     RN 7
a_0     RN 8    ; output accumulators
a_1     RN 9
a_2     RN 10
a_3     RN 11

        ; void fir_16by16_arm7m
        ;  (int *a,
        ;   int *x,
        ;   struct { int *c; unsigned int M; } *c,
        ;   unsigned int N)
fir_16by16_arm7m
        STMFD   sp!, {r4-r11, lr}
        LDMIA   c, {c, M}       ; load coefficient array and length
next_sample_arm7m
        STMFD   sp!, {N, M}
        LDMIA   x!, {x_0, x_1, x_2}
        MOV     a_0, #0         ; zero accumulators
        MOV     a_1, #0
        MOV     a_2, #0
        MOV     a_3, #0
next_tap_arm7m
        ; perform next block of 4x3=12 taps
        LDMIA   c!, {c_0, c_1, c_2}
        MLA     a_0, x_0, c_0, a_0
        MLA     a_0, x_1, c_1, a_0
        MLA     a_0, x_2, c_2, a_0
        MLA     a_1, x_1, c_0, a_1
        MLA     a_1, x_2, c_1, a_1
        MLA     a_2, x_2, c_0, a_2
        LDMIA   x!, {x_0, x_1, x_2}
        MLA     a_1, x_0, c_2, a_1
        MLA     a_2, x_0, c_1, a_2
        MLA     a_2, x_1, c_2, a_2
        MLA     a_3, x_0, c_0, a_3
        MLA     a_3, x_1, c_1, a_3
        MLA     a_3, x_2, c_2, a_3
        SUBS    M, M, #3        ; processed 3 coefficents
        BGT     next_tap_arm7m
        LDMFD   sp!, {N, M}
        STMIA   a!, {a_0, a_1, a_2, a_3}
        SUB     c, c, M, LSL#2  ; restore coefficient pointer
        SUB     x, x, M, LSL#2  ; restore data pointer
        ADD     x, x, #(4-3)*4  ; advance data pointer
        SUBS    N, N, #4        ; filtered four samples
        BGT     next_sample_arm7m
        LDMFD   sp!, {r4-r11, pc}

;// Example 8.10

a       RN 0    ; array for output samples a[]
x       RN 1    ; array of input samples x[]
c       RN 2    ; array of coefficients c[]
N       RN 3    ; number of outputs (a multiple of 4)
M       RN 4    ; number of coefficients (a multiple of 4)
c_0     RN 3    ; coefficient registers
c_1     RN 12
x_0     RN 5    ; data registers
x_1     RN 6
x_2     RN 7
x_3     RN 14
a_0     RN 8    ; output accumulators
a_1     RN 9
a_2     RN 10
a_3     RN 11

        ; void fir_16by16_arm9m
        ;  (int *a,
        ;   short *x,
        ;   struct { short *c; unsigned int M; } *c,
        ;   unsigned int N)
fir_16by16_arm9m
        STMFD   sp!, {r4-r11, lr}
        LDMIA   c, {c, M}
next_sample_arm9m
        STMFD   sp!, {N, M}
        LDRSH   x_0, [x], #2
        LDRSH   x_1, [x], #2
        LDRSH   x_2, [x], #2
        LDRSH   x_3, [x], #2
        MOV     a_0, #0
        MOV     a_1, #0
        MOV     a_2, #0
        MOV     a_3, #0
next_tap_arm9m
        ; perform next block of 4x4=16 taps
        LDRSH   c_0, [c], #2
        LDRSH   c_1, [c], #2
        SUBS    M, M, #4
        MLA     a_0, x_0, c_0, a_0
        LDRSH   x_0, [x], #2
        MLA     a_1, x_1, c_0, a_1
        MLA     a_2, x_2, c_0, a_2
        MLA     a_3, x_3, c_0, a_3
        LDRSH   c_0, [c], #2
        MLA     a_0, x_1, c_1, a_0
        LDRSH   x_1, [x], #2
        MLA     a_1, x_2, c_1, a_1
        MLA     a_2, x_3, c_1, a_2
        MLA     a_3, x_0, c_1, a_3
        LDRSH   c_1, [c], #2
        MLA     a_0, x_2, c_0, a_0
        LDRSH   x_2, [x], #2
        MLA     a_1, x_3, c_0, a_1
        MLA     a_2, x_0, c_0, a_2
        MLA     a_3, x_1, c_0, a_3
        MLA     a_0, x_3, c_1, a_0
        LDRSH   x_3, [x], #2
        MLA     a_1, x_0, c_1, a_1
        MLA     a_2, x_1, c_1, a_2
        MLA     a_3, x_2, c_1, a_3
        BGT     next_tap_arm9m
        LDMFD   sp!, {N, M}
        STMIA   a!, {a_0, a_1, a_2, a_3}
        SUB     c, c, M, LSL#1  ; restore coefficient pointer
        SUB     x, x, M, LSL#1  ; advance data pointer
        SUBS    N, N, #4        ; filtered four samples
        BGT     next_sample_arm9m
        LDMFD   sp!, {r4-r11, pc}

;// Example 8.11

a       RN 0    ; array for output samples a[]
x       RN 1    ; array of input samples x[] (32-bit aligned)
c       RN 2    ; array of coefficients c[] (32-bit aligned)
N       RN 3    ; number of outputs (a multiple of 6)
M       RN 4    ; number of coefficients (a multiple of 6)
c_10    RN 0    ; coefficient pairs
c_32    RN 3
x_10    RN 5    ; sample pairs
x_32    RN 6
x_54    RN 7
a_0     RN 8    ; output accumulators
a_1     RN 9
a_2     RN 10
a_3     RN 11
a_4     RN 12
a_5     RN 14

        ; void fir_16by16_arm9e
        ;  (int *a,
        ;   short *x,
        ;   struct { short *c; unsigned int M; } *c,
        ;   unsigned int N)
fir_16by16_arm9e
        STMFD   sp!, {r4-r11, lr}
        LDMIA   c, {c, M}
next_sample_arm9e
        STMFD   sp!, {a, N, M}
        LDMIA   x!, {x_10, x_32, x_54}  ; preload six samples
        MOV     a_0, #0                 ; zero accumulators
        MOV     a_1, #0
        MOV     a_2, #0
        MOV     a_3, #0
        MOV     a_4, #0
        MOV     a_5, #0
next_tap_arm9e
        ; perform next block of 6x6=36 taps
        LDMIA   c!, {c_10, c_32}        ; load four coefficients
        SUBS    M, M, #6
        SMLABB  a_0, x_10, c_10, a_0
        SMLATB  a_1, x_10, c_10, a_1
        SMLABB  a_2, x_32, c_10, a_2
        SMLATB  a_3, x_32, c_10, a_3
        SMLABB  a_4, x_54, c_10, a_4
        SMLATB  a_5, x_54, c_10, a_5
        SMLATT  a_0, x_10, c_10, a_0
        LDR     x_10, [x], #4           ; load two coefficients
        SMLABT  a_1, x_32, c_10, a_1
        SMLATT  a_2, x_32, c_10, a_2
        SMLABT  a_3, x_54, c_10, a_3
        SMLATT  a_4, x_54, c_10, a_4
        SMLABT  a_5, x_10, c_10, a_5
        LDR     c_10, [c], #4
        SMLABB  a_0, x_32, c_32, a_0
        SMLATB  a_1, x_32, c_32, a_1
        SMLABB  a_2, x_54, c_32, a_2
        SMLATB  a_3, x_54, c_32, a_3
        SMLABB  a_4, x_10, c_32, a_4
        SMLATB  a_5, x_10, c_32, a_5
        SMLATT  a_0, x_32, c_32, a_0
        LDR     x_32, [x], #4
        SMLABT  a_1, x_54, c_32, a_1
        SMLATT  a_2, x_54, c_32, a_2
        SMLABT  a_3, x_10, c_32, a_3
        SMLATT  a_4, x_10, c_32, a_4
        SMLABT  a_5, x_32, c_32, a_5
        SMLABB  a_0, x_54, c_10, a_0
        SMLATB  a_1, x_54, c_10, a_1
        SMLABB  a_2, x_10, c_10, a_2
        SMLATB  a_3, x_10, c_10, a_3
        SMLABB  a_4, x_32, c_10, a_4
        SMLATB  a_5, x_32, c_10, a_5
        SMLATT  a_0, x_54, c_10, a_0
        LDR     x_54, [x], #4
        SMLABT  a_1, x_10, c_10, a_1
        SMLATT  a_2, x_10, c_10, a_2
        SMLABT  a_3, x_32, c_10, a_3
        SMLATT  a_4, x_32, c_10, a_4
        SMLABT  a_5, x_54, c_10, a_5
        BGT     next_tap_arm9e
        LDMFD   sp!, {a, N, M}
        STMIA   a!, {a_0, a_1, a_2, a_3, a_4, a_5}
        SUB     c, c, M, LSL#1          ; restore coefficient pointer
        SUB     x, x, M, LSL#1          ; advance data pointer
        SUBS    N, N, #6
        BGT     next_sample_arm9e
        LDMFD   sp!, {r4-r11, pc}

;// Example 8.12

a       RN 0    ; array for output samples a[]
x       RN 1    ; array of input samples x[]
c       RN 2    ; array of coefficients c[] (32-bit aligned)
N       RN 3    ; number of outputs (a multiple of 5)
M       RN 4    ; number of coefficients (a multiple of 4)
c_10    RN 0    ; coefficient pair
c_32    RN 3
x_0     RN 5    ; input samples
x_1     RN 6
x_2     RN 7
x_3     RN 14
a_0     RN 8    ; output accumulators
a_1     RN 9
a_2     RN 10
a_3     RN 11
a_4     RN 12

        ; void fir_32by16_arm9e
        ;  (int *a,
        ;   int *x,
        ;   struct { short *c; unsigned int M; } *c,
        ;   unsigned int N)
fir_32by16_arm9e
        STMFD   sp!, {r4-r11, lr}
        LDMIA   c, {c, M}
next_sample32_arm9e
        STMFD   sp!, {a, N, M}
        LDMIA   x!, {x_0, x_1, x_2, x_3}
        MOV     a_0, #0
        MOV     a_1, #0
        MOV     a_2, #0
        MOV     a_3, #0
        MOV     a_4, #0
next_tap32_arm9e
        ; perform next block of 5x4=20 taps
        LDMIA   c!, {c_10, c_32}
        SUBS    M, M, #4
        SMLAWB  a_0, x_0, c_10, a_0
        SMLAWB  a_1, x_1, c_10, a_1
        SMLAWB  a_2, x_2, c_10, a_2
        SMLAWB  a_3, x_3, c_10, a_3
        SMLAWT  a_0, x_1, c_10, a_0
        LDMIA   x!, {x_0, x_1}
        SMLAWT  a_1, x_2, c_10, a_1
        SMLAWT  a_2, x_3, c_10, a_2
        SMLAWB  a_0, x_2, c_32, a_0
        SMLAWB  a_1, x_3, c_32, a_1
        SMLAWT  a_0, x_3, c_32, a_0
        LDMIA   x!, {x_2, x_3}
        SMLAWB  a_4, x_0, c_10, a_4
        SMLAWT  a_3, x_0, c_10, a_3
        SMLAWT  a_4, x_1, c_10, a_4
        SMLAWB  a_2, x_0, c_32, a_2
        SMLAWB  a_3, x_1, c_32, a_3
        SMLAWB  a_4, x_2, c_32, a_4
        SMLAWT  a_1, x_0, c_32, a_1
        SMLAWT  a_2, x_1, c_32, a_2
        SMLAWT  a_3, x_2, c_32, a_3
        SMLAWT  a_4, x_3, c_32, a_4
        BGT     next_tap32_arm9e
        LDMFD   sp!, {a, N, M}
        STMIA   a!, {a_0, a_1, a_2, a_3, a_4}
        SUB     c, c, M, LSL#1
        SUB     x, x, M, LSL#2
        ADD     x, x, #(5-4)*4
        SUBS    N, N, #5
        BGT     next_sample32_arm9e
        LDMFD   sp!, {r4-r11, pc}

;// Example 8.13

a       RN 0    ; array for output samples a[]
x       RN 1    ; array of input samples x[]
c       RN 2    ; array of coefficients c[]
N       RN 3    ; number of outputs (a multiple of 3)
M       RN 4    ; number of coefficients (a multiple of 2)
c_0     RN 3    ; coefficient registers
c_1     RN 12
x_0     RN 5    ; data registers
x_1     RN 6
a_0l    RN 7    ; accumulators (low 32 bits)
a_0h    RN 8    ; accumulators (high 32 bits)
a_1l    RN 9
a_1h    RN 10
a_2l    RN 11
a_2h    RN 14

        ; void fir_32by32
        ;  (long long *a,
        ;   int *x,
        ;   struct { int *c; unsigned int M; } *c,
        ;   unsigned int N)
fir_32by32
        STMFD   sp!, {r4-r11, lr}
        LDMIA   c, {c, M}
next_sample32
        STMFD   sp!, {N, M}
        LDMIA   x!, {x_0, x_1}
        MOV     a_0l, #0
        MOV     a_0h, #0
        MOV     a_1l, #0
        MOV     a_1h, #0
        MOV     a_2l, #0
        MOV     a_2h, #0
next_tap32
        ; perform next block of 3x2=6 taps
        LDMIA   c!, {c_0, c_1}
        SMLAL   a_0l, a_0h, x_0, c_0
        SMLAL   a_1l, a_1h, x_1, c_0
        SMLAL   a_0l, a_0h, x_1, c_1
        LDMIA   x!, {x_0, x_1}
        SUBS    M, M, #2
        SMLAL   a_2l, a_2h, x_0, c_0
        SMLAL   a_1l, a_1h, x_0, c_1
        SMLAL   a_2l, a_2h, x_1, c_1
        BGT     next_tap32
        LDMFD   sp!, {N, M}
        STMIA   a!, {a_0l, a_0h, a_1l, a_1h, a_2l, a_2h}
        SUB     c, c, M, LSL#2
        SUB     x, x, M, LSL#2
        ADD     x, x, #(3-2)*4
        SUBS    N, N, #3
        BGT     next_sample32
        LDMFD   sp!, {r4-r11, pc}

        END
