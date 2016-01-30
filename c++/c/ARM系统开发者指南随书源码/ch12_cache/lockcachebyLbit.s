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
; * Example 12.8
; */

;-----------------------------------------------------------------
; void lockDcache( * data, int size); /* lock data in D-cache */
; void lockIcache( * data, int size); /* lock code in I-cache */
;-----------------------------------------------------------------
        AREA lockcacheblock , CODE, READONLY ; Start of Area block

        IF  {CPU} = "ARM926EJ-S"   :LOR: \
            {CPU} = "ARM1026EJ-S"
          EXPORT lockDCache
          EXPORT lockICache
          EXPORT bittest
          INCLUDE cache.h

adr       RN 0    ; current address of code or data
size      RN 1    ; memory size in bytes
tmp       RN 2    ; scratch register
tmp1      RN 3    ; scratch register 
c9f       RN 12   ; CP15:c9 register format

          MACRO
          CACHELOCKBYLBIT $op

          ADD     size, adr, size         ; size = end address
          BIC     adr, adr, #(1<<CLINE)-1 ; align to CLINE
          MOV     tmp,  #(1<<CLINE)-1     ; scratch CLINE mask
          TST     size, tmp               ; CLINE end fragment ?
          SUB     size, size, adr         ; add alignment bytes
          MOV     size, size, lsr #CLINE  ; convert size 2 # CLINE
          ADDNE   size, size, #1          ; add CLINE for fragment
          CMP     size, #(1<<NSET)-1      ; size to large ?
          BHI     %FT1                    ; exit return victim base

          IF "$op" = "Icache"
            MRC     p15, 0, c9f, c9, c0, 1  ; get i-cache lock bits
          ENDIF 
          IF "$op" = "Dcache"
            MRC     p15, 0, c9f, c9, c0, 0  ; get d-cache lock bits
          ENDIF
        
          AND     tmp, c9f, #0xf        ; tmp = state of Lbits
          MOV     tmp1, #1              
          TST     c9f, tmp1             ; test lock bit 0
          MOVNE   tmp1, tmp1, LSL #1
          TSTNE   c9f, tmp1             ; test lock bit 1
          MOVNE   tmp1, tmp1, LSL #1
          TSTNE   c9f, tmp1             ; test lock bit 2
          MOVNE   tmp1, tmp1, LSL #1
          BNE     %FT1                  ; ERROR: no available ways
          CMP     size, #0                ; no lockdown requested 
          BEQ     %FT1                    ; exit return size =0

          MVN     tmp1, tmp1            ; select L bit 
          AND     tmp1, tmp1, #0xf      ; mask off non L bits
          BIC     c9f, c9f, #0xf        ; construct c9f
          ADD     c9f, c9f, tmp1
     
          IF "$op" = "Icache"
            MCR     p15, 0, c9f, c9, c0, 1 ; set lock I page
          ENDIF
          IF "$op" = "Dcache"
            MCR     p15, 0, c9f, c9, c0, 0 ; set lock D page
          ENDIF
5
          IF "$op" = "Icache"
           MCR     p15, 0, adr, c7, c13, 1    ; load code cacheline
           ADD     adr, adr, #1<<CLINE        ; cline addr =+ 1
          ENDIF
          IF "$op" = "Dcache"
            LDR     tmp1, [adr], #1<<CLINE ; load data cacheline 
          ENDIF

          SUBS    size, size, #1        ; cline =- 1
          BNE     %BT5                  ; loop thru clines

          MVN     tmp1, c9f             ; lock selected L-bit
          AND     tmp1, tmp1, #0xf      ; mask off non L-bits
          ORR     tmp, tmp, tmp1        ; merge with orig L-bits
          BIC     c9f, c9f, #0xf        ; clear all L-bits
          ADD     c9f, c9f, tmp         ; set L-bits in c9f
          
          IF "$op" = "Icache"
            MCR     p15, 0, adr, c9, c0, 1 ; set i-cache lock bits
          ENDIF
          IF "$op" = "Dcache"
            MCR     p15, 0, adr, c9, c0, 0 ; set d-cache lock bits
          ENDIF
1
          MOV     r0, tmp1              ; return allocated way
          MOV     pc, lr
          MEND

lockDCache
          CACHELOCKBYLBIT Dcache
lockICache
          CACHELOCKBYLBIT Icache
          ENDIF
        IF  {CPU} = "ARM926EJ-S"   :LOR: \
            {CPU} = "ARM1026EJ-S"
bittest
        MRC     p15, 0, r0, c9, c0, 0  ; get d-cache lock bits
        BIC     r0, r0, #0xf
        ORR     r0, r0, #0x7
        MCR     p15, 0, r0, c9, c0, 0  ; set d-cache lock bits
        MRC     p15, 0, r0, c9, c0, 0  ; get d-cache lock bits
        MOV     pc, lr
        ENDIF
          EXPORT Arch
Arch
          DCB {CPU}
        END