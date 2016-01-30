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
 * Test module for the example routines of Chapter 6
 */

#ifndef CH06TEST_H
#define CH06TEST_H
 
/* Compile time options */
#define VERBOSE 1

/* Data types */
typedef signed char int8;
typedef short int16;
typedef long int32;
typedef unsigned long uint32;
typedef signed long sint32;
typedef long long int64;
typedef unsigned long long uint64;
typedef signed long long sint64;
typedef double real;

/* Function types */
typedef void fn_tolower(char *out, char *in);
typedef unsigned fn_shift(unsigned *out, unsigned *in, unsigned N, unsigned k);
typedef void fn_scale(int *out, int *in, unsigned shift);
typedef void fn_merge(char *pz, char *px, char *py, unsigned a);
typedef void fn_memset(char *s, unsigned int c, unsigned int N);
typedef void fn_matrix_mul(int *a, int *b, int *c);
typedef char *fn_bit_write(char *bitstream, int *codes, char *code_lens);
typedef int  *fn_bit_read(char *bitstream, int *codes, int *look_code, char *look_codebits);
typedef int fn_switch(int type);
typedef int fn_load(char *data);
typedef void fn_store(char *data, int x);
typedef int fn_checksum(char *data, unsigned int N);

/* Section 6.2 */
void gen_str(char *out, int len);
fn_tolower str_tolower;
fn_tolower str_tolower_preload;
fn_tolower str_tolower_unrolled;

/* Section 6.3 */
void gen_bytes(char *out, int len);
fn_shift ref_shift_bits;
fn_shift shift_bits;
fn_scale shift_right;
fn_merge ref_merge_images;
fn_merge merge_images;
#define IMAGE_SIZE (176*144) /* QCIF image size */

/* Section 6.5 */
fn_memset my_memset;
fn_matrix_mul matrix_mul;
fn_matrix_mul ref_matrix_mul;

/* Section 6.6 */
fn_bit_write bitstream_write_test;
fn_bit_read bitstream_read_test;

/* Section 6.7 */
fn_switch switch_absolute;
fn_switch switch_relative;
fn_switch switch_hash;
fn_switch ref_switch;
fn_switch ref_switch_hash;
#define ref_switch_absolute ref_switch
#define ref_switch_relative ref_switch

/* Section 6.8 - unaligned data */
fn_checksum checksum_32_little;
fn_checksum ref_checksum_32_little;
fn_load load_32_little;
fn_load load_32_big;
fn_store store_32_little;
fn_store store_32_big;
int ref_read_32_little(char *p);
int ref_read_32_big(char *p);

/* Test string to lower function */
int test_tolower(
  char *name,           /* function name */
  fn_tolower *fn          /* function to test */
);

#define TEST_TOLOWER(name) errors += test_tolower(#name, &name);

/* Test bit shifting function */
int test_shift(
  char *name,           /* function name */
  fn_shift *fn          /* function to test */
);

#define TEST_SHIFT(name) errors += test_shift(#name, &name);

/* Test right shift/scaling function */
int test_scale(
  char *name,           /* function name */
  fn_scale *fn          /* function to test */
);

#define TEST_SCALE(name) errors += test_scale(#name, &name);

/* Test image merging */
int test_merge(
  char *name,           /* function name */
  fn_merge *fn          /* function to test */
);

#define TEST_MERGE(name) errors += test_merge(#name, &name);

/* Test a MEMSET function */
int test_memset(
  char *name,           /* function name */
  fn_memset *fn         /* function to test */
);

#define TEST_MEMSET(name) errors += test_memset(#name, &name);

/* Test matrix multiply function */
int test_matrix_mul(
  char *name,           /* function name */
  fn_matrix_mul *fn         /* function to test */
);

#define TEST_MATRIX_MUL(name) errors += test_matrix_mul(#name, &name);

/* Test bitstream read/write functions */
int test_bitstream(
  char *name_write,         /* function name */
  char *name_read,
  fn_bit_write *fn_write,
  fn_bit_read  *fn_read
);

#define TEST_BITSTREAM(write,read) errors += test_bitstream(#write, #read, &write, &read);

/* Test switch functions */
int test_switch(
  char *name,         /* function name */
  fn_switch *fn_ref,
  fn_switch *fn
);

#define TEST_SWITCH(name) errors += test_switch(#name, &ref_##name, &name);

/* Test load store functions */
int test_loadstore(
  char *load,          /* function name */
  char *store,         /* function name */
  fn_load *fn_load,
  fn_store *fn_store,
  int big              /* big endian flag */
);

#define TEST_LOADSTORE(load,store,big) errors += test_loadstore(#load, #store, &load, &store, big);

/* Test little endian checksum functions */
int test_checksum(
  char *name,         /* function name */
  fn_checksum *fn_ref,
  fn_checksum *fn
);

#define TEST_CHECKSUM(name) errors += test_checksum(#name, &ref_##name, &name);

#endif
