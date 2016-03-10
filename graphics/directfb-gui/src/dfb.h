/*
 * dfb.h
 *
 *  Created on: Feb 8, 2012
 *      Author: admin
 */

#ifndef DFB_H_
#define DFB_H_

#include "utils.h"
#include "dfbcontext.h"

void (*dfb_update) (float elapsedTime);
void (*dfb_event_handler) (DFBInputDeviceKeySymbol * sym);
void (*dfb_render) (void);

int dfb_init (int argc, char **argv, unsigned short width,
	      unsigned short height);
void dfb_loop ();
void dfb_destroy ();

#endif /* DFB_H_ */
