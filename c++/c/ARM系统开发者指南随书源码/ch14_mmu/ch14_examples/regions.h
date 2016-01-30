/* ____________________________________________________________________
 *
 * Copyright (c) 2003, Andrew N. Sloss, Dominic Symes, Chris Wright
 * All rights reserved.
 * ____________________________________________________________________
 * 
 * NON-COMMERCIAL USE License
 * 
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met: 
 *
 * 1. For NON-COMMERCIAL USE only.
 * 
 * 2. Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer. 
 *
 * 3. Redistributions in binary form must reproduce the above 
 *    copyright notice, this list of conditions and the following 
 *    disclaimer in the documentation and/or other materials provided 
 *    with the distribution. 
 *
 * 4. All advertising materials mentioning features or use of this 
 *    software must display the following acknowledgement:
 *
 *    This product includes software developed by Andrew N. Sloss,
 *    Chris Wright and Dominic Symes. 
 *
 *  THIS SOFTWARE IS PROVIDED BY THE CONTRIBUTORS ``AS IS'' AND ANY 
 *  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
 *  PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE CONTRIBUTORS BE 
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, 
 *  OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
 *  OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR 
 *  TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT 
 *  OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 *  OF SUCH DAMAGE. 
 *
 * If you have questions about this license or would like a different
 * license please email : andrew@sloss.net
 *
 * 
 */

#define ENABLECLTDOM0  0x00000001
#define ENABLECLTDOM1  0x00000004
#define ENABLECLTDOM2  0x00000010
#define ENABLECLTDOM3  0x00000040
#define ENABLECLTDOM4  0x00000100
#define ENABLECLTDOM5  0x00000400
#define ENABLECLTDOM6  0x00001000
#define ENABLECLTDOM7  0x00004000
#define ENABLECLTDOM8  0x00010000
#define ENABLECLTDOM9  0x00040000
#define ENABLECLTDOM10 0x00100000
#define ENABLECLTDOM11 0x00400000
#define ENABLECLTDOM12 0x01000000
#define ENABLECLTDOM13 0x04000000
#define ENABLECLTDOM14 0x10000000
#define ENABLECLTDOM15 0x40000000

#define CHANGEDOM0    0x00000003
#define CHANGEDOM1    0x0000000c
#define CHANGEDOM2    0x00000030
#define CHANGEDOM3    0x000000c0
#define CHANGEDOM4    0x00000300
#define CHANGEDOM5    0x00000c00
#define CHANGEDOM6    0x00003000
#define CHANGEDOM7    0x0000c000
#define CHANGEDOM8    0x00030000
#define CHANGEDOM9    0x000c0000
#define CHANGEDOM10   0x00300000
#define CHANGEDOM11   0x00c00000
#define CHANGEDOM12   0x03000000
#define CHANGEDOM13   0x0c000000
#define CHANGEDOM14   0x30000000
#define CHANGEDOM15   0xc0000000

#define CHANGEALLDOM   0xffffffff

#define DOMNA       0x00000000
#define DOMAA       0xffffffff

#define DOMMGR3     0x000000c0
#define DOMMGR15    0xc0000000
#define DOM3CLT     0x00000040

#if defined(__TARGET_CPU_ARM920T) | defined(__TARGET_CPU_ARM922T) 
#define ENABLEMMU       0x00000001
#define ENABLEDCACHE    0x00000004
#define ENABLEICACHE    0x00001000
#define ENABLES         0x00000100
#define ENABLER         0x00000200
#define ENABLEHIVECT    0xc0002000
#define ENABLEASYNC     0xc0000000
#define ENABLESYNC      0x40000000
#define ENABLEFASTBUS   0x40000000

#define CHANGEMMU       0x00000001
#define CHANGEDCACHE    0x00000004
#define CHANGEICACHE    0x00001000
#define CHANGES         0x00000100
#define CHANGER         0x00000200
#define CHANGEHIVECT    0xc0002000
#define CHANGECLOCKING  0xc0000000
#endif

#if defined(__TARGET_CPU_ARM720T) 
#define ENABLEMMU    0x00000001
#define ENABLECACHE  0x00000004
#define ENABLEWB     0x00000008
#define ENABLES      0x00000100
#define ENABLER      0x00000200
#define ENABLEHIVECT 0xc0002000

#define CHANGEMMU    0x00000001
#define CHANGECACHE  0x00000004
#define CHANGEWB     0x00000008
#define CHANGES      0x00000100
#define CHANGER      0x00000200
#define CHANGEHIVECT 0xc0002000
#endif


#if defined(__TARGET_CPU_ARM920T) | defined(__TARGET_CPU_ARM922T) 
  #define cb 0x0
  #define cB 0x1
  #define WT 0x2
  #define WB 0x3
#endif
 /* 720 */
#if defined(__TARGET_CPU_ARM720T)
  #define cb 0x0
  #define cB 0x1
  #define Cb 0x2
  #define WT 0x3
#endif
/* cb = not cached/not buffered */
/* cB = not Cached/Buffered */
/* Cb = Cached/not Buffered */
/* WT = write through cache */
/* WB = write back cache */


/* 920T &720T  permissions */
#define NANA 0x00  
#define RWNA 0x01 
#define RWRO 0x02
#define RWRW 0x03
/* NA = no access, RO = read only, RW = read/write */


#define FAULT 0
#define COARSE 1
#define SECTION 2
#define FINE 3
#define MASTER 2

#define LARGEPAGE 64
#define SMALLPAGE 4
#define TINYPAGE  1


#define notUsed 0x0