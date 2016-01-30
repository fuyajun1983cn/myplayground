/*
 * Copyright (C) 2010 ARM Limited. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#include "xorgVersion.h"
#include "xf86.h"
#include "xf86drm.h"
#include "dri2.h"
#include "damage.h"
#include "mali_def.h"
#include "mali_fbdev.h"
#include "mali_exa.h"
#include "mali_dri.h"
#include "damage.h"

typedef struct
{
	PixmapPtr pPixmap;
	Bool isPageFlipped;
	Bool has_bb_reference;
	int previous_canflip;
	unsigned short previous_width;
	unsigned short previous_height;
	unsigned long previous_serial_number;
} MaliDRI2BufferPrivateRec, *MaliDRI2BufferPrivatePtr;

static unsigned long
MaliDRI2DrawableSerial(DrawablePtr pDraw)
{
	return  pDraw->serialNumber;
}

static Bool create_buffer(DrawablePtr pDraw, DRI2Buffer2Ptr buffer)
{
	ScreenPtr pScreen = pDraw->pScreen;
	ScrnInfoPtr pScrn = xf86Screens[pScreen->myNum];
	MaliPtr fPtr = MALIPTR(pScrn);

	MaliDRI2BufferPrivatePtr privates = buffer->driverPrivate;
	PixmapPtr pPixmapToWrap = NULL;
	PrivPixmap *privPixmapToWrap;

	PixmapPtr pWindowPixmap = NULL;
	PrivPixmap *privWindowPixmap = NULL;

	if (pDraw->type == DRAWABLE_WINDOW)
	{
		pWindowPixmap = pScreen->GetWindowPixmap((WindowPtr) pDraw);
		privWindowPixmap = (PrivPixmap *)exaGetPixmapDriverPrivate(pWindowPixmap);
	}

	DRI2_BUFFER_SET_FB(buffer->flags, 0);

	if (DRI2CanFlip(pDraw) && fPtr->use_pageflipping && DRAWABLE_WINDOW == pDraw->type)
	{
		assert(privWindowPixmap->buf_info);
		int frontLeft = privWindowPixmap->buf_info->current_pixmap;
		int backLeft = (frontLeft + 1) % privWindowPixmap->buf_info->num_pixmaps;

		if (DRI2BufferFrontLeft == buffer->attachment || DRI2BufferFakeFrontLeft == buffer->attachment)
		{
			pPixmapToWrap = privWindowPixmap->buf_info->pPixmaps[frontLeft];
		}
		else if (DRI2BufferBackLeft == buffer->attachment)
		{
			pPixmapToWrap = privWindowPixmap->buf_info->pPixmaps[backLeft];
		}

		privates->isPageFlipped = TRUE;
		DRI2_BUFFER_SET_FB(buffer->flags, 1);
	}

	/* Either the surface isn't swappable or the framebuffer back buffer is already in use */
	if (pPixmapToWrap == NULL)
	{
		if (DRI2BufferFrontLeft == buffer->attachment)
		{
			if (DRAWABLE_PIXMAP == pDraw->type)
			{
				pPixmapToWrap = (PixmapPtr)pDraw;
			}
			else
			{
				pPixmapToWrap = pScreen->GetWindowPixmap((WindowPtr) pDraw);
			}

			privPixmapToWrap = (PrivPixmap *)exaGetPixmapDriverPrivate(pPixmapToWrap);
		}
		else
		{
			int i, backLeft;
			PrivPixmap *tmpPrivPixmap;
			/* Create new pixmaps for the offscreen data */
			PrivBuffer *buf_info = calloc(1, sizeof(*buf_info));

			if (NULL == buf_info)
			{
				ERROR_MSG("[%s:%d] unable to allocate buf_info\n", __FUNCTION__, __LINE__);
				return FALSE;
			}

			buf_info->current_pixmap = 0;

			/* Create fPtr->dri2_num_buffers - 1 back pixmaps, so we have total fPtr->dri2_num_buffers pixmaps
			 * include the front one, But if SwapBuffer is called to do copy, then we have to create another
			 * back pixmap to match the total fPtr->dri2_num_buffers pixmaps */
			for (i = 0; i < fPtr->dri2_num_buffers - 1; i++)
			{
				buf_info->pPixmaps[i] = (*pScreen->CreatePixmap)(pScreen, pDraw->width, pDraw->height, (buffer->format != 0) ? buffer->format : pDraw->depth, 0);

				if (!buf_info->pPixmaps[i])
				{
					ERROR_MSG("[%s:%d] unable to allocate %d th PixmapPtr, total: %d needed\n", __FUNCTION__, __LINE__, i, fPtr->dri2_num_buffers);
					break;
				}

				tmpPrivPixmap = (PrivPixmap *)exaGetPixmapDriverPrivate(buf_info->pPixmaps[i]);
				tmpPrivPixmap->buf_info = buf_info;

			}

			if (i == 0)
			{
				ERROR_MSG("[%s:%d] unable to allocate any PixmapPtr\n", __FUNCTION__, __LINE__);
				free(buf_info);
				return FALSE;
			}

			buf_info->num_pixmaps = i;
			backLeft = (buf_info->current_pixmap + 1) % buf_info->num_pixmaps;
			pPixmapToWrap = buf_info->pPixmaps[backLeft];
			/* This is the only case where we don't need to add an additional reference to the pixmap, so
			 * drop one here to negate the increase at the end of the function */
			pPixmapToWrap->refcnt--;
			exaMoveInPixmap(pPixmapToWrap);
		}
	}

	privates->pPixmap = pPixmapToWrap;
	privPixmapToWrap = (PrivPixmap *)exaGetPixmapDriverPrivate(pPixmapToWrap);

	buffer->cpp = pPixmapToWrap->drawable.bitsPerPixel / 8;
	buffer->name = ump_secure_id_get(privPixmapToWrap->mem_info->handle);
	buffer->pitch = pPixmapToWrap->devKind;

	if (0 == buffer->pitch)
	{
		WARNING_MSG("Autocalculating pitch");
		buffer->pitch = ((pPixmapToWrap->drawable.width * pPixmapToWrap->drawable.bitsPerPixel) + 7) / 8;
	}

	if (privPixmapToWrap->isFrameBuffer)
	{
		assert((privPixmapToWrap->mem_info->offset & DRI2_BUFFER_FLAG_MASK) == 0);
		DRI2_BUFFER_SET_REUSED(buffer->flags, 1);
		buffer->flags |= privPixmapToWrap->mem_info->offset;
	}
	else if (buffer->attachment == DRI2BufferBackLeft)
	{
		assert(privPixmapToWrap->mem_info->offset == 0);
		DRI2_BUFFER_SET_REUSED(buffer->flags, 0);
	}

	pPixmapToWrap->refcnt++;

	return TRUE;
}

