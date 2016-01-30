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
;// Section 8.4: IIR Filters

        AREA    ch08_4, CODE, READONLY

        EXPORT  iir_q14_arm7m
        EXPORT  iir_q14_arm9m
        EXPORT  iir_q14_arm9e

;// Example 8.14

y       RN 0    ; address for output samples y[]
x       RN 1    ; address of input samples x[]
b       RN 2    ; address of biquads
N       RN 3    ; number of samples to filter (a multiple of 2)
M       RN 4    ; number of biquads to apply
x_0     RN 2    ; input samples
x_1     RN 4
a_1     RN 6    ; biquad coefficient -a[1] at Q14
a_2     RN 7    ; biquad coefficient -a[2] at Q14
b_1     RN 8    ; biquad coefficient +b[1] at Q14
b_2     RN 9    ; biquad coefficient +b[2] at Q14
s_1     RN 10   ; s[t-1] then s[t-2] (alternates)
s_2     RN 11   ; s[t-2] then s[t-1] (alternates)
acc0    RN 12   ; accumulators
acc1    RN 14

        ; typedef struct {
        ;   int a1,a2;  /* coefficients -a[1],-a[2] at Q14 */
        ;   int b1,b2;  /* coefficients +b[1],+b[2] at Q14 */
        ;   int s1,s2;  /* s[t-1], s[t-2] */
        ; } biquad;
        ;
        ; void iir_q14_arm7m
        ;  (int *y,
        ;   int *x,
        ;   struct { biquad *b; unsigned int M; } *b,
        ;   unsigned int N);
iir_q14_arm7m
        STMFD   sp!, {r4-r11, lr}
        LDMIA   b, {b, M}
next_biquad_arm7m
        LDMIA   b!, {a_1, a_2, b_1, b_2, s_1, s_2}
        STMFD   sp!, {b, N, M}
next_sample_arm7m
        ; use a 2x1 block IIR
        LDMIA   x!, {x_0, x_1}
        ; apply biquad to sample 0 (x_0)
        MUL     acc0, s_1, a_1
        MLA     acc0, s_2, a_2, acc0
        MUL     acc1, s_1, b_1
        MLA     acc1, s_2, b_2, acc1
        ADD     s_2, x_0, acc0, ASR #14
        ADD     x_0, s_2, acc1, ASR #14
        ; apply biquad to sample 1 (x_1)
        MUL     acc0, s_2, a_1
        MLA     acc0, s_1, a_2, acc0
        MUL     acc1, s_2, b_1
        MLA     acc1, s_1, b_2, acc1
        ADD     s_1, x_1, acc0, ASR #14
        ADD     x_1, s_1, acc1, ASR #14
        STMIA   y!, {x_0, x_1}
        SUBS    N, N, #2
        BGT     next_sample_arm7m
        LDMFD   sp!, {b, N, M}
        STMDB   b, {s_1, s_2}
        SUB     y, y, N, LSL#2
        MOV     x, y
        SUBS    M, M, #1
        BGT     next_biquad_arm7m
        LDMFD   sp!, {r4-r11, pc}

;// Example 8.15

y       RN 0    ; address for output samples y[]
x       RN 1    ; address of input samples x[]
b       RN 2    ; address of biquads
N       RN 3    ; number of samples to filter (a multiple of 2)
M       RN 4    ; number of biquads to apply
x_0     RN 2    ; input samples
x_1     RN 4
round   RN 5    ; rounding value (1<<13)
a_1     RN 6    ; biquad coefficient -a[1] at Q14
a_2     RN 7    ; biquad coefficient -a[2] at Q14
b_1     RN 8    ; biquad coefficient +b[1] at Q14
b_2     RN 9    ; biquad coefficient +b[2] at Q14
s_1     RN 10   ; s[t-1] then s[t-2] (alternates)
s_2     RN 11   ; s[t-2] then s[t-1] (alternates)
acc0    RN 12   ; accumulators
acc1    RN 14

        ; typedef struct {
        ;   short a1,a2; /* coefficients -a[1],-a[2] at Q14 */
        ;   short b1,b2; /* coefficients +b[1],+b[2] at Q14 */
        ;   short s1,s2; /* s[t-1], s[t-2] */
        ; } biquad;
        ;
        ; void iir_q14_arm9m
        ;  (short *y,
        ;   short *x,
        ;   struct { biquad *b; unsigned int M; } *b,
        ;   unsigned int N);
iir_q14_arm9m
        STMFD   sp!, {r4-r11, lr}
        LDMIA   b, {b, M}
        MOV     round, #1<<13
iir_next_biquad
        LDRSH   a_1, [b], #2
        LDRSH   a_2, [b], #2
        LDRSH   b_1, [b], #2
        LDRSH   b_2, [b], #2
        LDRSH   s_1, [b], #2
        LDRSH   s_2, [b], #2
        STMFD   sp!, {b, N, M}
