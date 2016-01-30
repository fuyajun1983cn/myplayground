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
;// Section 6.4.3: Register allocation

        AREA    ch06_4_3, CODE, READONLY
        
        EXPORT  shift_bits
        EXPORT  shift_right

;// Example 6.11
        
out     RN 0    ; output array for N-bit shifted integer
in      RN 1    ; input array for N-bit source integer
N       RN 2    ; length in bits (a multiple of 256)
k       RN 3    ; number of bits to shift (0-32)

x_0     RN 5
x_1     RN 6
x_2     RN 7
x_3     RN 8
x_4     RN 9
x_5     RN 10
x_6     RN 11
x_7     RN 12
y_0     RN 4
y_1     RN x_0
y_2     RN x_1
y_3     RN x_2
y_4     RN x_3
y_5     RN x_4
y_6     RN x_5
y_7     RN x_6
kr      RN lr

        ; void shift_bits(unsigned *out, unsigned *in, int N, int k)
shift_bits
        STMFD   sp!, {r4-r11, lr}       ; save registers
        RSB     kr, k, #32              ; kr = 32-k;
        MOV     y_0, #0                 ; initial carry
loop    
        LDMIA   in!, {x_0-x_7}          ; load 8 words
        ORR     y_0, y_0, x_0, LSL k    ; shift the 8 words
        MOV     y_1, x_0, LSR kr        ; recall x_0 = y_1
        ORR     y_1, y_1, x_1, LSL k 
        MOV     y_2, x_1, LSR kr
        ORR     y_2, y_2, x_2, LSL k 
        MOV     y_3, x_2, LSR kr
        ORR     y_3, y_3, x_3, LSL k 
        MOV     y_4, x_3, LSR kr
        ORR     y_4, y_4, x_4, LSL k 
        MOV     y_5, x_4, LSR kr
        ORR     y_5, y_5, x_5, LSL k 
        MOV     y_6, x_5, LSR kr
        ORR     y_6, y_6, x_6, LSL k 
        MOV     y_7, x_6, LSR kr
        ORR     y_7, y_7, x_7, LSL k 
        STMIA   out!, {y_0-y_7}         ; store 8 words
        MOV     y_0, x_7, LSR kr
        SUBS    N, N, #256              ; N -= (8 words * 32 bits)
        BNE     loop                    ; if (N!=0) goto loop;
        MOV     r0, y_0                 ; return carry;
        LDMFD   sp!, {r4-r11, pc}

        MAP     0   ; map symbols to offsets starting at offset 0
a       FIELD   4   ; a is 4 byte integer (at offset 0)
b       FIELD   2   ; b is 2 byte integer (at offset 4)
c       FIELD   2   ; c is 2 byte integer (at offset 6)
d       FIELD   64  ; d is an array of 64 characters (at offset 8)
length  FIELD   0   ; length records the current offset reached

example
        STMFD   sp!, {r4-r11, lr}   ; save callee registers
        SUB     sp, sp, #length     ; create stack frame
        ; ...
        STR     r0, [sp, #a]        ; a = r0;
        LDRSH   r1, [sp, #b]        ; r1 = b;
        ADD     r2, sp, #d          ; r2 = &d[0]
        ; ...
        ADD     sp, sp, #length     ; restore the stack pointer
        LDMFD   sp!, {r4-r11, pc}   ; return

;// Example 6.15

out     RN 0    ; address of the output array
in      RN 1    ; address of the input array
cntshf  RN 2    ; count and shift right amount
x       RN 3    ; scratch variable

        ; void shift_right(int *out, int *in, unsigned shift);
shift_right
        ADD     cntshf, cntshf, #39<<8 ; count = 39
shift_loop    
        LDR     x, [in], #4
        SUBS    cntshf, cntshf, #1<<8  ; decrement count
        MOV     x, x, ASR cntshf       ; shift by shift
        STR     x, [out], #4
        BGE     shift_loop             ; continue if count>=0
        MOV     pc, lr
        
        END