static void destroy_buffer(DrawablePtr pDraw, DRI2Buffer2Ptr buffer)
{
	ScreenPtr pScreen = pDraw->pScreen;
	ScrnInfoPtr pScrn = xf86Screens[pScreen->myNum];
	MaliPtr fPtr = MALIPTR(pScrn);

	DEBUG_STR(1, "Destroying attachment %d for drawable %p", buffer->attachment, pDraw);

	MaliDRI2BufferPrivatePtr private = buffer->driverPrivate;
	PrivPixmap *privPixmap = (PrivPixmap *)exaGetPixmapDriverPrivate(private->pPixmap);

	if (!privPixmap->isFrameBuffer)
	{
		int i;
		PrivBuffer *buf_info = privPixmap->buf_info;
		assert(private->pPixmap->refcnt);

		if (buf_info && private->pPixmap->refcnt == 1)
		{
			for (i = 0; i < fPtr->dri2_num_buffers && buf_info->pPixmaps[i]; i++)
			{
				(*pScreen->DestroyPixmap)(buf_info->pPixmaps[i]);
			}

			free(buf_info);
		}
		else
		{
			(*pScreen->DestroyPixmap)(private->pPixmap);
		}
	}
}

static DRI2Buffer2Ptr MaliDRI2CreateBuffer(DrawablePtr pDraw, unsigned int attachment, unsigned int format)
{
	ScreenPtr pScreen = pDraw->pScreen;
	DRI2Buffer2Ptr buffer;
	MaliDRI2BufferPrivatePtr privates;

	DEBUG_STR(1, "Creating attachment %u around drawable %p (window pixmap %p)", attachment, pDraw, pScreen->GetWindowPixmap((WindowPtr)pDraw));

	buffer = calloc(1, sizeof(*buffer));

	if (NULL == buffer)
	{
		return NULL;
	}

	privates = calloc(1, sizeof(*privates));

	if (NULL == privates)
	{
		free(buffer);
		return NULL;
	}

	/* initialize privates info to default values */
	privates->pPixmap = NULL;
	privates->isPageFlipped = FALSE;
	privates->has_bb_reference = FALSE;
	privates->previous_canflip = DRI2CanFlip(pDraw);
	privates->previous_width = pDraw->width;
	privates->previous_height = pDraw->height;
	privates->previous_serial_number = MaliDRI2DrawableSerial(pDraw);

	/* initialize buffer info to default values */
	buffer->attachment = attachment;
	buffer->driverPrivate = privates;
	buffer->format = format;
	buffer->flags = 0;

	if (!create_buffer(pDraw, buffer))
	{
		free(privates);
		free(buffer);
		return NULL;
	}

	return buffer;
}

