/*
 * textlist.h
 *
 *  Created on: Feb 4, 2012
 *      Author: admin
 */

#ifndef TEXTAREA_H_
#define TEXTAREA_H_

#include "dfb.h"

typedef struct TextAreaLooks
{
  DFBColor textColor;
  DFBColor backColor;
  DFBColor borderColor;
  DFBFontDescription textWindowFontDsc;
  IDirectFBFont *textFont;

} TextAreaLooks;

typedef struct TextArea
{
  char *text;
  int textSize;
  int maxTextSize;
  int fontHeight;
  int transparency;
  TextAreaLooks looks;
  DFBRectangle dimensions;
  int cursorPos;

} TextArea;

TextArea *textarea_create (const char *text, int maxTextSize,
			   DFBRectangle * dimensions, TextAreaLooks * looks);
void textarea_destroy (TextArea * this);
int textarea_addchar (TextArea * this, char c);
int textarea_removecharbsp (TextArea * this);
int textarea_removechardel (TextArea * this);
int textarea_cursormove (TextArea * this, int where);
void textarea_draw (TextArea * this, IDirectFBSurface * surface);
char *textarea_gettext (TextArea * this);
void textarea_clear (TextArea * this);

#endif /* TEXTAREA_H_ */
