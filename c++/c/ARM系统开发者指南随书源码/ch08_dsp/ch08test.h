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
 * Test module for the example routines of Chapter 8
 */

#ifndef CH08TEST_H
#define CH08TEST_H
 
/* Compile time options */
#define VERBOSE 0

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
typedef struct { real re,im; } complex;

/* Format types
 * The top 16 bits gives the Q shift in bits for the type
 * The bottom 16 bits gives the size in bits for the type
 */
typedef enum
{
  q13in32 = (13<<16)|32,
  q13in16 = (13<<16)|16,
  q14in32 = (14<<16)|32,
  q14in16 = (14<<16)|16,
  q15in32 = (15<<16)|32,
  q15in16 = (15<<16)|16,
  q26in32 = (26<<16)|32,
  q29in32 = (29<<16)|32,
  q58in64 = (58<<16)|64,
  tend
} format;

#define QSHIFT(type) (type>>16)
#define TSIZE(type) (type & 0xFF)
 
/* Function types */
typedef int32 fn_dot(void *data, void *coefs, int N);
typedef struct { void *c; int M; } sCoefs;
typedef struct { real *c; int M; } rCoefs;
typedef struct { void *b; int M; } sBiquads;
typedef struct { real *b; int M; } rBiquads;
typedef void fn_fir(void *a, void *x, sCoefs *c, int N);
typedef void fn_iir(void *y, void *x, sBiquads *b, int N);
typedef void fn_fft(void *y, void *x, int N);
 
/* Section 8.2 */
fn_dot dot_16by16_arm7m;
fn_dot dot_16by16_arm9m;
fn_dot dot_16by16_SA1;
fn_dot dot_16by16_arm9e;
fn_dot dot_16by16_arm10;
fn_dot dot_16by16_xscale;
real ref_dot(real *samps, real *coefs, unsigned nSamps);

/* Section 8.3 */
fn_fir fir_16by16_arm7m;
fn_fir fir_16by16_arm9m;
fn_fir fir_16by16_arm9e;
fn_fir fir_32by16_arm9e;
fn_fir fir_32by32;
void ref_fir(real *a, real *x, rCoefs *c, int N);

/* Section 8.4 */
fn_iir iir_q14_arm7m;
fn_iir iir_q14_arm9m;
fn_iir iir_q14_arm9e;
void ref_iir(real *y, real *x, rBiquads *b, int N);

/* Section 8.5 */
fn_fft fft_16_arm9m;
fn_fft fft_16_arm9e;
void ref_bit_reverse(complex *y, complex *x, int N);
void ref_powers_table(complex *table, complex w, int N);
void ref_fft_stage(complex *y, complex *table, int R, int S);
void ref_fft(complex *y, complex *x, int N);

/* Functions to generate and test data */
void *my_malloc(int size);
void *gen_data(int size, format type, real *ref);
real *gen_signal(int size, int code);
void free_signal(void *data);
int compare(real *ref, void *data, format type, int size, int maxerr);
void print_signal(char *name, real *signal, int size);
void print_data(char *name, void *data, format type, int size);
void gen_fft_tables(int N, int arch);

/* Test dot product functions */
int test_dot(
  char *name,           /* function name */
  fn_dot *fn,           /* function to test */
  format samp,          /* input sample format */
  format coef,          /* input coefficient format */
  format result,        /* output result format */
  int maxerr            /* maximum error alowed */
);

#define TEST_DOT(name, samp, coef, result, maxerr) errors += test_dot(#name, &name, samp, coef, result, maxerr);

/* Test FIR filter functions */
int test_fir(
  char *name,           /* function name */
  fn_fir *fn,           /* function to test */
  format samp,          /* input sample format */
  format coef,          /* input coefficient format */
  format result,        /* output result format */
  int maxerr            /* maximum error alowed */
);

#define TEST_FIR(name, samp, coef, result, maxerr) errors += test_fir(#name, &name, samp, coef, result, maxerr);

/* Test IIR filter functions */
int test_iir(
  char *name,           /* function name */
  fn_iir *fn,           /* function to test */
  format samp,          /* input sample format */
  format coef,          /* input coefficient format */
  format result,        /* output result format */
  int maxerr            /* maximum error alowed */
);

#define TEST_IIR(name, samp, coef, result, maxerr) errors += test_iir(#name, &name, samp, coef, result, maxerr);

/* Test FFT functions */
int test_fft(
  char *name,           /* function name */
  fn_fft *fn,           /* function to test */
  format samp,          /* input sample format */
  format result,        /* output result format */
  int maxerr            /* maximum error alowed */
);

#define TEST_FFT(name, samp, result, maxerr) errors += test_fft(#name, &name, samp, result, maxerr);

#endif
