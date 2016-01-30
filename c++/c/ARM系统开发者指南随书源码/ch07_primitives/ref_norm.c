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
 * Reference code for examples of section 7.2
 */
 
#include "ch07test.h"

__value_in_regs pair32 ref_unorm(int32 a)
{
  pair32 r;
  uint32 x, shift;
  
  x=a;
  if (x==0)
  {
    shift=32;
  }
  else
  {
    shift=0;
    while (x<0x80000000ul)
    {
      x<<=1;
      shift++;
    }
  }
    
  r.a = x;
  r.b = shift;
  
  return r;
}

__value_in_regs pair32 ref_snorm(int32 a)
{
  pair32 r;
  sint32 x, shift;
  
  x=a;
  if (x==0)
  {
    shift=32;
  }
  else
  {
    shift=0;
    while (-(1<<30)<=x && x<(1<<30))
    {
      x<<=1;
      shift++;
    }
  }
    
  r.a = x;
  r.b = shift;
  
  return r;
}

/* count trailing zeros */

int32 ref_ctz(int32 a)
{
  uint32 x = a;
  int shift=0;
  while ((x&1)==0)
  {
    x = (x>>1) | (1u<<31);
    shift++;
  }
  return shift;
}
