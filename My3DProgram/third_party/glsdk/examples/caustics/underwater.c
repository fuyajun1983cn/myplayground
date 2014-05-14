
/*********************************************************************
This example uses functionality removed in OpenGL 3.1 core and above.
**********************************************************************/


/* Copyright (c) Mark J. Kilgard, 1997. */

/* This program is freely distributable without licensing fees and is
provided without guarantee or warrantee expressed or implied. This
program is -not- in the public domain. */

/* X compile line: cc -o underwater underwater.c texload.c dino.c -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm */

/* This code compiles and works with any of 1) OpenGL 1.0 with no
texture extensions, 2) OpenGL 1.0 with texture extensions, or 3)
OpenGL 1.1. */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <glload/gl_all.h>
#include <glload/gll.h>
#include <GL/freeglut.h>

#include "texload.h"
#include "dino.h"

#ifndef M_PI
#define M_PI 3.14159265
#endif


#define NUM_PATTERNS 32
#define FLOOR_FILE "floor.rgb"

static GLuint causticTextures[NUM_PATTERNS];
static GLuint groundTexture;

enum
{
	PASS_NORMAL, PASS_CAUSTIC
};

enum
{
	M_POSITIONAL, M_DIRECTIONAL, M_GREENISH_LIGHT, M_WHITE_LIGHT,
	M_NO_CAUSTICS, M_WITH_CAUSTICS, M_SWITCH_MODEL,
	M_INCREASE_RIPPLE_SIZE, M_DECREASE_RIPPLE_SIZE
};

enum
{
	MODEL_SPHERE, MODEL_CUBE, MODEL_DINO
};

static int object = MODEL_SPHERE;
static int reportSpeed = 0;
static int dinoDisplayList;
static GLfloat causticScale = 1.0;

static GLfloat lightPosition[4];
/* XXX Diffuse light color component > 1.0 to brighten caustics. */
static GLfloat lightDiffuseColor[] = {1.0, 1.5, 1.0, 1.0};  /* XXX Green = 1.5 */
static GLfloat defaultDiffuseMaterial[] = {0.8, 0.8, 0.8, 1.0};

static int directionalLight = 1;
static int showCaustics = 1, causticMotion = 1;
static int useMipmaps = 1;
static int currentCaustic = 0;
static int causticIncrement = 1;

static float lightAngle = 0.0, lightHeight = 20;
static GLfloat angle = -150;   /* in degrees */
static GLfloat angle2 = 30;   /* in degrees */

static int moving = 0, startx, starty;
static int lightMoving = 0, lightStartX, lightStartY;

static GLfloat floorVertices[4][3] =
{
	{ -20.0, 0.0, 20.0 },
	{ 20.0, 0.0, 20.0 },
	{ 20.0, 0.0, -20.0 },
	{ -20.0, 0.0, -20.0 },
};

#define RADIANS_TO_DEGREES ((float)(-180.0f / M_PI))

void drawLightLocation()
{
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glColor3f(1.0, 1.0, 0.0);
	if (directionalLight)
	{
		/* Draw an arrowhead. */
		glDisable(GL_CULL_FACE);
		glTranslatef(lightPosition[0], lightPosition[1], lightPosition[2]);
		glRotatef(lightAngle * RADIANS_TO_DEGREES, 0.0f, 1.0f, 0.0f);
		glRotatef(atanf(lightHeight/12) * RADIANS_TO_DEGREES, 0.0f, 0.0f, 1.0f);
		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0, 0, 0);
		glVertex3f(2, 1, 1);
		glVertex3f(2, -1, 1);
		glVertex3f(2, -1, -1);
		glVertex3f(2, 1, -1);
		glVertex3f(2, 1, 1);
		glEnd();
		/* Draw a white line from light direction. */
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
		glVertex3f(0, 0, 0);
		glVertex3f(5, 0, 0);
		glEnd();
		glEnable(GL_CULL_FACE);
	}
	else
	{
		/* Draw a yellow ball at the light source. */
		glTranslatef(lightPosition[0], lightPosition[1], lightPosition[2]);
		glutSolidSphere(1.0, 5, 5);
	}
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

