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
; * Example 12.2
; */  

        AREA flushAll, CODE, READONLY ; Start of Area block
;----------------------------------------------------------------
; C-prototype
; void  flushCache(void);   /* flush all caches */
; void  flushDCache(void);  /* flush D-cache */
; void  flushICache(void);  /* flush I-cache */
;----------------------------------------------------------------
        IF  {CPU} = "ARM720T"       :LOR: \
            {CPU} = "ARM920T"       :LOR: \
            {CPU} = "ARM922T"       :LOR: \
            {CPU} = "ARM926EJ-S"    :LOR: \
            {CPU} = "ARM940T"       :LOR: \
            {CPU} = "ARM946E-S"     :LOR: \
            {CPU} = "ARM1022E"      :LOR: \
            {CPU} = "ARM1026EJ-S"   :LOR: \
            {CPU} = "SA-110"   :LOR: \
            {CPU} = "XSCALE"

c7f       RN 0 ; register in CP17:c7 format
          MACRO
          CACHEFLUSH $op
    
          MOV     c7f, #0
          IF      "$op" = "Icache"
            MCR     p15,0,c7f,c7,c5,0      ; flush I-cache
          ENDIF
          IF      "$op" = "Dcache"
            MCR     p15,0,c7f,c7,c6,0      ; flush D-cache
          ENDIF
          IF      "$op" = "IDcache"
            IF {CPU} = "ARM940T" :LOR: \
               {CPU} = "ARM946E-S"
              MCR     p15,0,c7f,c7,c5,0    ; flush I-cache
              MCR     p15,0,c7f,c7,c6,0    ; flush D-cache
            ELSE
              MCR     p15,0,c7f,c7,c7,0    ; flush I-cache & D-cache
            ENDIF
          ENDIF
          MOV     pc, lr
          MEND
      
          IF  {CPU} = "ARM720T"
            EXPORT flushCache
flushCache
            CACHEFLUSH IDcache
          ELSE
            EXPORT flushCache
            EXPORT flushICache
            EXPORT flushDCache
flushCache
            CACHEFLUSH IDcache
flushICache
            CACHEFLUSH Icache     
flushDCache
            CACHEFLUSH Dcache 
          ENDIF   
        ENDIF 
        END                             ; End of Area	
