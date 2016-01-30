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

        IF {CPU} = "ARM920T" 
CSIZE   EQU 14  ; cache size as 2**CSIZE (16 K assumed)
CLINE   EQU  5  ; cache line size in bytes as 2**CLINE
NWAY    EQU  6  ; set associativity = 2**NWAY (64 way)
I7SET   EQU  5  ; CP15 c7 set incrementer as 2**ISET
I7WAY   EQU 26  ; CP15 c7 way incrementer as 2**SSET
I9WAY   EQU 26  ; CP15 c9 way incrementer as 2**SSET
        ENDIF
        IF {CPU} = "ARM922T" 
CSIZE   EQU 14  ; cache size as 2**CSIZE (16 K assumed)
CLINE   EQU  5  ; cache line size in bytes as 2**CLINE
NWAY    EQU  6  ; set associativity = 2**NWAY (64 way)
I7SET   EQU  5  ; CP15 c7 set incrementer as 2**ISET
I7WAY   EQU 26  ; CP15 c7 way incrementer as 2**SSET
I9WAY   EQU 26  ; CP15 c9 way incrementer as 2**SSET
    ENDIF
        IF {CPU} = "ARM926EJ-S" 
CSIZE   EQU 14  ; cache size as 2**CSIZE (16 K assumed)
CLINE   EQU  5  ; cache line size in bytes as 2**CLINE
NWAY    EQU  2  ; set associativity = 2**NWAY (4 way)
I7SET   EQU  4  ; CP15 c7 set incrementer as 2**ISET
I7WAY   EQU 30  ; CP15 c7 way incrementer as 2**IWAY
    ENDIF
        IF {CPU} = "ARM940T" 
CSIZE   EQU 12  ; cache size as 2**CSIZE (4K)
CLINE   EQU  4  ; cache line size in bytes as 2**CLINE
NWAY    EQU  6  ; set associativity = 2**NWAY (64 way)
I7SET   EQU  4  ; CP15 c7 set incrementer = 2**ISET
I7WAY   EQU 26  ; CP15 c7 way incrementer = 2**IWAY
I9WAY   EQU 0   ; CP15 c9 way incrementer = 2**IWAY
    ENDIF
        IF {CPU} = "ARM946E-S" 
CSIZE   EQU 12  ; cache size as 2**CSIZE (4 K assumed)
CLINE   EQU  5  ; cache line size in bytes as 2**CLINE
NWAY    EQU  2  ; set associativity = 2**NWAY (4 way)
I7SET   EQU  4  ; CP15 c7 set incrementer = 2**ISET
I7WAY   EQU 30  ; CP15 c7 way incrementer = 2**IWAY
I9WAY   EQU  0  ; CP15 c7 way incrementer = 2**IWAY
    ENDIF
        IF {CPU} = "ARM1022E" 
CSIZE   EQU 14  ; cache size as 2**CSIZE (16 K)
CLINE   EQU  5  ; cache line size in bytes as 2**CLINE
NWAY    EQU  6  ; set associativity = 2**NWAY (64 way)
I7SET   EQU  5  ; CP15 c7 set incrementer as 2**ISET
I7WAY   EQU 26  ; CP15 c7 way incrementer as 2**SSET
I9WAY   EQU 26  ; CP15 c7 way incrementer = 2**IWAY
    ENDIF
        IF {CPU} = "ARM1026EJ-S" 
CSIZE   EQU 14  ; cache size as 2**CSIZE (16 K assumed)
CLINE   EQU  5  ; cache line size in bytes as 2**CLINE
NWAY    EQU  2  ; set associativity = 2**NWAY (4 way)
I7SET   EQU  5  ; CP15 c7 set incrementer as 2**ISET
I7WAY   EQU 30  ; CP15 c7 way incrementer as 2**IWAY
    ENDIF
        IF {CPU} = "SA-110" 
CSIZE   EQU 14  ; cache size as 2**CSIZE (16 K)
CLINE   EQU  5  ; cache line size in bytes as 2**CLINE
NWAY    EQU  5  ; set associativity = 2**NWAY (4 way)
CleanAddressDcache  EQU 0x8000
    ENDIF
    IF {CPU} = "XSCALE" 
CSIZE   EQU 15  ; cache size as 2**CSIZE (32 K)
CLINE   EQU  5  ; cache line size in bytes as 2**CLINE
NWAY    EQU  5  ; set associativity = 2**NWAY (32 way)
MNWAY   EQU  1  ; set assoc mini D-cache = 2**NWAY (2 way)
MCSIZE  EQU 11  ; mini cache size  as 2**CSIZE (2 K)
CleanAddressDcache  EQU 0x8000  ;(32K block 0x8000-0x10000)
CleanAddressMiniDcache  EQU 0x10000 ;(2K block 0x10000-0x10800)
    ENDIF

;   ----------------
SWAY    EQU (CSIZE-NWAY)         ; size of way = 2**SWAY
NSET    EQU (CSIZE-NWAY-CLINE) ; cachelines per way = 2**NSET

      MACRO  
      CPWAIT  
      MRC     p15, 0, r12, c2, c0, 0 ; read any CP15
      MOV     r12, r12 
      SUB     pc, pc, #4 ; branch to next instruction
      MEND
        END