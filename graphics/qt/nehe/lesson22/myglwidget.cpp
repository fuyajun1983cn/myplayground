#include "myglwidget.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>
#include <QApplication>
#include <QPainter>
#include <QDebug>
#include <GL/glu.h>
#include <QVector>
#include <QVector3D>
#include <QVector2D>
#include <math.h>

#define MAX_EMBOSS (GLfloat)0.008f	// Maximum Emboss-Translate. Increase To Get Higher Immersion
                                    // At A Cost Of Lower Quality (More Artifacts Will Occur!)

namespace {

bool	emboss = false;												// Emboss Only, No Basetexture?
bool    bumps = true;													// Do Bumpmapping?
bool    useMultitexture = true;
GLint maxTexelUnits=1;

    GLfloat     xrot = 0;             // X Rotation ( NEW )
    GLfloat     yrot = 0;             // Y Rotation ( NEW )
    GLfloat     xspeed;
    GLfloat     yspeed;
    GLfloat     z = -5.0f;             // Z

    GLuint  filter=1;								// Which Filter To Use
    GLuint  texture[3];								// Storage For 3 Textures
    GLuint  bump[3];								// Our Bumpmappings
    GLuint  invbump[3];								// Inverted Bumpmaps
    GLuint  glLogo;									// Handle For OpenGL-Logo
    GLuint  multiLogo;								// Handle For Multitexture-Enabled-Logo
    GLfloat LightAmbient[]	= { 0.2f, 0.2f, 0.2f};					// Ambient Light Is 20% White
    GLfloat LightDiffuse[]	= { 1.0f, 1.0f, 1.0f};					// Diffuse Light Is White
    GLfloat LightPosition[]	= { 0.0f, 0.0f, 2.0f};					// Position Is Somewhat In Front Of Screen
    GLfloat Gray[]		= { 0.5f, 0.5f, 0.5f, 1.0f};

    // Data Contains The Faces For The Cube In Format 2xTexCoord, 3xVertex;
    // Note That The Tesselation Of The Cube Is Only Absolute Minimum.
    GLfloat data[]= {
            // FRONT FACE
            0.0f, 0.0f,		-1.0f, -1.0f, +1.0f,
            1.0f, 0.0f,		+1.0f, -1.0f, +1.0f,
            1.0f, 1.0f,		+1.0f, +1.0f, +1.0f,
            0.0f, 1.0f,		-1.0f, +1.0f, +1.0f,
            // BACK FACE
            1.0f, 0.0f,		-1.0f, -1.0f, -1.0f,
            1.0f, 1.0f,		-1.0f, +1.0f, -1.0f,
            0.0f, 1.0f,		+1.0f, +1.0f, -1.0f,
            0.0f, 0.0f,		+1.0f, -1.0f, -1.0f,
            // Top Face
            0.0f, 1.0f,		-1.0f, +1.0f, -1.0f,
            0.0f, 0.0f,		-1.0f, +1.0f, +1.0f,
            1.0f, 0.0f,		+1.0f, +1.0f, +1.0f,
            1.0f, 1.0f,		+1.0f, +1.0f, -1.0f,
            // Bottom Face
            1.0f, 1.0f,		-1.0f, -1.0f, -1.0f,
            0.0f, 1.0f,		+1.0f, -1.0f, -1.0f,
            0.0f, 0.0f,		+1.0f, -1.0f, +1.0f,
            1.0f, 0.0f,		-1.0f, -1.0f, +1.0f,
            // Right Face
            1.0f, 0.0f,		+1.0f, -1.0f, -1.0f,
            1.0f, 1.0f,		+1.0f, +1.0f, -1.0f,
            0.0f, 1.0f,		+1.0f, +1.0f, +1.0f,
            0.0f, 0.0f,		+1.0f, -1.0f, +1.0f,
            // Left Face
            0.0f, 0.0f,		-1.0f, -1.0f, -1.0f,
            1.0f, 0.0f,		-1.0f, -1.0f,  1.0f,
            1.0f, 1.0f,		-1.0f,  1.0f,  1.0f,
            0.0f, 1.0f,		-1.0f,  1.0f, -1.0f
    };

