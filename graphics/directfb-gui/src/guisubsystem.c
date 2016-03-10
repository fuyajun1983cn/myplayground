/*
 * guisubsystem.c
 *
 *  Created on: Feb 4, 2012
 *      Author: admin
 */
#include "guisubsystem.h"
#include "timer.h"
#include "dialog.h"
#include "dfb.h"

//dialog being displayed
struct Dialog *focusedDialog = NULL;

static void
gui_eventhandler (DFBInputDeviceKeySymbol * sym)
{
  switch (*sym)
    {
    case DIKS_SPACE:
      dialog_switchinputmode (focusedDialog);
      break;

    case DIKS_CURSOR_LEFT:
      textarea_cursormove (focusedDialog->textArea, DIKS_CURSOR_LEFT);
      break;

    case DIKS_CURSOR_RIGHT:
      textarea_cursormove (focusedDialog->textArea, DIKS_CURSOR_RIGHT);
      break;

    case DIKS_BACKSPACE:
      textarea_removecharbsp (focusedDialog->textArea);
      break;

    case DIKS_DELETE:
      textarea_removechardel (focusedDialog->textArea);
      break;
      /*
       * Prikazuje tekst iz textarea-e na stdout
       */
    case DIKS_ENTER:
      {
	char *ladida = textarea_gettext (focusedDialog->textArea);
	printf ("%s\n", ladida);
	break;
      }

    default:
      dialog_eventhandler (focusedDialog, sym);
      break;
    }
}

static void
gui_render ()
{
  dialog_draw (focusedDialog, surface);
}

int
gui_initcomponents ()
{

  DFBRectangle rec = { 0, 0, 640, 480 };

  DialogLooks l;
  {
    l.backColor = create_color (COLOR_WHITE_);
    l.textColor = create_color (COLOR_BLUE_);
    l.tipColor = create_color (COLOR_RED_);
    l.titleColor = create_color (COLOR_BLUE_);
    l.titleTextColor = create_color (COLOR_GREEN_);
    l.titleHeight = 25;

    l.fontDsc.flags = DFDESC_HEIGHT | DFDESC_WIDTH;
    l.fontDsc.height = 12;
    l.fontDsc.width = 16;
    l.fontTitle = NULL;
    l.fontText = NULL;
    l.fontTip = NULL;
  }

  create_font ("decker.ttf", &l.fontDsc, &l.fontTitle);
  create_font ("decker.ttf", &l.fontDsc, &l.fontText);
  create_font ("decker.ttf", &l.fontDsc, &l.fontTip);

  focusedDialog = dialog_create ("MULTITAP PROGRAM", &rec, NUM_MODE, &l);

  assert (focusedDialog != NULL);

  TextAreaLooks areaL;
  {
    areaL.textColor = create_color (COLOR_BLACK_);
    areaL.backColor = create_color (255, 255, 255, 100);
    areaL.borderColor = create_color (COLOR_BLACK_);
    areaL.textWindowFontDsc.flags = DFDESC_HEIGHT;
    areaL.textWindowFontDsc.height = 12;
    create_font ("decker.ttf", &areaL.textWindowFontDsc, &areaL.textFont);
  }

  DFBRectangle rec1 = { 5, 5, 630, 470 };

  TextArea *text = textarea_create ("Enter text here...\n"
				    "Commands: \n"
				    "Backspace - Deletes character left of the cursor position\n"
				    "Delete - Deletes character right of the cursor position\n"
				    "Space - Changes dialog's input mode\n"
				    "Escape - Exits the program",
				    1000, &rec1, &areaL);

  assert (text != NULL);

  focusedDialog->textArea = text;

  return DFB_TRUE;
}

int
gui_init ()
{
  gui_initcomponents ();

  dfb_event_handler = gui_eventhandler;
  dfb_render = gui_render;

  return DFB_TRUE;
}

void
gui_destroy ()
{
  dialog_destroy (focusedDialog);
}
