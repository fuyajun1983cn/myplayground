/*
 * timer.c
 *
 *  Created on: Feb 4, 2012
 *      Author: admin
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "timer.h"
#include <sys/time.h>

void *g_start_timer (void *data);

pthread_mutex_t fakeMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t fakeCond = PTHREAD_COND_INITIALIZER;

void
start_timer (int secs, Dialog * this, void (*_f_ptr) (Dialog * this))
{
  g_stopwatch.seconds = secs;
  g_stopwatch.func_ptr = _f_ptr;
  g_stopwatch.dialog = this;

  pthread_t thread_id;

  int rc =
    pthread_create (&thread_id, NULL, g_start_timer, (void *) &g_stopwatch);

  if (rc)
    printf ("Error creating timer thread\n");
}

void
sleepy (int secs)
{
  struct timespec timeToWait;
  const struct timespec *restrict timeToWaitP;
  struct timeval now;

  gettimeofday (&now, NULL);

  timeToWait.tv_sec = now.tv_sec + secs;
  timeToWait.tv_nsec = now.tv_usec * 200;

  timeToWaitP = &timeToWait;

  pthread_mutex_lock (&fakeMutex);
  pthread_cond_timedwait (&fakeCond, &fakeMutex, timeToWaitP);
  pthread_mutex_unlock (&fakeMutex);
}

void *
g_start_timer (void *data)
{
  int seconds = ((struct stopwatch *) data)->seconds;
  void (*callback_fn) (Dialog * this) = ((struct stopwatch *) data)->func_ptr;
  sleepy (seconds);
  (*callback_fn) (((struct stopwatch *) data)->dialog);
  return NULL;
}
