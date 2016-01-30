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
 * Test module for the example routines of Chapter 7
 */
 
#include <stdio.h>
#include "ch07test.h"

int main(void)
{
  int errors=0;

  printf("Testing examples for Chapter 7\n");

  /* Section 7.1 */
  TEST_B64(mul_64to64, gen_s64, gen_s64, 1);
  TEST_B64TO128(umul_64to128_arm7m, gen_s64, gen_s64, 1);
  TEST_B64TO128(umul_64to128_arm9e, gen_s64, gen_s64, 1);
  TEST_B64TO128(smul_64to128, gen_s64, gen_s64, 1);
  /* Section 7.2 */
  TEST_U32TOB32(unorm_arm9e, gen_s32, 1);
  TEST_U32TOB32(snorm_arm9e, gen_s32, 1);
  TEST_U32TOB32(unorm_arm7m, gen_s32, 1);
  TEST_U32TOB32(unorm_arm7m_hash, gen_s32, 1);
  TEST_U32(ctz_arm9e, gen_s32_ctz, 1);
  TEST_U32(ctz_arm7m, gen_s32_ctz, 1);
  /* Section 7.3 */
  TEST_B32TOB32(udiv_simple_test, gen_s32, gen_s32, 1);
  TEST_B32TOB32(udiv_32by32_arm7m, gen_s32, gen_s32, 1);
  TEST_B32TOB32(udiv_32by16_arm7m, gen_u15, gen_s32, 1);
  TEST_32_64TOB32(udiv_64by32_arm7m, gen_u31, gen_s64, 1);
  TEST_B32TOB32(udiv_32by32_arm9e, gen_s32, gen_s32, 1);
  TEST_B32(udiv_q15_arm9e, gen_u15, gen_u31, 1);
  TEST_B32(udiv_q31_arm9e, gen_u31, gen_s32, 1);
  TEST_B32TOB32(sdiv_32by32_arm7m, gen_s32, gen_s32, 1);
  /* Section 7.4 */
  TEST_U32(usqr_simple_test, gen_s32, 1);
  TEST_U32(usqr_32, gen_s32, 1);
  TEST_U32(ucbr_32, gen_s32, 1);
  TEST_U32(rsqr_32, gen_s32, 2);
  /* Section 7.5 */
  TEST_U32(ulog2_32, gen_s32, 2);
  TEST_U32(uexp2_32, gen_s32, 4);
  TEST_U32(sin_32, gen_s32, 4);
  TEST_U32(cos_32, gen_s32, 4);
  /* Section 7.6 */
  TEST_U32(byte_reverse, gen_s32, 1);
  TEST_U32(byte_reverse_2reg, gen_s32, 1);
  TEST_U32(bit_count, gen_s32, 1);
  TEST_U32(bit_reverse, gen_s32, 1);
  TEST_U32(bit_spread, gen_s32, 1);
  TEST_U32(bit_rev_spread, gen_s32, 1);
  /* Section 7.7 */
  TEST_U32(qsat_16, gen_s32, 1);
  TEST_B32(qshl_32, gen_s32, gen_shift, 1);
  TEST_B32(qshr_32, gen_s32, gen_shift, 1);
  TEST_B32(qadd_32, gen_s32, gen_s32, 1);
  TEST_B32(qsub_32, gen_s32, gen_s32, 1);
  TEST_B32(absa_32, gen_s32, gen_s32, 1);
  TEST_U32(qabs_32, gen_s32, 1);
  /* Section 7.8 */
  TEST_RAND(rand_32);
    
  if (errors)
  {
    printf("Test finished with %d errors.\n", errors);
    return 1;
  }
  else
  {
    printf("Test passed.\n");
  }
  return 0;
}

int test_b64(
  char *name,           /* function name */
  fn_b64 *ref,          /* reference to test against */
  fn_b64 *fn,           /* function to test */
  fn_u64 *nextb,        /* generator for "b" values */
  fn_u64 *nextc,        /* generator for "c" values */
  int maxerr            /* maximum error alowed */
)
{
  int64 b=0,c=0,out,refout,d;
  int err=0;
  
  printf("Testing function: %s\n", name);
  
  do
  {
#if VERBOSE
    printf("b = %016llx\n", b);
#endif
    do
    {
      /* test the function */
      refout = (*ref)(b,c);
      out = (*fn)(b,c);
      d = out-refout;
      if (d<0) d=-d;
      if (d>=maxerr)
      {
        printf("FAIL %s(%016llx, %016llx) = ", name, b, c);
        printf("%016llx (ref: %016llx)\n", out, refout);
        err++;
      }
      c = (*nextc)(c);
    } while (c);
    
    b = (*nextb)(b);
  } while (b);

  return err;
}

