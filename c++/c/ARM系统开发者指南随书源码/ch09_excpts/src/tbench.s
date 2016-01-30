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
* 
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

;/*****************************************************************************
; *
; *  Module       : tbench.s
; *  Descriptions : TestBench is a very basic confidence test. It excercies 
; *               : each interrupt handler and verifies that the handler 
; *               : has not corrupted the User registers or IRQ stack. 
; *               :
; *  OS           : generic
; *  Platform     : generic
; *  History      :
; *
; *  31th December 2003
; *  - added header
; *
; ****************************************************************************/
 
; *****************************************************************************
; IMPORT
; *****************************************************************************

     IMPORT nestedInterruptHandler
     IMPORT reentrantInterruptHandler
     IMPORT prioritizedSimpleInterruptHandler
     IMPORT prioritizedStandardInterruptHandler
     IMPORT prioritizedDirectInterruptHandler
     IMPORT prioritizedGroupedInterruptHandler
     IMPORT vectorServiceRoutine

; *****************************************************************************
; MACROS/DEFINES
; *****************************************************************************

Maskmd          EQU 0x1f                ; Mask mode
SVC32md         EQU 0x13                ; SVC mode 
I_Bit           EQU 0x80                ; IRQ bit
SEMIHOSTING     EQU 0x123456            ; semihosting SWI
SYS_WRITE0      EQU 0x04                ; semihosting string output
MAXNUMTESTS     EQU 7                   ; number of tests

; *****************************************************************************
; CODE
; *****************************************************************************
     
     AREA testbench,CODE,READWRITE
     ENTRY
; -- initialize a mock USER environment
init
     BL       initUserEnvironment       ; initialize User registers
; -- output test banner               
begin
     LDR     r1,=strBanner              ; r1 = @strBanner 
     BL      printTest                  ; print Banner
     MOV     r1,#1                      ; reset r1 = 1
     B       startTest                  ; branch to start test
startTest
     LDR     r0,nextTest                ; r0 = nextTest
