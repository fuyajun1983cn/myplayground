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
 * Chapter 5 example routines
 */
 
#include "ch05test.h"

/* Section 5.1 */
/* initial example */

void memclr(char *data, int N)
{
  for ( ; N>0; N--)
  {
    *data=0;
    data++;
  }
}

/* Section 5.2 - look at basic data types */
/* first check whether char is signed or unsigned */

int testchar(char *p, char a)
{
  return *p + a;
}

int testshort(short *p, short a)
{
  return *p + a;
}

long testlong(long *p, long a)
{
  return *p + a;
}

long long testlonglong(long long *p, long long a)
{
  return *p + a;
}

/* checksum routines
 * checksum of a 64-bit packet
 */

int checksum_v1(int *data)
{
  char i;
  int sum=0;
   
  for (i=0; i<64; i++)
  {
    sum += data[i];
  }
  return sum;
}
  

int checksum_v2(int *data)
{
  unsigned int i;
  int sum=0;
    
  for (i=0; i<64; i++)
  {
    sum += data[i];
  }
  return sum;
}
  

short checksum_v3(short *data)
{
  unsigned int i;
  short sum=0;
    
  for (i=0; i<64; i++)
  {
    sum = (short)(sum + data[i]);
  }
  return sum;
}

/* Example 5.1 */  

short checksum_v4(short *data)
{
  unsigned int i;
  int sum=0;
    
  for (i=0; i<64; i++)
  {
    sum += *(data++);
  }
  return (short)sum;
}

short add_v1(short a, short b)
{
  return (short)(a + (b>>1));
}
  
int add_v2(int a, int b)
{
  return add_v3((short)a,(short)b);
}

/* signed int no good for /2 */  

int average_v1(int a, int b)
{
  return (a+b)/2;
}

unsigned int average_v2(unsigned int a, unsigned int b)
{
  return (a+b)/2;
}

/* 5.3 - C looping structures */

int checksum_v5(int *data)
{
  unsigned int i;
  int sum=0;
    
  for (i=0; i<64; i++)
  {
    sum += *(data++);
  }
  return sum;
}

/* Example 5.2 */

int checksum_v6(int *data)
{
  unsigned int i;
  int sum=0;
    
  for (i=64; i!=0; i--)
  {
    sum += *(data++);
  }
  return sum;
}


int checksum_v7(int *data, unsigned int N)
{
  int sum=0;
    
  for ( ; N!=0; N--)
  {
    sum += *(data++);
  }
  return sum;
}

/* Example 5.3 */

int checksum_v8(int *data, unsigned int N)
{
  int sum=0;
    
  do
  {
    sum += *(data++);
  } while ( --N!=0);
  return sum;
}

/* Example 5.4 */

int checksum_v9(int *data, unsigned int N)
{
  int sum=0;
    
  do
  {
    sum += *(data++);
    sum += *(data++);
    sum += *(data++);
    sum += *(data++);
    N-=4;
  } while ( N!=0);
  return sum;
}

/* Example 5.5 */

int checksum_v10(int *data, unsigned int N)
{
  unsigned int i;
  int sum=0;
    
  for (i=N/4; i!=0; i--)
  {
    sum += *(data++);
    sum += *(data++);
    sum += *(data++);
    sum += *(data++);
  }
  for (i=N&3; i!=0; i--)
  {
    sum += *(data++);
  }
  return sum;
}

/* Section 5.4 - register allocation */

/* Section 5.5 - function calls */

/* four function arguments */
/* actually a very good aliasing example! */
/* second is 1 instruction longer - but more efficient overall */

char *queue_bytes_v1(
  char *Q_start,        /* Queue buffer start address */
  char *Q_end,          /* Queue buffer end address */
  char *Q_ptr,          /* Current queue pointer position */
  char *data,           /* Data to insert into the queue */
  unsigned int N)       /* Number of bytes to insert */
{
  do
  {
    *(Q_ptr++) = *(data++);
    
    if (Q_ptr == Q_end)
    {
      Q_ptr = Q_start;
    }
  } while (--N);
  return Q_ptr;
}