    void drawCube()
    {
        int i;
        glBegin(GL_QUADS);
            // Front Face
            glNormal3f( 0.0f, 0.0f, +1.0f);
            for (i=0; i<4; i++) {
                glTexCoord2f(data[5*i],data[5*i+1]);
                glVertex3f(data[5*i+2],data[5*i+3],data[5*i+4]);
            }
            // Back Face
            glNormal3f( 0.0f, 0.0f,-1.0f);
            for (i=4; i<8; i++) {
                glTexCoord2f(data[5*i],data[5*i+1]);
                glVertex3f(data[5*i+2],data[5*i+3],data[5*i+4]);
            }
            // Top Face
            glNormal3f( 0.0f, 1.0f, 0.0f);
            for (i=8; i<12; i++) {
                glTexCoord2f(data[5*i],data[5*i+1]);
                glVertex3f(data[5*i+2],data[5*i+3],data[5*i+4]);
            }
            // Bottom Face
            glNormal3f( 0.0f,-1.0f, 0.0f);
            for (i=12; i<16; i++) {
                glTexCoord2f(data[5*i],data[5*i+1]);
                glVertex3f(data[5*i+2],data[5*i+3],data[5*i+4]);
            }
            // Right face
            glNormal3f( 1.0f, 0.0f, 0.0f);
            for (i=16; i<20; i++) {
                glTexCoord2f(data[5*i],data[5*i+1]);
                glVertex3f(data[5*i+2],data[5*i+3],data[5*i+4]);
            }
            // Left Face
            glNormal3f(-1.0f, 0.0f, 0.0f);
            for (i=20; i<24; i++) {
                glTexCoord2f(data[5*i],data[5*i+1]);
                glVertex3f(data[5*i+2],data[5*i+3],data[5*i+4]);
            }
        glEnd();
    }

    void initLights()
    {
        glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
        glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
        glEnable(GL_LIGHT1);
    }

    // Calculates v=vM, M Is 4x4 In Column-Major, v Is 4dim. Row (i.e. "Transposed")
    void VMatMult(GLfloat *M, GLfloat *v) {
        GLfloat res[3];
        res[0]=M[ 0]*v[0]+M[ 1]*v[1]+M[ 2]*v[2]+M[ 3]*v[3];
        res[1]=M[ 4]*v[0]+M[ 5]*v[1]+M[ 6]*v[2]+M[ 7]*v[3];
        res[2]=M[ 8]*v[0]+M[ 9]*v[1]+M[10]*v[2]+M[11]*v[3];;
        v[0]=res[0];
        v[1]=res[1];
        v[2]=res[2];
        v[3]=M[15];											// Homogenous Coordinate
    }

    /*	Okay, Here Comes The Important Stuff:

        On http://www.nvidia.com/marketing/Developer/DevRel.nsf/TechnicalDemosFrame?OpenPage
        You Can Find A Demo Called GL_BUMP That Is A Little Bit More Complicated.
        GL_BUMP:   Copyright Diego Trtara, 1999.
                 -  diego_tartara@ciudad.com.ar  -

        The Idea Behind GL_BUMP Is, That You Compute The Texture-Coordinate Offset As Follows:
            0) All Coordinates Either In Object Or In World Space.
            1) Calculate Vertex v From Actual Position (The Vertex You're At) To The Lightposition
            2) Normalize v
            3) Project This v Into Tangent Space.
                Tangent Space Is The Plane "Touching" The Object In Our Current Position On It.
                Typically, If You're Working With Flat Surfaces, This Is The Surface Itself.
            4) Offset s,t-Texture-Coordinates By The Projected v's x And y-Component.

        * This Would Be Called Once Per Vertex In Our Geometry, If Done Correctly.
        * This Might Lead To Incoherencies In Our Texture Coordinates, But Is Ok As Long As You Did Not
        * Wrap The Bumpmap.

        Basically, We Do It The Same Way With Some Exceptions:
            ad 0) We'll Work In Object Space All Time. This Has The Advantage That We'll Only
                  Have To Transform The Lightposition From Frame To Frame. This Position Obviously
                  Has To Be Transformed Using The Inversion Of The Modelview Matrix. This Is, However,
                  A Considerable Drawback, If You Don't Know How Your Modelview Matrix Was Built, Since
                  Inverting A Matrix Is Costly And Complicated.
            ad 1) Do It Exactly That Way.
            ad 2) Do It Exactly That Way.
            ad 3) To Project The Lightvector Into Tangent Space, We'll Support The Setup-Routine
                  With Two Directions: One Of Increasing s-Texture-Coordinate Axis, The Other In
                  Increasing t-Texture-Coordinate Axis. The Projection Simply Is (Assumed Both
                  texCoord Vectors And The Lightvector Are Normalized) The Dotproduct Between The
                  Respective texCoord Vector And The Lightvector.
            ad 4) The Offset Is Computed By Taking The Result Of Step 3 And Multiplying The Two
                  Numbers With MAX_EMBOSS, A Constant That Specifies How Much Quality We're Willing To
                  Trade For Stronger Bump-Effects. Just Temper A Little Bit With MAX_EMBOSS!

        WHY THIS IS COOL:
            * Have A Look!
            * Very Cheap To Implement (About One Squareroot And A Couple Of MULs)!
            * Can Even Be Further Optimized!
            * SetUpBump Doesn't Disturb glBegin()/glEnd()
            * THIS DOES ALWAYS WORK - Not Only With XY-Tangent Spaces!!

        DRAWBACKS:
            * Must Know "Structure" Of Modelview-Matrix Or Invert It. Possible To Do The Whole Thing
            * In World Space, But This Involves One Transformation For Each Vertex!
    */