int test_b64to128(
  char *name,           /* function name */
  fn_b64to128 *ref,     /* reference to test against */
  fn_b64to128 *fn,      /* function to test */
  fn_u64 *nextb,        /* generator for "b" values */
  fn_u64 *nextc,        /* generator for "c" values */
  int maxerr            /* maximum error alowed */
)
{
  int64 b=0,c=0;
  uint128 refout, out;
  int d;
  int err=0;
  
  printf("Testing function: %s\n", name);
  
  do
  {
#if VERBOSE
    printf("b = %016llx\n", b);
#endif
    do
    {
      /* test the function */
      refout = (*ref)(b,c);
      out = (*fn)(b,c);
      d = (int)(out.a0-refout.a0);
      if (d<0) d=-d;
      if (out.a1!=refout.a1 ||
          out.a2!=refout.a2 ||
          out.a3!=refout.a3 ||
          d>=maxerr)
      {
        printf("FAIL %s(%016llx, %016llx)\n", name, b, c);
        printf("  out: ");
        print128(out);
        printf("\n  ref: ");
        print128(refout);
        printf("\n");
        err++;
      }
      c = (*nextc)(c);
    } while (c);
    
    b = (*nextb)(b);
  } while (b);

  return err;
}

int test_b32tob32(
  char *name,           /* function name */
  fn_b32tob32 *ref,     /* reference to test against */
  fn_b32tob32 *fn,      /* function to test */
  fn_u32 *nextb,        /* generator for "b" values */
  fn_u32 *nextc,        /* generator for "c" values */
  int maxerr            /* maximum error alowed */
)
{
  int32 b=0, c=0;
  pair32 refout, out;
  int d;
  int err=0;
  
  printf("Testing function: %s\n", name);
  
  do
  {
#if VERBOSE
    printf("b = %08lx\n", b);
#endif
    do
    {
      /* test the function */
      refout = (*ref)(b,c);
      out = (*fn)(b,c);
      d = (int)(out.a-refout.a);
      if (d<0) d=-d;
      if (out.b!=refout.b || d>=maxerr)
      {
        printf("FAIL %s(%08lx,%08lx) = ", name, b, c);
        printf("%08lx %08lx ", out.a, out.b);
        printf("(ref: %08lx %08lx)\n", refout.a, refout.b);
        err++;
      }
      c = (*nextc)(c);
    } while (c);
    
    b = (*nextb)(b);
  } while (b);

  return err;
}

int test_32_64tob32(
  char *name,           /* function name */
  fn_32_64tob32 *ref,     /* reference to test against */
  fn_32_64tob32 *fn,      /* function to test */
  fn_u32 *nextb,        /* generator for "b" values */
  fn_u64 *nextc,        /* generator for "c" values */
  int maxerr            /* maximum error alowed */
)
{
  int32 b=0;
  int64 c=0;
  pair32 refout, out;
  int d;
  int err=0;
  
  printf("Testing function: %s\n", name);
  
  do
  {
#if VERBOSE
    printf("b = %08lx\n", b);
#endif
    do
    {
      /* test the function */
      refout = (*ref)(b,c);
      out = (*fn)(b,c);
      d = (int)(out.a-refout.a);
      if (d<0) d=-d;
      if (out.b!=refout.b || d>=maxerr)
      {
        printf("FAIL %s(%08lx,%016llx) = ", name, b, c);
        printf("%08lx %08lx ", out.a, out.b);
        printf("(ref: %08lx %08lx)\n", refout.a, refout.b);
        err++;
      }
      c = (*nextc)(c);
    } while (c);
    
    b = (*nextb)(b);
  } while (b);

  return err;
}