/* Example 5.6 */
  
void queue_bytes_v2(Queue *queue, char *data, unsigned int N)
{
  char *Q_ptr = queue->Q_ptr;
  char *Q_end = queue->Q_end;
    
  do
  {
    *(Q_ptr++) = *(data++);

    if (Q_ptr == Q_end)
    {
      Q_ptr = queue->Q_start;
    }
  } while (--N);
  queue->Q_ptr = Q_ptr;
}
  
/* show that calls to functions declared in same file are more efficient */

/* Example 5.7 */

unsigned int nybble_to_hex(unsigned int d)
{
  if (d<10)
  {
    return d+'0';
  }
  return d-10+'A';
}

void uint_to_hex(char *out, unsigned int in)
{
  unsigned int i;
    
  for (i=8; i!=0; i--)
  {
    in = (in<<4) | (in>>28); /* rotate in left by 4 bits */
    *(out++) = (char)nybble_to_hex(in & 15);
  }
}

/* Section 5.6 - pointer aliasing */

void timers_v1(int *timer1, int *timer2, int *step)
{
  *timer1 += *step;
  *timer2 += *step;
}

void timers_v2(State *state, Timers *timers)
{
  timers->timer1 += state->step;
  timers->timer2 += state->step;
}

/* Example 5.8 */
  
void timers_v3(State *state, Timers *timers)
{
  int step = state->step;
  
  timers->timer1 += step;
  timers->timer2 += step;
}
  
int checksum_next_packet(void)
{
  int *data;
  int N, sum=0;
  
  data = get_next_packet(&N);
  
  do
  {
    sum += *(data++);
  } while (--N);
  
  return sum;
}

void ctolower(char *c)
{
  if (*c>='A' && *c<='Z')
  {
    *c += 'a'-'A';
  }
}

/* function call subexpression elimination */
/* unless clip1() declared as pure - but that's armcc only */

int inc1(int sum, int *step)
{
  sum += *step;
  sum = clip1(sum);
  sum += *step;
  return sum;
}


/* Section 5.7 - structure arrangement */

/* Section 5.8 - bitfields */
  

void dostages_v1(Stages_v1 *stages)
{
  if (stages->stageA)
  {
    dostageA();
  }
  if (stages->stageB)
  {
    dostageB();
  }
  if (stages->stageC)
  {
    dostageC();
  }
}

/* Example 5.9 */
  
void dostages_v2(Stages_v2 *stages_v2)
{
  Stages_v2 stages = *stages_v2;
    
  if (stages & STAGEA)
  {
    dostageA();
  }
  if (stages & STAGEB)
  {
    dostageB();
  }
  if (stages & STAGEC)
  {
    dostageC();
  }
}
  
/* Section 5.9 - unaligned datra and endianness */

#ifdef __ARMCC_VERSION
  
int readint(__packed int *data)
{
  return *data;
}

#endif

/* Example 5.10 */

int readint_little(char *data)
{
  int a0,a1,a2,a3;
    
  a0 = *(data++);
  a1 = *(data++);
  a2 = *(data++);
  a3 = *(data++);
  return a0 | (a1<<8) | (a2<<16) | (a3<<24);
}

int readint_big(char *data)
{
  int a0,a1,a2,a3;
    
  a0 = *(data++);
  a1 = *(data++);
  a2 = *(data++);
  a3 = *(data++);
  return (((((a0<<8) | a1)<<8) | a2)<<8) | a3;
}

/* Example 5.11 */

