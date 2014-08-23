#ifndef FYJSTD_H
#define FYJSTD_H

#define FYJ_API

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <sys/time.h>
#include <unistd.h>

#ifndef ASSERT
#define ASSERT(str) assert(0 && (str))
#endif

#define FYJ_FILE		FILE
#define FYJ_READ	"r"
#define FYJ_READBINARY "rb"
#define FYJ_WRITE	"w"
#define FYJ_APPEND	"a"

#define FYJ_SEEK_SET	SEEK_SET
#define FYJ_SEEK_CUR	SEEK_CUR
#define FYJ_SEEK_END	SEEK_END

#define FYJ_EOF	EOF

#define fyj_fread	fread
#define fyj_fwrite	fwrite
#define fyj_fputc	fputc
#define fyj_fopen	fopen
#define fyj_fseek	fseek
#define fyj_ftell	ftell
#define fyj_fclose	fclose

#define fyj_printf     printf
#define fyj_fprintf	fprintf
#define fyj_fflush	fflush
#define fyj_ltostr	ltostr


#define fyj_new new
#define fyj_delete delete

#define fyj_memcpy	memcpy
#define fyj_malloc	malloc
#define fyj_memset	memset
#define fyj_memmove memmove
#define fyj_free	free
#define fyj_realloc	realloc

#define fyj_strlen	strlen
#define fyj_strdup	strdup

#define fyj_sprintf	sprintf
#define fyj_strcmp	strcmp
#define fyj_memcmp	memcmp

#define fyj_strtod	strtod
#define fyj_strcpy	strcpy
#define fyj_strncpy	strncpy

#define fyj_atoi   atoi

#define fyj_abs(x)	(x<0)?(-x):(x)
#define fyj_fabs	glb_abs

typedef unsigned long long uint64;
typedef signed long long int64;
typedef signed int		int32;
typedef unsigned int	uint32;
typedef signed short	int16;
typedef unsigned short	uint16;
typedef signed char		int8;
typedef unsigned char	uint8;

typedef unsigned int	size_t;


#define CHECK_POINTER(ptr)  \
							if (!(ptr)) { \
								fyj_fprintf(stderr, "NULL Pointer detected at %d in %d", __LINE__, __FILE__ );\
							}
							
#endif