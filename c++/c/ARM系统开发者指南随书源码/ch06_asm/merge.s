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
;// Section 6.4.3: Register allocation

        AREA    ch06_4_3, CODE, READONLY
        
        EXPORT  merge_images

;// Example 6.16
        
IMAGE_WIDTH     EQU 176 ; QCIF width
IMAGE_HEIGHT    EQU 144 ; QCIF height

pz      RN 0    ; pointer to destination image (word aligned)
px      RN 1    ; pointer to first source image (word aligned)
py      RN 2    ; pointer to second source image (word aligned)
a       RN 3    ; 8-bit scaling factor (0-256)

xx      RN 4    ; holds four x pixels [ x3, x2, x1, x0 ]
yy      RN 5    ; holds four y pixels [ y3, y2, y1, y0 ] 
x       RN 6    ; holds two expanded x pixels [ x2, x0 ]
y       RN 7    ; holds two expanded y pixels [ y2, y0 ]
z       RN 8    ; holds four z pixels [ z3, z2, z1, z0 ]
count   RN 12   ; number of pixels remaining
mask    RN 14   ; constant mask with value 0x00ff00ff

        ; void merge_images(char *pz, char *px, char *py, int a)
merge_images
        STMFD   sp!, {r4-r8, lr}
        MOV     count, #IMAGE_WIDTH*IMAGE_HEIGHT
        LDR     mask, =0x00FF00FF   ; [    0, 0xFF,    0, 0xFF ]
merge_loop
        LDR     xx, [px], #4        ; [   x3,   x2,   x1,   x0 ]
        LDR     yy, [py], #4        ; [   y3,   y2,   y1,   y0 ]
        AND     x, mask, xx         ; [    0,   x2,    0,   x0 ]
        AND     y, mask, yy         ; [    0,   y2,    0,   y0 ]
        SUB     x, x, y             ; [    (x2-y2),    (x0-y0) ]
        MUL     x, a, x             ; [  a*(x2-y2),  a*(x0-y0) ]
        ADD     x, x, y, LSL#8      ; [         w2,         w0 ]
        AND     z, mask, x, LSR#8   ; [    0,   z2,    0,   z0 ]
        AND     x, mask, xx, LSR#8  ; [    0,   x3,    0,   x1 ]
        AND     y, mask, yy, LSR#8  ; [    0,   y3,    0,   y1 ]
        SUB     x, x, y             ; [    (x3-y3),    (x1-y1) ]
        MUL     x, a, x             ; [  a*(x3-y3),  a*(x1-y1) ]
        ADD     x, x, y, LSL#8      ; [         w3,         w1 ]
        AND     x, mask, x, LSR#8   ; [    0,   z3,    0,   z1 ]
        ORR     z, z, x, LSL#8      ; [   z3,   z2,   z1,   z0 ]
        STR     z, [pz], #4         ; store four z pixels
        SUBS    count, count, #4
        BGT     merge_loop
        LDMFD   sp!, {r4-r8, pc}
        
        END
