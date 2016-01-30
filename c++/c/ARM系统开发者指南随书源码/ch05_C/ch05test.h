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
 * Test module for the example routines of Chapter 4
 */

#ifndef CH05TEST_H
#define CH05TEST_H

/* compiler dependent options */
#ifdef __GNUC__
  #define __packed
  #define __pure
  #define __inline inline
#endif

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

/* function prototypes */
typedef int fn_checksum(void *data, unsigned int N);
typedef void fn_tohex(char *out, unsigned int in);
typedef void fn_scale(
  unsigned int *dest, 
  unsigned int *src,
  unsigned int scale,
  unsigned int length);
typedef void fn_tolower(char *out, char *in);
typedef int fn_satcor(short *x, short *y, unsigned int N);
typedef int fn_readint(char *data);
typedef void fn_readsamp(short *out, char *in, unsigned int N);
typedef int fn_div(int n, int d);

/* Section 5.1 - introduction */
void memclr(char *data, int N);

/* Section 5.2 - types */
int testchar(char *p, char a);
int testshort(short *p, short a);
long testlong(long *p, long a);
long long testlonglong(long long *p, long long a);
int checksum_v1(int *data);
int checksum_v1_s(int *data);
int checksum_v2(int *data);
int checksum_v2_s(int *data);
short checksum_v3(short *data);
short checksum_v3_s(short *data);
short checksum_v4(short *data);
short checksum_v4_s(short *data);
short add_v1(short a, short b);
int add_v2(int a, int b);
short add_v3(short a, short b);
int average_v1(int a, int b);
unsigned int average_v2(unsigned int a, unsigned int b);

/* Section 5.3 - looping */
int checksum_v5(int *data);
int checksum_v5_s(int *data);
int checksum_v6(int *data);
int checksum_v6_s(int *data);
int checksum_v7(int *data, unsigned int N);
int checksum_v7_s(int *data, unsigned int N);
int checksum_v8(int *data, unsigned int N);
int checksum_v8_s(int *data, unsigned int N);
int checksum_v9(int *data, unsigned int N);
int checksum_v9_s(int *data, unsigned int N);
int checksum_v10(int *data, unsigned int N);
int checksum_v10_s(int *data, unsigned int N);

/* Section 5.4 - register allocation */

/* Section 5.5 - function calls */
char *queue_bytes_v1(
  char *Q_start,        /* Queue buffer start address */
  char *Q_end,          /* Queue buffer end address */
  char *Q_ptr,          /* Current queue pointer position */
  char *data,           /* Data to insert into the queue */
  unsigned int N);      /* Number of bytes to insert */
char *queue_bytes_v1_s(
  char *Q_start,        /* Queue buffer start address */
  char *Q_end,          /* Queue buffer end address */
  char *Q_ptr,          /* Current queue pointer position */
  char *data,           /* Data to insert into the queue */
  unsigned int N);      /* Number of bytes to insert */

typedef struct {
  char *Q_start;        /* Queue buffer start address */
  char *Q_end;          /* Queue buffer end address */
  char *Q_ptr;          /* Current queue pointer position */
} Queue;

void queue_bytes_v2(Queue *queue, char *data, unsigned int N);
void queue_bytes_v2_s(Queue *queue, char *data, unsigned int N);

unsigned int nybble_to_hex(unsigned int in);
void uint_to_hex(char *out, unsigned int in);
void uint_to_hex_s(char *out, unsigned int in);

/* Section 5.6 - pointer aliasing */
void timers_v1(int *timer1, int *timer2, int *step);
typedef struct { int step; } State;
typedef struct { int timer1, timer2; } Timers;
void timers_v2(State *state, Timers *timers);
void timers_v3(State *state, Timers *timers);
int *get_next_packet(int *N);
int checksum_next_packet(void);
void ctolower(char *c);
int clip1(int);
int inc1(int sum, int *step);

/* Section 5.7 - structure layout */
typedef
struct {
  char a;
  int  b;
  char c;
  short d;
}
struct_1;

typedef
struct {
  char a;
  char c;
  short d;
  int b;
}
struct_2;

typedef
__packed struct {
  char a;
  int  b;
  char c;
  short d;
}
struct_3;

