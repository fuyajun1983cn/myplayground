/*
 * dialog.c
 *
 *  Created on: Feb 4, 2012
 *      Author: admin
 */
#include "dialog.h"
#include <sys/time.h>
#include "timer.h"
#include "dfb.h"

enum DFBEM_NUMBERS
{ DFBEM_0 = 0x04, DFBEM_1 = 0x06, DFBEM_2 = 0x03, DFBEM_3 = 0x08,
  DFBEM_4 = 0x00, DFBEM_5 = 0x5D, DFBEM_6 = 0x01, DFBEM_7 = 0x05,
  DFBEM_8 = 0x02, DFBEM_9 = 0x07
};

static int numKeys = 0;
static int fieldCursor = 0;
static int indexTable = 0;
static int lastKey = -1;
static int firstKey = -1;
static int inputDif = 0;

static int ASCII_NUM_CAPS_DIFF = 48;
static int ASCII_CAPS_DIFFERENCE = -32;

char *alpha_table[11] = {
  ".,-?!'@:;/()",
  "abc",
  "def",
  "ghi",
  "jkl",
  "mno",
  "pqrs",
  "tuv",
  "wxyz",
  " \n",
  "0123456789"
};

static DFBBoolean __check_first__ = DFB_FALSE;

static void
send_character (Dialog * this, char c)
{
  textarea_addchar (this->textArea, c);
}

void
wait_sec_tosend (Dialog * this)
{
  numKeys--;
  if (numKeys == 0)
    {
      send_character (this,
		      alpha_table[indexTable][fieldCursor - 1] + inputDif);
      fieldCursor = 0;
    }
}

void
dialog_eventhandler (struct Dialog *this, DFBInputDeviceKeySymbol * sym)
{
  assert (this != NULL);
  firstKey = (*sym & 0xFF);
  if (firstKey >= DIKS_0 && firstKey <= DIKS_9)
    {
      indexTable = firstKey - ASCII_NUM_CAPS_DIFF;

      if (this->input_mode != NUM_MODE)
	{
	  inputDif = this->input_mode * ASCII_CAPS_DIFFERENCE;
	  int lastIndexTbl = lastKey - ASCII_NUM_CAPS_DIFF;

	  if ((firstKey == DIKS_0 || firstKey == DIKS_9)
	      && (this->input_mode == BIGALPHA_MODE))
	    {
	      inputDif = 0;
	    }

	  if ((firstKey != lastKey) && (numKeys > 0))
	    {
	      send_character (this,
			      alpha_table[lastIndexTbl][fieldCursor - 1] +
			      inputDif);
	      fieldCursor = 1;
	    }
	  else
	    fieldCursor++;

	  if (fieldCursor > strlen (alpha_table[indexTable]))
	    fieldCursor = 1;

	  numKeys++;

	  start_timer (1, this, wait_sec_tosend);

	  lastKey = firstKey;
	}
      else
	send_character (this, alpha_table[10][indexTable]);
    }

  if (__check_first__ == DFB_FALSE)
    {
      textarea_clear (this->textArea);
      __check_first__ = DFB_TRUE;
    }

}

const char *
dialog_getname (Dialog * this)
{
  assert (this != NULL);
  puts (this->name);
  return this->name;
}

void
dialog_switchinputmode (Dialog * this)
{
  assert (this != NULL);
  this->input_mode = (this->input_mode + 1) % 3;
  printf ("Input mode: %d\n", this->input_mode);
}

int
dialog_addlooks (Dialog * this, DialogLooks * looks)
{
  assert (this != NULL);
  assert (looks != NULL);
  this->looks = *looks;
  /*
   * TO-DO
   * Return code
   */
  return 0;
}

Dialog *
dialog_create (const char *name, DFBRectangle * dim,
	       enum INPUT_MODE inputMode, DialogLooks * dlooks)
{
  assert (dim != NULL);
  assert (dlooks != NULL);

  Dialog *tempD = NULL;

  tempD = (Dialog *) malloc (sizeof (Dialog));
  {
    tempD->name = name;
    tempD->input_mode = inputMode;
    tempD->textArea = NULL;
    tempD->dialogPos.x = dim->x;
    tempD->dialogPos.y = dim->y;
    tempD->width = dim->w;
    tempD->height = dim->h;
    tempD->input_mode = inputMode;
  }

  dialog_addlooks (tempD, dlooks);

  return tempD;
}

//hteo sam da ovako izgleda, da se prosledjuje surface
void
dialog_draw (struct Dialog *this, IDirectFBSurface * surface)
{
  //blending required
  surface->SetDrawingFlags (surface, DSDRAW_BLEND);

  // Porter Duff
  surface->SetPorterDuff (surface, DSPD_SRC_OVER);
  surface->SetBlittingFlags (surface, DSBLIT_BLEND_ALPHACHANNEL);

  //draw the main window
  DFBCHECK (surface->
	    SetColor (surface, this->looks.backColor.r,
		      this->looks.backColor.g, this->looks.backColor.b,
		      this->looks.backColor.a));
  DFBCHECK (surface->
	    FillRectangle (surface, this->dialogPos.x, this->dialogPos.y,
			   this->width, this->height));

  //draw title bar
  DFBCHECK (surface->
	    SetColor (surface, this->looks.titleColor.r,
		      this->looks.titleColor.g, this->looks.titleColor.b,
		      this->looks.titleColor.a));
  DFBCHECK (surface->
	    FillRectangle (surface, this->dialogPos.x,
			   this->dialogPos.y - this->looks.titleHeight,
			   this->width, this->looks.titleHeight));

  //draw title bar text
  DFBCHECK (surface->SetFont (surface, this->looks.fontTitle));
  DFBCHECK (surface->
	    SetColor (surface, this->looks.titleTextColor.r,
		      this->looks.titleTextColor.g,
		      this->looks.titleTextColor.b,
		      this->looks.titleTextColor.a));
  DFBCHECK (surface->
	    DrawString (surface, this->name, -1,
			this->dialogPos.x + this->width / 2,
			this->dialogPos.y - this->looks.titleHeight / 2,
			DSTF_CENTER));

  //draw textarea
  textarea_draw (this->textArea, surface);
}

static void
resetglobals ()
{
  numKeys = 0;
  fieldCursor = 0;
  indexTable = 0;
  lastKey = -1;
  firstKey = -1;
  inputDif = 0;
}


void
dialog_resetproperties (Dialog * this)
{
  resetglobals ();
}

void
dialog_destroy (Dialog * this)
{
  this->looks.fontText->Release (this->looks.fontText);
  this->looks.fontTip->Release (this->looks.fontTip);
  this->looks.fontTitle->Release (this->looks.fontTitle);

  textarea_destroy (this->textArea);

  free (this);
}
