/**
 * Copyright (c)  2017     Yajun Fu (fuyajun1983cn@163.com)
 * 
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

static void handle_child_process_output(char buf[], int count)
{
  for (int i = 0; i < count; i++) {
    putchar(buf[i]);
  }
}

int main(int argc, char *argv[])
{
  int filedes[2];
  if (pipe(filedes) == -1) {
    perror("create pipe failed\n");
    exit(1);
  }

  char *argVec[10];
  if (argc != 2)
    exit(1);
  argVec[0] = strrchr(argv[1], '/');
  if (argVec[0] != NULL)
    argVec[0]++;
  else
    argVec[0] = argv[1];

  argVec[1] = "-H";
  argVec[2] = NULL; /* It must be null terminated */
      

  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    exit(1);
  } else if (pid == 0) {
    /* filedes[1] --> entrance
       filedes[0] --> exit
    */
    while((dup2(filedes[1], STDOUT_FILENO) == -1) && (errno == EINTR)) {
      perror("connect stdout to filedes[1]");
    }
    /*
    while((dup2(filedes[1], STDERR_FILENO) == -1) && (errno == EINTR)) {
      perror("connect stderr to filedes[1]");
      }*/
    close(filedes[0]);
    execve(argv[1], argVec, (char*)0);
    //execl("/usr/bin/df", "df", "-H', (char*)0");
    perror("exit");
    _exit(1);
  }

  /* filedes[1] --> entrance
     filedes[0] --> exit
  */
  /*
  while((dup2(filedes[0], STDOUT_FILENO) == -1) && (errno == EINTR)) {
    perror("connect filedes[0] to stdout");
    }*/
  /*
  while((dup2(filedes[0], STDERR_FILENO) == -1) && (errno == EINTR)) {
    perror("connect filedes[0] to stderr");
    }*/
  /* the parent process has no need to access the entrance of the pipe */
  close(filedes[1]);
  
  char buffer[4096];
  while (1) {
    ssize_t count = read(filedes[0], buffer, sizeof(buffer));
    if (count == -1) {
      if (errno == EINTR)
        continue;
      else {
        perror("failed to read");
        exit(1);
      }
    } else if (count == 0){
      break;
    } else {
      handle_child_process_output(buffer, count);
    }
  }
  close(filedes[0]);
  
  return 0;
}