static void MaliDRI2DestroyBuffer(DrawablePtr pDraw, DRI2Buffer2Ptr buffer)
{
	ScreenPtr pScreen = pDraw->pScreen;
	ScrnInfoPtr pScrn = xf86Screens[pScreen->myNum];
	MaliPtr fPtr = MALIPTR(pScrn);

	DEBUG_STR(1, "Destroying attachment %d for drawable %p", buffer->attachment, pDraw);

	if (NULL != buffer)
	{
		destroy_buffer(pDraw, buffer);
		free(buffer->driverPrivate);
		free(buffer);
	}
}

static int wt_set_window_pixmap(WindowPtr win, pointer data)
{
	ScreenPtr pScreen = ((DrawablePtr)win)->pScreen;

	/* We only want to update the window pixmap for non-redirected windows. Otherwise redirected windows will end up
	 * drawing to the front buffer. */
	if (win && win->redirectDraw == RedirectDrawNone)
	{
		pScreen->SetWindowPixmap(win, (PixmapPtr)data);
		return WT_WALKCHILDREN;
	}
	else
	{
		/* Don't walk the children of a redirected window as they won't be marked as redirected but as their
		 * parent is they will be too. If we continue to walk to them they will end up drawing to the front
		 * buffer. */
		return WT_DONTWALKCHILDREN;
	}
}

static void exchange_buffers(DrawablePtr pDraw, DRI2BufferPtr front, DRI2BufferPtr back, int dri2_complete_cmd)
{
	ScreenPtr pScreen = pDraw->pScreen;
	ScrnInfoPtr pScrn = xf86Screens[pScreen->myNum];
	MaliPtr fPtr = MALIPTR(pScrn);
	MaliDRI2BufferPrivatePtr front_priv = front->driverPrivate;
	MaliDRI2BufferPrivatePtr back_priv  = back->driverPrivate;
	PixmapPtr front_pixmap = front_priv->pPixmap;
	PixmapPtr back_pixmap  = back_priv->pPixmap;
	PrivPixmap *front_pixmap_priv = (PrivPixmap *)exaGetPixmapDriverPrivate(front_pixmap);
	PrivPixmap *back_pixmap_priv  = (PrivPixmap *)exaGetPixmapDriverPrivate(back_pixmap);
	int nextBack;
	PrivPixmap *nextPrivPixmap;

	assert(back_pixmap_priv->buf_info);
	back_pixmap_priv->buf_info->current_pixmap = (back_pixmap_priv->buf_info->current_pixmap + 1) %  back_pixmap_priv->buf_info->num_pixmaps;
	nextBack = (back_pixmap_priv->buf_info->current_pixmap + 1) % back_pixmap_priv->buf_info->num_pixmaps;
	nextPrivPixmap = (PrivPixmap *)exaGetPixmapDriverPrivate(back_pixmap_priv->buf_info->pPixmaps[nextBack]);

	if (dri2_complete_cmd == DRI2_FLIP_COMPLETE)
	{
		assert(front_pixmap_priv->buf_info == back_pixmap_priv->buf_info);
		exchange(front->name, back->name);
		exchange(front->flags, back->flags);
		front_priv->pPixmap = back_priv->pPixmap;
	}
	else if (dri2_complete_cmd == DRI2_EXCHANGE_COMPLETE)
	{
		exchange(front->name, back->name);
		exchange(front_pixmap_priv->mem_info, back_pixmap_priv->mem_info);
	}

	back->name = ump_secure_id_get(nextPrivPixmap->mem_info->handle);
	back_priv->pPixmap = back_pixmap_priv->buf_info->pPixmaps[nextBack];
}

