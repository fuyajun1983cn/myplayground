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
 * Reference DSP routines for Chapter 8
 */
 
#include "ch08test.h"
#include <math.h>

static const real pi = 3.141592653589;

real ref_dot(real *samps, real *coefs, unsigned nSamps)
{
  real acc=0;
  
  for ( ; nSamps!=0; nSamps--)
  {
    acc += (*samps++) * (*coefs++);
  }
  
  return acc;
}

void ref_fir(real *a, real *x, rCoefs *coefs, int N)
{
  real *c = coefs->c;   /* coefficient pointer */
  int M = coefs->M;     /* number of coefficients */
  int i;
 
  do
  {
    real acc = 0;
    
    for (i=0; i<M; i++)
    {
      acc += x[i] * c[i];
    }
    
    *a++ = acc;
    x++;
    
  } while (--N);
}

void ref_iir(real *y, real *x, rBiquads *b, int N)
{
  unsigned int i, M = b->M;
  real acc, *biquad;
  
  do
  {
    /* filter next sample */
    biquad = b->b;
    acc = *x++;
    
    for (i=0; i<M; i++)
    {
       real a1,a2,b1,b2,s0,s1,s2;
       
       /* process the next biquad */
       a1 = *biquad++;  /* -a1 */
       a2 = *biquad++;  /* -a2 */
       b1 = *biquad++;  /* +b1 */
       b2 = *biquad++;  /* +b2 */
       s1 = biquad[0];  /* s[t-1] */
       s2 = biquad[1];  /* s[t-2] */
       
       s0 = acc + s1*a1 + s2*a2;
       acc = s0 + s1*b1 + s2*b2;
       
       *biquad++ = s0;  /* new s[t-1] */
       *biquad++ = s1;  /* new s[t-2] */
    }
    *y++ = acc;
  } while (--N);
}

/* Bit reverse and array - N must be a power of two */

void ref_bit_reverse(complex *y, complex *x, int N)
{
  unsigned int i,j,k;  /* j=bit reversal of i */
  
  for (i=0, j=0; i<N; i++)
  {
    y[i] = x[j];
    
    /* increment j in a bit reversed way */
    k=N>>1;
    while (j & k)
    {
      j = j^k;
      k >>= 1;
    }
    j = j^k; 
  }
}

__inline complex C_MUL(complex b, complex c)
{
  complex a;
  a.re = b.re*c.re - b.im*c.im;
  a.im = b.re*c.im + b.im*c.re;
  return a;
}

__inline complex C_ADD(complex b, complex c)
{
  complex a;
  a.re = b.re + c.re;
  a.im = b.im + c.im;
  return a;
}

__inline complex C_SUB(complex b, complex c)
{
  complex a;
  a.re = b.re - c.re;
  a.im = b.im - c.im;
  return a;
}

__inline complex C_HALVE(complex b)
{
  complex a;
  a.re = b.re/2.0;
  a.im = b.im/2.0;
  return a;
}

/* Calculate a table of powers of w:
 *  1, w, w^2, ...., w^(N-1)
 * N must be a power of 2
 */
 
void ref_powers_table(complex *table, complex w, int N)
{
  int i;
  
  table[0].re = 1.0;
  table[0].im = 0.0;
  
  for (i=1; i<N; i++)
  {
    table[i] = C_MUL(table[i-1], w);
  }
}

/* Perform the next FFT stage
 *  R = the size of each input block (R-point DFT's)
 *  S = the number of input blocks (R*S=N)
 * On output we have doubled R and halved S
 */

void ref_fft_stage(complex *y, complex *table, int R, int S)
{
  int i,j;
  complex x0,x1,xx,z;
  
  for (i=0; i<R/2; i++)
  {
    z = table[i*S];
    
    for (j=0; j<S; j++)
    {
      x0 = y[j*R+i];
      x1 = y[j*R+i+R/2];
      xx = C_MUL(x1, z);
      x1 = C_SUB(x0, xx);
      x0 = C_ADD(x0, xx);
      y[j*R+i]    =C_HALVE(x0);  /* (x0+z*x1)/2 */
      y[j*R+i+R/2]=C_HALVE(x1);  /* (x0-z*x1)/2 */
    }
  }
}

/* Perform a radix 2 FFT */

void ref_fft(complex *y, complex *x, int N)
{
  complex w, *table;
  int R,S;
  
  /* create table of powers of w */
  table = (complex*)my_malloc(N*sizeof(complex)/2);
  w.re = cos(-2.0*pi/(real)N);
  w.im = sin(-2.0*pi/(real)N);
  ref_powers_table(table, w, N/2);
  
  /* bit reverse the input array */
  ref_bit_reverse(y, x, N);
    
  /* perform radix 2 FFT stages */
  for (R=2, S=N/2; S!=0; S>>=1, R<<=1)
  {
    ref_fft_stage(y, table, R, S);
  }
}
