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
; *  Module       : vic.s
; *  Descriptions : Vector Interrupt Service Routine
; *  Example      : 9.10
; *  OS           : generic
; *  Platform     : generic
; *  History      :
; *
; *  31th December 2003
; *  - added header
; *
; ***********************************************************************/

     EXPORT vectorServiceRoutine

INTON          EQU 0x0000               ; enable interrupts
SYS32md        EQU 0x1f                 ; ***??? system mode 
IRQ32md        EQU 0x12                 ; system mode
I_Bit          EQU 0x80
VICBaseAddr    EQU 0xfffff000           ; base address of VIC controller
VICVectorAddr  EQU VICBaseAddr+0x30     ; isr address of interupt 

Maskmd		EQU 0x1f                ; processor mode mask
SVC32md		EQU 0x13                ; SVC mode

     AREA vic,CODE,readonly

vectorServiceRoutine
     SUB     r14,r14,#4                 ; r14-=4
     STMFD   r13!, {r0-r3,r12,r14}      ; save context
     MRS     r12, spsr                  ; copy spsr
     STMFD   r13!,{r12}                 ; save spsr
     MSR     cpsr_c, #INTON|SYS32md     ; cpsr_c=ift_system
     ; <insert code>
     MSR     cpsr_c, #I_Bit|IRQ32md     ; cpsr_c=Ift_irq
     LDMFD   r13!, {r12}                ; restore r12 (spsr_irq)
     MSR     spsr_cxsf, r12             ; restore spsr
     LDR     r1,=VICVectorAddr          ; load VectorAddress
     STR     r0, [r1]                   ; inform VIC interrupt serviced
     LDMFD   r13!, {r0-r3,r12,pc}^      ; return
     END