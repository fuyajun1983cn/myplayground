/*
 * dialog.h
 *
 *  Created on: Feb 4, 2012
 *      Author: admin
 */

#ifndef DIALOG_H_
#define DIALOG_H_

#include "textarea.h"

enum INPUT_MODE
{ SMALLALPHA_MODE, BIGALPHA_MODE, NUM_MODE } INPUT_MODES;

typedef struct DialogLooks
{
  IDirectFBFont *fontText;
  IDirectFBFont *fontTitle;
  IDirectFBFont *fontTip;
  DFBFontDescription fontDsc;
  DFBColor titleColor;
  DFBColor titleTextColor;
  DFBColor backColor;
  DFBColor textColor;
  DFBColor tipColor;
  unsigned short titleHeight;

} DialogLooks;

typedef struct Dialog
{
  enum INPUT_MODE input_mode;
  const char *name;
  unsigned short width;
  unsigned short height;
  DFBPoint dialogPos;
  DialogLooks looks;
  TextArea *textArea;

} Dialog;



Dialog *dialog_create (const char *name, DFBRectangle * dimensions,
		       enum INPUT_MODE inputMode, DialogLooks * dlooks);
void dialog_destroy (Dialog * this);

void dialog_eventhandler (Dialog * this, DFBInputDeviceKeySymbol * sym);
int dialog_addtextarea (Dialog * this);
void dialog_draw (Dialog * this, IDirectFBSurface * surface);
void dialog_switchinputmode (Dialog * this);
int dialog_addlooks (Dialog * this, DialogLooks * looks);
void dialog_resetproperties (Dialog * this);
const char *dialog_getname (Dialog * this);

#endif /* DIALOG_H_ */
