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

#ifndef CH07TEST_H
#define CH07TEST_H
 
/* Compile time options */
#define VERBOSE 0

/* Check armcc or gcc compiler */

#ifdef __ARMCC_VERSION
  /* armcc */
#else
  #define __value_in_regs
#endif

/* Data types */
typedef long int32;
typedef unsigned long uint32;
typedef signed long sint32;
typedef long long int64;
typedef unsigned long long uint64;
typedef signed long long sint64;
typedef struct { uint32 a0,a1,a2,a3; } uint128;
typedef struct { uint32 a0,a1,a2; sint32 a3; } sint128;
typedef struct { int32 a, b; } pair32;
 
/* Function types */
typedef int32 fn_u32(int32);            /* unary 32-bit */
typedef int32 fn_b32(int32, int32);     /* binary 32-bit */
typedef int64 fn_u64(int64);            /* unary 64-bit */
typedef int64 fn_b64(int64, int64);     /* binary 64-bit */
typedef __value_in_regs uint128 fn_b64to128(uint64,uint64);
typedef __value_in_regs sint128 fn_sb64to128(sint64,sint64);
typedef __value_in_regs pair32 fn_u32tob32(int32);
typedef __value_in_regs pair32 fn_b32tob32(int32,int32);
typedef __value_in_regs pair32 fn_32_64tob32(int32,int64);
 
/* Section 7.1 */
fn_b64 mul_64to64;
fn_b64 ref_mul_64to64;
fn_b64to128 umul_64to128_arm7m;
fn_b64to128 umul_64to128_arm9e;
fn_b64to128 ref_umul_64to128;
#define ref_umul_64to128_arm7m ref_umul_64to128
#define ref_umul_64to128_arm9e ref_umul_64to128
fn_sb64to128 smul_64to128;
fn_sb64to128 ref_smul_64to128;

/* Section 7.2 */
fn_u32tob32 unorm_arm9e;
fn_u32tob32 snorm_arm9e;
fn_u32tob32 unorm_arm7m;
fn_u32tob32 unorm_arm7m_hash;
fn_u32tob32 ref_unorm;
fn_u32tob32 ref_snorm;
#define ref_unorm_arm9e ref_unorm
#define ref_snorm_arm9e ref_snorm
#define ref_unorm_arm7m ref_unorm
#define ref_unorm_arm7m_hash ref_unorm
fn_u32 ctz_arm9e;
fn_u32 ctz_arm7m;
fn_u32 ref_ctz;
#define ref_ctz_arm9e ref_ctz
#define ref_ctz_arm7m ref_ctz

/* Section 7.3 */
unsigned udiv_simple(unsigned d, unsigned r, unsigned N);
fn_b32tob32 udiv_simple_test;
fn_b32tob32 udiv_32by32_arm7m;
fn_b32tob32 udiv_32by32_arm9e;
fn_b32tob32 ref_udiv_32by32;
#define ref_udiv_32by32_arm7m ref_udiv_32by32
#define ref_udiv_32by32_arm9e ref_udiv_32by32
#define ref_udiv_simple_test ref_udiv_32by32
fn_b32tob32 udiv_32by16_arm7m;
fn_b32tob32 ref_udiv_32by16;
#define ref_udiv_32by16_arm7m ref_udiv_32by16
fn_32_64tob32 udiv_64by32_arm7m;
fn_32_64tob32 ref_udiv_64by32;
#define ref_udiv_64by32_arm7m ref_udiv_64by32
fn_b32 udiv_q15_arm9e;
fn_b32 ref_udiv_q15;
#define ref_udiv_q15_arm9e ref_udiv_q15
fn_b32 udiv_q31_arm9e;
fn_b32 ref_udiv_q31;
#define ref_udiv_q31_arm9e ref_udiv_q31
fn_b32tob32 sdiv_32by32_arm7m;
fn_b32tob32 ref_sdiv_32by32;
#define ref_sdiv_32by32_arm7m ref_sdiv_32by32

/* Section 7.4 */
unsigned usqr_simple(unsigned r, unsigned N);
fn_u32 usqr_32;
fn_u32 usqr_simple_test;
fn_u32 ucbr_32;
fn_u32 rsqr_32;
fn_u32 ref_usqr_32;
fn_u32 ref_ucbr_32;
fn_u32 ref_rsqr_32;
#define ref_usqr_simple_test ref_usqr_32

/* Section 7.5 */
fn_u32 ref_ulog2_32;
fn_u32 ref_uexp2_32;
fn_u32 ref_sin_32;
fn_u32 ref_cos_32;
fn_u32 ulog2_32;
fn_u32 uexp2_32;
fn_u32 sin_32;
fn_u32 cos_32;

/* Section 7.6 */
fn_u32 byte_reverse_2reg;
fn_u32 byte_reverse;
fn_u32 ref_byte_reverse;
#define ref_byte_reverse_2reg ref_byte_reverse
fn_u32 bit_count;
fn_u32 ref_bit_count;
fn_u32 bit_reverse;
fn_u32 ref_bit_reverse;
fn_u32 bit_spread;
fn_u32 ref_bit_spread;
fn_u32 bit_rev_spread;
fn_u32 ref_bit_rev_spread;

