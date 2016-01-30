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
; *  Module       : psih9_11.s
; *  Descriptions : Prioritized Simple Interrupt Handler
; *  Example      : 9.11
; *  OS           : generic
; *  Platform     : generic
; *  History      :
; *
; *  31th December 2003
; *  - added header
; *
; ***********************************************************************/

     EXPORT prioritizedSimpleInterruptHandler

I_Bit       EQU 0x80

PRIORITY_0     EQU 2                    ; Comms Rx
PRIORITY_1     EQU 1                    ; Comms Tx
PRIORITY_2     EQU 0                    ; Timer 1
PRIORITY_3     EQU 3                    ; Timer 2

BINARY_0       EQU 1<<PRIORITY_0        ; 1<<2 0x00000004
BINARY_1       EQU 1<<PRIORITY_1        ; 1<<1 0x00000002
BINARY_2       EQU 1<<PRIORITY_2        ; 1<<0 0x00000001
BINARY_3       EQU 1<<PRIORITY_3        ; 1<<3 0x00000008

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

     AREA   psih,CODE,readonly

prioritizedSimpleInterruptHandler  ; instruction    state : comment
     SUB     r14, r14, #4               ; 2 : r14_irq -= 4
     STMFD   r13!, {r14}                ; 2 : save r14_irq
     MRS     r14, SPSR                  ; 2 : copy spsr_irq
     STMFD   r13!, {r10,r11,r12,r14}    ; 2 : save context
     LDR     r14, =ic_Base              ; 3 : int crtl addr
     MOV     r11, #PRIORITY_3           ; 3 : default priority
     LDR     r10, [r14, #IRQStatus]     ; 3 : load IRQ status
     TST     r10, #BINARY_3             ; 4 : if Timer 2
     MOVNE   r11, #PRIORITY_3           ; 4 :   then P3(lo)
     TST     r10, #BINARY_2             ; 4 : if Timer 1
     MOVNE   r11, #PRIORITY_2           ; 4 :   then P2
     TST     r10, #BINARY_1             ; 4 : if Comm Tx
     MOVNE   r11, #PRIORITY_1           ; 4 :   then P1
     TST     r10, #BINARY_0             ; 4 : if Comm Rx
     MOVNE   r11, #PRIORITY_0           ; 4 :  then P0(hi) 
     LDR     r12, [r14,#IRQEnable]      ; 4 : IRQEnable reg
     ADR     r10, priority_masks        ; 4 : mask address
     LDR     r10, [r10,r11,LSL #2]      ; 4 : priority value
     AND     r12, r12,r10               ; 4 : AND enable reg
     STR     r12, [r14,#IRQEnableClear] ; 4 : clear ints 
     MRS     r14, CPSR                  ; 4 : copy CPSR
     BIC     r14, r14, #I_Bit           ; 4 : clear I-bit
     MSR     CPSR_c, r14                ; 4 : enable IRQ ints
     LDR     pc, [pc, r11, LSL#2]       ; 5 : jump to an ISR
     NOP                                ;
     DCD     service_timer1             ; timer0 ISR
     DCD     service_commtx             ; commtx ISR
     DCD     service_commrx             ; commrx ISR
     DCD     service_timer2             ; timer1 ISR

priority_masks
     DCD     MASK_2                     ; priority mask 2 
     DCD     MASK_1                     ; priority mask 1
     DCD     MASK_0                     ; priority mask 0
     DCD     MASK_3                     ; priority mask 3
	

service_commrx
     ; <insert code>
service_commtx
     ; <insert code>
service_timer2
     ; <insert code>
service_timer1	
     STMFD   r13!, {r0-r9}              ; 6 : save context
     ; <insert code>
     LDMFD   r13!, {r0-r10}             ; 7 : restore context
     MRS     r11, CPSR                  ; 8 : copy cpsr
     ORR     r11, r11, #I_Bit           ; 8 : set I-bit
     MSR     CPSR_c, r11                ; 8 : disable IRQ
     LDR     r11, =ic_Base              ; 8 : int ctrl addr
     STR     r12, [r11, #IRQEnableSet]  ; 8 : enable ints
     LDMFD   r13!, {r11, r12, r14}      ; 9 : restore context
     MSR     SPSR_cxsf, r14             ; 9 : set spsr
     LDMFD   r13!, {pc}^                ; 9 : return

     END