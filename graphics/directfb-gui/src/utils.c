/*
 * utils.c
 *
 *  Created on: Feb 10, 2012
 *      Author: admin
 */


#include "utils.h"
#include "dfb.h"

DFBColor
create_color (int r, int g, int b, int a)
{
  DFBColor c;
  c.r = r;
  c.g = g;
  c.b = b;
  c.a = a;
  return c;
}

void
create_font (const char *fontName, DFBFontDescription * fds,
	     IDirectFBFont ** font)
{
  printf ("fontName: %s\n", fontName);
  assert (dfb != NULL);
  DFBCHECK (dfb->
	    CreateFont (dfb, fontName, fds, font));
}

void
rectangle_clamp (DFBRectangle * rec, DFBRectangle * against)
{
  assert (rec != NULL);
  assert (against != NULL);

  int xDiff = against->w - against->x;
  int yDiff = against->h - against->y;
}