static Bool MaliDRI2CanExchange(DrawablePtr pDraw, DRI2BufferPtr front, DRI2BufferPtr back)
{
	MaliDRI2BufferPrivatePtr front_priv = front->driverPrivate;
	MaliDRI2BufferPrivatePtr back_priv  = back->driverPrivate;
	PixmapPtr front_pixmap = front_priv->pPixmap;
	PixmapPtr back_pixmap  = back_priv->pPixmap;
	PrivPixmap *front_pixmap_priv = (PrivPixmap *)exaGetPixmapDriverPrivate(front_pixmap);
	PrivPixmap *back_pixmap_priv  = (PrivPixmap *)exaGetPixmapDriverPrivate(back_pixmap);

	Bool can_exchange = TRUE;

	if (!(front_pixmap->drawable.width == back_pixmap->drawable.width &&
	        front_pixmap->drawable.height == back_pixmap->drawable.height &&
	        front_pixmap->drawable.bitsPerPixel == back_pixmap->drawable.bitsPerPixel))
	{
		can_exchange = FALSE;
	}

	if (front_pixmap_priv->isFrameBuffer != back_pixmap_priv->isFrameBuffer)
	{
		can_exchange = FALSE;
	}

	if (front_pixmap_priv->mem_info->usize != back_pixmap_priv->mem_info->usize)
	{
		can_exchange = FALSE;
	}

	return can_exchange;
}

static void platform_wait_for_vsync(ScrnInfoPtr pScrn, int fb_lcd_fd)
{
#if PLATFORM_ORION
	int interrupt = 1;

	if (ioctl(fb_lcd_fd, S3CFB_SET_VSYNC_INT, &interrupt) < 0)
	{
		WARNING_MSG("failed in S3CFB_SET_VSYNC_INT");
	}

	int crtc = 0;

	if (ioctl(fb_lcd_fd, FBIO_WAITFORVSYNC, &crtc) < 0)
	{
		WARNING_MSG("failed in FBIO_WAITFORVSYNC");
	}

	interrupt = 0;

	if (ioctl(fb_lcd_fd, S3CFB_SET_VSYNC_INT, &interrupt) < 0)
	{
		WARNING_MSG("failed in S3CFB_SET_VSYNC_INT");
	}

#endif
}

static void MaliDRI2CopyRegion(DrawablePtr pDraw, RegionPtr pRegion, DRI2BufferPtr pDstBuffer, DRI2BufferPtr pSrcBuffer)
{
	GCPtr pGC;
	RegionPtr copyRegion;
	ScreenPtr pScreen = pDraw->pScreen;
	ScrnInfoPtr pScrn = xf86Screens[pScreen->myNum];
	MaliPtr fPtr = MALIPTR(pScrn);
	PixmapPtr winPixmap;

	MaliDRI2BufferPrivatePtr srcPrivate = pSrcBuffer->driverPrivate;
	MaliDRI2BufferPrivatePtr dstPrivate = pDstBuffer->driverPrivate;

	PixmapPtr srcPixmap = srcPrivate->pPixmap;
	PixmapPtr dstPixmap = dstPrivate->pPixmap;

	DrawablePtr srcDrawable = &srcPrivate->pPixmap->drawable;
	DrawablePtr dstDrawable = pDraw;

	DEBUG_STR(1, "Blitting!");

	pGC = GetScratchGC(pDraw->depth, pScreen);
	copyRegion = REGION_CREATE(pScreen, NULL, 0);
	REGION_COPY(pScreen, copyRegion, pRegion);
	(*pGC->funcs->ChangeClip)(pGC, CT_REGION, copyRegion, 0);
	ValidateGC(dstDrawable, pGC);
	(*pGC->ops->CopyArea)(srcDrawable, dstDrawable, pGC, 0, 0, pDraw->width, pDraw->height, 0, 0);
	FreeScratchGC(pGC);
}

