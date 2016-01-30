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
;// Section 6.8: Efficient switches

        AREA    ch06_8, CODE, READONLY
        
        EXPORT  switch_absolute
        EXPORT  switch_relative
        EXPORT  switch_hash
        
;// Example 6.26
        
x       RN 0
hash    RN 1
        
        ; int switch_absolute(int x)
switch_absolute
        CMP     x, #8
        LDRLT   pc, [pc, x, LSL#2]
        B       method_d
        DCD     method_0
        DCD     method_1
        DCD     method_2
        DCD     method_3
        DCD     method_4
        DCD     method_5
        DCD     method_6
        DCD     method_7

;// Example 6.27

        ; int switch_relative(int x)
switch_relative
        CMP     x, #8
        ADDLT   pc, pc, x, LSL#2
        B       method_d
        B       method_0
        B       method_1
        B       method_2
        B       method_3
        B       method_4
        B       method_5
        B       method_6
        B       method_7

;// Example 6.29

        ; int switch_hash(int x)
switch_hash
        RSB     hash, x, x, LSL#4       ; hash=x*15
        RSB     hash, hash, hash, LSL#5 ; hash=x*15*31
        AND     hash, hash, #7<<9       ; mask out the hash value
        ADD     pc, pc, hash, LSR#6
        NOP
        TEQ     x, #0x01
        BEQ     method_0
        TEQ     x, #0x02
        BEQ     method_1
        TEQ     x, #0x40
        BEQ     method_6
        TEQ     x, #0x04
        BEQ     method_2
        TEQ     x, #0x80
        BEQ     method_7
        TEQ     x, #0x20
        BEQ     method_5
        TEQ     x, #0x10
        BEQ     method_4
        TEQ     x, #0x08
        BEQ     method_3
        B       method_d
        
method_0
        MOV     r0, #0xe0
        MOV     pc, lr
method_1
        MOV     r0, #0xe1
        MOV     pc, lr
method_2
        MOV     r0, #0xe2
        MOV     pc, lr
method_3
        MOV     r0, #0xe3
        MOV     pc, lr
method_4
        MOV     r0, #0xe4
        MOV     pc, lr
method_5
        MOV     r0, #0xe5
        MOV     pc, lr
method_6
        MOV     r0, #0xe6
        MOV     pc, lr
method_7
        MOV     r0, #0xe7
        MOV     pc, lr
method_d
        MOV     r0, #0xed
        MOV     pc, lr

        END
