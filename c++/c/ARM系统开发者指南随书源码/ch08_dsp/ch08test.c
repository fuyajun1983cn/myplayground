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
 
#include <stdio.h>
#include "ch08test.h"

int main(void)
{
  int maxerr, errors=0;
  
  //gen_fft_tables(4096, 5);

  printf("Testing examples for Chapter 8\n");
  
  /* Section 8.2 */
  maxerr=1<<13;
  TEST_DOT(dot_16by16_arm7m, q13in32, q13in32, q26in32, maxerr);
  TEST_DOT(dot_16by16_arm9m, q13in16, q13in16, q26in32, maxerr);
  TEST_DOT(dot_16by16_SA1  , q13in32, q13in32, q26in32, maxerr);
  TEST_DOT(dot_16by16_arm9e, q13in16, q13in16, q26in32, maxerr);
  TEST_DOT(dot_16by16_arm10, q13in16, q13in16, q26in32, maxerr);
  TEST_DOT(dot_16by16_xscale, q13in16, q13in16, q26in32, maxerr);
  
  /* Section 8.3 */
  maxerr=1<<15;
  TEST_FIR(fir_16by16_arm7m, q13in32, q13in32, q26in32, maxerr);
  TEST_FIR(fir_16by16_arm9m, q13in16, q13in16, q26in32, maxerr);
  TEST_FIR(fir_16by16_arm9e, q13in16, q13in16, q26in32, maxerr);
  TEST_FIR(fir_32by16_arm9e, q29in32, q13in16, q26in32, maxerr);
  TEST_FIR(fir_32by32, q29in32, q29in32, q58in64, 0x7FFFFFFF);
  
  /* Section 8.4 */
  TEST_IIR(iir_q14_arm7m, q13in32, q14in32, q13in32, 8);
  TEST_IIR(iir_q14_arm9m, q13in16, q14in16, q13in16, 8);
  TEST_IIR(iir_q14_arm9e, q13in16, q14in16, q13in16, 8);

  /* Section 8.5 */
  TEST_FFT(fft_16_arm9m, q15in16, q15in16, 7);
  TEST_FFT(fft_16_arm9e, q15in16, q15in16, 7);
  
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

int test_dot(
  char *name,           /* function name */
  fn_dot *fn,           /* function to test */
  format samp,          /* input sample format */
  format coef,          /* input coefficient format */
  format result,        /* output result format */
  int maxerr            /* maximum error alowed */
)
{
  int32 out;
  const int nSamps=40;
  void *samps, *coefs;
  real *ref_samps, *ref_coefs, ref_out;
  
  printf("Testing function: %s\n", name);

  /* generate test signal */  
  ref_samps = gen_signal(nSamps, 0);
  ref_coefs = gen_signal(nSamps, 1);
  
  /* create samples buffer */
  samps = gen_data(nSamps, samp, ref_samps);
  coefs = gen_data(nSamps, coef, ref_coefs);

#if 0
  print_signal("ref_samps", ref_samps, nSamps);
  print_data("samps", samps, samp, nSamps);
  print_signal("ref_coefs", ref_coefs, nSamps);
  print_data("coefs", coefs, coef, nSamps);
#endif
  
  /* run the test routine */
  out = (*fn)(samps, coefs, nSamps);
  ref_out = ref_dot(ref_samps, ref_coefs, nSamps);
  
  free_signal(ref_samps);
  free_signal(ref_coefs);
  free_signal(samps);
  free_signal(coefs);
  
  return compare(&ref_out, &out, result, 1, maxerr);
}

int test_fir(
  char *name,           /* function name */
  fn_fir *fn,           /* function to test */
  format samp,          /* input sample format */
  format coef,          /* input coefficient format */
  format result,        /* output result format */
  int maxerr            /* maximum error alowed */
)
{
  const int nCoefs=24;
  const int nOut = 36;
  const int nSamps=nCoefs+nOut-1;
  void *samps, *out;
  sCoefs coefs;
  real *ref_samps, *ref_out;
  rCoefs ref_coefs;
  int err;
  
  printf("Testing function: %s\n", name);

  /* generate test signal */  
  ref_samps   = gen_signal(nSamps, 0);
  ref_coefs.c = gen_signal(nCoefs, 1);
  ref_coefs.M = nCoefs;
  ref_out     = gen_signal(nOut, 2);
  
  /* create samples buffer */
  samps   = gen_data(nSamps, samp, ref_samps);
  coefs.c = gen_data(nCoefs, coef, ref_coefs.c);
  coefs.M = nCoefs;
  out     = gen_data(nOut, result, ref_out);

#if 0
  print_signal("ref_samps", ref_samps, nSamps);
  print_data("samps", samps, samp, nSamps);
  print_signal("ref_coefs", ref_coefs.c, nCoefs);
  print_data("coefs", coefs.c, coef, nCoefs);
#endif
  
  /* run the test routine */
  (*fn)(out, samps, &coefs, nOut);
  ref_fir(ref_out, ref_samps, &ref_coefs, nOut);
  
  free_signal(ref_samps);
  free_signal(ref_coefs.c);
  free_signal(samps);
  free_signal(coefs.c);
  
  err = compare(ref_out, out, result, nOut, maxerr);
  free_signal(ref_out);
  free_signal(out);
  
  return err;
}

int test_iir(
  char *name,           /* function name */
  fn_iir *fn,           /* function to test */
  format samp,          /* input sample format */
  format coef,          /* input coefficient format */
  format result,        /* output result format */
  int maxerr            /* maximum error alowed */
)
{
  const int nBiquads=4;
  const int nSamps=36;
  void *samps, *out;
  sBiquads biquads;
  real *ref_samps, *ref_out;
  rBiquads ref_biquads;
  int i, err;
  
  printf("Testing function: %s\n", name);

  /* generate test signal */  
  ref_samps     = gen_signal(nSamps, 3);
  ref_biquads.b = gen_signal(nBiquads*6, 1);
  ref_biquads.M = nBiquads;
  ref_out       = gen_signal(nSamps, 2);
  
  /* zero initial states */
  for (i=0; i<nBiquads; i++)
  {
    ref_biquads.b[6*i+4] = 0.0;
    ref_biquads.b[6*i+5] = 0.0;
  }
  
  /* create samples buffer */
  samps     = gen_data(nSamps, samp, ref_samps);
  biquads.b = gen_data(nBiquads*6, coef, ref_biquads.b);
  biquads.M = nBiquads;
  out       = gen_data(nSamps, result, ref_out);

#if 0
  print_signal("ref_samps", ref_samps, nSamps);
  print_data("samps", samps, samp, nSamps);
  print_signal("ref_coefs", ref_coefs.c, nCoefs);
  print_data("coefs", coefs.c, coef, nCoefs);
#endif
  
  /* run the test routine */
  (*fn)(out, samps, &biquads, nSamps);
  ref_iir(ref_out, ref_samps, &ref_biquads, nSamps);
  
  free_signal(ref_samps);
  free_signal(ref_biquads.b);
  free_signal(samps);
  free_signal(biquads.b);
  
  err = compare(ref_out, out, result, nSamps, maxerr);
  free_signal(ref_out);
  free_signal(out);
  
  return err;
}

int test_fft(
  char *name,           /* function name */
  fn_fft *fn,           /* function to test */
  format samp,          /* input sample format */
  format result,        /* output result format */
  int maxerr            /* maximum error alowed */
)
{
  const int nSamps=256;
  void *samps, *out;
  real *ref_samps, *ref_out;
  int err;
  
  printf("Testing function: %s\n", name);

  /* generate test signal */  
  ref_samps     = gen_signal(2*nSamps, 3);
  ref_out       = gen_signal(2*nSamps, 2);
  
  /* create samples buffer */
  samps     = gen_data(2*nSamps, samp, ref_samps);
  out       = gen_data(2*nSamps, result, ref_out);
  
  /* run the test routine */
  (*fn)(out, samps, nSamps);
  ref_fft((complex*)ref_out, (complex*)ref_samps, nSamps);
  
#if 0
  { int i, j=4; real d=0;
    for (i=0; i<j; i++) d+=ref_samps[2*i*(nSamps/j)];
    printf("average = %lf\n", d/(real)j);
  }
  print_signal("ref_samps", ref_samps, 2*nSamps);
  print_data("samps", samps, samp, 2*nSamps);
  print_signal("ref_out", ref_out, 2*nSamps);
  print_data("out", out, result, 2*nSamps);
#endif

  free_signal(ref_samps);
  free_signal(samps);
  
  err = compare(ref_out, out, result, 2*nSamps, maxerr);
  free_signal(ref_out);
  free_signal(out);
  
  return err;
}
