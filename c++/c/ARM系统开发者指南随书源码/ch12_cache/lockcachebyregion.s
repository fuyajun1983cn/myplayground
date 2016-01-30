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
; * Example 12.9
; */
;-----------------------------------------------------------------
; void lockDCache( * data, int size); /* lock data in D-cache */
; void lockICache( * data, int size); /* lock code in I-cache */
;-----------------------------------------------------------------
        AREA lockcachebyregion , CODE, READONLY ; Start of Area block
        IF  {CPU} = "XSCALE" 
          EXPORT lockICache
          EXPORT lockDCache
          EXPORT lockDCacheRAM
          INCLUDE cache.h

adr     RN 0    ; current address of code or data
size    RN 1    ; memory size in bytes
tmp     RN 2    ; cpc15:c9 31 (load 5:0 victim pointer)
tmp1    RN 3    ; scratch register for LDR instruction
        MACRO
        CACHELOCKREGION $op

        ADD     size, adr, size         ; size = end address
        BIC     adr, adr, #(1<<CLINE)-1 ; align to CLINE
        MOV     tmp,  #(1<<CLINE)-1 ; scratch CLINE mask
        TST     size, tmp           ; CLINE end fragment ?
        SUB     size, size, adr         ; add alignment bytes
        MOV     size, size, lsr #CLINE  ; convert size 2 # CLINE
        ADDNE   size, size, #1          ; add CLINE to hold fragment

        CMP     size, #0                ; no lockdown requested 
        BEQ     %FT1                    ; exit return size =0
        
        IF      "$op" = "Dcache" :LOR: "$op" = "DcacheRAM"
          MCR     p15, 0, adr, c7, c10, 4 ; drain write buffer
          MOV     tmp, #1
          MCR     p15, 0, tmp, c9, c2, 0 ; unlock data cache
          CPWAIT
          MOV     tmp, #0           ; even words to zero
        ENDIF
        IF      "$op" = "DcacheRAM"
          MOV     tmp1, #0          ; init odd words to zero
        ENDIF
5
        IF      "$op" = "Icache"
          MCR     p15, 0, adr, c9, c1, 0; lock ICache line
          ADD     adr, adr, #1<<CLINE    
        ENDIF
        IF      "$op" = "Dcache"
          MCR     p15, 0, adr, c7, c10, 1   ; clean dirty line
          MCR     p15, 0, adr, c7, c6, 1    ; Flush d-cache line
          LDR     tmp, [adr], #1<<CLINE ; load data cacheline 
        ENDIF

        IF      "$op" = "DcacheRAM"
          MCR     p15, 0, adr, c7, c2, 5  ; Allocate d-cache line
          MCR     p15, 0, adr, c7, c10, 4 ; drain write buffer
          STRD    tmp, [adr], #8    ; init 2 zero & adr=+2
          STRD    tmp, [adr], #8    ; init 2 zero & adr=+2
          STRD    tmp, [adr], #8    ; init 2 zero & adr=+2
          STRD    tmp, [adr], #8    ; init 2 zero & adr=+2
        ENDIF
        SUBS    size, size, #1
        BNE     %BT5

        IF "$op" = "Dcache" :LOR: "$op" = "DcacheRAM"
          MCR     p15, 0, adr, c7, c10, 4   ; drain write buffer
          MCR     p15, 0, tmp, c9, c2, 0    ; lock data cache
          CPWAIT
        ENDIF
1
        MOV     r0, #0
        MOV     pc, lr
        MEND
lockICache
          CACHELOCKREGION Icache
lockDCache
          CACHELOCKREGION Dcache
lockDCacheRAM
          CACHELOCKREGION DcacheRAM
        ENDIF
        END