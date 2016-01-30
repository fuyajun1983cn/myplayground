;/*
; *  ____________________________________________________________________
; * 
; *  Copyright (c) 2004, Andrew N. Sloss, Chris Wright and Dominic Symes
; *  All rights reserved.
; *  ____________________________________________________________________
; * 
; *  NON-COMMERCIAL USE License
; *  
; *  Redistribution and use in source and binary forms, with or without 
; *  modification, are permitted provided that the following conditions 
; *  are met: 
; *  
; *  1. For NON-COMMERCIAL USE only.
; * 
; *  2. Redistributions of source code must retain the above copyright 
; *     notice, this list of conditions and the following disclaimer. 
; * 
; *  3. Redistributions in binary form must reproduce the above 
; *     copyright notice, this list of conditions and the following 
; *     disclaimer in the documentation and/or other materials provided 
; *     with the distribution. 
; * 
; *  4. All advertising materials mentioning features or use of this 
; *     software must display the following acknowledgement:
; * 
; *     This product includes software developed by Andrew N. Sloss,
; *     Chris Wright and Dominic Symes. 
; * 
; *   THIS SOFTWARE IS PROVIDED BY THE CONTRIBUTORS ``AS IS'' AND ANY 
; *   EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
; *   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
; *   PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE CONTRIBUTORS BE 
; *   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, 
; *   OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
; *   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
; *   OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
; *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR 
; *   TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT 
; *   OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
; *   OF SUCH DAMAGE. 
; * 
; *  If you have questions about this license or would like a different
; *  license please email :
; * 
; *  andrew@sloss.net
; * 
; * 
; */

;/***********************************************************************
; *
; *  Module       : pdih9_13.s
; *  Descriptions : Prioritized Direct Interrupt Handler
; *  Example      : 9.13
; *  OS           : generic
; *  Platform     : generic
; *  History      :
; *
; *  31th December 2003
; *  - added header
; *
; ***********************************************************************/

     EXPORT prioritizedDirectInterruptHandler

I_Bit          EQU 0x80

PRIORITY_0     EQU 2	                ; Comms Rx
PRIORITY_1     EQU 1	                ; Comms Tx
PRIORITY_2     EQU 0	                ; Timer 1
PRIORITY_3     EQU 3	                ; Timer 2

BINARY_0       EQU 1<<PRIORITY_0         ; 1<<2 0x00000004
BINARY_1       EQU 1<<PRIORITY_1         ; 1<<1 0x00000002
BINARY_2       EQU 1<<PRIORITY_2         ; 1<<0 0x00000001
BINARY_3       EQU 1<<PRIORITY_3         ; 1<<3 0x00000008

MASK_3         EQU BINARY_3
MASK_2         EQU MASK_3+BINARY_2
MASK_1         EQU MASK_2+BINARY_1
MASK_0         EQU MASK_1+BINARY_0 

ic_Base        EQU 0x80000000
IRQStatus      EQU 0x0
IRQRawStatus   EQU 0x4
IRQEnable      EQU 0x8
IRQEnableSet   EQU 0x8
IRQEnableClear EQU 0xc

bit_timer1    EQU 0
bit_commtx    EQU 1
bit_commrx    EQU 2
bit_timer2    EQU 3

     AREA pdih,CODE,readonly

prioritizedDirectInterruptHandler ; instruction	 comment
     SUB     r14, r14, #4               ; r14_irq-=4
     STMFD   r13!, {r14}                ; save r14_irq
     MRS     r14, SPSR                  ; copy spsr_irq
     STMFD   r13!,{r10,r11,r12,r14}     ; save context
     LDR     r14, =ic_Base              ; int crtl addr
     LDR     r10, [r14, #IRQStatus]     ; load IRQ status
     ADR     r12, isr_table             ; obtain ISR table addr
     TST     r10, #BINARY_0             ; if CommRx
     LDRNE   pc, [r12,#PRIORITY_0<<2]   ;   then jump CommRx ISR
     TST     r10, #BINARY_1             ; if CommTx
     LDRNE   pc, [r12,#PRIORITY_1<<2]   ;   then jump CommTx ISR 
     TST     r10, #BINARY_2             ; if Timer1
     LDRNE   pc, [r12,#PRIORITY_2<<2]   ;   then jump Timer1 ISR
     TST     r10, #BINARY_3             ; if Timer2
     LDRNE   pc, [r12,#PRIORITY_3<<2]   ;   then jump Timer2 ISR
     B       service_none               ; capture spurious ints
     
isr_table
     DCD     service_timer1             ; timer1 ISR
     DCD     service_commtx             ; commtx ISR
     DCD     service_commrx             ; commrx ISR
     DCD     service_timer2             ; timer2 ISR

priority_masks
     DCD     MASK_2                     ; priority mask 2
     DCD     MASK_1                     ; priority mask 1
     DCD     MASK_0                     ; priority mask 0
     DCD     MASK_3                     ; priority mask 3

service_timer1	
     MOV     r11, #bit_timer1           ; copy bit_timer1				
     LDR     r14, =ic_Base              ; int ctrl addr 
     LDR     r12, [r14,#IRQEnable]      ; IRQ enable register
     ADR     r10, priority_masks        ; obtain priority addr
     LDR     r10, [r10,r11,LSL#2]       ; load priority mask 
     AND     r12, r12, r10              ; AND enable reg
     STR     r12, [r14,#IRQEnableClear] ; clear ints
     MRS     r14, CPSR                  ; copy CPSR
     BIC     r14, r14, #I_Bit           ; clear I-bit	
     MSR     CPSR_c, r14                ; enable IRQ 

    ; <insert code>
    
     LDMFD   r13!,{r10,r11,r12,r14}
     MSR     SPSR_cf, r14
     LDMFD   r13!, {pc}^

service_timer2
; <insert routine here>

service_commrx
; <insert routine here>

service_commtx
; <insert routine here>
     
service_none
     B       service_none
	
     END