void read_samples(short *out, char *in, unsigned int N)
{
  unsigned short *data; /* aligned input pointer */
  unsigned int sample, next;
  
  switch ((unsigned int)in & 1)
  {
    case 0: /* the input pointer is aligned */
      data = (unsigned short *)in;
      do
      {
        sample = *(data++);
#ifdef __BIG_ENDIAN
        sample = (sample>>8) | (sample<<8);
#endif
        *(out++) = (short)sample;
      } while (--N);
      break;
      
    case 1: /* the input pointer is not aligned */
      data = (unsigned short *)(in-1);
      sample = *(data++);
#ifdef __BIG_ENDIAN
      sample = sample & 0xFF; /* get first byte of sample */
#else
      sample = sample >> 8;   /* get first byte of sample */
#endif
      do
      {
        next = *(data++);
        /* complete one sample and start the next */
#ifdef __BIG_ENDIAN
        *out++ = (short)((next & 0xFF00) | sample);
        sample = next & 0xFF;
#else
        *out++ = (short)((next<<8) | sample);
        sample = next>>8;
#endif
      } while (--N);
      break;
  }
}

/* Section 5.10 - division */

point getxy_v1(unsigned int offset, unsigned int bytes_per_line)
{
  point p;
    
  p.y = offset / bytes_per_line;
  p.x = offset - p.y * bytes_per_line;
  return p;
}

/* Example 5.12 */
  
point getxy_v2(unsigned int offset, unsigned int bytes_per_line)
{
  point p;
    
  p.x = offset % bytes_per_line;
  p.y = offset / bytes_per_line;
  return p;
}

/* Example 5.13 */
  
void scale(
  unsigned int *dest,   /* destination for the scale data */
  unsigned int *src,    /* source unscaled data */
  unsigned int d,       /* denominator to divide by */
  unsigned int N)       /* data length */
{
  unsigned int s = 0xFFFFFFFFu / d;

  do
  {
    unsigned int n, q, r;
      
    n = *(src++);
    q = (unsigned int)( ((unsigned long long)n * s) >> 32);
    r = n - q*d;
    if (r >= d)
    {
      q++;
    }
    *(dest++) = q;
  } while (--N);
}

/* Example 5.14 */

unsigned int udiv_by_const(unsigned int n, unsigned int d)
{
  unsigned int s,k,q;
  
  /* We assume d!=0 */
    
  /* first find k such that (1<<k) <= d < (1<<(k+1)) */
  for (k=0; d/2>=(1u<<k); k++);
  
  if (d==1u<<k)
  {
     /* we can implement the divide with a shift */
     return n>>k;
  }
  
  /* d is in the range (1<<k) < d < (1<<(k+1)) */
  s = (unsigned int)(((1ull<<(32+k))+(1ull<<k))/d);
  
  if ((unsigned long long)s*d >= (1ull<<(32+k)))
  {
    /* n/d = (n*s)>>(32+k) */
    q = (unsigned int)(((unsigned long long)n*s)>>32);
    return q>>k;
  }
  
  /* n/d = (n*s+s)>>(32+k) */
  q = (unsigned int)(((unsigned long long)n*s + s)>>32);
  return q>>k;
}

/* Example 5.15 */

int sdiv_by_const(int n, int d)
{
  int s,k,q;
  unsigned int D;
  
  /* set D to be the absolute value of d, we assume d!=0 */
  if (d>0)
  {
    D=(unsigned int)d;   /* 1 <= D <= 0x7FFFFFFF */
  }
  else
  {
    D=(unsigned int)-d;  /* 1 <= D <= 0x80000000 */
  }
    
  /* first find k such that (1<<k) <= D < (1<<(k+1)) */
  for (k=0; D/2>=(1u<<k); k++);
  
  if (D==1u<<k)
  {
     /* we can implement the divide with a shift */
     q = n>>31;         /* 0 if n>0, -1 if n<0 */
     q = n + ((unsigned)q>>(32-k)); /* insert rounding */
     q = q>>k;          /* divide */
     if (d<0)
     {
       q = -q;          /* correct sign */
     }
     return q;
  }
  
  /* Next find s in the range 0<=s<=0xFFFFFFFF */
  /* Note that k here is one smaller than the k in the equation */
  s = (int)(((1ull<<(31+(k+1)))+(1ull<<(k+1)))/D);
    
  if (s>=0)
  {
    q = (int)(((signed long long)n*s)>>32);
  }
  else
  {
    /* (unsigned)s = (signed)s + (1<<32) */
    q = n + (int)(((signed long long)n*s)>>32);
  }
  q = q>>k;
  
  /* if n<0 then the formula requires us to add one */
  q += (unsigned)n>>31;
  
  /* if d was negative we must correct the sign */
  if (d<0)
  {
    q = -q;
  }
  
  return q;
}


