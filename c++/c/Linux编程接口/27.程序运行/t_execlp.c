#include "tlpi_hdr.h"

int
main(int argc, char *argv[])
{
  if (argc != 2 || strcmp(argv[1], "--help") == 0)
    usageErr("%s filename\n", argv[0]);

  execlp(argv[1], argv[1], "Hell world", (char *)NULL);
  errExit("execlp");
}