typedef enum {
  FALSE,
  TRUE
} Bool;

/* 5.8 - Bitfields */

void dostageA(void);
void dostageB(void);
void dostageC(void);

typedef struct {
  unsigned int stageA : 1;
  unsigned int stageB : 1;
  unsigned int stageC : 1;
} Stages_v1;
  
void dostages_v1(Stages_v1 *stages);

typedef unsigned long Stages_v2;
#define STAGEA (1ul<<0)
#define STAGEB (1ul<<1)
#define STAGEC (1ul<<2)

void dostages_v2(Stages_v2 *stages2);

/* 5.9 - Alignment and Endianness */

int readint(__packed int *data);
int readint_little(char *data);
int readint_big(char *data);
void read_samples(short *out, char *in, unsigned int N);

/* 5.10 - Division */

typedef struct {
  int x;
  int y;
} point;
    
typedef point fn_getxy(unsigned int offset, unsigned int bytes_per_line);
point getxy_v1(unsigned int offset, unsigned int bytes_per_line);
point getxy_v1_s(unsigned int offset, unsigned int bytes_per_line);
point getxy_v2(unsigned int offset, unsigned int bytes_per_line);
point getxy_v2_s(unsigned int offset, unsigned int bytes_per_line);
void scale(unsigned int *dest, unsigned int *src, unsigned int scale, unsigned int length);
void scale_s(unsigned int *dest, unsigned int *src, unsigned int scale, unsigned int length);
unsigned int udiv_by_const(unsigned int n, unsigned int d);
int sdiv_by_const(int n, int d);

/* 5.12 - Inline functions */

fn_satcor sat_correlate_v1;
fn_satcor sat_correlate_v2;
fn_satcor sat_correlate_v3;
fn_satcor sat_correlate_v1_s;
fn_satcor sat_correlate_v2_s;
fn_satcor sat_correlate_v3_s;

void flush_Icache(void);
void str_tolower(char *out, char *in);
void str_tolower_s(char *out, char *in);



/* Test checksum operations */
int test_checksum(
  char *name,           /* function name */
  fn_checksum *fn,      /* function to test */
  int N,                /* number of elements */
  int size              /* size of each element in bytes */
);

#define TEST_CHECKSUM(name, N, size) errors += test_checksum(#name, (fn_checksum*)(&name), N, size);

/* Test queue operations */
int test_queue(
  char *name,           /* function name */
  int version           /* version */
);

#define TEST_QUEUE(name, ver) errors += test_queue(#name, ver);

/* Test to hex conversion */
int test_tohex(
  char *name,           /* function name */
  fn_tohex *fn          /* function to test */
);

#define TEST_TOHEX(name) errors += test_tohex(#name, &name);

/* Test to getxy routines */
int test_getxy(
  char *name,           /* function name */
  fn_getxy *fn          /* function to test */
);

#define TEST_GETXY(name) errors += test_getxy(#name, &name);

/* Test scale routines */
int test_scale(
  char *name,           /* function name */
  fn_scale *fn          /* function to test */
);

#define TEST_SCALE(name) errors += test_scale(#name, &name);

/* Test string to lower case */
int test_tolower(
  char *name,           /* function name */
  fn_tolower *fn        /* function to test */
);

#define TEST_TOLOWER(name) errors += test_tolower(#name, &name);

/* Test saturating correlate */
int test_satcor(
  char *name,           /* function name */
  fn_satcor *fn         /* function to test */
);

#define TEST_SATCOR(name) errors += test_satcor(#name, &name);

/* Test read ints */
int test_readint(
  char *name,           /* function name */
  fn_readint *fn,       /* function to test */
  int big               /* endianness */
);

#define TEST_READINT(name, big) errors += test_readint(#name, (fn_readint*)&name, big);

/* Test read samples */
int test_readsamp(
  char *name,           /* function name */
  fn_readsamp *fn        /* function to test */
);

#define TEST_READSAMP(name) errors += test_readsamp(#name, &name);

/* Test divide routines */
int test_div(
  char *name,           /* function name */
  fn_div *fn,           /* function to test */
  int sign              /* set for signed divide */
);

#define TEST_DIV(name, sign) errors += test_div(#name, (fn_div*)&name, sign);

#endif
