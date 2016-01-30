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
;// Chapter 5
;// ADS1.1 compiler ouput - annotated

        AREA    ch04, CODE, READONLY
        
        EXPORT  checksum_v1_s
        EXPORT  checksum_v2_s
        EXPORT  checksum_v3_s
        EXPORT  checksum_v4_s
        EXPORT  checksum_v5_s
        EXPORT  checksum_v6_s
        EXPORT  checksum_v7_s
        EXPORT  checksum_v8_s
        EXPORT  checksum_v9_s
        EXPORT  checksum_v10_s
        EXPORT  queue_bytes_v1_s
        EXPORT  queue_bytes_v2_s
        EXPORT  uint_to_hex_s
        EXPORT  getxy_v1_s
        EXPORT  getxy_v2_s
        EXPORT  scale_s
        EXPORT  sat_correlate_v1_s
        EXPORT  sat_correlate_v2_s
        EXPORT  sat_correlate_v3_s
        EXPORT  str_tolower_s
        
        IMPORT  add_v3
        IMPORT  clip1
        IMPORT  dostageA
        IMPORT  dostageB
        IMPORT  dostageC
        IMPORT  get_next_packet
        IMPORT  __rt_udiv
        
;// Section 5.2 - variable types

checksum_v1_s
        MOV     r2,r0             ; r2 = data
        MOV     r0,#0             ; sum = 0
        MOV     r1,#0             ; i = 0
