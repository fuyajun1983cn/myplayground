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

;/*
; * Example 12.5
; */

;------------------------------------------------------------------------
; clean or clean-and-flush cache on xscale or strongarm
;----------------------------------------------------------------
; C-prototype
; void  cleanDCache(void);                /* clean all Dcache */
; void  cleanFlushDCache(void);           /* clean & flush all Dcache */
; void  cleanFlushCache(void);            /* clean & flush Dcache by way */
;------------------------------------------------------------------------
        AREA cleancachexscale , CODE, READONLY ; Start of Area block

        IF  {CPU} = "XSCALE" :LOR: {CPU} = "SA-110"
          EXPORT cleanDCache
          EXPORT cleanFlushDCache
          EXPORT cleanFlushCache
          INCLUDE cache.h
         

adr       RN  0   ; start address
nl        RN  1   ; number of cache lines to process
tmp   RN  12  ; scratch register

          MACRO
          CACHECLEANXSCALE $op

          IF "$op" = "Dclean"
            LDR     adr, =CleanAddressDcache
            MOV     nl, #1024      ; (32 ways * 32 clines)
            MOV     nl, #(1<<(NWAY+NSET))
          ENDIF
          IF "$op" = "DcleanMini"
            LDR     adr, =CleanAddressMiniDcache
            MOV     nl, #64        ; (2 ways * 32 clines)
            MOV     nl, #(1<<(MNWAY+NSET))
          ENDIF
5   
          IF  {CPU} = "XSCALE" :LAND: "$op" = "Dclean"
            MCR     p15, 0, adr, c7, c2, 5  ; allocate d-cline
            ADD     adr, adr, #32           ; +1 d-cline
          ENDIF
          IF  {CPU} = "SA-110" :LOR: "$op"= "DcleanMini"
            LDR     tmp,[adr],#32      ; Load data, +1 d-cline
          ENDIF
          SUBS    nl, nl, #1                ; -1 loop count
          BNE     %BT5
          IF  {CPU} = "XSCALE"
            CPWAIT
          ENDIF
          MEND

cleanDCache
          CACHECLEANXSCALE Dclean
          MOV pc, lr
cleanFlushDCache
          STMFD   sp!, {lr}
          BL cleanDCache
          IF  {CPU} = "XSCALE"
            BL cleanMiniDCache
          ENDIF
          MOV     r0, #0
          MCR     p15,0,r0,c7,c6,0    ; flush D-cache
          IF  {CPU} = "XSCALE"
            CPWAIT
          ENDIF
          LDMFD   sp!, {pc}
cleanFlushCache
          STMFD   sp!, {lr}
          BL cleanDCache
          IF  {CPU} = "XSCALE"
            BL cleanMiniDCache
          ENDIF
          MOV     r0, #0
          MCR     p15,0,r0,c7,c7,0    ; flush I-cache & D-cache
          IF  {CPU} = "XSCALE"
            CPWAIT
          ENDIF
          LDMFD   sp!, {pc}
        ENDIF

        IF  {CPU} = "XSCALE"
          EXPORT cleanMiniDCache

cleanMiniDCache          
          CACHECLEANXSCALE DcleanMini
          MOV pc, lr
        ENDIF

        END                             ; End of Area		