#include <stdio.h>

static void print_all(FILE *stream)
{
  int c;
  while ((c = getc(stream)) != EOF) {
    putchar(c);
  }
}

int main(int argc, char *argv[])
{
  FILE *stream;
  if ((stream = popen("netstat", "r")) != NULL ) {
    print_all(stream);
    pclose(stream);
  }
  return 0;
}
