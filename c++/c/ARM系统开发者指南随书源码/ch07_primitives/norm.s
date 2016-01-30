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
;// Section 7.2: Signed and unsigned normalisation routines

        AREA    ch07_2, CODE, READONLY

        EXPORT  unorm_arm9e
        EXPORT  snorm_arm9e
        EXPORT  unorm_arm7m
        EXPORT  unorm_arm7m_hash
        EXPORT  ctz_arm9e
        EXPORT  ctz_arm7m

x       RN 0    ; input, output integer
shift   RN 1    ; shift to normalize

        ; __value_in_regs struct { unsigned x; int shift; }
        ;   unorm_arm9e(unsigned x)
unorm_arm9e
        CLZ     shift, x            ; left shift to normalize
        MOV     x, x, LSL shift     ; normalize
        MOV     pc, lr

        ; __value_in_regs struct { signed x; int shift; }
        ;   unorm_arm9e(signed x)
snorm_arm9e                         ; [ s s s 1-s x x ... ]
        EOR     shift, x, x, LSL#1  ; [ 0 0 1  x  x x ... ]
        CLZ     shift, shift        ; left shift to normalize
        MOV     x, x, LSL shift     ; normalize
        MOV     pc, lr

        ; __value_in_regs struct { unsigned x; int shift; }
        ;   unorm_arm7m(unsigned x)
unorm_arm7m
        MOV     shift, #0           ; shift=0;
        CMP     x, #1<<16           ; if (x < (1<<16))
        MOVCC   x, x, LSL#16        ;   { x = x<<16;
        ADDCC   shift, shift, #16   ;     shift+=16; }
        TST     x, #0xFF000000      ; if (x < (1<<24))
        MOVEQ   x, x, LSL#8         ;   { x = x<<8;
        ADDEQ   shift, shift, #8    ;     shift+=8; }
        TST     x, #0xF0000000      ; if (x < (1<<28))
        MOVEQ   x, x, LSL#4         ;   { x = x<<4;
        ADDEQ   shift, shift, #4    ;     shift+=4; }
        TST     x, #0xC0000000      ; if (x < (1<<30))
        MOVEQ   x, x, LSL#2         ;   { x = x<<2;
        ADDEQ   shift, shift, #2    ;     shift+=2; }
        TST     x, #0x80000000      ; if (x < (1<<31))
        ADDEQ   shift, shift, #1    ;   { shift+=1;
        MOVEQS  x, x, LSL#1         ;     x<<=1;
        MOVEQ   shift, #32          ;     if (x==0) shift=32; }
        MOV     pc, lr

table   RN 2    ; address of hash lookup table

        ; __value_in_regs struct { unsigned x; int shift; }
        ;   unorm_arm7m_hash(unsigned x)
unorm_arm7m_hash
        ORR     shift, x, x, LSR#1
        ORR     shift, shift, shift, LSR#2
        ORR     shift, shift, shift, LSR#4
        ORR     shift, shift, shift, LSR#8
        BIC     shift, shift, shift, LSR#16
        RSB     shift, shift, shift, LSL#9      ; *(2^9-1)
        RSB     shift, shift, shift, LSL#11     ; *(2^11-1)
        RSB     shift, shift, shift, LSL#14     ; *(2^14-1)
        ADR     table, unorm_arm7m_hash_table
        LDRB    shift, [table, shift, LSR#26]
        MOV     x, x, LSL shift
        MOV     pc, lr

unorm_arm7m_hash_table
        DCB     0x20, 0x14, 0x13, 0xff, 0xff, 0x12, 0xff, 0x07
        DCB     0x0a, 0x11, 0xff, 0xff, 0x0e, 0xff, 0x06, 0xff
        DCB     0xff, 0x09, 0xff, 0x10, 0xff, 0xff, 0x01, 0x1a
        DCB     0xff, 0x0d, 0xff, 0xff, 0x18, 0x05, 0xff, 0xff
        DCB     0xff, 0x15, 0xff, 0x08, 0x0b, 0xff, 0x0f, 0xff
        DCB     0xff, 0xff, 0xff, 0x02, 0x1b, 0x00, 0x19, 0xff
        DCB     0x16, 0xff, 0x0c, 0xff, 0xff, 0x03, 0x1c, 0xff
        DCB     0x17, 0xff, 0x04, 0x1d, 0xff, 0xff, 0x1e, 0x1f

        ; unsigned ctz_arm9e(unsigned x)
ctz_arm9e
        RSBS    shift, x, #0    ; shift=-x
        AND     shift, shift, x ; isolate trailing 1 of x
        CLZCC   shift, shift    ; number of zeros above last 1
        RSC     r0, shift, #32  ; number of zeros below last 1
        MOV     pc, lr

        ; unsigned ctz_arm7m(unsigned x)
ctz_arm7m
        RSB     shift, x, #0
        AND     shift, shift, x               ; isolate lowest bit
        ADD     shift, shift, shift, LSL#4    ; *(2^4+1)
        ADD     shift, shift, shift, LSL#6    ; *(2^6+1)
        RSB     shift, shift, shift, LSL#16   ; *(2^16-1)
        ADR     table, ctz_arm7m_hash_table
        LDRB    r0, [table, shift, LSR#26]
        MOV     pc, lr

ctz_arm7m_hash_table
        DCB     0x20, 0x00, 0x01, 0x0c, 0x02, 0x06, 0xff, 0x0d
        DCB     0x03, 0xff, 0x07, 0xff, 0xff, 0xff, 0xff, 0x0e
        DCB     0x0a, 0x04, 0xff, 0xff, 0x08, 0xff, 0xff, 0x19
        DCB     0xff, 0xff, 0xff, 0xff, 0xff, 0x15, 0x1b, 0x0f
        DCB     0x1f, 0x0b, 0x05, 0xff, 0xff, 0xff, 0xff, 0xff
        DCB     0x09, 0xff, 0xff, 0x18, 0xff, 0xff, 0x14, 0x1a
        DCB     0x1e, 0xff, 0xff, 0xff, 0xff, 0x17, 0xff, 0x13
        DCB     0x1d, 0xff, 0x16, 0x12, 0x1c, 0x11, 0x10

        END
