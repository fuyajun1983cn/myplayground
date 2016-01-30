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
;// Section 7.3: Division routines

        AREA    ch07_3, CODE, READONLY

        EXPORT  udiv_32by32_arm7m
        EXPORT  udiv_32by16_arm7m
        EXPORT  udiv_64by32_arm7m
        EXPORT  sdiv_32by32_arm7m
       

d       RN 0    ; input denominator d, output quotient
r       RN 1    ; input numerator n, output remainder
t       RN 2    ; scratch register
q       RN 3    ; current quotient

        ; __value_in_regs struct { unsigned q, r; }
        ;   udiv_32by32_arm7m(unsigned d, unsigned n)
udiv_32by32_arm7m
        MOV     q, #0             ; zero quotient
        RSBS    t, d, r, LSR#3    ; if ((r>>3)>=d) C=1; else C=0;
        BCC     div_3bits         ; quotient fits in 3 bits
        RSBS    t, d, r, LSR#8    ; if ((r>>8)>=d) C=1; else C=0;
        BCC     div_8bits         ; quotient fits in 8 bits
        MOV     d, d, LSL#8       ; d = d*256
        ORR     q, q, #0xFF000000 ; make div_loop iterate twice
        RSBS    t, d, r, LSR#4    ; if ((r>>4)>=d) C=1; else C=0;
        BCC     div_4bits         ; quotient fits in 12 bits
        RSBS    t, d, r, LSR#8    ; if ((r>>8)>=d) C=1; else C=0;
        BCC     div_8bits         ; quotient fits in 16 bits
        MOV     d, d, LSL#8       ; d = d*256
        ORR     q, q, #0x00FF0000 ; make div_loop iterate 3 times
        RSBS    t, d, r, LSR#8    ; if ((r>>8)>=d)
        MOVCS   d, d, LSL#8       ; { d = d*256;
        ORRCS   q, q, #0x0000FF00 ; make div_loop iterate 4 times}
        RSBS    t, d, r, LSR#4    ; if ((r>>4)<d)
        BCC     div_4bits         ;   r/d quotient fits in 4 bits
        RSBS    t, d, #0          ; if (0 >= d)
        BCS     div_by_0          ;   goto divide by zero trap
        ; fall through to the loop with C=0
div_loop
        MOVCS   d, d, LSR#8       ; if (next loop) d = d/256
div_8bits                         ; calculate 8 quotient bits
        RSBS    t, d, r, LSR#7    ; if ((r>>7)>=d) C=1; else C=0;
        SUBCS   r, r, d, LSL#7    ; if (C) r -= d<<7;
        ADC     q, q, q           ; q=(q<<1)+C;
        RSBS    t, d, r, LSR#6    ; if ((r>>6)>=d) C=1; else C=0;
        SUBCS   r, r, d, LSL#6    ; if (C) r -= d<<6;
        ADC     q, q, q           ; q=(q<<1)+C;
        RSBS    t, d, r, LSR#5    ; if ((r>>5)>=d) C=1; else C=0;
        SUBCS   r, r, d, LSL#5    ; if (C) r -= d<<5;
        ADC     q, q, q           ; q=(q<<1)+C;
        RSBS    t, d, r, LSR#4    ; if ((r>>4)>=d) C=1; else C=0;
        SUBCS   r, r, d, LSL#4    ; if (C) r -= d<<4;
        ADC     q, q, q           ; q=(q<<1)+C;
div_4bits                         ; calculate 4 quotient bits
        RSBS    t, d, r, LSR#3    ; if ((r>>3)>=d) C=1; else C=0;
        SUBCS   r, r, d, LSL#3    ; if (C) r -= d<<3;
        ADC     q, q, q           ; q=(q<<1)+C;
div_3bits                         ; calculate 3 quotient bits
        RSBS    t, d, r, LSR#2    ; if ((r>>2)>=d) C=1; else C=0;
        SUBCS   r, r, d, LSL#2    ; if (C) r -= d<<2;
        ADC     q, q, q           ; q=(q<<1)+C;
        RSBS    t, d, r, LSR#1    ; if ((r>>1)>=d) C=1; else C=0;
        SUBCS   r, r, d, LSL#1    ; if (C) r -= d<<1;
        ADC     q, q, q           ; q=(q<<1)+C;
        RSBS    t, d, r           ; if (r>=d) C=1; else C=0;
        SUBCS   r, r, d           ; if (C) r -= d;
        ADCS    q, q, q           ; q=(q<<1)+C; C=old q bit 31;
div_next
        BCS     div_loop          ; loop if more quotient bits
        MOV     r0, q             ; r0 = quotient; r1=remainder;
        MOV     pc, lr            ; return { r0, r1 } structure;
div_by_0
        MOV     r0, #-1
        MOV     r1, #-1
        MOV     pc, lr            ; return { -1, -1 } structure;
        
        
