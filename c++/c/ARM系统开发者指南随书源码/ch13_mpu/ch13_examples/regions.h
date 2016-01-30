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


/* Region Type Assignment */
#define  STANDARD 0 
#define  EXTENDED 1 

/* Access Permissions */
#define NANA 0
#define RWNA 1 
#define RWRO 2 
#define RWRW 3 
#define RONA 5 
#define RORO 6 

/* Region Size */
#define SIZE_4G   31
#define SIZE_2G   30
#define SIZE_1G   29
#define SIZE_512M 28
#define SIZE_256M 27
#define SIZE_128M 26
#define SIZE_64M  25
#define SIZE_32M  24
#define SIZE_16M  23
#define SIZE_8M   22
#define SIZE_4M   21
#define SIZE_2M   20
#define SIZE_1M   19
#define SIZE_512K 18
#define SIZE_256K 17
#define SIZE_128K 16
#define SIZE_64K  15
#define SIZE_32K  14
#define SIZE_16K  13
#define SIZE_8K   12
#define SIZE_4K   11

/* CB = ICache[2], DCache[1], Write Buffer[0] */
#define CCB 7
#define CWB 7
#define CCb 6
#define CWT 6
#define CcB 5
#define Ccb 4
#define cCB 3
#define cWB 3
#define cCb 2
#define cWT 2
#define ccB 1
#define ccb 0

/* Region enable */
#define R_ENABLE 1
#define R_DISABLE 0


#define ENABLEMPU    (0x1<<0)
#define ENABLEDCACHE (0x1<<2)
#define ENABLEICACHE (0x1<<12)
#define MASKMPU      (0x1<<0)
#define MASKDCACHE   (0x1<<2)
#define MASKICACHE   (0x1<<12)




