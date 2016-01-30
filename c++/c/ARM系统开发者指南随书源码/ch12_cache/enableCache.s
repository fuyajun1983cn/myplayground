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

        AREA cache_routines , CODE, READONLY ; Start of Area block
     
        EXPORT enableMPU
        EXPORT enableCache
        EXPORT enableICache
        EXPORT enableDCache
        EXPORT disableCache
        EXPORT disableDCache
        EXPORT disableICache
        EXPORT enableRandom
        EXPORT enableRoundRobin

;------------------------------------
enableMPU
        MRC     p15,0,r0,c1,c0,0    ; Read control register
        ORR     r0,r0,#0x00000001   ; Enable MPU 
        MCR     p15,0,r0,c1,c0,0    ; Write to control register 1
        MOV     r0, #0
        MOV     pc, lr

;------------------------------------
disableCache
        MRC     p15,0,r0,c1,c0,0    ; Read control register
        BIC     r0,r0,#0x00001000   ; Clear Icache enable bit
        BIC     r0,r0,#0x00000004   ; Clear Dcache enable bit 
        MCR     p15,0,r0,c1,c0,0    ; Write to control register 1
        MOV     r0, #0
        MOV     pc,lr
;------------------------------------
disableDCache
        MRC     p15,0,r0,c1,c0,0    ; Read control register
        BIC     r0,r0,#0x00000004   ; Clear Dcache enable bit 
        MCR     p15,0,r0,c1,c0,0    ; Write to control register 1
        MOV     r0, #0
        MOV     pc,lr
;------------------------------------
disableICache
        MRC     p15,0,r0,c1,c0,0    ; Read control register
        BIC     r0,r0,#0x00001000   ; Clear Icache enable bit
        MCR     p15,0,r0,c1,c0,0    ; Write to control register 1
        MOV     r0, #0
        MOV     pc,lr
	
;------------------------------------
enableCache
        MRC     p15,0,r0,c1,c0,0    ; Read control register
        ORR     r0,r0,#0x00001000   ; Set enable Icache
        ORR     r0,r0,#0x00000004   ; Set enable Dcache and protection unit 
        MCR     p15,0,r0,c1,c0,0    ; Write to control register 1
        MOV     r0, #0
        MOV     pc, lr
        
;------------------------------------
enableICache
        MRC     p15,0,r0,c1,c0,0    ; Read control register
        ORR     r0,r0,#0x00001000   ; Enable Icache
        MCR     p15,0,r0,c1,c0,0    ; Write to control register 1
        MOV     r0, #0
        MOV     pc, lr

;------------------------------------
enableDCache
        MRC     p15,0,r0,c1,c0,0    ; Read control register
        ORR     r0,r0,#0x00000004   ; Enable Dcache 
        MCR     p15,0,r0,c1,c0,0    ; Write to control register 1
        MOV     r0, #0
        MOV     pc, lr

;------------------------------------
enableRoundRobin
        IF {CPU} = "ARM940T"
          MRC     p15,0,r0,c15,c0,0   ; Read round robin register
          ORR     r0,r0,#0x0000000c 	; enable d-cache round robin
          MCR     p15,0,r0,c15,c0,0   ; Write to test register c15
          MRC     p15,0,r0,c15,c0,0   ; Read round robin register
        ENDIF
        IF {CPU} = "ARM920T"       :LOR: \
           {CPU} = "ARM922T"
          MRC     p15,0,r0,c1,c0,0    ; Read control register
          ORR     r0,r0,#0x00004000   ; Enable Icache
          MCR     p15,0,r0,c1,c0,0    ; Write to control register 1
        ENDIF
;        MOV     r0, #0
        MOV     pc, lr
;------------------------------------
enableRandom
        IF {CPU} = "ARM940T"
          MRC     p15,0,r0,c15,c0,0   ; Read round robin register
          BIC     r0,r0,#0x0000000c 	; enable d-cache round robin
          MCR     p15,0,r0,c15,c0,0   ; Write to test register c15
          MRC     p15,0,r0,c15,c0,0   ; Read round robin register
        ENDIF
        IF {CPU} = "ARM920T"       :LOR: \
           {CPU} = "ARM922T"
          MRC     p15,0,r0,c1,c0,0    ; Read control register
          BIC     r0,r0,#0x00004000   ; Enable Icache
          MCR     p15,0,r0,c1,c0,0    ; Write to control register 1
        ENDIF
;        MOV     r0, #0
        MOV     pc, lr
;------------------------------------
        END