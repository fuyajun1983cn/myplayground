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
 * Reference code for examples of section 7.6
 */
 
#include "ch07test.h"

int32 ref_byte_reverse(int32 a)
{
  int32 b=0;
  unsigned i;
  
  for (i=4; i!=0; i--)
  {
    b = (b<<8) | (a & 0xFF);
    a = a>>8;
  }

  return b;
}

int32 ref_bit_count(int32 a)
{
  int32 b=0;
  unsigned i;
  
  for (i=32; i!=0; i--)
  {
    b += a&1;
    a = a>>1;
  }
  return b;
}

int32 ref_bit_reverse(int32 a)
{
  int32 b=0;
  unsigned i;
  
  for (i=0; i<32; i++)
  {
    if (a&((int32)1u<<i))
    {
      b |= (int32)1u<<(31-i);
    }
  }
  return b;
}

int32 ref_bit_spread(int32 a)
{
  int32 b=0;
  unsigned i;
  
  for (i=0; i<32; i++)
  {
    if (a&((int32)1u<<i))
    {
      int j=2*i;
      if (j>=32) j-=31;
      b |= (int32)1u<<j;
    }
  }
  return b;
}

int32 ref_bit_rev_spread(int32 a)
{
  int32 b=0;
  unsigned i;
  
  for (i=0; i<32; i++)
  {
    if (a&((int32)1u<<i))
    {
      int j=2*i;
      if (j>=32)
      {
        j=63-j;
      }
      else
      {
        j=30-j;
      }
      b |= (int32)1u<<j;
    }
  }
  return b;
}
