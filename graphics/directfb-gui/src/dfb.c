/*
 * dfb.c
 *
 *  Created on: Feb 8, 2012
 *      Author: admin
 */

#include "dfb.h"
#include <pthread.h>

pthread_t processingThread;

pthread_mutex_t processingThread_mutex;
pthread_mutex_t keyevent_mutex;

static int DFB_SCREENW = 0;
static int DFB_SCREENH = 0;
static int KEY_PRESSED_ = 0;
static int WAKE_UP_ = 0;

/**************************************************************************
 *
 **************************************************************************/
void
process_events ()
{
  pthread_mutex_init (&keyevent_mutex, NULL);
  int quit = 0;

  if (dfb->
      CreateInputEventBuffer (dfb, DICAPS_ALL /*DICAPS_KEYS */ , DFB_TRUE,
			      &evbuf))
    {
      printf ("Create DFBInputEventBuffer failed\n");
      dfb_destroy ();
      return;
    }

  while (quit == 0)
    {
      DFBInputEvent evt;
      evbuf->WaitForEvent (evbuf);
      while (evbuf->GetEvent (evbuf, DFB_EVENT (&evt)) == DFB_OK)
	{
	  pthread_mutex_lock (&keyevent_mutex);
	  if (evt.type == DIET_KEYRELEASE)
	    KEY_PRESSED_ = 0;	// prevent getting events while key is pressed

	  if (((evt.type == DIET_KEYPRESS) && !KEY_PRESSED_) ||
	      ((evt.type == DIET_KEYPRESS) && WAKE_UP_))
	    {
	      KEY_PRESSED_ = 1;

	      if (WAKE_UP_)
		WAKE_UP_ = 0;

	      switch (evt.key_symbol)
		{
		case DIKS_ESCAPE:
		  {
		    quit = 1;
		    escap_ctrl = DIKS_DOWN;
		    break;
		  }
		default:
		  {
		    dfb_event_handler (&evt.key_symbol);
		    break;
		  }
		}
	    }
	  pthread_mutex_unlock (&keyevent_mutex);
	}
    }
  pthread_mutex_destroy (&keyevent_mutex);
}

/**************************************************************************
 *
 **************************************************************************/
void *
run_event_processing (void *arg)
{
  process_events ();
  pthread_mutex_destroy (&processingThread_mutex);
  return NULL;
}

/*****************************************************************************
 * Creates event processing thread that handles the keyboard and mouse input *
 *****************************************************************************/
void
create_eventproc_thread ()
{
  /* Init mutex */
  pthread_mutex_init (&processingThread_mutex, NULL);
  /* Create thread */
  pthread_create (&processingThread, NULL, run_event_processing, NULL);
}


/**************************************************************************
 *
 **************************************************************************/
int
dfb_init (int argc, char **argv, unsigned short width, unsigned short height)
{

  DFBCHECK (DirectFBInit (&argc, &argv));
  DFBCHECK (DirectFBCreate (&dfb));
  DFBCHECK (dfb->SetCooperativeLevel (dfb, DFSCL_FULLSCREEN));

  escap_ctrl = DIKS_UP;
  surf_dsc.flags = DSDESC_CAPS | DSDESC_WIDTH | DSDESC_HEIGHT;
  surf_dsc.height = height;
  surf_dsc.width = width;
  surf_dsc.caps = DSCAPS_PRIMARY | DSCAPS_FLIPPING;

  DFBCHECK (dfb->CreateSurface (dfb, &surf_dsc, &surface));
  DFBCHECK (surface->GetSize (surface, &DFB_SCREENW, &DFB_SCREENH));

  //Hide the cursor
  dfb->GetDisplayLayer (dfb, 0x00, &layer);
  layer->SetCooperativeLevel (layer, DLSCL_ADMINISTRATIVE);
  layer->SetCursorOpacity (layer, 0);

  /*
   * TO-DO
   * Return code
   */
  return 0;
}

/**************************************************************************
 *
 **************************************************************************/
void
dfb_loop ()
{
  create_eventproc_thread ();
  while (escap_ctrl == DIKS_UP)
    {
      DFBCHECK (surface->SetColor (surface, 0x00, 0x00, 0x00, 0xFF));
      DFBCHECK (surface->
		FillRectangle (surface, 0, 0, DFB_SCREENW, DFB_SCREENH));
      dfb_render ();
      DFBCHECK (surface->Flip (surface, NULL, 0));
    }
  pthread_join (processingThread, NULL);
}

void
dfb_destroy ()
{
  assert (surface != NULL);
  assert (dfb != NULL);
  assert (layer != NULL);
  assert (evbuf != NULL);

  evbuf->Release (evbuf);
  surface->Release (surface);
  layer->Release (layer);
  dfb->Release (dfb);
}