/* Draw a floor (possibly textured). */
static void drawFloor(int pass)
{
	if (pass == PASS_NORMAL)
	{
		glBindTexture(GL_TEXTURE_2D, groundTexture);
	}

	/* The glTexCoord2f calls get ignored when in texture generation
	mode (ie, when modulating in caustics). */

	glBegin(GL_QUADS);
	glNormal3f(0.0, 1.0, 0.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3fv(floorVertices[0]);
	glTexCoord2f(0.0, 2.0);
	glVertex3fv(floorVertices[1]);
	glTexCoord2f(2.0, 2.0);
	glVertex3fv(floorVertices[2]);
	glTexCoord2f(2.0, 0.0);
	glVertex3fv(floorVertices[3]);
	glEnd();
}

void drawObject(int pass)
{
	if (pass == PASS_NORMAL)
	{
		/* The objects are not textured (they could be if someone
		wanted them to be) so disable texture in the normal pass.  In
		the caustic pass, we want to avoid disabling texture though. */
		glDisable(GL_TEXTURE_2D);
	}

	glPushMatrix();

	/* If object is dino, put feet on the floor. */
	glTranslatef(0.0f, object == MODEL_DINO ? 8.0f : 12.0f, 0.0f);

	switch (object)
	{
	case MODEL_SPHERE:
		glutSolidSphere(6.0, 12, 12);
		break;
	case MODEL_CUBE:
		glutSolidCube(7.0);
		break;
	case MODEL_DINO:
		glCallList(dinoDisplayList);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, defaultDiffuseMaterial);
		break;
	}
	glPopMatrix();

	if (pass == PASS_NORMAL)
	{
		glEnable(GL_TEXTURE_2D);
	}
}

void drawScene(int pass)
{
	/* The 0.03 in the Y column is just to shift the texture coordinates
	a little based on Y (depth in the water) so that vertical faces
	(like on the cube) do not get totally vertical caustics. */
	GLfloat sPlane[4] = { 0.05f, 0.03f, 0.0f, 0.0f };
	GLfloat tPlane[4] = { 0.0f, 0.03f, 0.05f, 0.0f };

	/* The causticScale determines how large the caustic "ripples" will
	be.  See the "Increate/Decrease ripple size" menu options. */

	sPlane[0] = 0.05f * causticScale;
	sPlane[1] = 0.03f * causticScale;

	tPlane[1] = 0.03f * causticScale;
	tPlane[2] = 0.05f * causticScale;

	if (pass == PASS_CAUSTIC)
	{
		/* Set current color to "white" and disable lighting
		to emulate OpenGL 1.1's GL_REPLACE texture environment. */
		glColor3f(1.0f, 1.0f, 1.0f);
		glDisable(GL_LIGHTING);

		/* Generate the S & T coordinates for the caustic textures
		from the object coordinates. */

		glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
		glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
		glTexGenfv(GL_S, GL_OBJECT_PLANE, sPlane);
		glTexGenfv(GL_T, GL_OBJECT_PLANE, tPlane);
		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_GEN_T);

		glBindTexture(GL_TEXTURE_2D, causticTextures[currentCaustic]);
	}

	drawFloor(pass);
	drawObject(pass);

	if (pass == PASS_CAUSTIC)
	{
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_GEN_S);
		glDisable(GL_TEXTURE_GEN_T);
	}
}

void display(void)
{
	int startTime, endTime;

	/* Simplistic benchmarking.  Be careful about results. */
	if (reportSpeed)
	{
		startTime = glutGet(GLUT_ELAPSED_TIME);
	}

	/* Clear depth and color buffer. */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* Reposition the light source. */
	lightPosition[0] = 12 * cosf(lightAngle);
	lightPosition[1] = lightHeight;
	lightPosition[2] = 12 * sinf(lightAngle);
	if (directionalLight)
	{
		lightPosition[3] = 0.0;
	}
	else
	{
		lightPosition[3] = 1.0;
	}

	glPushMatrix();
	/* Perform scene rotations based on user mouse input. */
	glRotatef(angle2, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);

	/* Position the light again, after viewing rotation. */
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

	/* Draw the light location. */
	drawLightLocation();

	/* Normal pass rendering the scene (caustics get added
	after this pass). */
	drawScene(PASS_NORMAL);

	if (showCaustics)
	{
		/* Disable depth buffer update and exactly match depth
		buffer values for slightly faster rendering. */
		glDepthMask(GL_FALSE);
		glDepthFunc(GL_EQUAL);

		/* Multiply the source color (from the caustic luminance
		texture) with the previous color from the normal pass.  The
		caustics are modulated into the scene. */
		glBlendFunc(GL_ZERO, GL_SRC_COLOR);
		glEnable(GL_BLEND);

		drawScene(PASS_CAUSTIC);

		/* Restore fragment operations to normal. */
		glDepthMask(GL_TRUE);
		glDepthFunc(GL_LESS);
		glDisable(GL_BLEND);
	}
	glPopMatrix();

	glutSwapBuffers();

	if (reportSpeed)
	{
		glFinish();
		endTime = glutGet(GLUT_ELAPSED_TIME);
		printf("Speed %.3g frames/sec (%d ms)\n", 1000.0/(endTime-startTime), endTime-startTime);
		fflush(stdout);
	}
}

