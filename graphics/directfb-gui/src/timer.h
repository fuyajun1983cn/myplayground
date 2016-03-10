/*
 * timer.h
 *
 *  Created on: Feb 4, 2012
 *      Author: admin
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <pthread.h>
#include "dialog.h"

struct stopwatch
{
  int seconds;
  void (*func_ptr) (Dialog * this);
  Dialog *dialog;
} g_stopwatch;

void start_timer (int seconds, Dialog * this, void (*_f_ptr) (Dialog * this));

#endif /* TIMER_H_ */
