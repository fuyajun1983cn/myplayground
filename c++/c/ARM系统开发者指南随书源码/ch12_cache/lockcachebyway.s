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
; * Example 12.7
; */
;-----------------------------------------------------------------
; void lockDcache( * data, int size); /* lock data in D-cache */
; void lockIcache( * data, int size); /* lock code in I-cache */
;-----------------------------------------------------------------
        AREA lockcacheblock , CODE, READONLY ; Start of Area block

        IF  {CPU} = "ARM920T"       :LOR: \
            {CPU} = "ARM922T"       :LOR: \
            {CPU} = "ARM940T"       :LOR: \
            {CPU} = "ARM946E-S"     :LOR: \
            {CPU} = "ARM1022E"
          EXPORT lockDCache
          EXPORT lockICache
          INCLUDE cache.h

adr       RN 0    ; current address of code or data
size      RN 1    ; memory size in bytes
nw        RN 1    ; memory size in ways
count     RN 2
tmp       RN 2    ; scratch register
tmp1      RN 3    ; scratch register 
c9f       RN 12   ; CP15:c9 register format

          MACRO
          CACHELOCKBYWAY $op

          BIC     adr, adr, #(1<<CLINE)-1 ; align to cline
          LDR     tmp, =(1<<SWAY)-1    ; scratch = size of way 
          TST     size, tmp            ; way end fragment ?
          MOV     nw, size, lsr #SWAY  ; convert bytes to ways
          ADDNE   nw, nw, #1           ; add way if fragment
          CMP     nw, #0               ; no lockdown requested 
          BEQ     %FT2                 ; exit return victim base

          IF "$op" = "Icache"
            MRC     p15, 0, c9f, c9, c0, 1  ; get i-cache victim
          ENDIF 
          IF "$op" = "Dcache"
            MRC     p15, 0, c9f, c9, c0, 0  ; get d-cache victim
          ENDIF
        
          AND     c9f, c9f, tmp       ; mask high bits c9f = victim
          ADD     tmp, c9f, nw        ; temp = victim + way count
          CMP     tmp, #(1<<NWAY)-1   ; > total ways ?
          MOVGT   r0, #-1             ; return -1 if to many ways
          BGT     %FT1                ; Error: cache way overrun
     
          IF {CPU} = "ARM940T" :LOR: {CPU} = "ARM946E-S"
            ORR     c9f, c9f, #1<<31  ; put cache in lockdown mode
          ENDIF    
10
          IF "$op" = "Icache"
            MCR     p15, 0, c9f, c9, c0, 1 ; set victim
          ENDIF
          IF "$op" = "Dcache"
            MCR     p15, 0, c9f, c9, c0, 0 ; set victim
          ENDIF

         MOV     count, #(1<<NSET)-1
5
          IF "$op" = "Icache"
           MCR     p15, 0, adr, c7, c13, 1    ; load code cacheline
           ADD     adr, adr, #1<<CLINE        ; cline addr =+ 1
          ENDIF
          IF "$op" = "Dcache"
            LDR     tmp1, [adr], #1<<CLINE ; load data cacheline 
          ENDIF

          SUBS    count, count, #1
          BNE     %BT5
          ADD     c9f, c9f, #1<<I9WAY     ; victim pointer =+ 1
          SUBS    nw, nw, #1              ; way counter =- 1
          BNE     %BT10                   ; repeat for # of ways
2
          IF {CPU} = "ARM940T" :LOR: {CPU} = "ARM946E-S"
            BIC     r0, c9f, #1<<31 ; clear lock bit & r0=victim
          ENDIF
          IF "$op" = "Icache"
            MCR     p15, 0, r0, c9, c0, 1 ; set victim counter
          ENDIF
          IF "$op" = "Dcache"
            MCR     p15, 0, r0, c9, c0, 0 ; set victim counter
          ENDIF
1
          MOV     pc, lr
          MEND

lockDCache
          CACHELOCKBYWAY Dcache
lockICache
          CACHELOCKBYWAY Icache
          ENDIF
        END