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
 * Generate test data
 */

#include <stdio.h>
#include <stdlib.h>
#include "ch08test.h"
#include <math.h>

static const real pi = 3.141592653589;

/* Claim an aligned working buffer */

#define ALIGNMENT 8  /* LDRD requires an 8-byte aligned buffer */

void *my_malloc(int size)
{
  void *p;
  unsigned int a;
  
  p = malloc(size+ALIGNMENT-1);
  if (!p)
  {
    printf("Failed to malloc working buffer of size %d\n", size);
    exit(1);
  }
  a = (unsigned int)p & (ALIGNMENT-1);
  if (a)
  {
    /* if not aligned then align the array */
    p = (void*)((char*)p+ALIGNMENT-a);
  }
  return p;
}

/* Generate a test signal of size real samples.
 * Each value of code generates a different signal.
 */

real *gen_signal(int size, int code)
{
  real *signal, scale;
  int i;
  int64 seed = 0x0123456789abcdefull;
  int64 mult;
  
  signal = (real *)my_malloc(size * sizeof(real));
  
  if (code==-1)
  {
    /* use an impluse */
    signal[0] = 1.0;
    for (i=1; i<size; i++)
    {
      signal[i] = 0.0;
    }
    return signal;
  }
  
  /* scramble code */
  mult  = code * 0x89abcdef76543210ull ^ 0xa75bc38291E6D6A5ull;
  scale = 1.0/(real)(1ull<<63);
  
  for (i=0; i<size; i++)
  {
    seed = seed * mult;
    signal[i] = (real)seed*scale;
  }
  
  return signal;
}

/* Free the memory used by a signal */

void free_signal(void *data)
{
  /* data may not be the pointer we malloced */
  (void)data;
  //free(data);
}

/* Display a signal */

void print_signal(char *name, real *signal, int size)
{
  int i;
  
  for (i=0; i<size; i++)
  {
    printf("%s[%02d]=%lf\n", name, i, signal[i]);
  }
}

/* Convert a real to a 64 bit integer */

static int64 real_to_int(real x)
{
  /* round and then cast */
  if (x>=0) x+=0.5;
  if (x<=0) x-=0.5;
  return (int64)x;
}

/* Convert a test signal to the indicated format type */

void *gen_data(int size, format type, real *ref)
{
  void *data;
  int tsize;
  real qscale;
  int i;
  
  tsize  = TSIZE(type);
  qscale = (real)(1ull<<QSHIFT(type));
    
  data = my_malloc(size*tsize+4);
  
  for (i=0; i<size; i++)
  {
    int64 d;
    
    d = real_to_int(ref[i]*qscale);
    
    switch (tsize)
    {
      case 8 : ((int8  *)data)[i] = (int8)d; break;
      case 16: ((int16 *)data)[i] = (int16)d; break;
      case 32: ((int32 *)data)[i] = (int32)d; break;
      case 64: ((int64 *)data)[i] = (int64)d; break;
      default: printf("Unknown data size %d\n", tsize);
               exit(1);
    }
  }
  
  return data;
}

/* Compare a reference signal with a fixed point point signal
 * to check that they match with a given tolerance.
 */
 
int compare(real *ref, void *data, format type, int size, int maxerr)
{
  int err=0, i;
  int tsize;
  real qscale;
  
  tsize  = TSIZE(type);
  qscale = (real)(1ull<<QSHIFT(type));
  
  for (i=0; i<size; i++)
  {
    int64 out, ref_out, d;
    
    ref_out = real_to_int(ref[i]*qscale);
    switch (tsize)
    {
      case 8 : out = ((int8  *)data)[i]; break;
      case 16: out = ((int16 *)data)[i]; break;
      case 32: out = ((int32 *)data)[i]; break;
      case 64: out = ((int64 *)data)[i]; break;
      default: printf("Unknown data size %d\n", tsize);
               exit(1);
    }
    d = out-ref_out;
    if (d<0) d=-d;
    if ((unsigned)d>=maxerr)
    {
      printf("FAIL[%d] : ", i);
      printf("%016llx %016llx (%016llx)\n", ref_out, out, d);
      err++;
    }
  }
  
  return err;
}

/* Display fixed point data */

void print_data(char *name, void *data, format type, int size)
{
  int i;
  int tsize;
  real qscale;
  
  tsize  = TSIZE(type);
  qscale = (real)(1ull<<QSHIFT(type));
    
  for (i=0; i<size; i++)
  {
    int64 out;
    
    switch (tsize)
    {
      case 8 : out = ((int8  *)data)[i]; break;
      case 16: out = ((int16 *)data)[i]; break;
      case 32: out = ((int32 *)data)[i]; break;
      case 64: out = ((int64 *)data)[i]; break;
      default: printf("Unknown data size %d\n", tsize);
               exit(1);
    }
    printf("%s[%02d]=%016llx (%lf)\n", name, i, out, (real)out/qscale);
  }
}

static int qconv(real x, int q)
{
   int scale = 1<<q;
   x = x*(real)(scale);
   if (x>=0) x+=0.5;
   if (x>=0x7FFF) x=0x7FFF;
   if (x<=0) x-=0.5;
   return (int)x;
}

static void fft_entry(real t, int arch)
{
  real c,s;
  
  c=cos(t);
  s=sin(t);
  if (arch<=4)
  {
    c=c-s;
    printf("0x%04x,0x%04x", qconv(c,14)&0xFFFF, qconv(s,14)&0xFFFF);
  }
  else
  {
    printf("0x%04x,0x%04x", qconv(c,15)&0xFFFF, qconv(s,15)&0xFFFF);
  }
}

static void gen_fft_table(int N, int arch)
{
  int k;
  real t;
  
  /* generate a radix 4 N-point table */
  printf("        ; N=%d t=2*PI*k/N for k=0,1,2,..,N/4-1\n", N);
  
  for (k=0; k<N/4; k++)
  {
    t = 2.0*pi*(real)k/(real)N;
    printf("        DCW ");
    fft_entry(3.0*t, arch);
    printf(", ");
    fft_entry(t, arch);
    printf(", ");
    fft_entry(2.0*t, arch);
    printf("\n");
  }
}

/* Generate the FFT tables */
void gen_fft_tables(int N, int arch)
{
  int n;
  
  printf("        ; FFT twiddle table of triplets E(3t), E(t), E(2t)\n");
  if (arch<=4)
  {
    printf("        ; Where E(t)=(cos(t)-sin(t))+i*sin(t) at Q14\n");
  }
  else
  {
    printf("        ; Where E(t)=cos(t)+i*sin(t) at Q15\n");
  }    
  
  for (n=16; n<=N; n<<=2)
  {
    gen_fft_table(n, arch);
  }
}
