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
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ch06test.h"

int main(void)
{
  int errors=0;
  
  printf("Testing examples for Chapter 6\n");

#if 1
  TEST_TOLOWER(str_tolower_preload);
  TEST_TOLOWER(str_tolower_unrolled);
  TEST_SHIFT(shift_bits);  
  TEST_SCALE(shift_right);
  TEST_MERGE(merge_images);
  TEST_MEMSET(my_memset);
  TEST_MATRIX_MUL(matrix_mul);
  TEST_BITSTREAM(bitstream_write_test, bitstream_read_test);
  TEST_SWITCH(switch_absolute);
  TEST_SWITCH(switch_relative);
  TEST_SWITCH(switch_hash);
#endif
  TEST_LOADSTORE(load_32_little, store_32_little, 0);
  TEST_LOADSTORE(load_32_big, store_32_big, 1);
  TEST_CHECKSUM(checksum_32_little);
  
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

#define TESTSIZE 1024
#define TESTOFF    64

int test_memset(
  char *name,           /* function name */
  fn_memset *fn         /* function to test */
)
{
  const int sizes[]={0,1,2,3,4,5,6,10,40,160,500};
  char workspace[TESTSIZE];
  int i,j,offset;
  int errors=0;
  
  printf("Testing function: %s\n", name);
  
  for (i=0; i<sizeof(sizes)/sizeof(sizes[0]); i++)
  {
    for (offset=0; offset<4; offset++)
    {
#if VERBOSE
      printf(" Memset size=%d Alignment=%d\n", sizes[i], offset);
#endif

      /* clear the workspace */
      for (j=0; j<TESTSIZE; j++)
      {
        workspace[j]=0x56;
      }
    
      /* run the memset */
#if 1
      (*fn)(workspace+TESTOFF+offset, 0xA4, sizes[i]);
#else
      { unsigned int t=*(volatile unsigned int*)0x12340000;
      (*fn)(workspace+TESTOFF+offset, 0xA4, sizes[i]);
       t-=*(volatile unsigned int*)0x12340000;
       printf("time = %d\n", t);
      }
#endif
    
      /* check the result */
      for (j=0; j<TESTSIZE; j++)
      {
        char c=0xA4;
      
        if (j<TESTOFF+offset || j>=TESTOFF+offset+sizes[i])
        {
          c=0x56;
        }
        if (workspace[j]!=c)
        {
          printf("Error offset[%d]=0x%02x (ref 0x%02x)\n", j-TESTOFF-offset, workspace[j], c);
          errors++;
        }
      }
    }
  }
  
  return errors;  
}

/* Test matrix multiply RxS by SxT to RxT */

#define R 40
#define S 40
#define T 40

int test_matrix_mul(
  char *name,           /* function name */
  fn_matrix_mul *fn         /* function to test */
)
{
  int a[R*T];
  int ref_a[R*T];
  int b[R*S];
  int c[S*T];
  int i, errors=0;

  printf("Testing function: %s\n", name);
  
  /* Fill matrices with some randomish values */
  for (i=0; i<R*S; i++)
  {
    b[i] = (5*i) % 23;
  }
  for (i=0; i<S*T; i++)
  {
    c[i] = (7*i) % 31;
  }
  
  /* call optimised and reference matrix multiplies */
  ref_matrix_mul(ref_a, b, c);
  (*fn)(a, b, c);
  
  /* compare outputs */
  for (i=0; i<R*T; i++)
  {
    if (a[i] != ref_a[i])
    {
      errors++;
      printf("Mismatch[%d]: %08x %08x\n", i, ref_a[i], a[i]);
    }
  }
  
  return errors;
}

#define NUM_BITS 1024

int test_shift(
  char *name,           /* function name */
  fn_shift *fn          /* function to test */
)
{
  unsigned int out[NUM_BITS/32];
  unsigned int ref_out[NUM_BITS/32];
  unsigned int in[NUM_BITS/32];
  int i, k, errors=0;
  unsigned int carry, ref_carry;
  

  printf("Testing function: %s\n", name);
  
  for (k=1; k<32; k++)
  {
#if VERBOSE
    //printf("Testing a shift of %d\n", k);
#endif

    for (i=0; i<NUM_BITS/32; i++)
    {
      in[i]=(unsigned)(i*0xA2345679+0x1234567f);
    }
    
    ref_carry = ref_shift_bits(ref_out, in, NUM_BITS, k);
    carry = (*fn)(out, in, NUM_BITS, k);
    
    for (i=0; i<NUM_BITS/32; i++)
    {
      if (out[i] != ref_out[i])
      {
        errors++;
        printf("Mismatch[%d]: %08x %08x\n", i, ref_out[i], out[i]);
      }
    }
    if (carry != ref_carry)
    {
      errors++;
      printf("Mismatch[carry]: %08x %08x\n", ref_carry, carry);
    }
  }

  return errors;
}

#define MAX_LEN 100

/* Test string to lower function */
int test_tolower(
  char *name,           /* function name */
  fn_tolower *fn          /* function to test */
)
{
  char out[MAX_LEN];
  char ref_out[MAX_LEN];
  char in[MAX_LEN];
  int len, errors=0;

  printf("Testing function: %s\n", name);
  
  for (len=0; len<MAX_LEN; len++)
  {
#if VERBOSE
    //printf("Testing tolower string of length %d\n", len);
#endif

    gen_str(in, len);
    
    str_tolower(ref_out, in);
    (*fn)(out, in);
    
    if (strcmp(ref_out, out))
    {
      errors++;
      printf("Mismatch: \"%s\" \"%s\"\n", ref_out, out);
    }
  }

  return errors;
}

#define SCALE_LEN 40

/* Test right shift/scaling function */
int test_scale(
  char *name,           /* function name */
  fn_scale *fn          /* function to test */
)
{
  int out[SCALE_LEN];
  int in[SCALE_LEN];
  int i, k, errors=0;
  
  printf("Testing function: %s\n", name);
  
  for (k=0; k<31; k++)
  {
#if VERBOSE
    //printf("Testing right shift of %d\n", k);
#endif

    for (i=0; i<SCALE_LEN; i++)
    {
      in[i] = 0xa5367898 * i + 0x23478909;
    }
    
    (*fn)(out, in, k);
    
    for (i=0; i<SCALE_LEN; i++)
    {
      if (out[i] != (in[i]>>k))
      {
        errors++;
        printf("Mismatch[%d]: %08x %08x\n", i, in[i]>>k, out[i]);    
      }
    }
  }
  
  return errors;
}

int test_merge(
  char *name,           /* function name */
  fn_merge *fn          /* function to test */
)
{
  char z[IMAGE_SIZE]; /* output */
  char ref_z[IMAGE_SIZE]; /* output */
  char x[IMAGE_SIZE];
  char y[IMAGE_SIZE];
  int i, a, errors=0;
  
  printf("Testing function: %s\n", name);
  
  for (a=0; a<=256; )
  {
#if VERBOSE
    printf("Testing merge of intensity %d\n", a);
#endif

    gen_bytes(x, IMAGE_SIZE);
    gen_bytes(y, IMAGE_SIZE);

    ref_merge_images(ref_z, x, y, a);
    (*fn)(z, x, y, a);
    
    for (i=0; i<IMAGE_SIZE; i++)
    {
      if (ref_z[i] != z[i])
      {
        errors++;
        printf("Mismatch[%d]: %02x %02x\n", i, ref_z[i], z[i]);    
      }
    }
    if (a==255) a=256;
    else a+=51;
  }
  
  return errors;  
}

#define N 8
#define MESSAGE_LENGTH 256

int test_bitstream(
  char *name_write,         /* function name */
  char *name_read,
  fn_bit_write *fn_write,
  fn_bit_read  *fn_read
)
{
  int look_code[1<<N];
  char look_codebits[1<<N];
  int message_codes[MESSAGE_LENGTH];
  char message_codebits[MESSAGE_LENGTH];
  char bitstream_buffer[MESSAGE_LENGTH+8];
  int received_codes[MESSAGE_LENGTH];
  int i, k, errors=0;
  int alignment;

  printf("Testing functions: %s %s\n", name_write, name_read);
  
  /* We test the bitstream functions with a very simple Huffman Code
   * For each k>=1 there is a code of length k bits consisting of
   * (k-1) 1's followed by a single 0 stop bit.
   */
  for (k=1; k<=N; k++)
  {
    int code = (1<<k)-2;  /* (k-1) 1's followed by 0 */
    
    /* fill in the lookup table for code length k */
    for (i=0; i<(1<<(N-k)); i++)
    {
      look_code    [ (code << (N-k)) + i ] = code;
      look_codebits[ (code << (N-k)) + i ] = (char)k;
    }
  }
  look_code    [(1<<N)-1] = -1;
  look_codebits[(1<<N)-1] = 0xFF; /* escape codes longer than N-bits */
  
  /* Now lets generate a message to send of codes <= N bits.
   * The message is terminated with an (N+1)-bit code
   */
  for (i=0; i<MESSAGE_LENGTH-1; i++)
  {
    k = (rand()%N)+1; /* randomish code length */
    message_codes[i] = (1<<k)-2;
    message_codebits[i] = (char)k;
  }
  message_codes[i] = (1<<(N+1))-2;
  message_codebits[i] = N+1;
  
  /* Now, for each byte alignment, encode and decode the message */
  for (alignment=0; alignment<4; alignment++)
  {
    char *bitstream = bitstream_buffer + 4 + alignment;
    int num_bytes, num_codes;

    bitstream[-1] = 0x59;
    num_bytes = (*fn_write)(bitstream, message_codes, message_codebits) - bitstream;
    if (bitstream[-1] != 0x59)
    {
      errors++;
      printf("Write bits corrupted initial memory %02x\n", bitstream[-1]);
    }
    
#if 0
    /* display the bitstream buffer contents */
    printf("bitstream = ");
    for (i=0; i<num_bytes; i++)
    {
      if ((i % 8)==0) putchar('\n');
      for (k=0x80; k!=0; k>>=1)
      {
        if (k & bitstream[i]) putchar('1');
        else putchar('0');
      }
      putchar(' ');
    }
    printf("\n");
#endif
    
#if VERBOSE
    printf("Alignment=%d Bytes written=%d\n", alignment, num_bytes);
#endif
    
    num_codes = (*fn_read)(bitstream, received_codes, look_code, look_codebits) - received_codes;
  
    if (num_codes!=MESSAGE_LENGTH-1)
    {
      errors++;
      printf("Message length incorrect: %d %d\n", MESSAGE_LENGTH-1, num_codes);
    }
    for (i=0; i<num_codes; i++)
    {
      if (message_codes[i]!=received_codes[i])
      {
        errors++;
        printf("Mismatch[%d]: %08x %08x\n", i, message_codes[i], received_codes[i]);
      }
    }

  }
  
  return errors;
}

/* Test switch functions */

int test_switch(
  char *name,           /* function name */
  fn_switch *ref,       /* ref */
  fn_switch *fn         /* fn to test */
)
{
  int i, j, k, errors=0;
  
  printf("Testing function: %s\n", name);
  
  for (k=0; k<512; k++)
  {
    i = (*ref)(k);
    j = (*fn)(k);
    
    if (i != j)
    {
      errors++;
      printf("Mismatch[%d]: %08x %08x\n", k, i, j);
    }
  }
  
  return errors;
}

/* Test unaligned checksum functions */

int test_checksum(
  char *name,           /* function name */
  fn_checksum *ref,       /* ref */
  fn_checksum *fn         /* fn to test */
)
{
  char data[]="16ygsy1gygdy3287484848df82hdun32dkj2nidjhid23";
  int i, j, a, errors=0;
  
  printf("Testing function: %s\n", name);
  
  for (a=0; a<4; a++)
  {
    /* for each alignment */
    i = (*ref)(&data[a], 3);
    j = (*fn)(&data[a], 3);
    
    if (i != j)
    {
      errors++;
      printf("Mismatch[%d]: %08x %08x\n", a, i, j);
    }
  }
  
  return errors;
}

int test_loadstore(
  char *load,          /* function name */
  char *store,         /* function name */
  fn_load *fload,
  fn_store *fstore,
  int big              /* big endian flag */
)
{
  char data[8];
  int a, errors=0;
  
  printf("Testings function: %s %s\n", load, store);
  
  for (a=0; a<4; a++)
  {
    int val;
  
    /* for each alignment */
    memset(data, 0, 8);
    
    (*fstore)(data+a, 0x01020304);
    if (big)
    {
      val = ref_read_32_big(data+a); 
    }
    else
    {
      val = ref_read_32_little(data+a); 
    }    
    
    if (val != 0x01020304)
    {
      errors++;
      printf("Mismatch[%d]: store %08x %08x\n", a, 0x01020304, val);
    }
    
    val = (*fload)(data+a);
    if (val != 0x01020304)
    {
      errors++;
      printf("Mismatch[%d]: load  %08x %08x\n", a, 0x01020304, val);
    }    
  }
  
  return errors;
}