/* Section 5.12 - inline functions and inline assembler */

__inline int qmac_v1(int a, int x, int y)
{
  int i;
  
  i = x*y; /* this multiplication cannot saturate */
  if (i>=0)
  {
    /* x*y is positive */
    i = 2*i;
    if (i<0)
    {
      /* the doubling saturated */
      i = 0x7FFFFFFF;
    }
    if (a + i < a)
    {
      /* the addition saturated */
      return 0x7FFFFFFF;
    }
    return a + i;
  }
  /* x*y is negative so the doubling can't saturate */
  if (a + 2*i > a)
  {
    /* the accumulate saturated */
    return -0x80000000;
  }
  return a + 2*i;
}

int sat_correlate_v1(short *x, short *y, unsigned int N)
{
  int a=0;
  
  do
  {
    a = qmac_v1(a, *(x++), *(y++) );
  } while (--N);
  return a;
}

#if !defined(__thumb) /* if compiling for ARM rather than Thumb */

/* Example 5.16 */

__inline int qmac_v2(int a, int x, int y)
{
  int i;
  const int mask = 0x80000000;
  
  i = x*y;
#ifdef __ARMCC_VERSION /* check for the armcc compiler */
  __asm
  {
    ADDS  i, i, i               /* double */
    EORVS i, mask, i, ASR 31    /* saturate the double */
    ADDS  a, a, i               /* accumulate */
    EORVS a, mask, a, ASR 31    /* saturate the accumulate */
  }
#endif
#ifdef __GNUC__ /* check for the gcc compiler */
  asm("ADDS  %0,%1,%2       ":"=r" (i):"r" (i)   ,"r" (i):"cc");
  asm("EORVS %0,%1,%2,ASR#31":"=r" (i):"r" (mask),"r" (i):"cc");
  asm("ADDS  %0,%1,%2       ":"=r" (a):"r" (a)   ,"r" (i):"cc");
  asm("EORVS %0,%1,%2,ASR#31":"=r" (a):"r" (mask),"r" (a):"cc");
#endif

  return a;
}

int sat_correlate_v2(short *x, short *y, unsigned int N)
{
  int a=0;
  
  do
  {
    a = qmac_v2(a, *(x++), *(y++) );
  } while (--N);
  return a;
}

#ifdef __TARGET_FEATURE_DSPMUL

/* Example 5.17 */

__inline int qmac_v3(int a, int x, int y)
{
  int i;
  
  __asm
  {
    SMULBB i, x, y  /* multiply */
    QDADD  a, a, i  /* double + saturate + accumulate + saturate */
  }
  return a;
}
  
int sat_correlate_v3(short *x, short *y, unsigned int N)
{
  int a=0;
  
  do
  {
    a = qmac_v3(a, *(x++), *(y++) );
  } while (--N);
  return a;
}

#endif

/* Example 5.18 */

void flush_Icache(void)
{
#ifdef __ARMCC_VERSION /* armcc */
  __asm { MCR p15, 0, 0, c7, c5, 0 }
#endif
#ifdef __GNUC__ /* gcc */
  asm ( "MCR p15, 0, r0, c7, c5, 0" );
#endif
}

#endif /* compiling for ARM not Thumb */

/* Example for section 6.3 */

void str_tolower(char *out, char *in)
{
  unsigned int c;
  
  do
  {
    c = *(in++);
    if (c>='A' && c<='Z')
    {
      c = c + ('a' - 'A');
    }
    *(out++) = (char)c;
  } while (c);
}
