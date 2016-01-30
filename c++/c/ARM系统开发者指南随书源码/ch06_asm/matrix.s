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
;// Section 6.6.3: Looping constructs

        AREA    ch06_6_3, CODE, READONLY
        
        EXPORT  matrix_mul
        
;// Example 6.21
        
R       EQU 40
S       EQU 40
T       EQU 40

a       RN 0    ; points to an R rows x T columns matrix
b       RN 1    ; points to an R rows x S columns matrix
c       RN 2    ; points to an S rows x T columns matrix
sum     RN 3
bval    RN 4
cval    RN 12
count   RN 14

        ; void matrx_mul(int *a, int *b, int *c)
matrix_mul
        STMFD   sp!, {r4, lr}
        MOV     count, #(R-1)           ; i=0
loop_i
        ADD     count, count, #(T-1)<<8 ; j=0
loop_j
        ADD     count, count, #(S-1)<<16 ; k=0
        MOV     sum, #0
loop_k  
        LDR     bval, [b], #4           ; bval = B[i,k], b=&B[i,k+1]
        LDR     cval, [c], #4*T         ; cval = C[k,j], c=&C[k+1,j]
        SUBS    count, count, #1<<16    ; k++
        MLA     sum, bval, cval, sum    ; sum += bval*cval
        BPL     loop_k                  ; branch if k<=S-1
        STR     sum, [a], #4            ; A[i,j] = sum, a=&A[i,j+1]
        SUB     c, c, #4*S*T            ; c = &C[0,j]
        ADD     c, c, #4                ; c = &C[0,j+1]
        ADDS    count, count, #(1<<16)-(1<<8) ; zero (S-1-k), j++
        SUBPL   b, b, #4*S              ; b = &B[i,0]
        BPL     loop_j                  ; branch if j<=T-1
        SUB     c, c, #4*T              ; c = &C[0,0]
        ADDS    count, count, #(1<<8)-1 ; zero (T-1-j), i++
        BPL     loop_i                  ; branch if i<=R-1
        LDMFD   sp!, {r4, pc}
        
        END
