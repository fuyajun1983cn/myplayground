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
; *  Module       : rih9_10.s
; *  Descriptions : Re-entrant Interrupt Handler
; *  Example      : 9.10
; *  OS           : generic
; *  Platform     : generic
; *  History      :
; *
; *  31th December 2003
; *  - added header
; *
; ***********************************************************************/

     EXPORT reentrantInterruptHandler


IRQ_R0          EQU 0
IRQ_SPSR        EQU 4
IRQ_R14         EQU 8

Maskmd          EQU 0x1f                ; Mask mode
SVC32md         EQU 0x13                ; SVC mode 
I_Bit           EQU 0x80                ; IRQ bit

ic_Base         EQU 0x80000000
IRQStatus       EQU 0x0
IRQRawStatus    EQU 0x4
IRQEnable       EQU 0x8
IRQEnableSet    EQU 0x8
IRQEnableClear  EQU 0xc

     AREA rih9_10,CODE,readonly

reentrantInterruptHandler  ; instruction      state : comment
     SUB     r14, r14, #4               ; 2 : r14_irq-=4
     STR     r14, [r13, #IRQ_R14]       ; 2 : save r14_irq
     MRS     r14, SPSR                  ; 2 : copy SPSR 
     STR     r14, [r13, #IRQ_SPSR]      ; 2 : save SPSR
     STR     r0, [r13, #IRQ_R0]         ; 2 : save r0
     MOV     r0, r13                    ; 2 : copy r13_irq
     MRS     r14, CPSR                  ; 3 : copy CPSR
     BIC     r14, r14, #Maskmd          ; 3 :
     ORR     r14, r14, #SVC32md         ; 3 :
     MSR     CPSR_c, r14                ; 3 : enter SVC mode
     STR     r14, [r13, #-8]!           ; 4 : save r14
     LDR     r14, [r0, #IRQ_R14]        ; 4 : r14_svc=r14_irq 
     STR     r14, [r13, #4]             ; 4 : save r14_irq
     LDR     r14, [r0, #IRQ_SPSR]       ; 4 : r14_svc=SPSR_irq
     LDR     r0, [r0, #IRQ_R0]          ; 4 : restore r0
     STMDB   r13!, {r0-r3,r8,r12,r14}   ; 4 : save context 
     LDR     r14, =ic_Base              ; 5 : int crtl address
     LDR     r8, [r14, #IRQStatus]      ; 5 : get int status
     STR     r8, [r14, #IRQEnableClear] ; 5 : clear interrupts
     MRS     r14, CPSR                  ; 6 : r14_svc=CPSR
     BIC     r14, r14, #I_Bit           ; 6 : 
     MSR     CPSR_c, r14                ; 6 : clear IRQ int
     BL      process_Interrupt          ; 7 : call ISR
     LDR     r14, =ic_Base              ; 9 : int ctrl address
     STR     r8, [r14, #IRQEnableSet]   ; 9 : enable ints 
     BL      read_RescheduleFlag        ; 9 : more processing
     CMP     r0, #0                     ; 8 : if processing
     LDMNEIA r13!, {r0-r3,r8,r12,r14}   ; 8 :  then load context
     MSRNE   SPSR_cxsf, r14             ; 8 :       update SPSR
     LDMNEIA r13!, {r14, pc}^           ; 8 :       return    
     LDMIA   r13!, {r0-r3, r8}          ; 10 : else load reg 
     STMDB   r13!, {r0-r11}             ; 10 :      save context
     BL      continue_Servicing         ; 11 : continue service
     LDMIA   r13!, {r0-r12, r14}        ; 12 : restore context 
     MSR     SPSR_cxsf, r14             ; 12 : update SPSR 
     LDMIA   r13!, {r14, pc}^           ; 12 : return

read_RescheduleFlag
     ; <implement your own reschedule flag code here>
     MOV     r0,#0                      ; more processing 
     MOV     pc,r14                     ; return

process_Interrupt
     ; <insert code>
     MOV     pc,r14                     ; return

continue_Servicing
     ; <insert code>
     MOV     pc,r14                     ; return

     END