iir_inner_loop
        ; use a 2x1 block IIR
        ; apply biquad to x_0
        MLA     acc0, s_1, a_1, round
        LDRSH   x_0, [x], #2
        MLA     acc0, s_2, a_2, acc0
        MLA     acc1, s_1, b_1, round
        MLA     acc1, s_2, b_2, acc1
        ADD     s_2, x_0, acc0, ASR #14
        ADD     x_0, s_2, acc1, ASR #14
        STRH    x_0, [y], #2
        ; apply biquad to x_1
        MLA     acc0, s_2, a_1, round
        LDRSH   x_1, [x], #2
        MLA     acc0, s_1, a_2, acc0
        MLA     acc1, s_2, b_1, round
        MLA     acc1, s_1, b_2, acc1
        ADD     s_1, x_1, acc0, ASR #14
        ADD     x_1, s_1, acc1, ASR #14
        STRH    x_1, [y], #2
        SUBS    N, N, #2
        BGT     iir_inner_loop
        LDMFD   sp!, {b, N, M}
        STRH    s_1, [b, #-4]
        STRH    s_2, [b, #-2]
        SUB     y, y, N, LSL#1
        MOV     x, y
        SUBS    M, M, #1
        BGT     iir_next_biquad
        LDMFD   sp!, {r4-r11, pc}

;// Example 8.16

y       RN 0    ; address for output samples y[]
x       RN 1    ; address of input samples x[]
b       RN 2    ; address of biquads (32-bit aligned)
N       RN 3    ; number of samples to filter (a multiple of 2)
M       RN 4    ; number of biquads to apply (a multiple of 2)
x_0     RN 2    ; input samples
x_1     RN 4
s_0     RN 5    ; new state
b0_a21  RN 6    ; biquad 0, packed -a[2], -a[1]
b0_b21  RN 7    ; biquad 0, packed +b[2], +b[1]
b0_s_1  RN 8    ; biquad 0, s[t-1]
b0_s_2  RN 9    ; biquad 0, s[t-2]
b1_a21  RN 10   ; biquad 1, packed -a[2], -a[1]
b1_b21  RN 11   ; biquad 1, packed +b[2], +b[1]
b1_s_1  RN 12   ; biquad 1, s[t-1]
b1_s_2  RN 14   ; biquad 1, s[t-2]

        ; typedef struct {
        ;   short a1,a2; /* coefficients -a[1],-a[2] at Q14 */
        ;   short b1,b2; /* coefficients +b[1],+b[2] at Q14 */
        ;   short s1,s2; /* s[t-1], s[t-2] */
        ; } biquad;
        ;
        ; void iir_q14_arm9e
        ;  (short *y,
        ;   short *x,
        ;   struct { biquad *b; unsigned int M; } *b,
        ;   unsigned int N);
iir_q14_arm9e
        STMFD   sp!, {r4-r11, lr}
        LDMIA   b, {b, M}
next_biquad_arm9e
        LDMIA   b!, {b0_a21, b0_b21}
        LDRSH   b0_s_1, [b], #2
        LDRSH   b0_s_2, [b], #2
        LDMIA   b!, {b1_a21, b1_b21}
        LDRSH   b1_s_1, [b], #2
        LDRSH   b1_s_2, [b], #2
        STMFD   sp!, {b, N, M}
next_sample_arm9e
        ; use a 2x2 block IIR
        LDRSH   x_0, [x], #2
        LDRSH   x_1, [x], #2
        SUBS    N, N, #2
        MOV     x_0, x_0, LSL #14
        MOV     x_1, x_1, LSL #14
        ; apply biquad 0 to sample 0
        SMLABB  x_0, b0_s_1, b0_a21, x_0
        SMLABT  s_0, b0_s_2, b0_a21, x_0
        SMLABB  x_0, b0_s_1, b0_b21, s_0
        SMLABT  x_0, b0_s_2, b0_b21, x_0
        MOV     b0_s_2, s_0, ASR #14
        ; apply biquad 0 to sample 1
        SMLABB  x_1, b0_s_2, b0_a21, x_1
        SMLABT  s_0, b0_s_1, b0_a21, x_1
        SMLABB  x_1, b0_s_2, b0_b21, s_0
        SMLABT  x_1, b0_s_1, b0_b21, x_1
        MOV     b0_s_1, s_0, ASR #14
        ; apply biquad 1 to sample 0
        SMLABB  x_0, b1_s_1, b1_a21, x_0
        SMLABT  s_0, b1_s_2, b1_a21, x_0
        SMLABB  x_0, b1_s_1, b1_b21, s_0
        SMLABT  x_0, b1_s_2, b1_b21, x_0
        MOV     b1_s_2, s_0, ASR #14
        ; apply biquad 1 to sample 1
        SMLABB  x_1, b1_s_2, b1_a21, x_1
        SMLABT  s_0, b1_s_1, b1_a21, x_1
        SMLABB  x_1, b1_s_2, b1_b21, s_0
        SMLABT  x_1, b1_s_1, b1_b21, x_1
        MOV     b1_s_1, s_0, ASR #14
        MOV     x_0, x_0, ASR #14
        MOV     x_1, x_1, ASR #14
        STRH    x_0, [y], #2
        STRH    x_1, [y], #2
        BGT     next_sample_arm9e
        LDMFD   sp!, {b, N, M}
        STRH    b0_s_1, [b, #-12-4]
        STRH    b0_s_2, [b, #-12-2]
        STRH    b1_s_1, [b, #-4]
        STRH    b1_s_2, [b, #-2]
        SUB     y, y, N, LSL#1
        MOV     x, y
        SUBS    M, M, #2
        BGT     next_biquad_arm9e
        LDMFD   sp!, {r4-r11, pc}

        END
