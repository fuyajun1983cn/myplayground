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
; * Example 12.3
; */ 

;------------------------------------------------------------------------
; clean or clean-and-flush cache using way/set indexing
;----------------------------------------------------------------
; C-prototypes
; void  cleanDCache(void);                /* clean all Dcache */
; void  cleanFlushDCache(void);           /* clean & flush all Dcache */
; void  cleanFlushCache(void);            /* clean & flush Dcache by way */
;------------------------------------------------------------------------
        AREA cleancachebyway , CODE, READONLY ; Start of Area block
        IF  {CPU} = "ARM920T"       :LOR: \
            {CPU} = "ARM922T"       :LOR: \
            {CPU} = "ARM940T"       :LOR: \
            {CPU} = "ARM946E-S"     :LOR: \
            {CPU} = "ARM1022E"
          EXPORT cleanDCache
          EXPORT cleanFlushDCache
          EXPORT cleanFlushCache
          INCLUDE cache.h
        
c7f       RN  0   ; cp15:c7  register format

          MACRO
          CACHECLEANBYWAY $op
       
          MOV     c7f, #0                     ; create c7 format
5
          IF      "$op" = "Dclean"
            MCR     p15, 0, c7f, c7, c10, 2   ; clean D-cline
          ENDIF
          IF      "$op" = "Dcleanflush"
            MCR     p15, 0, c7f, c7, c14, 2   ; cleanflush D-cline
          ENDIF

          ADD     c7f, c7f, #1<<I7SET         ; +1 set index
          TST     c7f, #1<<(NSET+I7SET)       ; test index overflow
          BEQ     %BT5 

          BIC     c7f, c7f, #1<<(NSET+I7SET)  ; clear index overflow
          ADDS    c7f, c7f, #1<<I7WAY         ; +1 victim pointer
          BCC     %BT5                        ; test way overflow
          MEND

cleanDCache
            CACHECLEANBYWAY Dclean
            MOV     pc, lr
cleanFlushDCache
            CACHECLEANBYWAY Dcleanflush
            MOV     pc, lr
cleanFlushCache
            CACHECLEANBYWAY Dcleanflush
            MCR     p15,0,r0,c7,c5,0    ; flush I-cache
            MOV     pc, lr
          ENDIF

          END