moreTests
     LDR     r1,[pc,r0,LSL#2]           ; load address of the test string 
     B       printAndTest               ; print and test the interrupt handler
     DCD     strTest1                   ; nested interrupt handler
     DCD     strTest2                   ; reentrant interrupt handler
     DCD     strTest3                   ; prioritized simple interrupt handler
     DCD     strTest4                   ; prioritized standard interrupt handler
     DCD     strTest5                   ; prioritized direct interrupt handler
     DCD     strTest6                   ; prioritized grouped interrupt handler
     DCD     strTest7                   ; vector service routine 
; -- print test and run
printAndTest
     BL      printTest                  ; output test string
     BL      setUpMode                  ; set IRQ mode 
     BL      setUpMockInterruptController ; setup the mock int cntrl
     ADR     r14,verify+4               ; branch verify routine
testInterruptHandler	
     LDR     r0,nextTest                ; r0 = test number
     LDR     pc,[pc,r0,LSL#2]           ; jump to a interrupt handler
     NOP
     DCD     nestedInterruptHandler
     DCD     reentrantInterruptHandler
     DCD     prioritizedSimpleInterruptHandler
     DCD     prioritizedStandardInterruptHandler
     DCD     prioritizedDirectInterruptHandler
     DCD     prioritizedGroupedInterruptHandler
     DCD     vectorServiceRoutine       
; -- verify interrupt handler hasn't corrupted registers and IRQ stack 
verify
     BL      verifyRegisters            ; verify registers 
     LDR     r0,nextTest                ; r0 = test number
     ADD     r0,r0,#1                   ; increment test number
     ADR     r1,nextTest                ; r1 = @nextTest
     STR     r0,[r1]                    ; store test number
     CMP     r0,#MAXNUMTESTS            ; if r0<MAXNUMTESTS
     BLT     moreTests                  ;   then branch to moreTest
     B       completeTest               ; completed tests
nextTest
     DCD     0x0                        ; store next test
completeTest
     LDR     r1,=strCompleteTest        ; r1 = string
     BL      printTest                  ; print test string
passed
     B       passed                     ; infinite loop

; *****************************************************************************
; * ROUTINES
; *****************************************************************************

; void setUpMockInterruptController (void);
; POST: mem32[0x80000000] = 0x00000001
; POST: r13_irq = 0x9000
;
setUpMockInterruptController
     LDR     r0,=0x80000000             ; ic_Base = @0x80000000
     MOV     r13,#1                     ; set r13 to show one interrupt
     STR     r13,[r0]                   ; 0x80000000=1
     MOV     r13,#0x9000                ; r13_irq=0x9000
     MOV     pc,lr                      ; return

; void verifyRegisters (void);
; POST: outputs PASS | FAIL 
; 
verifyRegisters
     CMP     r1,#1                      ; if r1!=1
     BNE     testFailed                 ;    then testFailed
     CMP     r2,#2                      ; if r2!=2
     BNE     testFailed                 ;    then testFailed
     CMP     r3,#3                      ; if r3!=3
     BNE     testFailed                 ;    then testFailed
     CMP     r4,#4                      ; if r4!=4
     BNE     testFailed                 ;    then testFailed
     CMP     r5,#5                      ; if r5!=5
     BNE     testFailed                 ;    then testFailed
     CMP     r6,#6                      ; if r6!=6
     BNE     testFailed                 ;    then testFailed
     CMP     r7,#7                      ; if r7!=7
     BNE     testFailed                 ;    then testFailed
     CMP     r8,#8                      ; if r8!=8
     BNE     testFailed                 ;    then testFailed
     CMP     r9,#9                      ; if r9!=9
     BNE     testFailed                 ;    then testFailed
     CMP     r10,#10                    ; if r10!=10
     BNE     testFailed                 ;    then testFailed
     CMP     r11,#11                    ; if r11!=11
     BNE     testFailed                 ;    then testFailed
     CMP     r12,#12                    ; if r12!=12
     BNE     testFailed                 ;    then testFailed
     MRS     r1,CPSR			; copy CPSR to r1
     BIC     r1,r1,#Maskmd		; mask the mode
     ORR     r1,r1,#0x12                ; CPSR=IFt_IRQ
     MSR     CPSR_cxsf,r1		; change to IRQ mode
     CMP     r13,#0x9000                ; if r13_usr!=0x9000
     BNE     testFailed                 ;    then testFailed
     MRS     r1,CPSR                    ; copy CPSR to r1
     BIC     r1,r1,#Maskmd              ; mask the mode
     ORR     r1,r1,#0x1f                ; CPSR=ift_SYS
     MSR     CPSR_cxsf,r1               ; change to SYSTEM mode
testPassed
     MOV     r0,#SYS_WRITE0             ; r0=SYS_WRITE0 (0x4)
     LDR     r1,=strPassed               ; r1 = @strPassed
     SWI     0x123456                   ; semihosting SWI
     B       continue                   ; jump to continue
testFailed
     MOV     r0,#SYS_WRITE0             ; r0=SYS_WRITE0 (0x4)
     LDR     r1,=strFailed               ; r1 = @strFailed
     SWI     0x123456                   ; semihosting SWI
continue     
     MOV     r1,#1                      ; reset r1=1
     MOV     pc,lr                      ; return

; void setUpMode (void);
; POST: CPSR = IFt_IRQ SPSR = ift_SYSTEM
setUpMode
     MOV     r0,lr                      ; copy the link register into r0
     MRS     r1,CPSR                    ; copy CPSR to r1
     BIC     r1,r1,#Maskmd              ; mask the mode
     ORR     r1,r1,#0x12|I_Bit          ; copy of CPSR = ift_IRQ
     MSR     CPSR_cxsf,r1		; change to IRQ mode
     MRS     r1,SPSR                    ; copy SPSR to r1
     BIC     r1,r1,#Maskmd              ; mask the mode
     ORR     r1,r1,#0x1f                ; SPSR_IRQ = ift_SYS
     MSR     SPSR_cxsf,r1               ; change SPSR to SYSTEM mode
     MOV     r1,#1                      ; reset r1=1
     MOV     pc,r0                      ; return

; void printTest (r1-address of string);
; POST: output zero terminated string in pointed to by r1
printTest
     MOV     r0,#SYS_WRITE0
     SWI     0x123456
     MOV     r1,#1
     MOV     pc,lr
; void initUserEnvironment (void);
; POST: r<n>_usr = n where n=1 to 12 
; POST: (note User and System mode registers are the same)
initUserEnvironment
; -- change to System mode
     MOV     r0,lr
     MRS     r1,CPSR			; copy CPSR to r1
     BIC     r1,r1,#Maskmd              ; mask the mode
     ORR     r1,r1,#0x1f                ; CPSR = ift_SYS
     MSR     CPSR_cxsf,r1		; change to SYSTEM mode
; -- set-up register values
     MOV     r1,#1                      ; r1 = 1
     MOV     r2,#2                      ; r2 = 3
     MOV     r3,#3                      ; r3 = 3
     MOV     r4,#4                      ; r4 = 4
     MOV     r5,#5                      ; r5 = 5
     MOV     r6,#6                      ; r6 = 6
     MOV     r7,#7                      ; r7 = 7
     MOV     r8,#8                      ; r8 = 8
     MOV     r9,#9                      ; r9 = 9
     MOV     r10,#10                    ; r10 = 10
     MOV     r11,#11                    ; r11 = 11
     MOV     r12,#12                    ; r12 = 12
     MOV     pc,r0                      ; return
     
; *****************************************************************************
; DATA
; *****************************************************************************

strBanner
     DCB     "Basic Confidence Test\n\n",0 ; banner string 
     ALIGN
strCompleteTest
     DCB     "\n\nComplete !!!\n",0     ; string to show completion
     ALIGN     
strPassed
     DCB     "PASSED \n",0              ; string "PASSED"
     ALIGN
strFailed
     DCB     "FAILED \n",0              ; string "FAILED"
     ALIGN
strTest1
     DCB     "Test[1] : Nested interrupt handler               - ",0
     ALIGN
strTest2
     DCB     "Test[2] : Reentrant interrupt handler            - ",0
     ALIGN
strTest3
     DCB     "Test[3] : Prioritized simple interrupt handler   - ",0
     ALIGN     
strTest4
     DCB     "Test[4] : Prioritized standard interrupt handler - ",0
     ALIGN
strTest5
     DCB     "Test[5] : Prioritized direct interrupt handler   - ",0
     ALIGN
strTest6
     DCB     "Test[6] : Prioritized grouped interrupt handler  - ",0
     ALIGN
strTest7
     DCB     "Test[7] : Vector interrupt handler               - ",0
     ALIGN

     END