/*
 * MaliDRI2ScheduleSwap is the implementation of DRI2SwapBuffers, this function
 * should wait for vblank event which will trigger registered event handler.
 * Event handler will do FLIP/SWAP/BLIT according to event type.
 *
 * Current DRM doesn't support vblank well, so this function just do FLIP/
 *       SWAP/BLIT directly, according to drawable information.
 */
static int MaliDRI2ScheduleSwap(ClientPtr client, DrawablePtr pDraw, DRI2BufferPtr front,
                                DRI2BufferPtr back, CARD64 *target_msc, CARD64 divisor,
                                CARD64 remainder, DRI2SwapEventPtr func, void *data)
{
	ScreenPtr pScreen = pDraw->pScreen;
	ScrnInfoPtr pScrn = xf86Screens[pScreen->myNum];
	MaliPtr fPtr = MALIPTR(pScrn);
	BoxRec box;
	RegionRec region;
	int dri2_complete_cmd = DRI2_BLIT_COMPLETE;
	int new_canflip = 0;

	MaliDRI2BufferPrivatePtr front_priv = front->driverPrivate;
	MaliDRI2BufferPrivatePtr back_priv  = back->driverPrivate;

	PixmapPtr front_pixmap = front_priv->pPixmap;
	PixmapPtr back_pixmap  = back_priv->pPixmap;
	assert(front_pixmap != NULL);
	assert(back_pixmap  != NULL);

	PrivPixmap *front_pixmap_priv = (PrivPixmap *)exaGetPixmapDriverPrivate(front_pixmap);
	PrivPixmap *back_pixmap_priv  = (PrivPixmap *)exaGetPixmapDriverPrivate(back_pixmap);

	new_canflip = DRI2CanFlip(pDraw);
#if DRI2INFOREC_VERSION < 6

	if ((back_priv->previous_canflip != new_canflip)
	        || (back_priv->previous_width != pDraw->width)
	        || (back_priv->previous_height != pDraw->height)
	        || (back_priv->previous_serial_number != MaliDRI2DrawableSerial(pDraw)))
	{
		back_pixmap->drawable.serialNumber = NEXT_SERIAL_NUMBER;
		back_priv->previous_width = pDraw->width;
		back_priv->previous_height = pDraw->height;
		back_priv->previous_serial_number = MaliDRI2DrawableSerial(pDraw);
	}

	if ((front_priv->previous_canflip != new_canflip)
	        || (front_priv->previous_width != pDraw->width)
	        || (front_priv->previous_height != pDraw->height)
	        || (front_priv->previous_serial_number != MaliDRI2DrawableSerial(pDraw)))
	{
		front_pixmap->drawable.serialNumber = NEXT_SERIAL_NUMBER;
		front_priv->previous_width = pDraw->width;
		front_priv->previous_height = pDraw->height;
		front_priv->previous_serial_number = MaliDRI2DrawableSerial(pDraw);
	}

	back_priv->previous_canflip = new_canflip;
	front_priv->previous_canflip = new_canflip;
#endif

	if (new_canflip && fPtr->use_pageflipping && DRAWABLE_WINDOW == pDraw->type && front_priv->isPageFlipped)
	{
		unsigned int line_length = fPtr->fb_lcd_var.xres * fPtr->fb_lcd_var.bits_per_pixel / 8;
		fPtr->fb_lcd_var.yoffset = back_pixmap_priv->mem_info->offset / line_length;
		DEBUG_STR(1, "Flipping! ofs %d", fPtr->fb_lcd_var.yoffset);

		if (ioctl(fPtr->fb_lcd_fd, FBIOPAN_DISPLAY, &fPtr->fb_lcd_var) == -1)
		{
			WARNING_MSG("failed in FBIOPAN_DISPLAY");
		}

		if (fPtr->use_pageflipping_vsync)
		{
			platform_wait_for_vsync(pScrn, fPtr->fb_lcd_fd);
		}

		ioctl(fPtr->fb_lcd_fd, FBIOGET_VSCREENINFO, &fPtr->fb_lcd_var);

		dri2_complete_cmd = DRI2_FLIP_COMPLETE;
		exchange_buffers(pDraw, front, back, dri2_complete_cmd);

		/* Tell the X server that all 2D rendering should be done to newPixmap from now on */
#if XORG_VERSION_CURRENT < XORG_VERSION_NUMERIC(1, 9, 4, 901, 0)
		pScreen->SourceValidate(pDraw, 0, 0, pDraw->width, pDraw->height);
#else
		pScreen->SourceValidate(pDraw, 0, 0, pDraw->width, pDraw->height, IncludeInferiors);
#endif
		/* Update all windows so that their front buffer is now the next one */
		WalkTree(pScreen, wt_set_window_pixmap, front_priv->pPixmap);
	}
	else if (MaliDRI2CanExchange(pDraw, front, back))
	{
		if (back_pixmap_priv->buf_info != front_pixmap_priv->buf_info && back_pixmap_priv->buf_info->num_pixmaps == fPtr->dri2_num_buffers)
		{
			back_pixmap_priv->buf_info->num_pixmaps = fPtr->dri2_num_buffers - 1;
		}

		dri2_complete_cmd = DRI2_EXCHANGE_COMPLETE;
		exchange_buffers(pDraw, front, back, dri2_complete_cmd);
	}
	else
	{
		box.x1 = 0;
		box.y1 = 0;
		box.x2 = pDraw->width;
		box.y2 = pDraw->height;
		REGION_INIT(pScreen, &region, &box, 0);

		/* Create new pixmaps if we are doing copy, so that there are total fPtr->dri2_num_buffers back pixmaps */
		if (back_pixmap_priv->buf_info->num_pixmaps < fPtr->dri2_num_buffers)
		{
			int old_num_pixmaps = back_pixmap_priv->buf_info->num_pixmaps;

			if (back_pixmap_priv->buf_info->pPixmaps[fPtr->dri2_num_buffers - 1])
			{
				back_pixmap_priv->buf_info->num_pixmaps = fPtr->dri2_num_buffers;
			}
			else
			{
				int i;
				PrivPixmap *tmpPrivPixmap;
				DrawablePtr drawable = &back_pixmap_priv->buf_info->pPixmaps[0]->drawable;

				for (i = back_pixmap_priv->buf_info->num_pixmaps; i < fPtr->dri2_num_buffers; i++)
				{
					back_pixmap_priv->buf_info->pPixmaps[i] = (*pScreen->CreatePixmap)(pScreen, drawable->width, drawable->height, drawable->depth, 0);

					if (!back_pixmap_priv->buf_info->pPixmaps[i])
					{
						break;
					}

					tmpPrivPixmap = (PrivPixmap *)exaGetPixmapDriverPrivate(back_pixmap_priv->buf_info->pPixmaps[i]);
					tmpPrivPixmap->buf_info = back_pixmap_priv->buf_info;
				}

				back_pixmap_priv->buf_info->num_pixmaps = i;
			}

			if (old_num_pixmaps == 1 && back_pixmap_priv->buf_info->num_pixmaps > 1)
			{
				back_pixmap_priv->buf_info->current_pixmap = (back_pixmap_priv->buf_info->current_pixmap + 1) % back_pixmap_priv->buf_info->num_pixmaps;
			}
		}

		MaliDRI2CopyRegion(pDraw, &region, front, back);
		dri2_complete_cmd = DRI2_BLIT_COMPLETE;
		exchange_buffers(pDraw, front, back, dri2_complete_cmd);
	}

	DRI2SwapComplete(client, pDraw, 0, 0, 0, dri2_complete_cmd, func, data);

	/* Adjust returned value */
	*target_msc += 1;


	return TRUE;
}