int test_u32tob32(
  char *name,           /* function name */
  fn_u32tob32 *ref,     /* reference to test against */
  fn_u32tob32 *fn,      /* function to test */
  fn_u32 *nextb,        /* generator for "b" values */
  int maxerr            /* maximum error alowed */
)
{
  int32 b=0;
  pair32 refout, out;
  int d;
  int err=0;
  
  printf("Testing function: %s\n", name);
  
  do
  {
#if VERBOSE
    printf("b = %08lx\n", b);
#endif
    /* test the function */
    refout = (*ref)(b);
    out = (*fn)(b);
    d = (int)(out.a-refout.a);
    if (d<0) d=-d;
    if (out.b!=refout.b || d>=maxerr)
    {
      printf("FAIL %s(%08lx) = ", name, b);
      printf("%08lx %08lx ", out.a, out.b);
      printf("(ref: %08lx %08lx)\n", refout.a, refout.b);
      err++;
    }
    
    b = (*nextb)(b);
  } while (b);

  return err;
}

int test_u32(
  char *name,           /* function name */
  fn_u32 *ref,     /* reference to test against */
  fn_u32 *fn,      /* function to test */
  fn_u32 *nextb,        /* generator for "b" values */
  int maxerr            /* maximum error alowed */
)
{
  int32 b=0;
  int32 refout, out;
  int d;
  int err=0;
  
  printf("Testing function: %s\n", name);
  
  do
  {
#if VERBOSE
    printf("b = %08lx\n", b);
#endif
    /* test the function */
    refout = (*ref)(b);
    out = (*fn)(b);
    d = (int)(out-refout);
    if (d<0) d=-d;
    if (d>=maxerr)
    {
      printf("FAIL %s(%08lx) = ", name, b);
      printf("%08lx ", out);
      printf("(ref: %08lx)\n", refout);
      err++;
    }
    
    b = (*nextb)(b);
  } while (b);

  return err;
}

int test_b32(
  char *name,           /* function name */
  fn_b32 *ref,          /* reference to test against */
  fn_b32 *fn,           /* function to test */
  fn_u32 *nextb,        /* generator for "b" values */
  fn_u32 *nextc,        /* generator for "c" values */
  int maxerr            /* maximum error alowed */
)
{
  int32 b=0, c=0;
  int32 refout, out;
  int d;
  int err=0;
  
  printf("Testing function: %s\n", name);
  
  do
  {
#if VERBOSE
    printf("b = %08lx\n", b);
#endif
    do
    {
      /* test the function */
      refout = (*ref)(b,c);
      out = (*fn)(b,c);
      d = (int)(out-refout);
      if (d<0) d=-d;
      if (d>=maxerr)
      {
        printf("FAIL %s(%08lx,%08lx) = ", name, b, c);
        printf("%08lx ", out);
        printf("(ref: %08lx)\n", refout);
        err++;
      }
      c = (*nextc)(c);
    } while (c);
    
    b = (*nextb)(b);
  } while (b);

  return err;
}

#define RANDSIZE 10     /* generate random numbers between 0 and 10 */

int test_rand(
  char *name,           /* function name */
  fn_u32 *fn            /* function to test */
)
{
  /* Test a random number generator using Chi Squared test */
  /* See Knuth Seminumerical Algorithms, Section 3.3.1 for the theory */
  unsigned i, n;
  unsigned bins[RANDSIZE];
  
  for (i=0; i<RANDSIZE; i++)
  {
    bins[i]=0;
  }
  
  printf("Testing function: %s\n", name);

  n = RANDSIZE*100;
  for (i=0; i<n; i++)
  {
    unsigned r;
    
    r = (unsigned)(*fn)(RANDSIZE);        /* generate the random number */
    if (r>=RANDSIZE)
    {
      printf("Random number not in range %d\n", r);
      return 1;
    }
#if VERBOSE
    if (i<40) printf("%ld ", (*fn)(10));
#endif
    bins[r]++;
  }
#if VERBOSE
  printf("\n");
#endif
  
  /* now work out the Chi Square */
  {
    unsigned sum=0;
    double chi;
    
    for (i=0; i<RANDSIZE; i++)
    {
#if VERBOSE
      printf("Frequency[%d] = %d\n", i, bins[i]);
#endif
      sum += bins[i]*bins[i];
    }
    chi = (double)RANDSIZE*(double)sum/(double)n - (double)n;
#if VERBOSE
    printf("Chi square = %lf\n", chi);
#endif
    /* check probability of this Chi Square is between 25% and 75% */
    if (chi < 5.0 || chi > 12.0 )
    {
      printf("Chi square not in correct range: %lf\n", chi);
      return 1;
    }
  }
  return 0;
}
