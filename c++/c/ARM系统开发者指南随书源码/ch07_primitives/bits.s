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
;// Section 7.6: Bit operations

        AREA    ch07_6, CODE, READONLY

        EXPORT  byte_reverse_2reg
        EXPORT  byte_reverse
        EXPORT  bit_count
        EXPORT  bit_reverse
        EXPORT  bit_spread
        EXPORT  bit_rev_spread

n       RN 0    ; input, output words
t       RN 1    ; scratch 1
m       RN 2    ; scratch 2

byte_reverse                     ; n = [  a ,  b ,  c ,  d  ]
        MVN     m, #0x0000FF00   ; m = [0xFF,0xFF,0x00,0xFF ]
        EOR     t, n, n, ROR #16 ; t = [ a^c, b^d, a^c, b^d ]
        AND     t, m, t, LSR#8   ; t = [  0 , a^c,  0 , a^c ]
        EOR     n, t, n, ROR #8  ; n = [  d ,  c ,  b ,  a  ]
        MOV     pc, lr

byte_reverse_2reg                ; n = [  a ,  b ,  c,   d  ]
        EOR     t, n, n, ROR#16  ; t = [ a^c, b^d, a^c, b^d ]
        MOV     t, t, LSR#8      ; t = [  0 , a^c, b^d, a^c ]
        BIC     t, t, #0xFF00    ; t = [  0 , a^c,  0 , a^c ]
        EOR     n, t, n, ROR #8  ; n = [  d ,  c ,  b ,  a  ]
        MOV     pc, lr

mask0   EQU     0x55555555      ; set bit positions with b0=0
mask1   EQU     0x33333333      ; set bit positions with b1=0
mask2   EQU     0x0F0F0F0F      ; set bit positions with b2=0
mask3   EQU     0x00FF00FF      ; set bit positions with b3=0
mask4   EQU     0x0000FFFF      ; set bit positions with b4=0

        MACRO
        PERMUTE_A $k
        ; [ ... b_k ... ] -> [ ... 1-b_k ... ]
        IF $k=4
          MOV   n, n, ROR#16
        ELSE
          LDR   m, =mask$k
          AND   t, m, n, LSR#(1<<$k)    ; get bits with index b_k=1
          AND   n, n, m                 ; get bits with index b_k=0
          ORR   n, t, n, LSL#(1<<$k)    ; swap them over
        ENDIF
        MEND

        MACRO
        PERMUTE_B $j, $k
        ; [ .. b_j .. b_k .. ] -> [ .. b_k .. b_j .. ]  and j>k
        LDR     m, =(mask$j:AND::NOT:mask$k) ; set when b_j=0 b_k=1
        EOR     t, n, n, LSR#(1<<$j)-(1<<$k)
        AND     t, t, m                      ; get bits where b_j!=b_k
        EOR     n, n, t, LSL#(1<<$j)-(1<<$k) ; change when b_j=1 b_k=0
        EOR     n, n, t                      ; change when b_j=0 b_k=1
        MEND

        MACRO
        PERMUTE_C $j, $k
        ; [ .. b_j .. b_k .. ] -> [ .. 1-b_k .. 1-b_j .. ]  and j>k
        LDR     m, =(mask$j:AND:mask$k)      ; set when b_j=0 b_k=0
        EOR     t, n, n, LSR#(1<<$j)+(1<<$k)
        AND     t, t, m                      ; get bits where b_j==b_k
        EOR     n, n, t, LSL#(1<<$j)+(1<<$k) ; change when b_j=1 b_k=1
        EOR     n, n, t                      ; change when b_j=0 b_k=0
        MEND

bit_reverse             ; n= [  b4   b3   b2   b1   b0  ]
        PERMUTE_A 0     ; -> [  b4   b3   b2   b1  1-b0 ]
        PERMUTE_A 1     ; -> [  b4   b3   b2  1-b1 1-b0 ]
        PERMUTE_A 2     ; -> [  b4   b3  1-b2 1-b1 1-b0 ]
        PERMUTE_A 3     ; -> [  b4  1-b3 1-b2 1-b1 1-b0 ]
        PERMUTE_A 4     ; -> [ 1-b4 1-b3 1-b2 1-b1 1-b0 ]
        MOV     pc, lr

bit_spread              ; n= [ b4 b3 b2 b1 b0 ]
        PERMUTE_B 4,3   ; -> [ b3 b4 b2 b1 b0 ]
        PERMUTE_B 3,2   ; -> [ b3 b2 b4 b1 b0 ]
        PERMUTE_B 2,1   ; -> [ b3 b2 b1 b4 b0 ]
        PERMUTE_B 1,0   ; -> [ b3 b2 b1 b0 b4 ]
        MOV     pc, lr

bit_rev_spread          ; n= [  b4   b3   b2   b1   b0 ]
        PERMUTE_C 4,3   ; -> [ 1-b3 1-b4  b2   b1   b0 ]
        PERMUTE_C 3,2   ; -> [ 1-b3 1-b2  b4   b1   b0 ]
        PERMUTE_C 2,1   ; -> [ 1-b3 1-b2 1-b1 1-b4  b0 ]
        PERMUTE_C 1,0   ; -> [ 1-b3 1-b2 1-b1 1-b0  b4 ]
        MOV     pc, lr

;=================================================================////

bit_count              ; input n = xyzxyzxyzxyzxyzxyzxyzxyzxyzxyzxy
        LDR     m, =0x49249249   ; 01001001001001001001001001001001
        AND     t, n, m, LSL #1  ; x00x00x00x00x00x00x00x00x00x00x0
        SUB     n, n, t, LSR #1  ; uuzuuzuuzuuzuuzuuzuuzuuzuuzuuzuu
        AND     t, n, m, LSR #1  ; 00z00z00z00z00z00z00z00z00z00z00
        ADD     n, n, t          ; vv0vv0vv0vv0vv0vv0vv0vv0vv0vv0vv
        ; triplets summed, uu=x+y, vv=x+y+z
        LDR     m, =0xC71C71C7   ; 11000111000111000111000111000111
        ADD     n, n, n, LSR #3  ; ww0vvwww0vvwww0vvwww0vvwww0vvwww
        AND     n, n, m          ; ww000www000www000www000www000www
        ; each www is the sum of six adjacent bits
        ADD     n, n, n, LSR #6  ; sum the w's
        ADD     n, n, n, LSR #12
        ADD     n, n, n, LSR #24
        AND     n, n, #63        ; mask out irrelevant bits
        MOV     pc, lr

        END