#define FULL_LOOP_TIME (1.5f)

void idle(void)
{
	double secElapsedTime = 0.0;

	/* Advance the caustic pattern. */
	secElapsedTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
	currentCaustic = (int)(fmod(secElapsedTime, FULL_LOOP_TIME) * (NUM_PATTERNS / FULL_LOOP_TIME));

	glutPostRedisplay();
}

void updateIdleFunc()
{
	/* Must be both displaying the caustic patterns and have the
	caustics in rippling motion to need an idle callback. */
	if (showCaustics && causticMotion)
	{
		glutIdleFunc(idle);
	}
	else
	{
		glutIdleFunc(NULL);
	}
}

void visible(int vis)
{
	/* Stop the animation when the window is not visible. */
	if (vis == GLUT_VISIBLE)
		updateIdleFunc();
	else
		glutIdleFunc(NULL);
}

/* ARGSUSED2 */
static void mouse(int button, int state, int x, int y)
{
	/* Rotate the scene with the left mouse button. */
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			moving = 1;
			startx = x;
			starty = y;
		}

		if (state == GLUT_UP)
		{
			moving = 0;
		}
	}
	/* Rotate the light position with the middle mouse button. */
	if (button == GLUT_MIDDLE_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			lightMoving = 1;
			lightStartX = x;
			lightStartY = y;
		}

		if (state == GLUT_UP)
		{
			lightMoving = 0;
		}
	}
}

/* ARGSUSED1 */
static void motion(int x, int y)
{
	if (moving)
	{
		angle = angle + (x - startx);
		angle2 = angle2 + (y - starty);
		startx = x;
		starty = y;
		glutPostRedisplay();
	}

	if (lightMoving)
	{
		lightAngle += (x - lightStartX) / 40.0f;
		lightHeight += (lightStartY - y) / 20.0f;
		lightStartX = x;
		lightStartY = y;
		glutPostRedisplay();
	}
}

/* ARGSUSED1 */
static void keyboard(unsigned char c, int x, int y)
{
	switch (c)
	{
  case 27:  /* Escape quits. */
	  glutLeaveMainLoop();
	  break;
  case 'R':  /* Simplistic benchmarking. */
  case 'r':
	  reportSpeed = !reportSpeed;
	  break;
  case ' ':  /* Spacebar toggles caustic rippling motion. */
	  causticMotion = !causticMotion;
	  updateIdleFunc();
	  break;
	}
}

