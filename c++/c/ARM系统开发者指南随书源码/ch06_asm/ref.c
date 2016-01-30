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
 * Reference C implementations for the routines of Chapter 6
 */
 
#include "ch06test.h" 

/* generate a randomish printable string of the given length */

void gen_str(char *out, int len)
{
  static unsigned seed=0x123456;
  
  while (len--)
  {
    char c;
    
    seed = seed * 0xabcdef45 + 0x13456789;
    c = (char)(seed >> 25);
    if (c==0x7F | c<0x20)
    {
      c=0x20;
    }
    *out++ = c;
  }
  *out=0; /* terminator */
}

/* generate random bytes of a given length */

void gen_bytes(char *out, int len)
{
  static unsigned seed=0x123456;
  
  while (len--)
  {
    seed = seed * 0xabcdef45 + 0x13456789;
    *out++ = (char)(seed >> 24);
  }
}

/* convert a string to lower case */

void str_tolower(char *out, char *in)
{
  unsigned int c;
  
  do
  {
    c = *in++;
    if (c>='A' && c<='Z')
    {
      c = c + ('a' - 'A');
    }
    *out++ = (char)c;
  } while (c);
}

/* shift an N-bit array along by k bits */

unsigned int ref_shift_bits(unsigned int *out, unsigned int *in,
                            unsigned int N, unsigned int k)
{
  unsigned int carry=0, x;
  
  do
  {
    x = *in++;
    *out++ = (x<<k) | carry;
    carry = x >> (32-k);
    N -= 32;
  } while (N);
  
  return carry;
}


/* matrix multiply a = b x c */

#define R 40
#define S 40
#define T 40

void ref_matrix_mul(int *a, int *b, int *c)
{
  unsigned int i,j,k;
  int sum;

  for (i=0; i<R; i++)
  {
    for (j=0; j<T; j++)
    {
      /* calculate a[i,j] */
      sum = 0;
      for (k=0; k<S; k++)
      {
        /* add b[i,k]*c[k,j] */
        sum += b[i*S+k]*c[k*T+j];
      }
      a[i*T+j] = sum;
    }
  }
}


void ref_merge_images(char *pz, char *px, char *py, unsigned a)
{
  int i;
  
  for (i=0; i<IMAGE_SIZE; i++)
  {
    pz[i] = (char)((px[i]*a + py[i]*(256-a))/256);
  }
}

static int method_0(void) { return 0xe0; }
static int method_1(void) { return 0xe1; }
static int method_2(void) { return 0xe2; }
static int method_3(void) { return 0xe3; }
static int method_4(void) { return 0xe4; }
static int method_5(void) { return 0xe5; }
static int method_6(void) { return 0xe6; }
static int method_7(void) { return 0xe7; }
static int method_d(void) { return 0xed; }


/* switch 0-7 */

int ref_switch(int x)
{
  switch (x)
  {
    case 0: return method_0();
    case 1: return method_1();
    case 2: return method_2();
    case 3: return method_3();
    case 4: return method_4();
    case 5: return method_5();
    case 6: return method_6();
    case 7: return method_7();
    default: return method_d();
  }
}

/* switch a power of two */

int ref_switch_hash(int x)
{
  switch (x)
  {
    case 0x01: return method_0();
    case 0x02: return method_1();
    case 0x04: return method_2();
    case 0x08: return method_3();
    case 0x10: return method_4();
    case 0x20: return method_5();
    case 0x40: return method_6();
    case 0x80: return method_7();
    default: return method_d();
  }
}


/* unaligned checksum */

int ref_read_32_little(char *p)
{
  return p[0] | (p[1]<<8) | (p[2]<<16) | (p[3]<<24);
}

int ref_read_32_big(char *p)
{
  return (p[0]<<24) | (p[1]<<16) | (p[2]<<8) | p[3];
}

int ref_checksum_32_little(char *data, unsigned int N)
{
  int sum=0;
  
  do
  {
    sum += ref_read_32_little(data);
    data += 4;
  } while (--N);
  
  return sum;
}