/*
 * textlist.c
 *
 *  Created on: Feb 4, 2012
 *      Author: admin
 */
#include "textarea.h"
#include "timer.h"

const int TEXT_OFFSET_NEWLINE = 3;
const int TEXT_OFFSET_X = 5;
const int TEXT_OFFSET_Y = 5;


TextArea *
textarea_create (const char *text, int maxTextSize, DFBRectangle * dimensions,
		 TextAreaLooks * looks)
{
  assert (looks != NULL);

  TextArea *tempArea = NULL;
  {
    tempArea = (TextArea *) malloc (sizeof (TextArea));
    tempArea->looks = *looks;
    tempArea->dimensions = *dimensions;
    tempArea->maxTextSize = maxTextSize;
    tempArea->text = (char *) malloc ((maxTextSize + 1) * sizeof (char));
    tempArea->looks.textFont->GetHeight (tempArea->looks.textFont,
					 &tempArea->fontHeight);
  }


  int textSize = strlen (text);

  if (textSize > maxTextSize)
    {
      printf ("Text length %d exceeds max text length %d\n", textSize,
	      maxTextSize);
      textSize = maxTextSize;
    }

  strncpy (tempArea->text, text, textSize);
  tempArea->text[textSize] = '|';
  tempArea->text[textSize + 1] = '\0';
  tempArea->textSize = textSize;
  tempArea->cursorPos = textSize;
  return tempArea;
}

int
textarea_removechardel (TextArea * this)
{
  assert (this != NULL);

  if (this->cursorPos >= this->textSize)
    return DFB_FALSE;

  for (int i = this->cursorPos; i <= this->textSize; ++i)
    {
      this->text[i] = this->text[i + 1];
    }

  this->text[this->cursorPos] = '|';
  this->textSize--;

  return DFB_TRUE;
}

void
textarea_clear (TextArea * this)
{
  memset (this->text, '\0', sizeof (this->text));
  this->cursorPos = 0;
  this->textSize = 0;
}

int
textarea_removecharbsp (TextArea * this)
{
  assert (this != NULL);

  if (this->cursorPos <= 0)
    return DFB_FALSE;

  this->cursorPos--;
  this->text[this->cursorPos] = '|';


  for (int i = this->cursorPos; i <= this->textSize; ++i)
    {
      this->text[i] = this->text[i + 1];
    }

  this->textSize--;

  return DFB_TRUE;
}

int
textarea_addchar (TextArea * this, char c)
{
  assert (this != NULL);
  if (this->textSize < this->maxTextSize)
    {
      for (int i = this->textSize; i > this->cursorPos; --i)
	{
	  this->text[i + 1] = this->text[i];
	}
      this->text[this->cursorPos] = c;
      this->text[this->cursorPos + 1] = '|';
      this->text[this->textSize + 2] = '\0';
      this->cursorPos++;
      this->textSize++;
      return DFB_TRUE;
    }
  return DFB_FALSE;
}

int
textarea_cursormove (TextArea * this, int where)
{
  assert (this != NULL);

  if (where == DIKS_CURSOR_LEFT)
    {
      if (this->cursorPos > 0)
	this->cursorPos--;
      else
	return DFB_FALSE;
      this->text[this->cursorPos + 1] = this->text[this->cursorPos];
      this->text[this->cursorPos] = '|';
    }
  else
    {
      if (this->cursorPos < this->textSize)
	this->cursorPos++;
      else
	return DFB_FALSE;
      this->text[this->cursorPos - 1] = this->text[this->cursorPos];
      this->text[this->cursorPos] = '|';
    }
  return DFB_TRUE;
}

void
textarea_draw (TextArea * this, IDirectFBSurface * surface)
{

  DFBCHECK (surface->SetColor (surface,
			       this->looks.borderColor.r,
			       this->looks.borderColor.g,
			       this->looks.borderColor.b,
			       this->looks.borderColor.a));

  DFBCHECK (surface->FillRectangle (surface,
				    this->dimensions.x - 3,
				    this->dimensions.y - 3,
				    this->dimensions.w + 6,
				    this->dimensions.h + 6));

  DFBCHECK (surface->SetColor (surface,
			       this->looks.backColor.r,
			       this->looks.backColor.g,
			       this->looks.backColor.b,
			       this->looks.backColor.a));

  DFBCHECK (surface->FillRectangle (surface,
				    this->dimensions.x,
				    this->dimensions.y,
				    this->dimensions.w, this->dimensions.h));

  DFBCHECK (surface->SetFont (surface, this->looks.textFont));
  DFBCHECK (surface->SetColor (surface,
			       this->looks.textColor.r,
			       this->looks.textColor.g,
			       this->looks.textColor.b,
			       this->looks.textColor.a));

  /*
   * Text drawing routine
   */
  DFBCHECK (surface->SetFont (surface, this->looks.textFont));
  DFBCHECK (surface->SetColor (surface, this->looks.textColor.r,
			       this->looks.textColor.g,
			       this->looks.textColor.b,
			       this->looks.textColor.a));

  int retWidth = 0;
  int retStrLen = 0;
  int yTextSpacing = this->dimensions.y;
  int maxWidth = this->dimensions.w;
  const char *text = this->text;

  const char *nextLine = NULL;

  do
    {
      if (this->looks.textFont->
	  GetStringBreak (this->looks.textFont, text, -1, maxWidth, &retWidth,
			  &retStrLen, &nextLine) != DFB_OK)
	{
	  break;
	}

      DFBCHECK (surface->
		DrawString (surface, text, retStrLen, this->dimensions.x,
			    yTextSpacing, DSTF_TOPLEFT));

      if (text == nextLine)
	break;

      yTextSpacing += this->fontHeight;

      text = nextLine;

    }
  while (text != NULL);

}

char *
textarea_gettext (TextArea * this)
{
  char *temp = (char *) malloc (sizeof (char) * this->textSize + 1);
  int j = 0;
  char *texPtr = this->text;
  for (int i = 0; i <= this->textSize; ++i)
    {
      if (texPtr[i] != '|')
	{
	  temp[j] = texPtr[i];
	  j++;
	}
    }
  return temp;
}

void
textarea_destroy (TextArea * this)
{
  this->looks.textFont->Release (this->looks.textFont);
  free (this->text);
  free (this);
}