d       RN 0    ; input denominator, output quotient
r       RN 1    ; input numerator n, output remainder
sign    RN 12

        ; __value_in_regs struct { signed q, r; }
        ;   udiv_32by32_arm7m(signed d, signed n)
sdiv_32by32_arm7m
        STMFD   sp!, {lr}
        ANDS    sign, d, #1<<31       ; sign=(d<0 ? 1<<31 : 0);
        RSBMI   d, d, #0              ; if (d<0) d=-d;
        EORS    sign, sign, r, ASR#32 ; if (r<0) sign=~sign;
        RSBCS   r, r, #0              ; if (r<0) r=-r;
        BL      udiv_32by32_arm7m     ; (d,r)=(r/d,r%d)
        MOVS    sign, sign, LSL#1     ; C=sign[31], N=sign[30]
        RSBCS   d, d, #0              ; if (sign[31]) d=-d;
        RSBMI   r, r, #0              ; if (sign[30]) r=-r;
        LDMFD   sp!, {pc}
        
       

m       RN 0    ; input denominator d then (-d<<14)
r       RN 1    ; input numerator n then remainder

        ; __value_in_regs struct { unsigned q, r; }
        ;   udiv_32by16_arm7m(unsigned d, unsigned n)
udiv_32by16_arm7m
        RSBS    m, m, r, LSR#15    ; m = (n>>15) - d
        BCS     overflow_15        ; overflow if (n>>15)>=d
        SUB     m, m, r, LSR#15    ; m = -d
        MOV     m, m, LSL#14       ; m = -d<<14
        ; 15 trial division steps follow
        ADDS    r, m, r            ; r=r-(d<<14); C=(r>=0);
        SUBCC   r, r, m            ; if (C==0) r+=(d<<14)
        ADCS    r, m, r, LSL #1    ; r=(2*r+C)-(d<<14); C=(r>=0);
        SUBCC   r, r, m            ; if (C==0) r+=(d<<14)
        ADCS    r, m, r, LSL #1    ; ... and repeat ...
        SUBCC   r, r, m
        ADCS    r, m, r, LSL #1
        SUBCC   r, r, m
        ADCS    r, m, r, LSL #1
        SUBCC   r, r, m
        ADCS    r, m, r, LSL #1
        SUBCC   r, r, m
        ADCS    r, m, r, LSL #1
        SUBCC   r, r, m
        ADCS    r, m, r, LSL #1
        SUBCC   r, r, m
        ADCS    r, m, r, LSL #1
        SUBCC   r, r, m
        ADCS    r, m, r, LSL #1
        SUBCC   r, r, m
        ADCS    r, m, r, LSL #1
        SUBCC   r, r, m
        ADCS    r, m, r, LSL #1
        SUBCC   r, r, m
        ADCS    r, m, r, LSL #1
        SUBCC   r, r, m
        ADCS    r, m, r, LSL #1
        SUBCC   r, r, m
        ADCS    r, m, r, LSL #1
        SUBCC   r, r, m
        ; extract answer and remainder (if required)
        ADC     r0, r, r           ; insert final answer bit
        MOV     r,  r0, LSR #15    ; extract remainder
        BIC     r0, r0, r, LSL #15 ; extract quotient
        MOV     pc, lr             ; return { r0, r }
overflow_15                        ; quotient oveflows 15 bits
        LDR     r0, =0x7FFF        ; maximum quotient
        MOV     r1, r0             ; maximum remainder
        MOV     pc, lr             ; return { 0x7fff, 0x7fff }

m       RN 0    ; input denominator d, -d
r       RN 1    ; input numerator (low), remainder (high)
t       RN 2    ; input numerator (high)
q       RN 3    ; result quotient and remainder (low)

        ; __value_in_regs struct { unsigned q, r; }
        ;   udiv_64by32_arm7m(unsigned d, unsigned long long n)
udiv_64by32_arm7m
        CMP     t, m            ; if (n >= (d<<32))
        BCS     overflow_32     ;   goto overflow_32;
        RSB     m, m, #0        ; m = -d
        ADDS    q, r, r         ; { [r,q] = 2*[r,q]-[d,0];
        ADCS    r, m, t, LSL#1  ;   C = ([r,q]>=0); }
        SUBCC   r, r, m         ; if (C==0) [r,q] += [d,0]
        GBLA    k               ; the next 32 steps are the same
k       SETA    1               ; so we generate them using an
        WHILE   k<32            ; assembler while loop
          ADCS  q, q, q         ; { [r,q] = 2*[r,q]+C - [d,0];
          ADCS  r, m, r, LSL#1  ;   C = ([r,q]>=0); }
          SUBCC r, r, m         ; if (C==0) [r,q] += [d,0]
k         SETA  k+1
        WEND
        ADCS    r0, q, q        ; insert final answer bit
        MOV     pc, lr          ; return { r0, r1 }
overflow_32
        MOV     r0, #-1
        MOV     r1, #-1
        MOV     pc, lr          ; return { -1, -1 }
        
        END
