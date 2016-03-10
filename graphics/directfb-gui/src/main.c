/*
 * main.c
 *
 *  Created on: Feb 9, 2012
 *      Author: admin
 */

#include <stdio.h>
#include <stdlib.h>

#include "dfb.h"
#include "guisubsystem.h"

int
main (int arg, char **argv)
{
  dfb = 0;
  dfb_init (arg, argv, 640, 480);
  gui_init ();
  dfb_loop ();
  gui_destroy ();
  dfb_destroy ();
  return 0;
}
