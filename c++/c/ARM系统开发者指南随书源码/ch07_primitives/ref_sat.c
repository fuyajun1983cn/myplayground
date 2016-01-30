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
 * Reference code for examples of section 7.7
 */
 
#include "ch07test.h"

#define MAXPOS (int32)(+0x7FFFFFFF)
#define MAXNEG (int32)(-0x80000000)

int32 ref_qsat_16(int32 a)
{
  if (a>=0x7FFF) return 0x7FFF;
  if (a<=-0x8000) return -0x8000;
  return a;
}

int32 ref_qshl_32(int32 b, int32 c)
{
  if (b>(MAXPOS>>c)) return MAXPOS;
  if (b<(MAXNEG>>c)) return MAXNEG;
  return b<<c;
}

/* rounded shift right - rounding up when at mid point */

int32 ref_qshr_32(int32 b, int32 c)
{
  int32 a;
  
  if (c==0) return b;
  
  a = b>>c;     /* integer part */
  b = b-(a<<c); /* remainder */
  if (b>=((int32)1<<(c-1)))
  {
    a++;
  }
  return a;
}

int32 ref_qadd_32(int32 b, int32 c)
{
  int64 a=(int64)b+(int64)c;
  
  if (a>=(int64)MAXPOS) return MAXPOS;
  if (a<=(int64)MAXNEG) return MAXNEG;
  return (int32)a;
}

int32 ref_qsub_32(int32 b, int32 c)
{
  int64 a=(int64)b-(int64)c;
  
  if (a>=(int64)MAXPOS) return MAXPOS;
  if (a<=(int64)MAXNEG) return MAXNEG;
  return (int32)a;
}

int32 ref_absa_32(int32 b, int32 c)
{
  if (c>=0) return b+c;
  return b-c;
}

int32 ref_qabs_32(int32 a)
{
  if (a<0)
  {
    a=-a;
  }
  /* trap the 0x80000000 case */
  if (a<0) return MAXPOS;
  return a;
}
