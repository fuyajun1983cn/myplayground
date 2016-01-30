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

#include "regions.h"
#include "protection.h"

/* Region Number Assignment */
#define  KERNEL 1 
#define  TASK  2 
#define  SHARED 3 
#define  PERIPH  4 


/*                  REGION NUMBER,   APTYPE, START ADDRESS, SIZE,  IAP,  DAP,  CB */

Region peripheralRegion = {PERIPH, STANDARD, 0x10000000, SIZE_1M , RONA, RWNA, ccb};
Region kernelRegion =     {KERNEL, STANDARD, 0x00000000, SIZE_4G , RONA, RWNA, CWT}; 
Region sharedRegion =     {SHARED, STANDARD, 0x00010000, SIZE_64K, RORO, RWRW, CWT};
Region task1Region  =     {TASK  , STANDARD, 0x00020000, SIZE_32K, RORO, RWRW, CWT};
Region task2Region  =     {TASK  , STANDARD, 0x00028000, SIZE_32K, RORO, RWRW, CWT};
Region task3Region  =     {TASK  , STANDARD, 0x00030000, SIZE_32K, RORO, RWRW, CWT};

/*
 * Main
 */

int main()
{

   initActiveRegions();
   enableMPU();

/* call  scheduler here */

   return 0;
}


/*
 * Chapter 13 Example 13.6
 */
 
void configRegion(Region *region)
{
/*
 * Step 1 - Define the size and location of the instruction
 *          and data regions using CP15:c6
 */

  regionSet(region->number, region->baseaddress, 
            region->size, R_DISABLE);

/* 
 * Step 2 - Set access permission for each region using CP15:c5
 */

  if (region->type == STANDARD) 
  {
    regionSetISAP(region->number, region->IAP);
    regionSetDSAP(region->number, region->DAP);
  }
  else if (region->type == EXTENDED)
  {
    regionSetIEAP(region->number, region->IAP);
    regionSetDEAP(region->number, region->DAP);
  }

/* 
 * Step 3 - Set the cache and write buffer attributes
 *          for each region using CP15:c2 for cache
 *          and CP15:c3 for the write buffer.
 */
 
   regionSetCB(region->number, region->CB);

/* 
 * Step 4 - Enable the caches, write buffer and the MPU
 *          using CP15:c6 and CP15:c1
 */

  regionSet(region->number, region->baseaddress, 
            region->size, R_ENABLE);
}

/*
 * Chapter 13 Example 13.7
 */
 
 void initActiveRegions()
{
  configRegion(&kernelRegion);
  configRegion(&sharedRegion);
  configRegion(&peripheralRegion);
  configRegion(&task1Region);
}

void enableMPU(void)
{
  unsigned int value, mask;
  
  value = ENABLEMPU | ENABLEDCACHE | ENABLEICACHE;
  mask = MASKMPU | MASKDCACHE | MASKICACHE;
  controlSet(value, mask);
}
