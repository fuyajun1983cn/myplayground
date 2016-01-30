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
 
 /*
  *  Example 12.1
  */
  
#include <stdio.h>
#include <time.h>

void cache_RRtest(unsigned int, unsigned int);
int readSet(unsigned int, unsigned int);
extern int enableRoundRobin(void);
extern int enableRandom(void);
extern void cleanFlushCache(void);


void cache_RRtest(unsigned int times,unsigned int numset)
{
   clock_t count;
   printf("Round Robin test size = %d\r\n", numset);
   enableRoundRobin();
   cleanFlushCache();
   count = clock();
   readSet(times,numset);
   count = clock() - count;
   printf("Round Robin enabled = %.2f seconds\r\n",
                     (float)count/CLOCKS_PER_SEC);
   enableRandom();
   cleanFlushCache();
   count = clock();
   readSet(times, numset);
   count = clock() - count;
   printf("Random enabled = %.2f seconds\r\n\r\n",
                      (float)count/CLOCKS_PER_SEC);
}

int readSet( unsigned int times, unsigned int numset)
{
   int setcount, value;
   volatile int *newstart;
   volatile int *start = (int *)0x20000;
   __asm
   {
      timesloop:
        MOV     newstart, start
        MOV     setcount, numset
      setloop:
        LDR     value,[newstart,#0];
        ADD     newstart,newstart,#0x40;
        SUBS    setcount, setcount, #1;
        BNE     setloop;
        SUBS    times, times, #1;
        BNE     timesloop;
   }
   return value;
}