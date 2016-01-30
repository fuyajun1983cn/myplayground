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

extern  void cache_RRtest(unsigned int times,unsigned int numset);
extern  void flushCache(void);
extern  void flushICache(void);
extern  void flushDCache(void);
extern  void cleanDCache(void);
extern  void cleanMiniDCache(void);
extern  void cleanFlushDCache(void);
extern  void cleanFlushCache(void);
extern  void flushICacheRegion(int *adr, unsigned int size);
extern  void flushDCacheRegion(int *adr, unsigned int size);
extern  void flushCacheRegion(int *adr, unsigned int size);
extern  void cleanDCacheRegion(int *adr, unsigned int size);
extern  void cleanFlushDCacheRegion(int *adr, unsigned int size);
extern  void cleanFlushCacheRegion(int *adr, unsigned int size);
extern void lockICache( int *, unsigned int); 
extern void lockDCache( int *, unsigned int); 
extern void lockDCacheRAM( int *, unsigned int); 

int main(void)
{
#if defined(__TARGET_CPU_ARM720T)
  flushCache();
#endif

#if defined(__TARGET_CPU_ARM920T) || defined(__TARGET_CPU_ARM922T) || \
    defined(__TARGET_CPU_ARM940T) || defined(__TARGET_CPU_ARM946E_S) || \
    defined(__TARGET_CPU_ARM1022E) || defined(__TARGET_CPU_ARM926EJ_S) || \
    defined(__TARGET_CPU_XSCALE) || defined(__TARGET_CPU_SA_110) || \
    defined(__TARGET_CPU_ARM1026EJ_S) 
  flushCache();
  flushICache();
  flushDCache();
#endif


#if defined(__TARGET_CPU_ARM920T) || defined(__TARGET_CPU_ARM922T) || \
    defined(__TARGET_CPU_ARM940T) || defined(__TARGET_CPU_ARM946E_S) || \
    defined(__TARGET_CPU_ARM1022E) || defined(__TARGET_CPU_ARM926EJ_S) || \
    defined(__TARGET_CPU_XSCALE) || defined(__TARGET_CPU_SA_110) || \
    defined(__TARGET_CPU_ARM1026EJ_S) 
cleanDCache();
cleanFlushDCache();
cleanFlushCache();
#endif

#if defined(__TARGET_CPU_XSCALE)
cleanMiniDCache();
#endif

#if defined(__TARGET_CPU_SA_110)
cleanDCacheRegion();
flushDCacheRegion();
cleanFlushDCacheRegion();
#endif

#if defined(__TARGET_CPU_ARM920T) || defined(__TARGET_CPU_ARM922T) || \
    defined(__TARGET_CPU_ARM946E_S) || defined(__TARGET_CPU_ARM926EJ_S) || \
    defined(__TARGET_CPU_ARM1022E) ||  defined(__TARGET_CPU_ARM1026EJ_S) || \
    defined(__TARGET_CPU_XSCALE) 
flushICacheRegion(0x0, 0x100);
flushDCacheRegion(0x0, 0x100);
flushCacheRegion(0x0, 0x100);
cleanDCacheRegion(0x0, 0x100);
cleanFlushDCacheRegion(0x0, 0x100);
cleanFlushCacheRegion(0x0, 0x100);
#endif

#if defined(__TARGET_CPU_ARM920T) || defined(__TARGET_CPU_ARM922T) || \
    defined(__TARGET_CPU_ARM940T) || defined(__TARGET_CPU_ARM946E_S) || \
    defined(__TARGET_CPU_ARM926EJ_S) || defined(__TARGET_CPU_ARM1026EJ_S) || \
    defined(__TARGET_CPU_XSCALE) || defined(__TARGET_CPU_ARM1022E) 

lockDCache(0x0, 0x100); /* lock data in D-cache */
lockICache(0x0, 0x100); /* lock code in I-cache */
#endif

#if    defined(__TARGET_CPU_XSCALE)
lockDCacheRAM(0x0, 0x10); /* lock data in D-cache */
#endif

  cache_RRtest(10000,64);
  cache_RRtest(10000,65);

}