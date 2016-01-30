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
 * Test module for the example routines of Chapter 5
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ch05test.h"

int main(void)
{
  int errors=0;
  
  printf("Testing examples for Chapter 5\n");
  TEST_CHECKSUM(checksum_v1, 64, 4);
  TEST_CHECKSUM(checksum_v2, 64, 4);
  TEST_CHECKSUM(checksum_v3, 64, 2);
  TEST_CHECKSUM(checksum_v4, 64, 2);
  TEST_CHECKSUM(checksum_v5, 64, 4);
  TEST_CHECKSUM(checksum_v6, 64, 4);
  TEST_CHECKSUM(checksum_v7, 63, 4);
  TEST_CHECKSUM(checksum_v8, 63, 4);
  TEST_CHECKSUM(checksum_v9, 64, 4);
  TEST_CHECKSUM(checksum_v10, 0, 4);
  TEST_CHECKSUM(checksum_v10, 1, 4);
  TEST_CHECKSUM(checksum_v10, 2, 4);
  TEST_CHECKSUM(checksum_v10, 3, 4);
  TEST_CHECKSUM(checksum_v10,64, 4);
  TEST_CHECKSUM(checksum_v10,65, 4);
  TEST_QUEUE(queue_bytes_v1, 1);
  TEST_QUEUE(queue_bytes_v2, 2);
  TEST_TOHEX(uint_to_hex);
  TEST_GETXY(getxy_v1);
  TEST_GETXY(getxy_v2);
  TEST_SCALE(scale);  
  TEST_READINT(readint_little,0);
  TEST_READINT(readint_big,1);
  TEST_READSAMP(read_samples);
  TEST_SATCOR(sat_correlate_v1);
  TEST_SATCOR(sat_correlate_v2);
#ifdef __TARGET_FEATURE_DSPMUL
  TEST_SATCOR(sat_correlate_v3);
#endif
  TEST_TOLOWER(str_tolower);
  TEST_DIV(udiv_by_const,0);
  TEST_DIV(sdiv_by_const,1);
#ifdef __ARMCC_VERSION
  /* check armcc/armasm specific functions */
#ifdef __BIG_ENDIAN
  TEST_READINT(readint,1);
#else
  TEST_READINT(readint,0);
#endif
  TEST_CHECKSUM(checksum_v1_s, 64, 4);
  TEST_CHECKSUM(checksum_v2_s, 64, 4);
  TEST_CHECKSUM(checksum_v3_s, 64, 2);
  TEST_CHECKSUM(checksum_v4_s, 64, 2);
  TEST_CHECKSUM(checksum_v5_s, 64, 4);
  TEST_CHECKSUM(checksum_v6_s, 64, 4);
  TEST_CHECKSUM(checksum_v7_s, 63, 4);
  TEST_CHECKSUM(checksum_v8_s, 63, 4);
  TEST_CHECKSUM(checksum_v9_s, 64, 4);
  TEST_CHECKSUM(checksum_v10_s, 0, 4);
  TEST_CHECKSUM(checksum_v10_s, 1, 4);
  TEST_CHECKSUM(checksum_v10_s, 2, 4);
  TEST_CHECKSUM(checksum_v10_s, 3, 4);
  TEST_CHECKSUM(checksum_v10_s,64, 4);
  TEST_CHECKSUM(checksum_v10_s,65, 4);
  TEST_QUEUE(queue_bytes_v1_s, 3);
  TEST_QUEUE(queue_bytes_v2_s, 4);
  TEST_TOHEX(uint_to_hex_s);
  TEST_GETXY(getxy_v1_s);
  TEST_GETXY(getxy_v2_s);
  TEST_SCALE(scale_s);
  TEST_SATCOR(sat_correlate_v1_s);
  TEST_SATCOR(sat_correlate_v2_s);
  TEST_SATCOR(sat_correlate_v3_s);
  TEST_TOLOWER(str_tolower_s);
#endif
  
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

/* external functions requited by the test */
short add_v3(short a, short b)
{
  return (short)(a+b);
}

int clip1(int x) { return x; }
void dostageA(void) {}
void dostageB(void) {}
void dostageC(void) {}
int *get_next_packet(int *N)
{
  static int data[2]={3,5};
  *N=2;
  return data;
}


int test_checksum(
  char *name,           /* function name */
  fn_checksum *fn,       /* function to test */
  int N,                /* number of elements */
  int size              /* size of each element in bytes */
)
{
  int sum, expected, i, errors=0;
  char *data;
  
  printf("Testing function: %s\n", name);
  
  data = (char*)malloc(N*size+1);
  if (!data)
  {
    return 1;
  }
  
  for (i=0; i<N; i++)
  {
    switch (size)
    {
      case 2: ((short*)data)[i]=(short)(i+1); break;
      case 4: ((int*)data)[i]=i+1; break;
    }
  }
  
  sum = (*fn)(data, N);
  expected = N*(N+1)/2;
  
  if (sum!=expected)
  {
    errors++;
    printf("Mismatch: %08x %08x\n", expected, sum); 
  }
  
  return errors;
}

#define Q_size 5

int test_queue(
  char *name,           /* function name */
  int version           /* version */
)
{
  int errors=0;
  char Q_start[Q_size+1];
  char *Q_end = Q_start+Q_size;
  char *Q_ptr = Q_start;
  char *data[2] = { "ABCDEF", "GHI" };
  char *result = "FGHIE";
  Queue Q;
  int i;
  
  Q.Q_start = Q_start;
  Q.Q_end   = Q_end;
  Q.Q_ptr   = Q_ptr;
  *Q_end = 0;

  printf("Testing function: %s\n", name);
  
  for (i=0; i<2; i++)
  {
    int len = strlen(data[i]);
    
    switch (version)
    {
      case 1:
        Q_ptr = queue_bytes_v1(Q_start, Q_end, Q_ptr, data[i], len);
        break;
        
      case 2:
        queue_bytes_v2(&Q, data[i], len);
        break;

#ifdef __ARMCC_VERSION        
      case 3:
        Q_ptr = queue_bytes_v1_s(Q_start, Q_end, Q_ptr, data[i], len);
        break;
        
      case 4:
        queue_bytes_v2_s(&Q, data[i], len);
        break;
#endif
      default:
        printf("Illegal queue function\n");
        exit(1);
    }
  }
  
  /* result should be "FGHIE" */
  if (strncmp(Q_start, result, Q_size))
  {
    errors++;
    printf("Mismatch: %s %s\n", result, Q_start);
  }
  
  return errors;
}

int test_tohex(
  char *name,           /* function name */
  fn_tohex *fn          /* function to test */
)
{
  int i, errors=0;
  struct { int i; char *s; } tests[4] = {
    { 0x12345678, "12345678" },
    {          0, "00000000" },
    {-0x80000000, "80000000" },
    { 0xabcdef01, "ABCDEF01" }
  };
  char str[9];
  
  str[8]=0;
  printf("Testing function: %s\n", name);
  
  for (i=0; i<4; i++)
  {
    (*fn)(str, tests[i].i);
    if (strcmp(str, tests[i].s))
    {
      errors++;
      printf("Mismatch: %s %s\n", tests[i].s, str);
    }
  }
  
  return errors;
}

int test_getxy(
  char *name,           /* function name */
  fn_getxy *fn          /* function to test */
)
{
  int x,y,errors=0;
  int bpl=51;
  
  printf("Testing function: %s\n", name);
  for (x=0; x<5; x++)
  {
    for (y=0; y<5; y++)
    {
      point p = (*fn)(x + y*bpl, bpl);
       
      if (p.x!=x || p.y!=y)
      {
        errors++;
        printf("Mismatch: x %d %d y %x %d\n", x, p.x, y, p.y);
      }
    }
  }

  return errors;
}

#define SCALE_SIZE 5

int test_scale(
  char *name,           /* function name */
  fn_scale *fn          /* function to test */
)
{
  int i,s,errors=0;
  unsigned int src[SCALE_SIZE];
  unsigned int dest[SCALE_SIZE];
  
  printf("Testing function: %s\n", name);
  for (s=1; s<10; s++)
  {
    for (i=0; i<SCALE_SIZE; i++)
    {
      src[i] = rand();
    }
    
    (*fn)(dest, src, s, SCALE_SIZE);
    
    for (i=0; i<SCALE_SIZE; i++)
    {
      unsigned int r=src[i]/s;
      
      if (r!=dest[i])
      {
        errors++;
        printf("Mismatch s=%d [%d]: %d %d\n", s, i, r, dest[i]);
      }
    }
  }

  return errors;
}

int test_tolower(
  char *name,           /* function name */
  fn_tolower *fn          /* function to test */
)
{
  char *in = "aBc!Z[";
  char *ref = "abc!z[";
  char out[10];
  int errors=0;
  
  printf("Testing function: %s\n", name);
  
  (*fn)(out, in);
  
  if (strcmp(ref, out))
  {
    errors++;
    printf("Mismatch: %s %s\n", ref, out);
  }

  return errors;
}

/* test normal behaviour */
static short tx_0[]={ -1, 2, 3, 4 };
static short ty_0[]={ 2, -3, 4, 7 };
/* test x*y overflow - but no overall overflow */
static short tx_1[]={ -0x8000, -0x8000 };
static short ty_1[]={  0x3000, -0x8000 };
/* +ve overflow */
static short tx_2[]={ 0x7000, 0x6000 };
static short ty_2[]={ 0x7000, 0x6000 };
/* -ve overflow */
static short tx_3[]={ -0x7000, 0x6000 };
static short ty_3[]={ 0x7000, -0x6000 };

/* tests */
static struct {
  int ans;
  short *x;
  short *y;
  unsigned int N;
} satcor_tests[] = {
  { 32*2, tx_0, ty_0, 4 },
  { 0x4FFFFFFF, tx_1, ty_1, 2 },
  { 0x7FFFFFFF, tx_2, ty_2, 2 },
  { 0x80000000, tx_3, ty_3, 2 }
};

int test_satcor(
  char *name,           /* function name */
  fn_satcor *fn        /* function to test */
)
{
  int errors=0;
  int i;
  
  printf("Testing function: %s\n", name);
  
  for (i=0; i<4; i++)
  {
    int acc, ref;
    
    acc = (*fn)(satcor_tests[i].x, satcor_tests[i].y, satcor_tests[i].N);
    ref = satcor_tests[i].ans;
    
    if (ref!=acc)
    {
      errors++;
      printf("Mismatch[%d]: %08x %08x\n", i, ref, acc);
    } 
  }
 
  return errors;
}

int test_readint(
  char *name,           /* function name */
  fn_readint *fn,       /* function to test */
  int big               /* endianness */
)
{
  int errors=0;
  int ref, val;
  char data[]={0,1,2,3,4,5,6,7};
  
  printf("Testing function: %s\n", name);
  if (big)
  {
    ref = 0x03040506;
  }
  else
  {
    ref = 0x06050403;
  }
  val = (*fn)(data+3);
  
  if (ref!=val)
  {
    errors++;
    printf("Mismatch: %08x %08x\n", ref, val);
  }

  return errors;
}

int test_readsamp(
  char *name,           /* function name */
  fn_readsamp *fn       /* function to test */
)
{
  int errors=0;
  /* fill with little endian samples
   * data[0] = 0x0100, 0x0302, 0x0504, ....
   * data[1] = 0x0201, 0x0403, 0x0604, ....
   */
  char data[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  short ref0[]={ 0x0302, 0x0504, 0x0706 };
  short ref1[]={ 0x0403, 0x0605, 0x0807 };
  short out[4];
  int i;
  
  printf("Testing function: %s\n", name);
  (*fn)(out, data+2, 3);
  for (i=0; i<3; i++)
  {
    if (out[i]!=ref0[i])
    {
      errors++;
      printf("Mismatch0[%d]: %08x %08x\n", i, ref0[i], out[i]);
    }
  }
  
  (*fn)(out, data+3, 3);  
  for (i=0; i<3; i++)
  {
    if (out[i]!=ref1[i])
    {
      errors++;
      printf("Mismatch1[%d]: %08x %08x\n", i, ref1[i], out[i]);
    }
  }

  return errors;
}

/* Generate signed 32-bit test data
 * 0,-1,1,-2,2,..,+MAX,-MAX in exponential trend
 */

static int gen_s32(int seed)
{
  int n;
  
  seed = ~seed;
  if (seed<0) return seed;
  if (seed<8) return (seed+1);
  n = seed + (seed>>1);
  if (n<0)
  {
    n = 0x7FFFFFFFul;
  }
  if (n>seed) return n;
  return 0;
}

int test_div(
  char *name,           /* function name */
  fn_div *fn,           /* function to test */
  int sign              /* set for signed divide */
)
{
  int d, errors=0;
 
  printf("Testing function: %s\n", name);
  
  for (d=gen_s32(0); d!=0; d=gen_s32(d))
  {
    int n=0;
#if VERBOSE
    printf("d=%08x\n", d);
#endif
    
    do
    {
      int qr, q;
      
      if (sign)
      {
        qr = n/d;
      }
      else
      {
        qr = (int)((unsigned)n/(unsigned)d);
      }
      q = (*fn)(n,d);
      
      if (qr!=q)
      {
        errors++;
        printf("Mismatch: %08x/%08x: %08x %08x\n", n, d, qr, q);
      }
      n=gen_s32(n);
    } while (n);
  }
  
  return errors;
}
