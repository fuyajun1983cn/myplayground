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
 * Reference code for examples of section 7.3
 */
 
#include "ch07test.h"

unsigned udiv_simple(unsigned d, unsigned n, unsigned N)
{
  unsigned q=0, r=n;
  
  do
  {                     /* calculate next quotient bit */
    N--;                /* move to next bit */
    if ( (r>>N) >= d )  /* if r>=d*(1<<N) */
    {
      r -= (d<<N);      /* update remainder */
      q += (1<<N);      /* update quotient */
    }
  } while (N);
  
  return q;
}

__value_in_regs pair32 udiv_simple_test(int32 a, int32 b)
{
  pair32 ans;
  
  if (a==0)
  {
    ans.a = -1;
    ans.b = -1;
  }
  else 
  {
    ans.a = udiv_simple((unsigned)a,(unsigned)b,32);
    ans.b = b-a*ans.a;
  }
  return ans;
}

__value_in_regs pair32 ref_udiv_32by32(int32 a, int32 b)
{
  uint32 d=a, n=b;
  pair32 r;
  
  if (d==0)
  {
    r.a=-1;
    r.b=-1;
  } else {
    r.a = n/d;
    r.b = n%d;
  }
  return r;
}

__value_in_regs pair32 ref_sdiv_32by32(int32 a, int32 b)
{
  sint32 d=a, n=b;
  pair32 r;
  
  if (d==0)
  {
    if (n<0)
    {
      r.a=+1;
      r.b=+1;
    }
    else
    {
      r.a=-1;
      r.b=-1;
    }
  } else {
    r.a = n/d;
    r.b = n%d;
  }
  return r;
}

__value_in_regs pair32 ref_udiv_32by16(int32 a, int32 b)
{
  uint32 d=a, n=b;
  pair32 r;
  
  if ((n>>15)>=d)
  {
    r.a = 0x7FFF;
    r.b = 0x7FFF;
  } else {
    r.a = n/d;
    r.b = n%d;
  }
  return r;
}

__value_in_regs pair32 ref_udiv_64by32(int32 a, int64 b)
{
  uint64 d=(unsigned)a;
  uint64 n=b;
  pair32 r;
  
  if ((n>>32)>=d)
  {
    r.a=-1;
    r.b=-1;
  }
  else 
  {
    r.a=(int32)(n/d);
    r.b=(int32)(n%d);
  }
  return r;
}

int32 ref_udiv_q15(int32 a, int32 b)
{
  uint32 d=(uint32)a, n=(uint32)b;
  
  if (n>=d)
  {
    return 0x7FFF;
  }
  else
  {
    return (n<<15)/d;
  }
}

int32 ref_udiv_q31(int32 a, int32 b)
{
  uint32 d=(uint32)a, n=(uint32)b;
  
  if (n>=d)
  {
    return 0x7FFFFFFF;
  }
  else
  {
    return (uint32)(((uint64)n<<31)/d);
  }
}