#if DRI2INFOREC_VERSION >= 6
/**
 * The mechanism to increase the pixmap's serial number to force dri2 to
 * re-create the buffer doesn't work with XServer later than Jun 18 2013,
 * so we have to use the "ReuseBufferNotify" to re-create the buffer
 */
void MaliDRI2ReuseBufferNotify(DrawablePtr pDraw, DRI2BufferPtr buffer)
{
	int new_canflip;
	ScreenPtr pScreen = pDraw->pScreen;
	ScrnInfoPtr pScrn = xf86Screens[pScreen->myNum];
	MaliPtr fPtr = MALIPTR(pScrn);
	MaliDRI2BufferPrivatePtr privates  = buffer->driverPrivate;
	PixmapPtr pWindowPixmap = NULL;
	PrivPixmap *privWindowPixmap = NULL;
	PixmapPtr pPixmapToWrap = NULL;
	PrivPixmap *privPixmapToWrap;

	DRI2_BUFFER_SET_REUSED(buffer->flags, 1);

	if (DRI2BufferBackLeft != buffer->attachment)
	{
		return;
	}

	new_canflip = DRI2CanFlip(pDraw);

	if ((privates->previous_canflip == new_canflip) &&
	        (privates->previous_width == pDraw->width) &&
	        (privates->previous_height == pDraw->height) &&
	        (privates->previous_serial_number == MaliDRI2DrawableSerial(pDraw)))
	{
		return;
	}

	privates->previous_canflip = new_canflip;
	privates->previous_width = pDraw->width;
	privates->previous_height = pDraw->height;
	privates->previous_serial_number = MaliDRI2DrawableSerial(pDraw);

	if (NULL != buffer)
	{
		destroy_buffer(pDraw, buffer);
	}

	create_buffer(pDraw, buffer);
}
#endif

