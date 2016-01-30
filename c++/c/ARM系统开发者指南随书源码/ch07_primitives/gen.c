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
 * Generate test data
 */

#include <stdio.h>
#include <math.h>
#include "ch07test.h"

/* Generate signed 32-bit test data
 * 0,-1,1,-2,2,..,+MAX,-MAX in exponential trend
 */

int32 gen_s32(int32 seed)
{
  int32 n;
  
  seed = ~seed;
  if (seed<0) return seed;
  if (seed<8) return (seed+1);
  n = seed + (seed>>1);
  if (n<0)
  {
    n = 0x7FFFFFFFul;
  }
  if (n>seed) return n;
  return 0;
}

/* generate shifts */

int32 gen_shift(int32 seed)
{
  seed++;
  return seed & 31;
}

/* generate unsigned 31 bit data */

int32 gen_u31(int32 seed)
{
  int32 n;
  
  if (seed<8) return (seed+1);
  n = seed + (seed>>1);
  if (n<0)
  {
    n = 0x7FFFFFFFul;
  }
  if (n>seed) return n;
  return 0;
}

/* generate unsigned 15 bit data */

int32 gen_u15(int32 seed)
{
  int32 n;
  
  if (seed<8) return (seed+1);
  n = seed + (seed>>1);
  if (n>0x7FFF)
  {
    n = 0x7FFFul;
  }
  if (n>seed) return n;
  return 0;
}

/* Generate 32-bit test data for trailing zeros test */

int32 gen_s32_ctz(int32 seed)
{
  if (seed & 1) return 0;
  seed = (seed>>1) | (1u<<31);
  seed = seed+(seed<<1);
  return seed;
}

/* Generate signed 64-bit test data
 * 0,-1,1,-2,2,..,+MAX,-MAX in exponential trend
 */

int64 gen_s64(int64 seed)
{
  int64 n;
  
  seed = ~seed;
  if (seed<0) return seed;
  if (seed<8) return (seed+1);
  n = seed + (seed>>1);
  if (n<0)
  {
    n = 0x7FFFFFFFFFFFFFFFull;
  }
  if (n>seed) return n;
  return 0;
}

void print128(uint128 a)
{
  printf("%08lx %08lx %08lx %08lx", a.a3, a.a2, a.a1, a.a0);
}