/* Section 7.7 */
fn_u32 qsat_16;
fn_b32 qshl_32;
fn_b32 qshr_32;
fn_b32 qadd_32;
fn_b32 qsub_32;
fn_b32 absa_32;
fn_u32 qabs_32;
fn_u32 ref_qsat_16;
fn_b32 ref_qshl_32;
fn_b32 ref_qshr_32;
fn_b32 ref_qadd_32;
fn_b32 ref_qsub_32;
fn_b32 ref_absa_32;
fn_u32 ref_qabs_32;

/* Section 7.8 */
fn_u32 rand_32;

/* Test value generators and output */
fn_u32 gen_shift;
fn_u32 gen_s32;
fn_u32 gen_u31;
fn_u32 gen_u15;
fn_u32 gen_s32_ctz;
fn_u64 gen_s64;         /* signed 64 bit generator */
void print128(uint128 a); /* print 128 bit values */

/* Test binary 64-bit functions with unary 64 bit result */
int test_b64(
  char *name,           /* function name */
  fn_b64 *ref,          /* reference to test against */
  fn_b64 *fn,           /* function to test */
  fn_u64 *nextb,        /* generator for "b" values */
  fn_u64 *nextc,        /* generator for "c" values */
  int maxerr            /* maximum error alowed */
);

#define TEST_B64(name, nextb, nextc, maxerr) errors += test_b64(#name, &ref_##name, &name, nextb, nextc, maxerr);
  
/* Test binary 64-bit functions with unary 128 bit result */
int test_b64to128(
  char *name,           /* function name */
  fn_b64to128 *ref,          /* reference to test against */
  fn_b64to128 *fn,           /* function to test */
  fn_u64 *nextb,        /* generator for "b" values */
  fn_u64 *nextc,        /* generator for "c" values */
  int maxerr            /* maximum error alowed */
);
#define TEST_B64TO128(name, nextb, nextc, maxerr) errors += test_b64to128(#name, (fn_b64to128*)(&ref_##name), (fn_b64to128*)(&name), nextb, nextc, maxerr);

/* Test unary 32-bit functions with binary 32-bit result */
int test_u32tob32(
  char *name,           /* function name */
  fn_u32tob32 *ref,     /* reference to test against */
  fn_u32tob32 *fn,      /* function to test */
  fn_u32 *nextb,        /* generator for "b" values */
  int maxerr            /* maximum error alowed */
);
#define TEST_U32TOB32(name, nextb, maxerr) errors += test_u32tob32(#name, &ref_##name, &name, nextb, maxerr);

/* Test binary 32-bit functions with binary 32-bit result */
int test_b32tob32(
  char *name,           /* function name */
  fn_b32tob32 *ref,     /* reference to test against */
  fn_b32tob32 *fn,      /* function to test */
  fn_u32 *nextb,        /* generator for "b" values */
  fn_u32 *nextc,        /* generator for "c" values */
  int maxerr            /* maximum error alowed */
);
#define TEST_B32TOB32(name, nextb, nextc, maxerr) errors += test_b32tob32(#name, &ref_##name, &name, nextb, nextc, maxerr);

/* Test binary 32-bit,64-bit functions with binary 32-bit result */
int test_32_64tob32(
  char *name,           /* function name */
  fn_32_64tob32 *ref,     /* reference to test against */
  fn_32_64tob32 *fn,      /* function to test */
  fn_u32 *nextb,        /* generator for "b" values */
  fn_u64 *nextc,        /* generator for "c" values */
  int maxerr            /* maximum error alowed */
);
#define TEST_32_64TOB32(name, nextb, nextc, maxerr) errors += test_32_64tob32(#name, &ref_##name, &name, nextb, nextc, maxerr);

/* Test unary 32-bit functions with unary 32-bit result */
int test_u32(
  char *name,           /* function name */
  fn_u32 *ref,          /* reference to test against */
  fn_u32 *fn,           /* function to test */
  fn_u32 *nextb,        /* generator for "b" values */
  int maxerr            /* maximum error alowed */
);
#define TEST_U32(name, nextb, maxerr) errors += test_u32(#name, &ref_##name, &name, nextb, maxerr);

/* Test binary 32-bit functions with unary 32-bit result */
int test_b32(
  char *name,           /* function name */
  fn_b32 *ref,          /* reference to test against */
  fn_b32 *fn,           /* function to test */
  fn_u32 *nextb,        /* generator for "b" values */
  fn_u32 *nextc,        /* generator for "c" values */
  int maxerr            /* maximum error alowed */
);
#define TEST_B32(name, nextb, nextc, maxerr) errors += test_b32(#name, &ref_##name, &name, nextb, nextc, maxerr);

/* Test a random number generator */
int test_rand(
  char *name,           /* function name */
  fn_u32 *fn            /* function to test */
);
#define TEST_RAND(name) errors += test_rand(#name, &name);

#endif
