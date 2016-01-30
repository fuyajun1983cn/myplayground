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
; * Example 12.6
; */  
;------------------------------------------------------------------------
; clean or flush cache from baseAddress to end of Region      
; r0 contains baseAddress 
; r1 contains size of Region in bytes
;
; void     flushICacheRegion(int *adr, unsigned int size);
; void     flushDCacheRegion(int *adr, unsigned int size);
; void     flushCacheRegion(int *adr, unsigned int size);
; void     cleanDCacheRegion(int *adr, unsigned int size);
; void     cleanFlushDCacheRegion(int *adr, unsigned int size);
; void     cleanFlushCacheRegion(int *adr, unsigned int size);

;------------------------------------------------------------------------
        AREA cacheRegionArea , CODE, READONLY ; Start of Area block

        IF  {CPU} = "ARM920T"       :LOR: \
            {CPU} = "ARM922T"       :LOR: \
            {CPU} = "ARM946E-S"     :LOR: \
            {CPU} = "ARM926EJ-S"    :LOR: \
            {CPU} = "ARM1022E"      :LOR: \
            {CPU} = "ARM1026EJ-S"   :LOR: \
            {CPU} = "XSCALE"        :LOR: \
            {CPU} = "SA-110"

          INCLUDE cache.h

adr       RN  0   ; active address
size      RN  1   ; size of region in bytes
nl        RN  1   ; number of cache lines to clean or flush

          MACRO 
          CACHEBYREGION $op

          BIC     adr, adr, #(1<<CLINE)-1       ; clip 2 cline adr
          MOV     nl, size, lsr #CLINE          ; bytes to cline 
10
          IF "$op" = "IcacheFlush"
            MCR     p15, 0, adr, c7, c5, 1      ; flush Icline@adr
          ENDIF
          IF "$op" = "DcacheFlush"
            MCR     p15, 0, adr, c7, c6, 1      ; flush Dccline@adr
          ENDIF
          IF "$op" = "IDcacheFlush"
            MCR     p15, 0, adr, c7, c5, 1      ; flush Icline@adr
            MCR     p15, 0, adr, c7, c6, 1      ; flush Dcline@adr
          ENDIF
          IF "$op" = "DcacheClean"
            MCR     p15, 0, adr, c7, c10, 1     ; clean Dcline@adr
          ENDIF
          IF "$op" = "DcacheCleanFlush"
            IF {CPU} = "XSCALE" :LOR: {CPU} = "SA-110"
              MCR     p15, 0, adr, c7, c10, 1   ; clean Dcline@adr
              MCR     p15, 0, adr, c7, c6, 1    ; flush Dcline@adr
            ELSE
              MCR     p15, 0, adr, c7, c14, 1 ; cleanflush Dcline@adr
            ENDIF
          ENDIF
          IF "$op" = "IDcacheCleanFlush"
            IF {CPU} = "ARM920T"   :LOR: {CPU} = "ARM922T"    :LOR: \
               {CPU} = "ARM946E-S" :LOR: {CPU} = "ARM926EJ-S" :LOR: \
               {CPU} = "ARM1022E"  :LOR: {CPU} = "ARM1026EJ-S" 
              MCR     p15, 0, adr, c7, c14, 1 ;cleanflush Dcline@adr
              MCR     p15, 0, adr, c7, c5, 1    ; flush Icline@adr
            ENDIF
            IF {CPU} = "XSCALE"
              MCR     p15, 0, adr, c7, c10, 1   ; clean Dcline@adr
              MCR     p15, 0, adr, c7, c6, 1    ; flush Dcline@adr
              MCR     p15, 0, adr, c7, c5, 1    ; flush Icline@adr
            ENDIF  	
          ENDIF

          ADD     adr, adr, #1<<CLINE           ; +1 next cline adr
          SUBS    nl, nl, #1                    ; -1 cline counter
          BNE     %BT10                         ; flush # lines +1
          IF {CPU} = "XSCALE"
            CPWAIT
          ENDIF
          MOV     pc, lr
          MEND

          IF {CPU} = "SA-110"
            EXPORT cleanDCacheRegion
            EXPORT flushDCacheRegion
            EXPORT cleanFlushDCacheRegion
cleanDCacheRegion
            CACHEBYREGION DcacheClean
flushDCacheRegion
            CACHEBYREGION DcacheFlush
cleanFlushDCacheRegion
            CACHEBYREGION DcacheCleanFlush
          ELSE
            EXPORT flushICacheRegion
            EXPORT flushDCacheRegion
            EXPORT flushCacheRegion
            EXPORT cleanDCacheRegion
            EXPORT cleanFlushDCacheRegion
            EXPORT cleanFlushCacheRegion
flushICacheRegion
            CACHEBYREGION IcacheFlush
flushDCacheRegion
            CACHEBYREGION DcacheFlush
flushCacheRegion
            CACHEBYREGION IDcacheFlush
cleanDCacheRegion
            CACHEBYREGION DcacheClean
cleanFlushDCacheRegion
            CACHEBYREGION DcacheCleanFlush
cleanFlushCacheRegion
            CACHEBYREGION IDcacheCleanFlush
          ENDIF
        ENDIF
        END