checksum_v1_loop
        LDR     r3,[r2,r1,LSL #2] ; r3 = data[i]
        ADD     r1,r1,#1          ; r1 = i+1
        AND     r1,r1,#0xff       ; i = (char)r1
        CMP     r1,#0x40          ; compare i, 64
        ADD     r0,r3,r0          ; sum += r3
        BCC     checksum_v1_loop  ; if (i<64) loop
        MOV     pc,r14            ; return sum
        
checksum_v2_s
        MOV     r2,r0             ; r2 = data
        MOV     r0,#0             ; sum = 0
        MOV     r1,#0             ; i = 0
checksum_v2_loop
        LDR     r3,[r2,r1,LSL #2] ; r3 = data[i]
        ADD     r1,r1,#1          ; r1++
        CMP     r1,#0x40          ; compare i, 64
        ADD     r0,r3,r0          ; sum += r3
        BCC     checksum_v2_loop  ; if (i<64) goto loop
        MOV     pc,r14            ; return sum
        
checksum_v3_s
        MOV     r2,r0             ; r2 = data
        MOV     r0,#0             ; sum = 0
        MOV     r1,#0             ; i = 0
checksum_v3_loop
        ADD     r3,r2,r1,LSL #1   ; r3 = &data[i]
        LDRH    r3,[r3,#0]        ; r3 = data[i]
        ADD     r1,r1,#1          ; i++
        CMP     r1,#0x40          ; compare i, 64
        ADD     r0,r3,r0          ; r0 = sum + r3
        MOV     r0,r0,LSL #16
        MOV     r0,r0,ASR #16     ; sum = (short)r0
        BCC     checksum_v3_loop  ; if (i<64) goto loop
        MOV     pc,r14            ; return sum
        
checksum_v4_s
        MOV     r2,#0             ; sum = 0
        MOV     r1,#0             ; i = 0
checksum_v4_loop
        LDRSH   r3,[r0],#2        ; r3 = *(data++)
        ADD     r1,r1,#1          ; i++
        CMP     r1,#0x40          ; compare i, 64
        ADD     r2,r3,r2          ; sum += r3
        BCC     checksum_v4_loop  ; if (sum<64) goto loop
        MOV     r0,r2,LSL #16
        MOV     r0,r0,ASR #16     ; r0 = (short)sum
        MOV     pc,r14            ; return r0
        
add_v1_s
        ADD     r0,r0,r1,ASR #1   ; r0 = (int)a + ((int)b>>1)
        MOV     r0,r0,LSL #16
        MOV     r0,r0,ASR #16     ; r0 = (short)r0
        MOV     pc,r14            ; return r0

add_v1_gcc        
        MOV     r0, r0, LSL #16
        MOV     r1, r1, LSL #16
        MOV     r1, r1, ASR #17   ; r1 = (int)a
        ADD     r1, r1, r0, ASR #16 ; r1 += (int)b
        MOV     r1, r1, LSL #16
        MOV     r0, r1, ASR #16   ; r0 = (short)r1
        MOV     pc, lr            ; return r0

add_v2_s
        MOV     r1,r1,LSL #16
        MOV     r0,r0,LSL #16
        MOV     r0,r0,ASR #16
        MOV     r1,r1,ASR #16
        B       add_v3
        
average_v1_s
        ADD     r0,r0,r1          ; r0 = a+b
        ADD     r0,r0,r0,LSR #31  ; if (r0<0) r0++
        MOV     r0,r0,ASR #1      ; r0 = r0>>1
        MOV     pc,r14            ; return r0
        
average_v2_s
        ADD     r0,r0,r1
        MOV     r0,r0,LSR #1
        MOV     pc,r14
        
;// Section 5.3 - looping
        
checksum_v5_s
        MOV     r2,r0             ; r2 = data
        MOV     r0,#0             ; sum = 0
        MOV     r1,#0             ; i = 0
checksum_v5_loop
        LDR     r3,[r2],#4        ; r3 = *(data++)
        ADD     r1,r1,#1          ; i++
        CMP     r1,#0x40          ; compare i, 64
        ADD     r0,r3,r0          ; sum += r3
        BCC     checksum_v5_loop  ; if (i<64) goto loop
        MOV     pc,r14            ; return sum
        
checksum_v6_s
        MOV     r2,r0             ; r2 = data
        MOV     r0,#0             ; sum = 0
        MOV     r1,#0x40          ; i = 64
checksum_v6_loop
        LDR     r3,[r2],#4        ; r3 = *(data++)
        SUBS    r1,r1,#1          ; i-- and set flags
        ADD     r0,r3,r0          ; sum += r3
        BNE     checksum_v6_loop  ; if (i!=0) goto loop
        MOV     pc,r14            ; return sum
        
checksum_v7_s
        MOV     r2,#0             ; sum = 0
        CMP     r1,#0             ; compare N, 0
        BEQ     checksum_v7_end   ; if (N==0) goto end
checksum_v7_loop
        LDR     r3,[r0],#4        ; r3 = *(data++)
        SUBS    r1,r1,#1          ; N-- and set flags
        ADD     r2,r3,r2          ; sum += r3
        BNE     checksum_v7_loop  ; if (N!=0) goto loop
checksum_v7_end
        MOV     r0,r2             ; r0 = sum
        MOV     pc,r14            ; return r0
        
checksum_v8_s
        MOV     r2,#0             ; sum = 0
checksum_v8_loop
        LDR     r3,[r0],#4        ; r3 = *(data++)
        SUBS    r1,r1,#1          ; N-- and set flags
        ADD     r2,r3,r2          ; sum += r3
        BNE     checksum_v8_loop  ; if (N!=0) goto loop
        MOV     r0,r2             ; r0 = sum
        MOV     pc,r14            ; return r0
        
checksum_v9_s
        MOV     r2,#0             ; sum = 0
checksum_v9_loop
        LDR     r3,[r0],#4        ; r3 = *(data++)
        SUBS    r1,r1,#4          ; N-=4 & set flags
        ADD     r2,r3,r2          ; sum += r3
        LDR     r3,[r0],#4        ; r3 = *(data++)
        ADD     r2,r3,r2          ; sum += r3
        LDR     r3,[r0],#4        ; r3 = *(data++)
        ADD     r2,r3,r2          ; sum += r3
        LDR     r3,[r0],#4        ; r3 = *(data++)
        ADD     r2,r3,r2          ; sum += r3
        BNE     checksum_v9_loop  ; if (N!=0) goto loop
        MOV     r0,r2             ; r0 = sum
        MOV     pc,r14            ; return r0
        
checksum_v10_s
        MOV     r3,#0
        MOVS    r2,r1,LSR #2
        BEQ     {pc} + 0x2c  ; 0x22c
        LDR     r12,[r0],#4
        SUBS    r2,r2,#1
        ADD     r3,r12,r3
        LDR     r12,[r0],#4
        ADD     r3,r12,r3
        LDR     r12,[r0],#4
        ADD     r3,r12,r3
        LDR     r12,[r0],#4
        ADD     r3,r12,r3
        BNE     {pc} - 0x24  ; 0x204
        ANDS    r1,r1,#3
        BEQ     {pc} + 0x14  ; 0x244
        LDR     r2,[r0],#4
        SUBS    r1,r1,#1
        ADD     r3,r2,r3
        BNE     {pc} - 0xc  ; 0x234
        MOV     r0,r3
        MOV     pc,r14
        
;// Section 5.4 - Register allocation
        
;// Section 5.5 - function calls
        
queue_bytes_v1_s
        STR      r14,[r13,#-4]!   ; save lr on the stack
        LDR      r12,[r13,#4]     ; r12 = N
queue_v1_loop
        LDRB     r14,[r3],#1      ; r14 = *(data++)
        STRB     r14,[r2],#1      ; *(Q_ptr++) = r14
        CMP      r2,r1            ; if (Q_ptr == Q_end)
        MOVEQ    r2,r0            ;   { Q_ptr = Q_start; }
        SUBS     r12,r12,#1       ; --N and set flags
        BNE      queue_v1_loop    ; if (N!=0) goto loop
        MOV      r0,r2            ; r0 = Q_ptr
        LDR      pc,[r13],#4      ; return r0
        
queue_bytes_v2_s
        STR      r14,[r13,#-4]!   ; save lr on the stack
        LDR      r3,[r0,#8]       ; r3  = queue->Q_ptr
        LDR      r14,[r0,#4]      ; r14 = queue->Q_end
queue_v2_loop
        LDRB     r12,[r1],#1      ; r12 = *(data++)
        STRB     r12,[r3],#1      ; *(Q_ptr++) = r12
        CMP      r3,r14           ; if (Q_ptr == Q_end)
        LDREQ    r3,[r0,#0]       ;   { Q_ptr = queue->Q_start }
        SUBS     r2,r2,#1         ; --N and set flags
        BNE      queue_v2_loop    ; if (N!=0) goto loop
        STR      r3,[r0,#8]       ; queue->Q_ptr = r3
        LDR      pc,[r13],#4      ; return
        
nybble_to_hex
        CMP     r0,#0xa
        ADDCS   r0,r0,#0x37
        ADDCC   r0,r0,#0x30
        MOV     pc,r14
        
uint_to_hex_s
        MOV     r3,#8             ; i = 8
uint_to_hex_loop
        MOV     r1,r1,ROR #28     ; in = (in<<4)|(in>>28)
        AND     r2,r1,#0xf        ; r2 = in & 15
        CMP     r2,#0xa           ; if (r2>=10)
        ADDCS   r2,r2,#0x37       ;   r2 += 'A'-10
        ADDCC   r2,r2,#0x30       ; else r2 += '0'
        STRB    r2,[r0],#1        ; *(out++) = r2
        SUBS    r3,r3,#1          ; i-- and set flags
        BNE     uint_to_hex_loop  ; if (i!=0) goto loop
        MOV     pc,r14            ; return

;// Section 5.6 - Pointer Aliasing

timers_v1
        LDR     r3,[r0,#0]        ; r3 = *timer1
        LDR     r12,[r2,#0]       ; r12 = *step
        ADD     r3,r3,r12         ; r3 += r12
        STR     r3,[r0,#0]        ; *timer1 = r3
        LDR     r0,[r1,#0]        ; r0 = *timer2
        LDR     r2,[r2,#0]        ; r2 = *step
        ADD     r0,r0,r2          ; r0 += r2
        STR     r0,[r1,#0]        ; *timer2 = t0
        MOV     pc,r14            ; return
        
timers_v2
        LDR     r2,[r1,#0]        ; r2 = timers->timer1
        LDR     r3,[r0,#0]        ; r3 = state->step
        ADD     r2,r2,r3          ; r2 += r3
        STR     r2,[r1,#0]        ; timers->timer1 = r2
        LDR     r2,[r1,#4]        ; r2 = timers->timer2
        LDR     r0,[r0,#0]        ; r0 = state->step
        ADD     r0,r2,r0          ; r0 += r2
        STR     r0,[r1,#4]        ; timers->timer2 = r0
        MOV     pc,r14            ; return
        
checksum_next_packet
        STMFD   r13!,{r4,r14}     ; save r4, lr on the stack
        SUB     r13,r13,#8        ; create two stacked variables
        ADD     r0,r13,#4         ; r0 = &N, N stacked
        MOV     r4,#0             ; sum = 0
        BL      get_next_packet   ; r0 = data
checksum_loop        
        LDR     r1,[r0],#4        ; r1 = *(data++)
        ADD     r4,r1,r4          ; sum += r1
        LDR     r1,[r13,#4]       ; r1 = N (read from stack)
        SUBS    r1,r1,#1          ; r1-- & set flags
        STR     r1,[r13,#4]       ; N = r1 (write to stack)
        BNE     checksum_loop     ; if (N!=0) goto loop
        MOV     r0,r4             ; r0 = sum
        ADD     r13,r13,#8        ; delete stacked variables
        LDMFD   r13!,{r4,pc}      ; return r0
        
ctolower
        LDRB    r1,[r0,#0]        ; r1 = *c
        SUB     r2,r1,#0x41       ; r2 = r1-'A'
        CMP     r2,#0x19          ; if (r2<=25)
        ADDLS   r1,r1,#0x20       ; { r1 += 'a'-'A';
        STRLSB  r1,[r0,#0]        ;   *c = r1; }
        MOV     pc,r14            ; return
        
inc1
        STMFD   r13!,{r4,r14}
        MOV     r4,r1
        LDR     r1,[r1,#0]
        ADD     r0,r1,r0
        BL      clip1
        LDR     r1,[r4,#0]
        ADD     r0,r1,r0
        LDMFD   r13!,{r4,pc}
                
;// Section 5.8 - bitfields
        
dostages_v1
        STMFD   r13!,{r4,r14}     ; stack r4, lr
        MOV     r4,r0             ; move stages to r4
        LDR     r0,[r0,#0]        ; r0 = stages bitfield
        TST     r0,#1             ; if (stages->stageA)
        BLNE    dostageA          ;   { dostageA(); }
        LDR     r0,[r4,#0]        ; r0 = stages bitfield
        MOV     r0,r0,LSL #30     ; shift bit 1 to bit 31
        CMP     r0,#0             ; if (bit31)
        BLLT    dostageB          ;   { dostageB(); }
        LDR     r0,[r4,#0]        ; r0 = stages bitfield
        MOV     r0,r0,LSL #29     ; shift bit 2 to bit 31
        CMP     r0,#0             ; if (!bit31)
        LDMLTFD r13!,{r4,r14}     ;   return
        BLT     dostageC          ; dostageC();
        LDMFD   r13!,{r4,pc}      ; return
        
dostages_v2
        STMFD   r13!,{r4,r14}     ; stack r4, lr
        LDR     r4,[r0,#0]        ; stages = *stages_v2
        TST     r4,#1             ; if (stage & STAGEA)
        BLNE    dostageA          ;   { dostageA(); }
        TST     r4,#2             ; if (stage & STAGEB)
        BLNE    dostageB          ;   { dostageB(); }
        TST     r4,#4             ; if (!(stage & STAGEC))
        LDMNEFD r13!,{r4,r14}     ;   return;
        BNE     dostageC          ; dostageC();
        LDMFD   r13!,{r4,pc}      ; return
        
;// Section 5.10 - Division
        
getxy_v1_s
        STMFD   r13!,{r4-r6,r14}
        MOV     r6,r0
        MOV     r0,r2
        MOV     r5,r2
        MOV     r4,r1
        BL      __rt_udiv
        MUL     r1,r5,r0
        SUB     r1,r4,r1
        STR     r0,[r6,#4]
        STR     r1,[r6,#0]
        LDMFD   r13!,{r4-r6,pc}
        
getxy_v2_s
        STMFD   r13!,{r4,r14}     ; stack r4, lr
        MOV     r4,r0             ; move p to r4
        MOV     r0,r2             ; r0 = bytes_per_line
        BL      __rt_udiv         ; (r0,r1) = (r1/r0, r1%r0)
        STR     r0,[r4,#4]        ; p.y = offset / bytes_per_line
        STR     r1,[r4,#0]        ; p.x = offset % bytes_per_line
        LDMFD   r13!,{r4,pc}      ; return
        
scale_s
        STMFD   r13!,{r3-r9,r14}
        MOV     r7,r1
        MOV     r6,r0
        MOV     r0,r2
        MVN     r1,#0
        MOV     r8,r3
        MOV     r5,r2
        BL      __rt_udiv
        MOV     r9,r0
scale_loop
        LDR     r4,[r7],#4
        MOV     r1,r9
        UMULL   r0,r1,r4,r9
        MOV     r0,r1
        MUL     r1,r0,r5
        SUB     r1,r4,r1
        CMP     r1,r5
        ADC     r0,r0,#0
        STR     r0,[r6],#4
        SUBS    r8,r8,#1
        BNE     scale_loop
        LDMFD   r13!,{r3-r9,pc}
        
readint
        BIC     r3,r0,#3          ; r3 = data & 0xFFFFFFFC
        AND     r0,r0,#3          ; r0 = data & 0x00000003
        MOV     r0,r0,LSL #3      ; r0 = bit offset of data word
        LDMIA   r3,{r3,r12}       ; r3, r12 = 8 bytes read from r3
        MOV     r3,r3,LSR r0      ; These three instructions
        RSB     r0,r0,#0x20       ; shift the 64 bit value r12.r3
        ORR     r0,r3,r12,LSL r0  ; right by r0 bits
        MOV     pc,r14            ; return r0

sat_correlate_v1_s
        STMFD   r13!,{r4,r5,r14}
        MOV     r5,#0x80000000
        MVN     r4,#0x80000000
        MOV     r3,#0
sat_v1_loop
        LDRH    r12,[r0],#2
        LDRH    r14,[r1],#2
        SMULBB  r12,r12,r14
        CMP     r12,#0
        BLT     sat_v1_neg
        MOV     r12,r12,LSL #1
        CMP     r12,#0
        MVNLT   r12,#0x80000000
        ADD     r12,r3,r12
        CMP     r12,r3
        MOVGE   r3,r12
        MOVLT   r3,r4
        B       sat_v1_next
sat_v1_neg
        ADD     r12,r3,r12,LSL #1
        CMP     r12,r3
        MOVLE   r3,r12
        MOVGT   r3,r5
sat_v1_next
        SUBS    r2,r2,#1
        BNE     sat_v1_loop
        MOV     r0,r3
        LDMFD   r13!,{r4,r5,pc}
        
sat_correlate_v2_s
        STMFD   r13!,{r4,r14}
        MOV     r14,#0x80000000
        MOV     r12,#0
sat_v2_loop
        LDRH    r3,[r0],#2
        LDRH    r4,[r1],#2
        SMULBB  r3,r3,r4
        ADDS    r3,r3,r3
        EORVS   r3,r14,r3,ASR #31
        ADDS    r12,r12,r3
        EORVS   r12,r14,r12,ASR #31
        SUBS    r2,r2,#1
        BNE     sat_v2_loop
        MOV     r0,r12
        LDMFD   r13!,{r4,pc}
        
sat_correlate_v3_s
        STR     r14,[r13,#-4]!    ; stack lr
        MOV     r12,#0            ; a = 0
sat_v3_loop
        LDRSH   r3,[r0],#2        ; r3 = *(x++)
        LDRSH   r14,[r1],#2       ; r14 = *(y++)
        SUBS    r2,r2,#1          ; N-- and set flags
        SMULBB  r3,r3,r14         ; r3 = r3 * r14
        QDADD   r12,r12,r3        ; a = sat(a+sat(2*r3))
        BNE     sat_v3_loop       ; if (N!=0) goto loop
        MOV     r0,r12            ; r0 = a
        LDR     pc,[r13],#4       ; return r0
        
flush_Icache
        MOV     r0,#0
        MCR     p15,0x0,r0,c7,c5,0
        MOV     pc,r14
        
;// This is used in Section 6.3
        
str_tolower_s
        LDRB    r2,[r1],#1        ; c = *(in++)
        SUB     r3,r2,#0x41       ; r3 = c - 'A'
        CMP     r3,#0x19          ; if (c <= 'Z'-'A')
        ADDLS   r2,r2,#0x20       ;   c += 'a'-'A'
        STRB    r2,[r0],#1        ; *(out++) = (char)c
        CMP     r2,#0             ; if (c!=0)
        BNE     str_tolower_s     ;   goto str_tolower
        MOV     pc,r14            ; return
        
        END
