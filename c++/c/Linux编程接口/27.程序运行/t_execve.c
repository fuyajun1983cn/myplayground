#include "tlpi_hdr.h"

int
main(int argc, char *argv[])
{
  char *argVec[10]; /* larger than required */
  char *envVec[] = {"GREET=salut", "BYE=adiue", NULL};

  if (argc != 2 || strcmp(argv[1], "--help") == 0) {
    usageErr("%s pathname\n", argv[0]);
  }

  argVec[0] = strrchr(argv[1], '/');
  if (argVec[0] != NULL)
    argVec[0]++;
  else
    argVec[0] = argv[1];
  argVec[1] = "Hello World";
  argVec[2] = "Good Bye";
  argVec[3] = NULL;

  execve(argv[1], argVec, envVec);
  errExit("recve"); /* if we get here, something is wrong */
}