Bool MaliDRI2ScreenInit(ScreenPtr pScreen)
{
	ScrnInfoPtr pScrn = xf86Screens[pScreen->myNum];
	MaliPtr fPtr = MALIPTR(pScrn);
	DRI2InfoRec info;
	int dri2_major = 2, dri2_minor = 0, i;
	struct stat sbuf;
	dev_t d;
	char *p;
#if DRI2INFOREC_VERSION >= 4
	const char *driverNames[1];
#endif

	if (xf86LoaderCheckSymbol("DRI2Version"))
	{
		DRI2Version(&dri2_major, &dri2_minor);
	}

	if (dri2_minor < 1)
	{
		ERROR_MSG("%s requires DRI2 module version 1.1.0 or later\n", __func__);
		return FALSE;
	}

	INFO_MSG("DRI2 version: %i.%i", dri2_major, dri2_minor);

	/* extract deviceName */
	info.fd = fPtr->drm_fd;
	fstat(info.fd, &sbuf);
	d = sbuf.st_rdev;

	p = fPtr->deviceName;

	for (i = 0; i < DRM_MAX_MINOR; i++)
	{
		snprintf(p, 64, DRM_DEV_NAME, DRM_DIR_NAME, i);

		if (stat(p, &sbuf) == 0 && sbuf.st_rdev == d)
		{
			break;
		}
	}

	if (i == DRM_MAX_MINOR)
	{
		ERROR_MSG("%s failed to open drm device\n", __func__);
		return FALSE;
	}


	info.driverName = "Mali DRI2";
	info.deviceName = p;

#if DRI2INFOREC_VERSION == 1
	info.version = 1;
	info.CreateBuffers = MaliDRI2CreateBuffers;
	info.DestroyBuffers = MaliDRI2DestroyBuffers;
#elif DRI2INFOREC_VERSION == 2
	info.version = 2;
	info.CreateBuffer = MaliDRI2CreateBuffer;
	info.DestroyBuffer = MaliDRI2DestroyBuffer;
#else
	info.version = 3;
	info.CreateBuffer = MaliDRI2CreateBuffer;
	info.DestroyBuffer = MaliDRI2DestroyBuffer;
#endif

	info.CopyRegion = MaliDRI2CopyRegion;

#if DRI2INFOREC_VERSION >= 4

	if (fPtr->use_pageflipping)
	{
		info.version = 4;
		info.ScheduleSwap = MaliDRI2ScheduleSwap;
		info.GetMSC = NULL;
		info.ScheduleWaitMSC = NULL;
		info.numDrivers = 1;
		info.driverNames = driverNames;
		driverNames[0] = info.driverName;
	}

#endif

#if DRI2INFOREC_VERSION >= 5
	info.version = 5;
	info.AuthMagic = NULL;
#endif

#if DRI2INFOREC_VERSION >= 6
	info.version = 6;
	info.ReuseBufferNotify = MaliDRI2ReuseBufferNotify;
	info.SwapLimitValidate = NULL;
#endif

	if (FALSE == DRI2ScreenInit(pScreen, &info))
	{
		return FALSE;
	}

	return TRUE;
}

void MaliDRI2CloseScreen(ScreenPtr pScreen)
{
	ScrnInfoPtr pScrn = xf86Screens[pScreen->myNum];
	MaliPtr fPtr = MALIPTR(pScrn);

	DRI2CloseScreen(pScreen);

	fPtr->dri_render = DRI_NONE;
}
