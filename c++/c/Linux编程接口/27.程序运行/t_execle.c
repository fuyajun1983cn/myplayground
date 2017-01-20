#include "tlpi_hdr.h"

int
main(int argc, char *argv[])
{
  char *envVec[] = { "GREET=salut", "BYE=dieu"};
  char *filename;
  
  if (argc != 2 || strcmp(argv[1], "--help") == 0)
    usageErr("%s pathname\n", argv[0]);

  filename = strrchr(argv[1], '/');
  if (filename != NULL)
    filename++;
  else
    filename = argv[1];

  execle(argv[1], filename, "Hello world", (char *)NULL, envVec);
  errExit("execle");
}
