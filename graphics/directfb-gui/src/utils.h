/*
 * utils.h
 *
 *  Created on: Feb 4, 2012
 *      Author: admin
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <directfb/directfb.h>

#define DEBUG_DFBCHECK
#define DEBUG_ASSERT

#define COLOR_RED_ 255,0,0,255
#define COLOR_BLUE_ 0,0,255,255
#define COLOR_GREEN_ 0,255,0,255
#define COLOR_BLACK_ 0,0,0,255
#define COLOR_WHITE_ 255,255,255,255

#define TRUE_ 1
#define FALSE_ 0
typedef char bool_;


#ifndef DEBUG_DFBCHECK
#define DFBCHECK(x...)
#else
#define DFBCHECK(x...)                                         \
	{                                                              \
	    DFBResult err = x;                                         \
		                                                       \
	    if (err != DFB_OK)                                         \
	    {                                                          \
		fprintf(stderr, "%s <%d>:\n", __FILE__, __LINE__ ); \
		DirectFBErrorFatal( #x, err );                         \
	    }                                                          \
	}
#endif



#ifndef DEBUG_ASSERT
#define assert(x)
#else
#define assert(x) \
                if(!(x)) \
                { \
                   fprintf(stdout, "ERROR - ASSERTION %s FAILED\t %s \t <%d>\n",#x, __FILE__, __LINE__); \
                }
#endif



DFBColor create_color (int r, int g, int b, int a);
void create_font (const char *fontName, DFBFontDescription * fds,
		  IDirectFBFont ** font);
void rectangle_clamp (DFBRectangle * rec, DFBRectangle * against);
#endif /* UTILS_H_ */