    void SetUpBumps(GLfloat *n, GLfloat *c, GLfloat *l, GLfloat *s, GLfloat *t) {
        GLfloat v[3];							// Vertex From Current Position To Light
        GLfloat lenQ;							// Used To Normalize

        // Calculate v From Current Vector c To Lightposition And Normalize v
        v[0]=l[0]-c[0];
        v[1]=l[1]-c[1];
        v[2]=l[2]-c[2];
        lenQ=(GLfloat) sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
        v[0]/=lenQ;		v[1]/=lenQ;		v[2]/=lenQ;
        // Project v Such That We Get Two Values Along Each Texture-Coordinat Axis.
        c[0]=(s[0]*v[0]+s[1]*v[1]+s[2]*v[2])*MAX_EMBOSS;
        c[1]=(t[0]*v[0]+t[1]*v[1]+t[2]*v[2])*MAX_EMBOSS;
    }

    void doLogo(void) {			// MUST CALL THIS LAST!!!, Billboards The Two Logos.
        glDepthFunc(GL_ALWAYS);
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
        glDisable(GL_LIGHTING);
        glLoadIdentity();
        glBindTexture(GL_TEXTURE_2D,glLogo);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,1.0f);	glVertex3f(0.23f, -0.4f,-1.0f);
            glTexCoord2f(1.0f,1.0f);	glVertex3f(0.53f, -0.4f,-1.0f);
            glTexCoord2f(1.0f,0.0f);	glVertex3f(0.53f, -0.25f,-1.0f);
            glTexCoord2f(0.0f,0.0f);	glVertex3f(0.23f, -0.25f,-1.0f);
        glEnd();
        if (useMultitexture) {
            glBindTexture(GL_TEXTURE_2D,multiLogo);
            glBegin(GL_QUADS);
                glTexCoord2f(0.0f,1.0f);	glVertex3f(-0.53f, -0.4f,-1.0f);
                glTexCoord2f(1.0f,1.0f);	glVertex3f(-0.33f, -0.4f,-1.0f);
                glTexCoord2f(1.0f,0.0f);	glVertex3f(-0.33f, -0.3f,-1.0f);
                glTexCoord2f(0.0f,0.0f);	glVertex3f(-0.53f, -0.3f,-1.0f);
            glEnd();
        }
        glDepthFunc(GL_LEQUAL);
    }

    bool doMesh1TexelUnits(void) {

        GLfloat c[4]={0.0f,0.0f,0.0f,1.0f};					// Holds Current Vertex
        GLfloat n[4]={0.0f,0.0f,0.0f,1.0f};					// Normalized Normal Of Current Surface
        GLfloat s[4]={0.0f,0.0f,0.0f,1.0f};					// s-Texture Coordinate Direction, Normalized
        GLfloat t[4]={0.0f,0.0f,0.0f,1.0f};					// t-Texture Coordinate Direction, Normalized
        GLfloat l[4];										// Holds Our Lightposition To Be Transformed Into Object Space
        GLfloat Minv[16];									// Holds The Inverted Modelview Matrix To Do So.
        int i;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer

        // Build Inverse Modelview Matrix First. This Substitutes One Push/Pop With One glLoadIdentity();
        // Simply Build It By Doing All Transformations Negated And In Reverse Order.
        glLoadIdentity();
        glRotatef(-yrot,0.0f,1.0f,0.0f);
        glRotatef(-xrot,1.0f,0.0f,0.0f);
        glTranslatef(0.0f,0.0f,-z);
        glGetFloatv(GL_MODELVIEW_MATRIX,Minv);
        glLoadIdentity();
        glTranslatef(0.0f,0.0f,z);

        glRotatef(xrot,1.0f,0.0f,0.0f);
        glRotatef(yrot,0.0f,1.0f,0.0f);

        // Transform The Lightposition Into Object Coordinates:
        l[0]=LightPosition[0];
        l[1]=LightPosition[1];
        l[2]=LightPosition[2];
        l[3]=1.0f;											// Homogenous Coordinate
        VMatMult(Minv,l);

    /*	PASS#1: Use Texture "Bump"
                No Blend
                No Lighting
                No Offset Texture-Coordinates */
        glBindTexture(GL_TEXTURE_2D, bump[filter]);
        glDisable(GL_BLEND);
        glDisable(GL_LIGHTING);
        drawCube();

    /* PASS#2:	Use Texture "Invbump"
                Blend GL_ONE To GL_ONE
                No Lighting
                Offset Texture Coordinates
                */
        glBindTexture(GL_TEXTURE_2D,invbump[filter]);
        glBlendFunc(GL_ONE,GL_ONE);
        glDepthFunc(GL_LEQUAL);
        glEnable(GL_BLEND);

        glBegin(GL_QUADS);
            // Front Face
            n[0]=0.0f;		n[1]=0.0f;		n[2]=1.0f;
            s[0]=1.0f;		s[1]=0.0f;		s[2]=0.0f;
            t[0]=0.0f;		t[1]=1.0f;		t[2]=0.0f;
            for (i=0; i<4; i++) {
                c[0]=data[5*i+2];
                c[1]=data[5*i+3];
                c[2]=data[5*i+4];
                SetUpBumps(n,c,l,s,t);
                glTexCoord2f(data[5*i]+c[0], data[5*i+1]+c[1]);
                glVertex3f(data[5*i+2], data[5*i+3], data[5*i+4]);
            }
            // Back Face
            n[0]=0.0f;		n[1]=0.0f;		n[2]=-1.0f;
            s[0]=-1.0f;		s[1]=0.0f;		s[2]=0.0f;
            t[0]=0.0f;		t[1]=1.0f;		t[2]=0.0f;
            for (i=4; i<8; i++) {
                c[0]=data[5*i+2];
                c[1]=data[5*i+3];
                c[2]=data[5*i+4];
                SetUpBumps(n,c,l,s,t);
                glTexCoord2f(data[5*i]+c[0], data[5*i+1]+c[1]);
                glVertex3f(data[5*i+2], data[5*i+3], data[5*i+4]);
            }
            // Top Face
            n[0]=0.0f;		n[1]=1.0f;		n[2]=0.0f;
            s[0]=1.0f;		s[1]=0.0f;		s[2]=0.0f;
            t[0]=0.0f;		t[1]=0.0f;		t[2]=-1.0f;
            for (i=8; i<12; i++) {
                c[0]=data[5*i+2];
                c[1]=data[5*i+3];
                c[2]=data[5*i+4];
                SetUpBumps(n,c,l,s,t);
                glTexCoord2f(data[5*i]+c[0], data[5*i+1]+c[1]);
                glVertex3f(data[5*i+2], data[5*i+3], data[5*i+4]);
            }
            // Bottom Face
            n[0]=0.0f;		n[1]=-1.0f;		n[2]=0.0f;
            s[0]=-1.0f;		s[1]=0.0f;		s[2]=0.0f;
            t[0]=0.0f;		t[1]=0.0f;		t[2]=-1.0f;
            for (i=12; i<16; i++) {
                c[0]=data[5*i+2];
                c[1]=data[5*i+3];
                c[2]=data[5*i+4];
                SetUpBumps(n,c,l,s,t);
                glTexCoord2f(data[5*i]+c[0], data[5*i+1]+c[1]);
                glVertex3f(data[5*i+2], data[5*i+3], data[5*i+4]);
            }
            // Right Face
            n[0]=1.0f;		n[1]=0.0f;		n[2]=0.0f;
            s[0]=0.0f;		s[1]=0.0f;		s[2]=-1.0f;
            t[0]=0.0f;		t[1]=1.0f;		t[2]=0.0f;
            for (i=16; i<20; i++) {
                c[0]=data[5*i+2];
                c[1]=data[5*i+3];
                c[2]=data[5*i+4];
                SetUpBumps(n,c,l,s,t);
                glTexCoord2f(data[5*i]+c[0], data[5*i+1]+c[1]);
                glVertex3f(data[5*i+2], data[5*i+3], data[5*i+4]);
            }
            // Left Face
            n[0]=-1.0f;		n[1]=0.0f;		n[2]=0.0f;
            s[0]=0.0f;		s[1]=0.0f;		s[2]=1.0f;
            t[0]=0.0f;		t[1]=1.0f;		t[2]=0.0f;
            for (i=20; i<24; i++) {
                c[0]=data[5*i+2];
                c[1]=data[5*i+3];
                c[2]=data[5*i+4];
                SetUpBumps(n,c,l,s,t);
                glTexCoord2f(data[5*i]+c[0], data[5*i+1]+c[1]);
                glVertex3f(data[5*i+2], data[5*i+3], data[5*i+4]);
            }
        glEnd();

    /* PASS#3:	Use Texture "Base"
                Blend GL_DST_COLOR To GL_SRC_COLOR (Multiplies By 2)
                Lighting Enabled
                No Offset Texture-Coordinates
                */
        if (!emboss) {
            glTexEnvf (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
            glBindTexture(GL_TEXTURE_2D,texture[filter]);
            glBlendFunc(GL_DST_COLOR,GL_SRC_COLOR);
            glEnable(GL_LIGHTING);
            drawCube();
        }

        xrot+=xspeed;
        yrot+=yspeed;
        if (xrot>360.0f) xrot-=360.0f;
        if (xrot<0.0f) xrot+=360.0f;
        if (yrot>360.0f) yrot-=360.0f;
        if (yrot<0.0f) yrot+=360.0f;

    /*	LAST PASS:	Do The Logos! */
        doLogo();

        return true;										// Keep Going
    }

    bool doMesh2TexelUnits(void) {

        GLfloat c[4]={0.0f,0.0f,0.0f,1.0f};					// holds current vertex
        GLfloat n[4]={0.0f,0.0f,0.0f,1.0f};					// normalized normal of current surface
        GLfloat s[4]={0.0f,0.0f,0.0f,1.0f};					// s-texture coordinate direction, normalized
        GLfloat t[4]={0.0f,0.0f,0.0f,1.0f};					// t-texture coordinate direction, normalized
        GLfloat l[4];										// holds our lightposition to be transformed into object space
        GLfloat Minv[16];									// holds the inverted modelview matrix to do so.
        int i;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer

        // Build Inverse Modelview Matrix First. This Substitutes One Push/Pop With One glLoadIdentity();
        // Simply Build It By Doing All Transformations Negated And In Reverse Order.
        glLoadIdentity();
        glRotatef(-yrot,0.0f,1.0f,0.0f);
        glRotatef(-xrot,1.0f,0.0f,0.0f);
        glTranslatef(0.0f,0.0f,-z);
        glGetFloatv(GL_MODELVIEW_MATRIX,Minv);
        glLoadIdentity();
        glTranslatef(0.0f,0.0f,z);

        glRotatef(xrot,1.0f,0.0f,0.0f);
        glRotatef(yrot,0.0f,1.0f,0.0f);

        // Transform The Lightposition Into Object Coordinates:
        l[0]=LightPosition[0];
        l[1]=LightPosition[1];
        l[2]=LightPosition[2];
        l[3]=1.0f;											// Homogenous Coordinate
        VMatMult(Minv,l);

    /*	PASS#1: Texel-Unit 0:	Use Texture "Bump"
                                No Blend
                                No Lighting
                                No Offset Texture-Coordinates
                                Texture-Operation "Replace"
                Texel-Unit 1:	Use Texture "Invbump"
                                No Lighting
                                Offset Texture Coordinates
                                Texture-Operation "Replace"
    */
        // TEXTURE-UNIT #0
        glActiveTexture(GL_TEXTURE0);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, bump[filter]);
        glTexEnvf(GL_TEXTURE_ENV, (GLenum)GL_TEXTURE_ENV_MODE, GL_COMBINE_EXT);
        glTexEnvf(GL_TEXTURE_ENV, (GLenum)GL_COMBINE_RGB_EXT, GL_REPLACE);
        // TEXTURE-UNIT #1:
        glActiveTexture(GL_TEXTURE1);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, invbump[filter]);
        glTexEnvf (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE_EXT);
        glTexEnvf (GL_TEXTURE_ENV, (GLenum)GL_COMBINE_RGB_EXT, GL_ADD);
        // General Switches:
        glDisable(GL_BLEND);
        glDisable(GL_LIGHTING);
        glBegin(GL_QUADS);
            // Front Face
            n[0]=0.0f;		n[1]=0.0f;		n[2]=1.0f;
            s[0]=1.0f;		s[1]=0.0f;		s[2]=0.0f;
            t[0]=0.0f;		t[1]=1.0f;		t[2]=0.0f;
            for (i=0; i<4; i++) {
                c[0]=data[5*i+2];
                c[1]=data[5*i+3];
                c[2]=data[5*i+4];
                SetUpBumps(n,c,l,s,t);
                glMultiTexCoord2f(GL_TEXTURE0,data[5*i]     , data[5*i+1]);
                glMultiTexCoord2f(GL_TEXTURE1,data[5*i]+c[0], data[5*i+1]+c[1]);
                glVertex3f(data[5*i+2], data[5*i+3], data[5*i+4]);
            }
            // Back Face
            n[0]=0.0f;		n[1]=0.0f;		n[2]=-1.0f;
            s[0]=-1.0f;		s[1]=0.0f;		s[2]=0.0f;
            t[0]=0.0f;		t[1]=1.0f;		t[2]=0.0f;
            for (i=4; i<8; i++) {
                c[0]=data[5*i+2];
                c[1]=data[5*i+3];
                c[2]=data[5*i+4];
                SetUpBumps(n,c,l,s,t);
                glMultiTexCoord2f(GL_TEXTURE0,data[5*i]     , data[5*i+1]);
                glMultiTexCoord2f(GL_TEXTURE1,data[5*i]+c[0], data[5*i+1]+c[1]);
                glVertex3f(data[5*i+2], data[5*i+3], data[5*i+4]);
            }
            // Top Face
            n[0]=0.0f;		n[1]=1.0f;		n[2]=0.0f;
            s[0]=1.0f;		s[1]=0.0f;		s[2]=0.0f;
            t[0]=0.0f;		t[1]=0.0f;		t[2]=-1.0f;
            for (i=8; i<12; i++) {
                c[0]=data[5*i+2];
                c[1]=data[5*i+3];
                c[2]=data[5*i+4];
                SetUpBumps(n,c,l,s,t);
                glMultiTexCoord2f(GL_TEXTURE0,data[5*i]     , data[5*i+1]     );
                glMultiTexCoord2f(GL_TEXTURE1,data[5*i]+c[0], data[5*i+1]+c[1]);
                glVertex3f(data[5*i+2], data[5*i+3], data[5*i+4]);
            }
            // Bottom Face
            n[0]=0.0f;		n[1]=-1.0f;		n[2]=0.0f;
            s[0]=-1.0f;		s[1]=0.0f;		s[2]=0.0f;
            t[0]=0.0f;		t[1]=0.0f;		t[2]=-1.0f;
            for (i=12; i<16; i++) {
                c[0]=data[5*i+2];
                c[1]=data[5*i+3];
                c[2]=data[5*i+4];
                SetUpBumps(n,c,l,s,t);
                glMultiTexCoord2f(GL_TEXTURE0,data[5*i]     , data[5*i+1]     );
                glMultiTexCoord2f(GL_TEXTURE1,data[5*i]+c[0], data[5*i+1]+c[1]);
                glVertex3f(data[5*i+2], data[5*i+3], data[5*i+4]);
            }
            // Right Face
            n[0]=1.0f;		n[1]=0.0f;		n[2]=0.0f;
            s[0]=0.0f;		s[1]=0.0f;		s[2]=-1.0f;
            t[0]=0.0f;		t[1]=1.0f;		t[2]=0.0f;
            for (i=16; i<20; i++) {
                c[0]=data[5*i+2];
                c[1]=data[5*i+3];
                c[2]=data[5*i+4];
                SetUpBumps(n,c,l,s,t);
                glMultiTexCoord2f(GL_TEXTURE0,data[5*i]     , data[5*i+1]     );
                glMultiTexCoord2f(GL_TEXTURE1,data[5*i]+c[0], data[5*i+1]+c[1]);
                glVertex3f(data[5*i+2], data[5*i+3], data[5*i+4]);
            }
            // Left Face
            n[0]=-1.0f;		n[1]=0.0f;		n[2]=0.0f;
            s[0]=0.0f;		s[1]=0.0f;		s[2]=1.0f;
            t[0]=0.0f;		t[1]=1.0f;		t[2]=0.0f;
            for (i=20; i<24; i++) {
                c[0]=data[5*i+2];
                c[1]=data[5*i+3];
                c[2]=data[5*i+4];
                SetUpBumps(n,c,l,s,t);
                glMultiTexCoord2f(GL_TEXTURE0,data[5*i]     , data[5*i+1]     );
                glMultiTexCoord2f(GL_TEXTURE1,data[5*i]+c[0], data[5*i+1]+c[1]);
                glVertex3f(data[5*i+2], data[5*i+3], data[5*i+4]);
            }
        glEnd();

    /* PASS#2	Use Texture "Base"
                Blend GL_DST_COLOR To GL_SRC_COLOR (Multiplies By 2)
                Lighting Enabled
                No Offset Texture-Coordinates
                */
        glActiveTexture(GL_TEXTURE1);
        glDisable(GL_TEXTURE_2D);
        glActiveTexture(GL_TEXTURE0);
        if (!emboss) {
            glTexEnvf (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
            glBindTexture(GL_TEXTURE_2D,texture[filter]);
            glBlendFunc(GL_DST_COLOR,GL_SRC_COLOR);
            glEnable(GL_BLEND);
            glEnable(GL_LIGHTING);
            drawCube();
        }

        xrot+=xspeed;
        yrot+=yspeed;
        if (xrot>360.0f) xrot-=360.0f;
        if (xrot<0.0f) xrot+=360.0f;
        if (yrot>360.0f) yrot-=360.0f;
        if (yrot<0.0f) yrot+=360.0f;

    /* LAST PASS:	Do The Logos! */
        doLogo();

        return true;										// Keep Going
    }
    bool doMeshNoBumps(void) {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
        glLoadIdentity();									// Reset The View
        glTranslatef(0.0f,0.0f,z);

        glRotatef(xrot,1.0f,0.0f,0.0f);
        glRotatef(yrot,0.0f,1.0f,0.0f);
        if (useMultitexture) {
            glActiveTexture(GL_TEXTURE1);
            glDisable(GL_TEXTURE_2D);
            glActiveTexture(GL_TEXTURE0);
        }
        glDisable(GL_BLEND);
        glBindTexture(GL_TEXTURE_2D,texture[filter]);
        glBlendFunc(GL_DST_COLOR,GL_SRC_COLOR);
        glEnable(GL_LIGHTING);
        drawCube();

        xrot+=xspeed;
        yrot+=yspeed;
        if (xrot>360.0f) xrot-=360.0f;
        if (xrot<0.0f) xrot+=360.0f;
        if (yrot>360.0f) yrot-=360.0f;
        if (yrot<0.0f) yrot+=360.0f;

    /* LAST PASS:	Do The Logos! */
        doLogo();

        return true;										// Keep Going
    }
}


