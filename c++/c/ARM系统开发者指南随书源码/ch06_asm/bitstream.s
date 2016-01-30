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
;// Section 6.7: Bit Manipulation

        AREA    ch06_7, CODE, READONLY
        
        EXPORT  bitstream_write_test
        EXPORT  bitstream_read_test

;// Example 6.24

;// register needed for the test harness
codes         RN 1  ; pointer to codes to insert in the bitstream
code_lens     RN 2  ; length of codes to insert in the bitstream

;// bitstream pack code
        
bitstream     RN 0  ; current byte address in the output bitstream
code          RN 4  ; current code
codebits      RN 5  ; length in bits of current code
bitbuffer     RN 6  ; 32-bit output big-endian bit buffer
bitsfree      RN 7  ; number of bits free in the bit buffer
tmp           RN 8  ; scratch register
mask          RN 12 ; endian reversal mask 0xFFFF00FF

bitstream_write_start
        MOV     bitbuffer, #0
        MOV     bitsfree, #32
align_loop
        TST     bitstream, #3
        LDRNEB  code, [bitstream, #-1]!
        SUBNE   bitsfree, bitsfree, #8
        ORRNE   bitbuffer, code, bitbuffer, ROR #8
        BNE     align_loop
        MOV     bitbuffer, bitbuffer, ROR #8
        MOV     pc, lr
        
bitstream_write_code
        SUBS    bitsfree, bitsfree, codebits
        BLE     full_buffer
        ORR     bitbuffer, bitbuffer, code, LSL bitsfree
        MOV     pc, lr
full_buffer
        RSB     bitsfree, bitsfree, #0
        ORR     bitbuffer, bitbuffer, code, LSR bitsfree
        IF {ENDIAN}="little"
          ; byte reverse the bit buffer prior to storing
          EOR   tmp, bitbuffer, bitbuffer, ROR #16
          AND   tmp, mask, tmp, LSR #8
          EOR   bitbuffer, tmp, bitbuffer, ROR #8
        ENDIF
        STR     bitbuffer, [bitstream], #4
        RSB     bitsfree, bitsfree, #32
        MOV     bitbuffer, code, LSL bitsfree
        MOV     pc, lr
        
bitstream_write_flush
        RSBS    bitsfree, bitsfree, #32
flush_loop
        MOVGT   bitbuffer, bitbuffer, ROR #24
        STRGTB  bitbuffer, [bitstream], #1
        SUBGTS  bitsfree, bitsfree, #8
        BGT     flush_loop
        MOV     pc, lr
        
        
        ; char *bitstream_write_test(char *bitstream, int *codes, char *code_lens)
bitstream_write_test
        STMFD   sp!, {r4-r11, lr}
        MVN     mask, #0x0000FF00
        BL      bitstream_write_start
write_next_code
        LDR     code, [codes], #4
        LDRB    codebits, [code_lens], #1
        BL      bitstream_write_code
        CMP     codebits, #N
        BLE     write_next_code
        BL      bitstream_write_flush
        LDMFD   sp!, {r4-r11, pc}

;// Example 6.25
        
;// registers needed for the test harness

codes         RN 1  ; pointer to codes read from the bitstream

;// bitstream unpack example        
        
bitstream     RN 0  ; current byte address in the input bitstream
look_code     RN 2  ; lookup table to convert next N-bits to a code
look_codebits RN 3  ; lookup table to convert next N-bits to a code length
code          RN 4  ; code read
codebits      RN 5  ; length of code read
bitbuffer     RN 6  ; 32-bit input buffer (big endian)
bitsleft      RN 7  ; number of valid bits in the buffer - N
tmp           RN 8  ; scratch
tmp2          RN 9  ; scratch
mask          RN 12 ; N-bit extraction mask (1<<N)-1
        
N             EQU 8 ; use a lookup table on 8 bits (N must be <= 9)
        

bitstream_read_start
        MOV     bitsleft, #32
read_fill_loop
        LDRB    tmp, [bitstream], #1
        ORR     bitbuffer, tmp, bitbuffer, LSL#8
        SUBS    bitsleft, bitsleft, #8
        BGT     read_fill_loop
        MOV     bitsleft, #(32-N)
        MOV     mask, #(1<<N)-1
        MOV     pc, lr

bitstream_read_code
        LDRB    codebits, [look_codebits, bitbuffer, LSR#(32-N)]
        AND     code, mask, bitbuffer, LSR#(32-N)
        LDR     code, [look_code, code, LSL#2]
        SUBS    bitsleft, bitsleft, codebits
        BMI     empty_buffer_or_long_code
        MOV     bitbuffer, bitbuffer, LSL codebits
        MOV     pc, lr
empty_buffer_or_long_code
        TEQ     codebits, #0xFF
        BEQ     long_code
        ; empty buffer - fill up with 3 bytes
        ; as N <= 9, we can fill 3 bytes without overflow
        LDRB    tmp, [bitstream], #1
        LDRB    tmp2, [bitstream], #1
        MOV     bitbuffer, bitbuffer, LSL codebits
        LDRB    codebits, [bitstream], #1
        ORR     tmp, tmp2, tmp, LSL#8
        RSB     bitsleft, bitsleft, #(8-N)
        ORR     tmp, codebits, tmp, LSL#8
        ORR     bitbuffer, bitbuffer, tmp, LSL bitsleft
        RSB     bitsleft, bitsleft, #(32-N)
        MOV     pc, lr
        
long_code
        ; handle the long code case depending on the application
        ; here we just return a code of -1
        MOV     code, #-1
        MOV     pc, lr
        
        ; int *bitstream_read_test(char *bitstream, int *codes,
        ;                          int *look_code, char *look_codebits)
bitstream_read_test
        STMFD   sp!, {r4-r11, lr}
        BL      bitstream_read_start
read_next_code        
        BL      bitstream_read_code
        CMP     code, #-1
        STRNE   code, [codes], #4
        BNE     read_next_code
        MOV     r0, codes
        LDMFD   sp!, {r4-r11, pc}
        
        END