void menuSelect(int value)
{
	switch (value)
	{
	case M_POSITIONAL:
		directionalLight = 0;
		break;
	case M_DIRECTIONAL:
		directionalLight = 1;
		break;
	case M_GREENISH_LIGHT:
		lightDiffuseColor[0] = 1.0;
		lightDiffuseColor[1] = 1.5;  /* XXX Green = 1.5 */
		lightDiffuseColor[2] = 1.0;
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuseColor);
		break;
	case M_WHITE_LIGHT:
		lightDiffuseColor[0] = 1.5;  /* XXX Red = 1.5 */
		lightDiffuseColor[1] = 1.5;  /* XXX Green = 1.5 */
		lightDiffuseColor[2] = 1.5;  /* XXX Blue = 1.5 */
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuseColor);
		break;
	case M_WITH_CAUSTICS:
		showCaustics = 1;
		updateIdleFunc();
		break;
	case M_NO_CAUSTICS:
		showCaustics = 0;
		updateIdleFunc();
		break;
	case M_SWITCH_MODEL:
		object = (object + 1) % 3;
		break;
	case M_INCREASE_RIPPLE_SIZE:
		causticScale /= 1.5;
		break;
	case M_DECREASE_RIPPLE_SIZE:
		causticScale *= 1.5;
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	int width, height;
	int i;
	GLubyte *imageData;

	glutInit(&argc, argv);
	for (i=1; i<argc; i++)
	{
		if (!strcmp("-lesstex", argv[i]))
		{
			/* Only use 16 caustic textures.  Saves texture memory and works
			better on slow machines. */
			causticIncrement = 2;
		}
		else if (!strcmp("-evenlesstex", argv[i]))
		{
			/* Only use 8 caustic textures.  Saves even more texture memory for
			slow machines.  Temporal rippling suffers. */
			causticIncrement = 4;
		}
		else if (!strcmp("-nomipmap", argv[i]))
		{
			/* Don't use linear mipmap linear texture filtering; instead
			use linear filtering. */
			useMipmaps = 0;
		}
		else
		{
			fprintf(stderr, "usage: caustics [-lesstex]\n");
			fprintf(stderr, "       -lesstex uses half the caustic textures.\n");
			fprintf(stderr, "       -evenlesstex uses one fourth of the caustic textures.\n");
			exit(1);
		}
	}

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutCreateWindow("underwater");
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
	LoadFunctions();

	/* Check that renderer has the GL_EXT_texture_object
	extension or supports OpenGL 1.1 */
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	/* Load the caustic ripple textures. */
	printf("loading caustics:");
	glGenTextures(NUM_PATTERNS, causticTextures);
	for (i=0; i<NUM_PATTERNS; i += causticIncrement)
	{
		char filename[80];

		sprintf(filename, "caust%02d.bw", i);
		printf(" %d", i);
		fflush(stdout);
		imageData = read_alpha_texture(filename, &width, &height);
		if (imageData == NULL)
		{
			fprintf(stderr, "\n%s: could not load image file\n", filename);
			exit(1);
		}

		glBindTexture(GL_TEXTURE_2D, causticTextures[i]);
		if (useMipmaps)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			gluBuild2DMipmaps(GL_TEXTURE_2D, GL_LUMINANCE, width, height,
				GL_LUMINANCE, GL_UNSIGNED_BYTE, imageData);
		}
		else
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, height, width, 0,
				GL_LUMINANCE, GL_UNSIGNED_BYTE, imageData);
		}
		free(imageData);
	}
	printf(".\n");

	/* Load an RGB file for the floor texture. */
	printf("loading RGB textures: floor");
	fflush(stdout);
	imageData = read_rgb_texture(FLOOR_FILE, &width, &height);
	if (imageData == NULL)
	{
		fprintf(stderr, "%s: could not load image file\n", FLOOR_FILE);
		exit(1);
	}
	printf(".\n");

	glGenTextures(1, &groundTexture);
	glBindTexture(GL_TEXTURE_2D, groundTexture);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	if (useMipmaps)
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, 256, 256, GL_RGB,
			GL_UNSIGNED_BYTE, imageData);
	}
	else
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
			GL_RGB, GL_UNSIGNED_BYTE, imageData);
	}
	free(imageData);

	/* Setup the projection and view. */
	glMatrixMode(GL_PROJECTION);
	gluPerspective( /* field of view in degree */ 40.0,
		/* aspect ratio */ 1.0,
		/* Z near */ 20.0, /* Z far */ 100.0);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0.0, 8.0, 60.0,  /* eye is at (0,8,60) */
		0.0, 8.0, 0.0,      /* center is at (0,8,0) */
		0.0, 1.0, 0.);      /* up is in postivie Y direction */

	/* Setup initial OpenGL rendering state. */
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuseColor);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	/* Register assorted GLUT callback routines. */
	glutDisplayFunc(display);
	glutVisibilityFunc(visible);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutKeyboardFunc(keyboard);

	/* Create a pop-up menu. */
	glutCreateMenu(menuSelect);
	glutAddMenuEntry("Positional light", M_POSITIONAL);
	glutAddMenuEntry("Directional light", M_DIRECTIONAL);
	glutAddMenuEntry("Greenish light", M_GREENISH_LIGHT);
	glutAddMenuEntry("White light", M_WHITE_LIGHT);
	glutAddMenuEntry("With caustics", M_WITH_CAUSTICS);
	glutAddMenuEntry("No caustics", M_NO_CAUSTICS);
	glutAddMenuEntry("Switch model", M_SWITCH_MODEL);
	glutAddMenuEntry("Increase ripple size", M_INCREASE_RIPPLE_SIZE);
	glutAddMenuEntry("Decrease ripple size", M_DECREASE_RIPPLE_SIZE);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	/* For rendering the MODEL_DINO object. */
	dinoDisplayList = makeDinosaur();

	/* Enter GLUT's main loop; callback dispatching begins. */
	glutMainLoop();
	return 0;             /* ANSI C requires main to return int. */
}