void MyGLWidget::showFPS()
{
    static GLint Frames = 0;

    /* Gather our frames per second */
   Frames++;
   {
       GLint t = fpsUpdater.elapsed();
       if (t >= 5000) {
           GLfloat seconds = t / 1000.0;
           GLfloat fps = Frames / seconds;
           QString title = windowTitle().mid(0, 16) + QString(" FPS: %1").arg(fps);
           setWindowTitle(title);
           t = 0;
           Frames = 0;
           fpsUpdater.restart();
       }
   }
}

void MyGLWidget::loadTextures()
{
   QImage image;
   char *alpha = NULL;
   unsigned char *temp = NULL;
   if (image.load(":/base.bmp")) {
       convertToGLFormat(image);
       glGenTextures(3, texture);

       //nearst
       glBindTexture(GL_TEXTURE_2D, texture[0]);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
       glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());

       //linear
       glBindTexture(GL_TEXTURE_2D, texture[1]);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
       glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());

       //mipmap
       glBindTexture(GL_TEXTURE_2D, texture[2]);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
       gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, image.width(), image.height(), GL_RGBA, GL_UNSIGNED_BYTE, image.bits());

   }

   if (image.load(":/bump.bmp")) {
       convertToGLFormat(image);

       glPixelTransferf(GL_RED_SCALE,0.5f);                // Scale RGB By 50%, So That We Have Only
       glPixelTransferf(GL_GREEN_SCALE,0.5f);              // Half Intenstity
       glPixelTransferf(GL_BLUE_SCALE,0.5f);
       glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);  // No Wrapping, Please!
       glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
       glGenTextures(3, bump);                     // Create Three Textures

       //nearst
       glBindTexture(GL_TEXTURE_2D, bump[0]);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
       glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());

       //linear
       glBindTexture(GL_TEXTURE_2D, bump[1]);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
       glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());

       //mipmap
       glBindTexture(GL_TEXTURE_2D, bump[2]);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
       gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, image.width(), image.height(), GL_RGBA, GL_UNSIGNED_BYTE, image.bits());

       temp = image.bits();
       for (int i = 0; i < 3 * image.width() * image.height(); i++) {
           temp[i] = 255 - temp[i];
       }
       glGenTextures(3, invbump);

       //nearst
       glBindTexture(GL_TEXTURE_2D, invbump[0]);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
       glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());

       //linear
       glBindTexture(GL_TEXTURE_2D, invbump[1]);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
       glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());

       //mipmap
       glBindTexture(GL_TEXTURE_2D, invbump[2]);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
       gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, image.width(), image.height(), GL_RGBA, GL_UNSIGNED_BYTE, image.bits());

   }

   if (image.load(":/opengl_alpha.bmp")) {
       convertToGLFormat(image);
       temp = image.bits();
       alpha = new char[4 * image.width() * image.height()];
       for (int a = 0; a < image.width() * image.height(); a++)
           alpha[4 * a + 3] = temp[a * 4];//R as alpha
#if 1
       if (image.load(":/opengl.bmp")) {
           convertToGLFormat(image);
           temp = image.bits();
           for (int a = 0; a < image.width() * image.height(); a++) {
               alpha[4*a] = temp[a*4];
               alpha[4*a+1] = temp[a*4+1];
               alpha[4*a+2] = temp[a*4+2];
           }
       }
#endif

       glGenTextures(1, &glLogo);
       //nearst
       glBindTexture(GL_TEXTURE_2D, glLogo);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
       glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, alpha);

       delete alpha;
       alpha = NULL;
   }
