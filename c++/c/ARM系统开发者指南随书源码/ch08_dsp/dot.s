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
;// Section 8.2: Dot products

        AREA    ch08_2, CODE, READONLY
        
        EXPORT  dot_16by16_arm7m
        EXPORT  dot_16by16_arm9m
        EXPORT  dot_16by16_SA1
        EXPORT  dot_16by16_arm9e
        EXPORT  dot_16by16_arm10
        EXPORT  dot_16by16_xscale
        
;// Example 8.2
        
x       RN 0    ; input array x[]
c       RN 1    ; input array c[]
N       RN 2    ; number of samples (a multiple of 5)
acc     RN 3    ; accumulator
x_0     RN 4    ; elements from array x[]
x_1     RN 5
x_2     RN 6
x_3     RN 7
x_4     RN 8
c_0     RN 9    ; elements from array c[]
c_1     RN 10
c_2     RN 11
c_3     RN 12
c_4     RN 14

        ; int dot_16by16_arm7m(int *x, int *c, unsigned N)
dot_16by16_arm7m
        STMFD   sp!, {r4-r11, lr}
        MOV     acc, #0
loop_7m ; accumulate 5 products
        LDMIA   x!, {x_0, x_1, x_2, x_3, x_4}
        LDMIA   c!, {c_0, c_1, c_2, c_3, c_4}
        MLA     acc, x_0, c_0, acc
        MLA     acc, x_1, c_1, acc
        MLA     acc, x_2, c_2, acc
        MLA     acc, x_3, c_3, acc
        MLA     acc, x_4, c_4, acc
        SUBS    N, N, #5
        BGT     loop_7m
        MOV     r0, acc
        LDMFD   sp!, {r4-r11, pc}

;// Example 8.3

x       RN 0    ; input array x[]
c       RN 1    ; input array c[]
N       RN 2    ; number of samples (a multiple of 4)
acc     RN 3    ; accumulator
x_0     RN 4    ; elements from array x[]
x_1     RN 5
c_0     RN 9    ; elements from array c[]
c_1     RN 10

        ; int dot_16by16_arm9m(short *x, short *c, unsigned N)
dot_16by16_arm9m
        STMFD   sp!, {r4-r5, r9-r10, lr}
        MOV     acc, #0
        LDRSH   x_0, [x], #2
        LDRSH   c_0, [c], #2
loop_9m ; accumulate 4 products
        SUBS    N, N, #4
        LDRSH   x_1, [x], #2
        LDRSH   c_1, [c], #2
        MLA     acc, x_0, c_0, acc
        LDRSH   x_0, [x], #2
        LDRSH   c_0, [c], #2
        MLA     acc, x_1, c_1, acc
        LDRSH   x_1, [x], #2
        LDRSH   c_1, [c], #2
        MLA     acc, x_0, c_0, acc
        LDRGTSH x_0, [x], #2
        LDRGTSH c_0, [c], #2
        MLA     acc, x_1, c_1, acc
        BGT     loop_9m
        MOV     r0, acc
        LDMFD   sp!, {r4-r5, r9-r10, pc}
        
;// Example 8.4

x       RN 0    ; input array x[]
c       RN 1    ; input array c[]
N       RN 2    ; number of samples (a multiple of 4)
acc     RN 3    ; accumulator
x_0     RN 4    ; elements from array x[]
x_1     RN 5
c_0     RN 9    ; elements from array c[]
c_1     RN 10

        ; int dot_16by16_SA1(int *x, int *c, unsigned N)
dot_16by16_SA1
        STMFD   sp!, {r4-r5, r9-r10, lr}
        MOV     acc, #0
        LDR     x_0, [x], #4
        LDR     c_0, [c], #4
loop_sa ; accumulate 4 products
        SUBS    N, N, #4
        LDR     x_1, [x], #4
        LDR     c_1, [c], #4
        MLA     acc, x_0, c_0, acc
        LDR     x_0, [x], #4
        LDR     c_0, [c], #4
        MLA     acc, x_1, c_1, acc
        LDR     x_1, [x], #4
        LDR     c_1, [c], #4
        MLA     acc, x_0, c_0, acc
        LDRGT   x_0, [x], #4
        LDRGT   c_0, [c], #4
        MLA     acc, x_1, c_1, acc
        BGT     loop_sa
        MOV     r0, acc
        LDMFD   sp!, {r4-r5, r9-r10, pc}

;// Example 8.5

x       RN 0    ; input array x[]
c       RN 1    ; input array c[]
N       RN 2    ; number of samples (a multiple of 8)
acc     RN 3    ; accumulator
x_10    RN 4    ; packed elements from array x[]
x_32    RN 5
c_10    RN 8    ; packed elements from array c[]
c_32    RN 9

        ; int dot_16by16_arm9e(short *x, short *c, unsigned N)
