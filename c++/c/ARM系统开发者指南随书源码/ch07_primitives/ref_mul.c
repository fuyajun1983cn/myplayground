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
 * Reference code for examples of section 7.1
 */
 
#include "ch07test.h"

int64 ref_mul_64to64(int64 b, int64 c)
{
  return b*c;
}

__value_in_regs uint128 ref_umul_64to128(uint64 b, uint64 c)
{
  uint128 a;
  uint64 acc;
  uint32 b0,b1,c0,c1,carry;
  
  b0 = (uint32)b;
  b1 = (uint32)(b>>32);
  c0 = (uint32)c;
  c1 = (uint32)(c>>32);
  
  acc   = (uint64)b0*c0;
  a.a0  = (uint32)acc;
  carry = (uint32)(acc>>32);
  acc   = (uint64)b1*c0 + carry;
  a.a1  = (uint32)acc;
  a.a2  = (uint32)(acc>>32);
  
  acc   = (uint64)b0*c1 + a.a1;
  a.a1  = (uint32)acc;
  carry = (uint32)(acc>>32);
  acc   = (uint64)b1*c1 + a.a2 + carry;
  a.a2  = (uint32)acc;
  a.a3  = (uint32)(acc>>32);
  
  return a;
}

__value_in_regs sint128 ref_smul_64to128(sint64 b, sint64 c)
{
  sint128 a;
  uint64 acc;
  uint32 b0,c0,carry;
  sint32 b1,c1,scarry;
  
  b0 = (uint32)b;
  b1 = (sint32)(b>>32);
  c0 = (uint32)c;
  c1 = (sint32)(c>>32);
  
  acc   = (uint64)b0*c0;
  a.a0  = (uint32)acc;
  carry = (uint32)(acc>>32);
  acc   = (sint64)b1*(uint64)c0 + carry;
  a.a1  = (uint32)acc;
  a.a3  = (sint32)(acc>>32);
  
  acc   = (uint64)b0*(sint64)c1 + (uint64)a.a1;
  a.a1  = (uint32)acc;
  scarry= (sint32)(acc>>32);
  acc   = (sint64)b1*(sint64)c1 + a.a3 + scarry;
  a.a2  = (uint32)acc;
  a.a3  = (sint32)(acc>>32);
  
  return a;
}