#if 1
   if (image.load(":/multi_on_alpha.bmp")) {
       convertToGLFormat(image);
       temp = image.bits();
       alpha = new char[4 * image.width() * image.height()];
       for (int a = 0; a < image.width() * image.height(); a++)
           alpha[4*a+3] = temp[a*4];

 #if 1
       QImage img;
       if (img.load(":/opengl.bmp")) {
           convertToGLFormat(img);
           temp = img.bits();
           for (int a = 0; a < image.width() * image.height(); a++) {
  //             alpha[4*a] = temp[a*4];
               alpha[4*a+1] = temp[a*4+1];
               alpha[4*a+2] = temp[a*4+2];
           }
       }
#endif
       glGenTextures(1, &multiLogo);
       //linear
       glBindTexture(GL_TEXTURE_2D, multiLogo);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
       glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, alpha);

       delete alpha;
       alpha = NULL;
   }
#endif
}

MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(parent), fullscreen(false)
{
    setWindowTitle(tr("nehe----lesson22"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(10);
    fpsUpdater = QTime::currentTime();
    fpsUpdater.start();
}

void MyGLWidget::initializeGL()
{
    loadTextures();
    glEnable(GL_TEXTURE_2D);    // Enable Texture Mapping ( NEW )

    glShadeModel(GL_SMOOTH);   // Enables Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);  // Black Background
    glClearDepth(1.0f);             // Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);        // Enables Depth Testing
    glDepthFunc(GL_LEQUAL);        // The Type Of Depth Test To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations

    initLights();
}

void MyGLWidget::resizeGL(int width, int height)
{
    if (height==0) {    // Prevent A Divide By Zero By
        height=1;    // Making Height Equal One
    }
    glViewport(0, 0, width, height);    // Reset The Current Viewport
    glMatrixMode(GL_PROJECTION);       // Select The Projection Matrix
    glLoadIdentity();                  // Reset The Projection Matrix

    // Calculate The Aspect Ratio Of The Window
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
    //glOrtho(0.0f,width,0,height,-1.0f,1.0f);

    glMatrixMode(GL_MODELVIEW);      // Select The Modelview Matrix
    glLoadIdentity();                // Reset The Modelview Matrix

}

void MyGLWidget::paintGL()
{
    if (bumps) {
            if (useMultitexture && maxTexelUnits>1)
                doMesh2TexelUnits();
            else
                doMesh1TexelUnits();
        }
    else
        doMeshNoBumps();
    showFPS();
}

void MyGLWidget::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_E:
        emboss = !emboss;
        break;
    case Qt::Key_M:
        useMultitexture=!useMultitexture;
        break;
    case Qt::Key_B:
        bumps=!bumps;
        break;
    case Qt::Key_I:
        filter++;
        filter%=3;
        break;
    case Qt::Key_PageDown:
        z -= 0.2f;
        break;
    case Qt::Key_PageUp:
        z += 0.2f;
        break;
    case Qt::Key_Up:
        xspeed -= 0.01f;
        break;
    case Qt::Key_Down:
        xspeed += 0.01f;
        break;
    case Qt::Key_Left:
        yspeed -= 0.01f;
        break;
    case Qt::Key_Right:
        yspeed += 0.01f;
        break;
    case Qt::Key_F:
        fullscreen = !fullscreen;
        if (fullscreen) {
            showFullScreen();
        } else {
            resize(640, 480);
            showNormal();
        }
        break;
    case Qt::Key_Escape:
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(NULL, "NeHe",
                           "Do you want to exit?",
                           QMessageBox::Yes | QMessageBox::No,
                           QMessageBox::Yes);
        if (reply == QMessageBox::Yes) {
                qApp->quit();
        }
        break;
    default:
        QGLWidget::keyPressEvent(e);
        break;
    }
}

void MyGLWidget::closeEvent(QCloseEvent *e)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "NeHe",
                       "Do you want to exit?",
                       QMessageBox::Yes | QMessageBox::No,
                       QMessageBox::No);
    if (reply == QMessageBox::Yes) {
            e->accept();
    } else {
        e->ignore();
    }
}
