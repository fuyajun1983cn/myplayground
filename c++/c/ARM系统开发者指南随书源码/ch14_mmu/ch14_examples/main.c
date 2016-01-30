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

#include <stdio.h>
#include <string.h>

#include "regions.h"
#include "mmu.h"


void mmuInit(void);

int main()
{
   mmuInit();

/* Place Scheduler Here */

   return 0; 
} /* end main */
  
/*
 * Chapter 14 Example 14.12
 */

void mmuInit()
{
  unsigned int enable, change;

  /* Step 1 Initialize system (fixed) page tables */
  mmuInitPT(&masterPT);      /* init master L1 PT with FAULT PTE */
  mmuInitPT(&systemPT);      /* init system L2 PT with FAULT PTE */
  mmuInitPT(&task3PT);       /*  init task 3 L2 PT with FAULT PTE */
  mmuInitPT(&task2PT);      /*  init task 2 L2 PT with FAULT PTE */
  mmuInitPT(&task1PT);      /*  init task 1 L2 PT with FAULT PTE */

  /* Step 2 filling page tables with translation and attribute data */
  mmuMapRegion(&kernelRegion);       /* Map kernelRegion SystemPT */
  mmuMapRegion(&sharedRegion);       /* Map sharedRegion SystemPT */
  mmuMapRegion(&pageTableRegion);  /* Map pagetableRegion SystemPT */
  mmuMapRegion(&peripheralRegion); /* Map peripheralRegion MasterPT */

  mmuMapRegion(&t3Region);       /* Map task3 PT with Region data */
  mmuMapRegion(&t2Region);       /* Map task3 PT with Region data */
  mmuMapRegion(&t1Region);       /* Map task3 PT with Region data */
   
  /* Step 3 activating page tables */
  mmuAttachPT(&masterPT);   /* load L1 TTB to cp15:c2:c0 register */
  mmuAttachPT(&systemPT);        /* load L2 system PTE into L1 PT */
  mmuAttachPT(&task1PT);  /* Step 3 load L2 task 1 PTE into L1 PT */

  /* Step 4 Set Domain Access */

  domainAccessSet(DOM3CLT , CHANGEALLDOM); /* set Domain Access */

  /* Step 5 Enable MMU, caches and write buffer */
  #if defined(__TARGET_CPU_ARM720T) 
    enable = ENABLEMMU | ENABLECACHE | ENABLEWB ;
    change = CHANGEMMU | CHANGECACHE | CHANGEWB ;
  #endif
  #if defined(__TARGET_CPU_ARM920T) 
    enable = ENABLEMMU | ENABLEICACHE | ENABLEDCACHE ;
    change = CHANGEMMU | CHANGEICACHE | CHANGEDCACHE ;
  #endif
  controlSet(enable, change);            /* enable cache and MMU */
}

