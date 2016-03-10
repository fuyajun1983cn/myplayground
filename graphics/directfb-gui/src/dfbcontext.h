/*
 * dfbcontext.h
 *
 *  Created on: Feb 8, 2012
 *      Author: admin
 */

#ifndef DFBCONTEXT_H_
#define DFBCONTEXT_H_

#include <stdlib.h>
#include <directfb/directfb.h>

IDirectFB *dfb;
IDirectFBEventBuffer *evbuf;
IDirectFBSurface *surface;
DFBInputDeviceKeyState escap_ctrl;	//DIKS_UP
IDirectFBDisplayLayer *layer;
DFBSurfaceDescription surf_dsc;

#endif /* DFBCONTEXT_H_ */
