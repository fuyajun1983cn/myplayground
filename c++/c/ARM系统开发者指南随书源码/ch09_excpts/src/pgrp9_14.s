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
; *  Module       : pgrp9_14.s
; *  Descriptions : Prioritized Grouped Interrupt Handler
; *  Example      : 9.14
; *  OS           : generic
; *  Platform     : generic
; *  History      :
; *
; *  31th December 2003
; *  - added header
; *
; ***********************************************************************/

     EXPORT prioritizedGroupedInterruptHandler

I_Bit		EQU 0x80

PRIORITY_0      EQU 2                   ; Comms Rx
PRIORITY_1      EQU 1                   ; Comms Tx
PRIORITY_2      EQU 0                   ; Timer 1
PRIORITY_3      EQU 3                   ; Timer 2

BINARY_0        EQU 1<<PRIORITY_0       ; 1<<2 0x00000004
BINARY_1        EQU 1<<PRIORITY_1       ; 1<<1 0x00000002
BINARY_2        EQU 1<<PRIORITY_2       ; 1<<0 0x00000001
BINARY_3        EQU 1<<PRIORITY_3       ; 1<<3 0x00000008

MASK_3          EQU BINARY_3
MASK_2          EQU MASK_3+BINARY_2
MASK_1          EQU MASK_2+BINARY_1
MASK_0          EQU MASK_1+BINARY_0 

ic_Base         EQU 0x80000000
IRQStatus       EQU 0x0
IRQRawStatus    EQU 0x4
IRQEnable       EQU 0x8
IRQEnableSet    EQU 0x8
IRQEnableClear  EQU 0xc

bit_timer0      EQU 0
bit_commtx      EQU 1
bit_commrx      EQU 2
bit_timer1      EQU 3

GROUP_0         EQU BINARY_0|BINARY_3 
GROUP_1         EQU BINARY_1|BINARY_2 

GMASK_1         EQU GROUP_1
GMASK_0         EQU GMASK_1+GROUP_0

MASK_TIMER1     EQU GMASK_0
MASK_COMMTX     EQU GMASK_1
MASK_COMMRX     EQU GMASK_1
MASK_TIMER2     EQU GMASK_0
   
     AREA pgrp,CODE,readonly

prioritizedGroupedInterruptHandler
     SUB     r14, r14,#4                ; r14_irq-=4
     STMFD   r13!, {r14}                 ; save r14_irq
     MRS     r14, SPSR                  ; copy spsr_irq
     STMFD   r13!, {r10,r11,r12,r14}    ; save context
     LDR     r14, =ic_Base              ; int ctrl addr
     LDR     r10, [r14, #IRQStatus]     ; load IRQ status
     ANDS    r11, r10, #GROUP_0         ; belong to GROUP_0
     ANDEQS  r11, r10, #GROUP_1         ; belong to GROUP_1
     AND     r10, r11, #0xf             ; Mask off top 24-bit 
     ADR     r11, lowest_significant_bit ; load LSB addr
     LDRB    r11, [r11, r10]            ; load byte
     B       disable_lower_priority     ; jump to routine

lowest_significant_bit
;   	0    1 2 3 4 5 6 7 8 9 a b c d e f
     DCB     0xff,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0
		
disable_lower_priority
     CMP     r11, #0xff                 ; if unknown
     BEQ     unknown_condition          ;   then jump
     LDR     r12, [r14, #IRQEnable]     ; load IRQ enable reg
     ADR     r10, priority_mask         ; load priority addr
     LDR     r10, [r10, r11, LSL #2]    ; mem32[r10+r11<<2]
     AND     r12, r12, r10              ; AND enable reg
     STR     r12, [r14,#IRQEnableClear] ; clear new ints
     MRS     r14, CPSR                  ; copy CPSR
     BIC     r14, r14, #I_Bit           ; clear I-bit
     MSR     CPSR_c, r14                ; enable IRQ ints
     LDR     pc, [pc, r11, LSL #2]      ; jump to an ISR
     NOP
     DCD     service_timer1             ; timer0 ISR
     DCD     service_commtx             ; commtx ISR
     DCD     service_commrx             ; commrx ISR
     DCD     service_timer2             ; timer1 ISR

priority_mask
     DCD     MASK_TIMER1                ; mask GROUP 0 
     DCD     MASK_COMMTX                ; mask GROUP 1
     DCD     MASK_COMMRX                ; mask GROUP 1
     DCD     MASK_TIMER2                ; mask GROUP 0

		
service_commrx
     ; <insert code>
service_commtx
     ; <insert code>
service_timer2
     ; <insert code>
service_timer1

     ; <insert code>

     LDMFD   r13!,{r10,r11,r12,r14}
     MSR     SPSR_cf, r14
     LDMFD   r13!, {pc}^
     
unknown_condition
     B       unknown_condition

     END