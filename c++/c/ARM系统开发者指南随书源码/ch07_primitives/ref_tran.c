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
 * Reference code for examples of section 7.5 (Transcendental functions)
 */
 
#include "ch07test.h"
#include <math.h>

static const double T16 = (double)(1<<16);
static const double T26 = (double)(1<<26);
static const double T28 = (double)(1<<28);
static const double T30 = (double)(1u<<30);
static const double T31 = (double)(1u<<31);
static const double PI  = 3.14159265358;

static unsigned uround(double d)
{
  return (unsigned int)(d+0.5);
}

static int round(double d)
{
  if (d>=0)
  {
    return (int)(d+0.5);
  }
  else
  {
    return (int)(d-0.5);
  }
}

/* input Q0, output Q26 */

int32 ref_ulog2_32(int32 a)
{
  uint32 n=a;
  
  if (n==0) return -0x03ffffff;
  return uround(log((double)n)/log(2)*T26);
}

/* input Q26, output Q0 */

int32 ref_uexp2_32(int32 n)
{
   double d;
   
   if (n<0) return 0;
   d = (double)n/T26;
   d = exp(d*log(2.0));
   return uround(d);
}

/* input Q32 of a circle, output Q30 */

int32 ref_sin_32(int32 n)
{
  double a= PI*(double)n/T31;
  return round(sin(a)*T30);
}

/* input Q32 of a circule, output Q30 */

int32 ref_cos_32(int32 n)
{
  double a=PI*(double)n/T31;
  return round(cos(a)*T30);
}
