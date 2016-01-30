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

#ifndef _MALI_DEF_H_
#define _MALI_DEF_H_

#ifndef MALI_DEBUG
#define MALI_DEBUG 1
#define MALI_DEBUG_LEVEL 0
#endif

#define PLATFORM_ORION   1

#if MALI_DEBUG
#define TRACE_ENTER() \
	do { xf86DrvMsg(pScrn->scrnIndex, X_INFO, "[%s:%d]: Entering\n",\
		                __FUNCTION__, __LINE__); } while (0)
#define TRACE_EXIT() \
	do { xf86DrvMsg(pScrn->scrnIndex, X_INFO, "[%s:%d]: Exiting\n",\
		                __FUNCTION__, __LINE__); } while (0)
#define DEBUG_MSG(nr,fmt, ...) \
	do { if (nr <= MALI_DEBUG_LEVEL) \
			xf86DrvMsg(pScrn->scrnIndex, X_INFO, "[%s:%d] " fmt "\n",\
			           __FUNCTION__, __LINE__, ##__VA_ARGS__); } while (0)
#define INFO_MSG(fmt, ...) \
	do { xf86DrvMsg(pScrn->scrnIndex, X_INFO, fmt "\n",\
		                ##__VA_ARGS__); } while (0)
#define CONFIG_MSG(fmt, ...) \
	do { xf86DrvMsg(pScrn->scrnIndex, X_CONFIG, fmt "\n",\
		                ##__VA_ARGS__); } while (0)
#define WARNING_MSG(fmt, ...) \
	do { xf86DrvMsg(pScrn->scrnIndex, X_WARNING, "[%s:%d] Warning: " fmt "\n",\
		                __FUNCTION__, __LINE__, ##__VA_ARGS__); } while (0)
#define ERROR_MSG(fmt, ...) \
	do { xf86DrvMsg(pScrn->scrnIndex, X_ERROR, "[%s:%d] Error: " fmt "\n",\
		                __FUNCTION__, __LINE__, ##__VA_ARGS__); } while (0)
#define ERROR_STR(fmt, ...) \
	do { xf86Msg(X_ERROR, "Error: " fmt "\n",\
		             ##__VA_ARGS__); } while (0)
#define DEBUG_STR(nr, fmt, ...) \
	do { if (nr <= MALI_DEBUG_LEVEL) \
			xf86Msg(X_INFO, "Debug: " fmt "\n",\
			        ##__VA_ARGS__); } while (0)
#else
#define TRACE_ENTER()
#define TRACE_EXIT()
#define DEBUG_MSG(nr,fmt, ...)
#define INFO_MSG(fmt, ...)
#define CONFIG_MSG(fmt, ...)
#define WARNING_MSG(fmt, ...)
#define ERROR_MSG(fmt, ...)
#define ERROR_STR(fmt, ...)
#define DEBUG_STR(nr,fmt,...)
#endif

/* This macro must be the same as defined in egl_platform_x11.c */
#define NUM_BUFFERS 2

#define GET_UMP_SECURE_ID_BUF(x) _IOWR('m', 311 + (x), unsigned int)

#define FBIO_WAITFORVSYNC        _IOW('F', 0x20, __u32)
#define S3CFB_SET_VSYNC_INT      _IOW('F', 206, unsigned int)

#define IGNORE( a )  ( a = a );

#define exchange(a, b) {\
		typeof(a) tmp = a; \
		a = b; \
		b = tmp; \
	}

#define DRI2_BUFFER_FB_MASK     0x02 /* FB: 1, non-FB: 0 */
#define DRI2_BUFFER_MAPPED_MASK 0x04 /* mapped: 1, not-mapped: 0 */
#define DRI2_BUFFER_REUSED_MASK 0x08 /* re-used: 1, re-created: 0 */
#define DRI2_BUFFER_AGE_MASK    0x70 /* buffer age */
#define DRI2_BUFFER_FLAG_MASK   0x7f /* dri2 buffer flag mask */

#define DRI2_BUFFER_GET_FB(flag)        ((flag) & DRI2_BUFFER_FB_MASK) ? 1 : 0
#define DRI2_BUFFER_SET_FB(flag, fb) (flag) |= (((fb) << 1) & DRI2_BUFFER_FB_MASK);
#define DRI2_BUFFER_GET_MAPPED(flag) ((flag) & DRI2_BUFFER_MAPPED_MASK) ? 1 : 0
#define DRI2_BUFFER_SET_MAPPED(flag, mapped) (flag) |= (((mapped) << 2) & DRI2_BUFFER_MAPPED_MASK);
#define DRI2_BUFFER_GET_REUSED(flag)      ((flag) & DRI2_BUFFER_REUSED_MASK) ? 1 : 0
#define DRI2_BUFFER_SET_REUSED(flag, reused) (flag) |= (((reused) << 3) & DRI2_BUFFER_REUSED_MASK);
#define DRI2_BUFFER_GET_AGE(flag) ((flag) & DRI2_BUFFER_AGE_MASK) >> 4
#define DRI2_BUFFER_SET_AGE(flag, age) (flag) |= (((age) << 4) & DRI2_BUFFER_AGE_MASK);

#endif
