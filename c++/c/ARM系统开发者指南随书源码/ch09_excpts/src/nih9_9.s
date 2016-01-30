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
; *  Module       : nih9_9.s
; *  Descriptions : Nested Interrupt Handler
; *  Example      : 9.9
; *  OS           : generic
; *  Platform     : generic
; *  History      :
; *
; *  31th December 2003
; *  - added header
; *
; ***********************************************************************/

     EXPORT nestedInterruptHandler

Maskmd     EQU 0x1f                     ; processor mode mask
SVC32md    EQU 0x13                     ; SVC mode
I_Bit      EQU 0x80                     ; IRQ bit 

FRAME_R0   EQU 0x00			
FRAME_R1   EQU FRAME_R0+4
FRAME_R2   EQU FRAME_R1+4
FRAME_R3   EQU FRAME_R2+4
FRAME_R4   EQU FRAME_R3+4
FRAME_R5   EQU FRAME_R4+4
FRAME_R6   EQU FRAME_R5+4
FRAME_R7   EQU FRAME_R6+4
FRAME_R8   EQU FRAME_R7+4
FRAME_R9   EQU FRAME_R8+4
FRAME_R10  EQU FRAME_R9+4
FRAME_R11  EQU FRAME_R10+4
FRAME_R12  EQU FRAME_R11+4
FRAME_PSR  EQU FRAME_R12+4
FRAME_LR   EQU FRAME_PSR+4
FRAME_PC   EQU FRAME_LR+4
FRAME_SIZE EQU FRAME_PC+4

	AREA nih9_9,CODE,readonly
	
nestedInterruptHandler ; instruction       state : comment		
     SUB     r14,r14,#4                 ; 2 :
     STMDB   r13!,{r0-r3,r12,r14}       ; 2 : save context
     ; <insert code here>
     BL      read_RescheduleFlag        ; 3 : more processing
     CMP     r0,#0                      ; 3 : if processing?
     LDMNEIA r13!,{r0-r3,r12,pc}^       ; 4 :   then return 
     MRS     r2,SPSR                    ; 5 : copy SPSR_irq
     MOV     r0,r13                     ; 5 : copy r13_irq
     ADD     r13,r13,#6*4               ; 5 : reset stack
     MRS     r1,CPSR                    ; 6 : copy CPSR
     BIC     r1,r1,#Maskmd              ; 6 :
     ORR     r1,r1,#SVC32md             ; 6 :
     MSR     CPSR_c,r1                  ; 6 : change SVC mode
     SUB     r13,r13,#FRAME_SIZE-FRAME_R4 ; 7 : make stack space 
     STMIA   r13,{r4-r11}               ; 7 : save r4-r11
     LDMIA   r0,{r4-r9}                 ; 7 : r4-r9 IRQ stack 
     BIC     r1,r1,#I_Bit               ; 8 : 
     MSR     CPSR_c,r1                  ; 8 : enable int
     STMDB   r13!,{r4-r7}               ; 9 : save r4-r7 SVC
     STR     r2,[r13,#FRAME_PSR]        ; 9 : save PSR
     STR     r8,[r13,#FRAME_R12]        ; 9 : save r12
     STR     r9,[r13,#FRAME_PC]         ; 9 : save pc      
     STR     r14,[r13,#FRAME_LR]        ; 9 : save lr
     ; <insert code here>
     LDMIA   r13!,{r0-r12,r14}          ; 11 : restore context
     MSR     SPSR_cxsf,r14              ; 11 : restore SPSR
     LDMIA   r13!,{r14,pc}^             ; 11 : return


read_RescheduleFlag
     ; <implement your own reschedule flag code here>
     MOV     r0,#0                      ; more processing 
     MOV     pc,r14                     ; return

     END
