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
;// Section 6.6.2: Looping constructs

        AREA    ch06_6_2, CODE, READONLY
        
;// Example 6.20
        
        EXPORT  my_memset
        
T_1     EQU 5
T_2     EQU 128
        
s       RN 0    ; current string pointer
c       RN 1    ; the character to fill with
N       RN 2    ; the number of bytes to fill
c_1     RN 3    ; copies of c
c_2     RN 4
c_3     RN 5
c_4     RN 6
c_5     RN 7
c_6     RN 8
c_7     RN 12

        ; void my_memset(char *s, unsigned int c, unsigned int N)
my_memset
        ;-------------------------------------------------------
        ; First section aligns the array
        CMP     N, #T_1         ; We know that T_1>=3
        BCC     memset_1ByteBlk ; if (N<T_1) goto memset_1ByteBlk
        ANDS    c_1, s, #3      ; find the byte alignment of s
        BEQ     aligned         ; branch if already aligned
        RSB     c_1, c_1, #4    ; number of bytes until alignment
        SUB     N, N, c_1       ; number of bytes after alignment
        CMP     c_1, #2
        STRB    c, [s], #1
        STRGEB  c, [s], #1      ; if (c_1>=2) then output byte
        STRGTB  c, [s], #1      ; if (c_1>=3) then output byte
aligned                         ; the s array is now aligned
        ORR     c, c, c, LSL#8  ; duplicate the character
        ORR     c, c, c, LSL#16 ; to fill all four bytes of c
        ;-------------------------------------------------------
        ; Second section writes blocks of 128 bytes
        CMP     N, #T_2         ; We know that T_2 >= 128
        BCC     memset_4ByteBlk ; if (N<T_2) goto memset_4ByteBlk
        STMFD   sp!, {c_2-c_6}  ; stack scratch registers
        MOV     c_1, c
        MOV     c_2, c
        MOV     c_3, c
        MOV     c_4, c
        MOV     c_5, c
        MOV     c_6, c
        MOV     c_7, c
        SUB     N, N, #128      ; bytes left after next block
loop128 ; write 32 words = 128 bytes        
        STMIA   s!, {c, c_1-c_6, c_7}  ; write 8 words
        STMIA   s!, {c, c_1-c_6, c_7}  ; write 8 words
        STMIA   s!, {c, c_1-c_6, c_7}  ; write 8 words
        STMIA   s!, {c, c_1-c_6, c_7}  ; write 8 words
        SUBS    N, N, #128      ; bytes left after next block
        BGE     loop128
        ADD     N, N, #128      ; number of bytes left
        LDMFD   sp!, {c_2-c_6}  ; restore corrupted registers
        ;-------------------------------------------------------
        ; Third section deals with left over bytes
memset_4ByteBlk
        SUBS    N, N, #4        ; try doing 4 bytes
loop4   ; write 4 bytes
        STRGE   c, [s], #4
        SUBGES  N, N, #4
        BGE     loop4
        ADD     N, N, #4        ; number of bytes left
memset_1ByteBlk
        SUBS    N, N, #1
loop1   ; write 1 byte
        STRGEB  c, [s], #1
        SUBGES  N, N, #1
        BGE     loop1
        MOV     pc, lr          ; finished so return

        END