dot_16by16_arm9e
        STMFD   sp!, {r4-r5, r8-r9, lr}
        MOV     acc, #0
        LDR     x_10, [x], #4
        LDR     c_10, [c], #4
loop_9e ; accumulate 8 products
        SUBS    N, N, #8
        LDR     x_32, [x], #4
        SMLABB  acc, x_10, c_10, acc
        LDR     c_32, [c], #4
        SMLATT  acc, x_10, c_10, acc
        LDR     x_10, [x], #4
        SMLABB  acc, x_32, c_32, acc
        LDR     c_10, [c], #4
        SMLATT  acc, x_32, c_32, acc
        LDR     x_32, [x], #4
        SMLABB  acc, x_10, c_10, acc
        LDR     c_32, [c], #4
        SMLATT  acc, x_10, c_10, acc
        LDRGT   x_10, [x], #4
        SMLABB  acc, x_32, c_32, acc
        LDRGT   c_10, [c], #4
        SMLATT  acc, x_32, c_32, acc
        BGT     loop_9e
        MOV     r0, acc
        LDMFD   sp!, {r4-r5, r8-r9, pc}
        
;// Example 8.6

x       RN 0    ; input array x[]
c       RN 1    ; input array c[]
N       RN 2    ; number of samples (a multiple of 10)
acc     RN 3    ; accumulator
x_10    RN 4    ; packed elements from array x[]
x_32    RN 5
x_54    RN 6
x_76    RN 7
x_98    RN 14
c_10    RN 8    ; packed elements from array c[]
c_32    RN 9
c_54    RN 10
c_76    RN 11
c_98    RN 12

        ; int dot_16by16_arm10(short *x, short *c, int n)
dot_16by16_arm10
        STMFD   sp!, {r4-r11, lr}
        LDMIA   x!, {x_10, x_32}
        MOV     acc, #0
        LDMIA   c!, {c_10, c_32}
loop_10 ; accumulate 10 products
        SUBS    N, N, #10
        LDMIA   x!, {x_54, x_76, x_98}
        SMLABB  acc, x_10, c_10, acc
        SMLATT  acc, x_10, c_10, acc
        LDMIA   c!, {c_54, c_76, c_98}
        SMLABB  acc, x_32, c_32, acc
        SMLATT  acc, x_32, c_32, acc
        LDMGTIA x!, {x_10, x_32}
        SMLABB  acc, x_54, c_54, acc
        SMLATT  acc, x_54, c_54, acc
        SMLABB  acc, x_76, c_76, acc
        LDMGTIA c!, {c_10, c_32}
        SMLATT  acc, x_76, c_76, acc
        SMLABB  acc, x_98, c_98, acc
        SMLATT  acc, x_98, c_98, acc
        BGT     loop_10
        MOV     r0, acc
        LDMFD   sp!, {r4-r11, pc}
        
;// Example 8.7

x       RN 0    ; input array x[] (64-bit aligned)
c       RN 1    ; input array c[] (64-bit aligned)
N       RN 2    ; number of samples (a multiple of 8)
acc0    RN 3    ; accumulators
acc1    RN 14
x_10    RN 4    ; packed elements from array x[]
x_32    RN 5
x_54    RN 6
x_76    RN 7
c_10    RN 8    ; packed elements from array c[]
c_32    RN 9
c_54    RN 10
c_76    RN 11

dot_16by16_xscale
        STMFD   sp!, {r4-r11, lr}
        LDRD    x_10, [x], #8   ; pre-load x_10, x_32
        LDRD    c_10, [c], #8   ; pre-load c_10, c_32
        MOV     acc0, #0
        MOV     acc1, #0
loop_xscale
        ; accumulate 8 products
        SUBS    N, N, #8
        LDRD    x_54, [x], #8   ; load x_54, x_76
        SMLABB  acc0, x_10, c_10, acc0
        SMLATT  acc1, x_10, c_10, acc1
        LDRD    c_54, [c], #8   ; load c_54, c_76
        SMLABB  acc0, x_32, c_32, acc0
        SMLATT  acc1, x_32, c_32, acc1
        LDRGTD  x_10, [x], #8   ; load x_10, x_32
        SMLABB  acc0, x_54, c_54, acc0
        SMLATT  acc1, x_54, c_54, acc1
        LDRGTD  c_10, [c], #8   ; load c_10, c_32
        SMLABB  acc0, x_76, c_76, acc0
        SMLATT  acc1, x_76, c_76, acc1
        BGT     loop_xscale
        ADD     r0, acc0, acc1
        LDMFD   sp!, {r4-r11, pc}

        END
