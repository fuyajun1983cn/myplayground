
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <ctype.h>
#include <errno.h>

#define SV_SOCK_PATH "/tmp/ud_ucase"
#define BUF_SIZE 10  /* Maximum size of messages exchanged between client to server */

inline void usageErr(const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  vprintf(fmt, ap);
  vprintf("\n", ap);
  va_end(ap);
  exit(0);
}

inline void errExit(const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  vprintf(fmt, ap);
  vprintf("\n", ap);
  va_end(ap);
  exit(0);
}

inline void errMsg(const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  vprintf(fmt, ap);
  vprintf("\n", ap);
  va_end(ap);
}


inline void fatal(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  vprintf(fmt, ap);
  vprintf("\n", ap);
  va_end(ap);
}
