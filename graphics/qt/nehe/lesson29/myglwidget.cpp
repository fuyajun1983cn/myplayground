#include "myglwidget.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>
#include <QApplication>
#include <QVector3D>
#include <QDebug>

#include <math.h>
#include <GL/glu.h>

namespace {
GLfloat		xrot;				/*  X Rotation */
GLfloat		yrot;				/*  Y Rotation */
GLfloat		zrot;				/*  Z Rotation */

GLuint		texture[1];			/*  Storage For 1 Texture */

typedef struct
{
    int width;				/*  Width Of Image In Pixels */
    int height;				/*  Height Of Image In Pixels */
    int format;				/*  Number Of Bytes Per Pixel */
    unsigned char *data;			/*  Texture Data */
} TEXTURE_IMAGE;

typedef TEXTURE_IMAGE *P_TEXTURE_IMAGE;		/*  A Pointer To The Texture Image Data Type */

P_TEXTURE_IMAGE t1;				/*  Pointer To The Texture Image Data Type */
P_TEXTURE_IMAGE t2;				/*  Pointer To The Texture Image Data Type */


/*  Allocate An Image Structure And Inside Allocate Its Memory Requirements */
P_TEXTURE_IMAGE AllocateTextureBuffer( GLint w, GLint h, GLint f)
{
    P_TEXTURE_IMAGE ti=NULL;				/*  Pointer To Image Struct */
    unsigned char *c=NULL;				/*  Pointer To Block Memory For Image */

    ti = (P_TEXTURE_IMAGE)malloc(sizeof(TEXTURE_IMAGE));/*  One Image Struct Please */

    if( ti != NULL ) {
        ti->width  = w;					/*  Set Width */
        ti->height = h;					/*  Set Height */
        ti->format = f;					/*  Set Format */
        c = (unsigned char *)malloc( w * h * f);
        if ( c != NULL ) {
            ti->data = c;
        }
        else {
        printf("Could Not Allocate Memory For A Texture Buffer\n");
            return NULL;
        }
    }
    else
    {
        printf("Could Not Allocate An Image Structure\n");
        return NULL;
    }
    return ti;													/*  Return Pointer To Image Struct */
}

/*  Free Up The Image Data */
void DeallocateTexture( P_TEXTURE_IMAGE t )
{
    if(t)
    {
        if(t->data)
        {
            free(t->data);
        }

        free(t);
    }
}

/*  Read A .RAW File In To The Allocated Image Buffer Using Data In The Image Structure Header. */
/*  Flip The Image Top To Bottom.  Returns 0 For Failure Of Read, Or Number Of Bytes Read. */
int ReadTextureData ( char *filename, P_TEXTURE_IMAGE buffer)
{
    FILE *f;
    int i,j,k,done=0;
    int stride = buffer->width * buffer->format;				/*  Size Of A Row (Width * Bytes Per Pixel) */
    unsigned char *p = NULL;

    f = fopen(filename, "rb");									/*  Open "filename" For Reading Bytes */
    if( f != NULL )												/*  If File Exists */
    {
        for( i = buffer->height-1; i >= 0 ; i-- )				/*  Loop Through Height (Bottoms Up - Flip Image) */
        {
            p = buffer->data + (i * stride );					/*   */
            for ( j = 0; j < buffer->width ; j++ )				/*  Loop Through Width */
            {
                for ( k = 0 ; k < buffer->format-1 ; k++, p++, done++ )
                {
                    *p = fgetc(f);								/*  Read Value From File And Store In Memory */
                }
                *p = 255; p++;									/*  Store 255 In Alpha Channel And Increase Pointer */
            }
        }
        fclose(f);												/*  Close The File */
    }
    else														/*  Otherwise */
    {
        printf("Unable To Open Image File\n");
    }
    return done;												/*  Returns Number Of Bytes Read In */
}

void BuildTexture (P_TEXTURE_IMAGE tex)
{
    glGenTextures(1, &texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
 //   gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, tex->width, tex->height, GL_RGBA, GL_UNSIGNED_BYTE, tex->data);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex->width, tex->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, tex->data);
}

void Blit( P_TEXTURE_IMAGE src, P_TEXTURE_IMAGE dst, int src_xstart, int src_ystart, int src_width, int src_height,
           int dst_xstart, int dst_ystart, int blend, int alpha)
{
    int i,j,k;
    unsigned char *s, *d;										/*  Source & Destination */

    /*  Clamp Alpha If Value Is Out Of Range */
    if( alpha > 255 ) alpha = 255;
    if( alpha < 0 ) alpha = 0;

    /*  Check For Incorrect Blend Flag Values */
    if( blend < 0 ) blend = 0;
    if( blend > 1 ) blend = 1;

    d = dst->data + (dst_ystart * dst->width * dst->format);    /*  Start Row - dst (Row * Width In Pixels * Bytes Per Pixel) */
    s = src->data + (src_ystart * src->width * src->format);    /*  Start Row - src (Row * Width In Pixels * Bytes Per Pixel) */

    for (i = 0 ; i < src_height ; i++ )				/*  Height Loop */
    {
        s = s + (src_xstart * src->format);			/*  Move Through Src Data By Bytes Per Pixel */
        d = d + (dst_xstart * dst->format);			/*  Move Through Dst Data By Bytes Per Pixel */
        for (j = 0 ; j < src_width ; j++ )			/*  Width Loop */
        {
            for( k = 0 ; k < src->format ; k++, d++, s++)	/*  "n" Bytes At A Time */
            {
                if (blend)										/*  If Blending Is On */
                    *d = ( (*s * alpha) + (*d * (255-alpha)) ) >> 8; /*  Multiply Src Data*alpha Add Dst Data*(255-alpha) */
                else											/*  Keep in 0-255 Range With >> 8 */
                    *d = *s;									/*  No Blending Just Do A Straight Copy */
            }
        }
        d = d + (dst->width - (src_width + dst_xstart))*dst->format;	/*  Add End Of Row */
        s = s + (src->width - (src_width + src_xstart))*src->format;	/*  Add End Of Row */
    }
}

}

void MyGLWidget::loadTextures()
{

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

MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(parent), fullscreen(false)
{
    setWindowTitle(tr("nehe----lesson29"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(10);
    fpsUpdater = QTime::currentTime();
    fpsUpdater.start();
}

void MyGLWidget::initializeGL()
{
    t1 = AllocateTextureBuffer( 256, 256, 4 );		/*  Get An Image Structure */
     if (ReadTextureData("/home/fuyajun/myplayground/qt/nehe/lesson29/Monitor.raw",t1)==0)	/*  Fill The Image Structure With Data */
     {															/*  Nothing Read? */
         printf("Could Not Read 'Monitor.raw' Image Data\n");
         return ;
     }

     t2 = AllocateTextureBuffer( 256, 256, 4 );		/*  Second Image Structure */
     if (ReadTextureData("/home/fuyajun/myplayground/qt/nehe/lesson29/GL.raw",t2)==0)	/*  Fill The Image Structure With Data */
     {						/*  Nothing Read? */
         printf("Could Not Read 'GL.raw' Image Data\n");
         return ;
     }

     /*  Image To Blend In, Original Image, Src Start X & Y, Src Width & Height, Dst Location X & Y, Blend Flag, Alpha Value */
     Blit(t2,t1,127,127,128,128,64,64,1,127);	/*  Call The Blitter Routine */

     BuildTexture (t1);				/*  Load The Texture Map Into Texture Memory */

     DeallocateTexture( t1 );			/*  Clean Up Image Memory Because Texture Is */
     DeallocateTexture( t2 );			/*  In GL Texture Memory Now */

     glEnable(GL_TEXTURE_2D);			/*  Enable Texture Mapping */

     glShadeModel(GL_SMOOTH);			/*  Enables Smooth Color Shading */
     glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	/*  This Will Clear The Background Color To Black */
     glClearDepth(1.0);				/*  Enables Clearing Of The Depth Buffer */
     glEnable(GL_DEPTH_TEST);			/*  Enables Depth Testing */
     glDepthFunc(GL_LESS);			/*  The Type Of Depth Test To Do */
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

    glMatrixMode(GL_MODELVIEW);      // Select The Modelview Matrix
    glLoadIdentity();                // Reset The Modelview Matrix

}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clear The Screen And The Depth Buffer
    glLoadIdentity();										/*  Reset The View */
    glTranslatef(0.0f,0.0f,-5.0f);

    glRotatef(xrot,1.0f,0.0f,0.0f);
    glRotatef(yrot,0.0f,1.0f,0.0f);
    glRotatef(zrot,0.0f,0.0f,1.0f);

    glBindTexture(GL_TEXTURE_2D, texture[0]);

    glBegin(GL_QUADS);
        /*  Front Face */
        glNormal3f( 0.0f, 0.0f, 1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
        /*  Back Face */
        glNormal3f( 0.0f, 0.0f,-1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
        /*  Top Face */
        glNormal3f( 0.0f, 1.0f, 0.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        /*  Bottom Face */
        glNormal3f( 0.0f,-1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
        /*  Right Face */
        glNormal3f( 1.0f, 0.0f, 0.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
        /*  Left Face */
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
    glEnd();

    xrot+=0.3f;
    yrot+=0.2f;
    zrot+=0.4f;

    showFPS();
}

void MyGLWidget::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
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
