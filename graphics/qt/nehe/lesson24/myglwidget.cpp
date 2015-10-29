#include "myglwidget.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>
#include <QApplication>
#include <QFile>
#include <QFileInfo>
#include <QDebug>

namespace {
int     sc;                                 // Used For Scrolling The Screen
int     maxtokens;                              // Keeps Track Of The Number Of Extensions Supported
int     swidth;                                 // Scissor Width
int     sheight;                                // Scissor Height

GLuint      base;                                   // Base Display List For The Font
GLuint textureID;

#pragma pack(push, 1)
struct TgaHeader
{
    char  identsize;          // size of ID field that follows 18 byte header (0 usually)
    char  colourmaptype;      // type of colour map 0=none, 1=has palette
    char  imagetype;          // type of image 0=none,1=indexed,2=rgb,3=grey,+8=rle packed

    short colourmapstart;     // first colour map entry in palette
    short colourmaplength;    // number of colours in palette
    char  colourmapbits;      // number of bits per palette entry 15,16,24,32

    short xstart;             // image x origin
    short ystart;             // image y origin

    short width;              // image width in pixels
    short height;             // image height in pixels

    char  bits;               // image bits per pixel 8,16,24,32
    char  descriptor;         // image descriptor bits (vh flip bits)

};
#pragma pack(pop)

void loadTGA(QString filename)
{
    // check if file has tga extension
    if (!filename.toLower().endsWith("tga"))
        return ;
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug("failed to open file");
        return ;
    }
    TgaHeader header;
    file.read((char*)&header, sizeof(TgaHeader));
    // we only deal with rgb images, unmapped and rle, and no additional header information
    if(header.imagetype != 2 && header.imagetype != 10 && !header.identsize && !header.colourmaptype)
    {
        file.close();
        return ;
    }

    int bytesPerPixel = header.bits/8;
    int imageSize = header.width * header.height * bytesPerPixel;
    uchar *imageData = new uchar[imageSize];
    file.read((char*)imageData, imageSize);
    file.close();

    // decode rle, if any
    if(header.imagetype == 10)
    {
        uchar *rleData = new uchar[imageSize];
        memcpy(rleData, imageData, imageSize);

        int i = 0;
        int r = 0;
        while(i < imageSize && r < imageSize)
        {
            int num = (rleData[r]&0x7F) + 1;
            if(rleData[r] > 127) // is rle
            {
                for(int k = 0; k < num; ++k)
                {
                    if(r + 1 + bytesPerPixel >= imageSize || i >= imageSize)
                        return ; // corrupt image data!

                    memcpy(&imageData[i], &rleData[r + 1], bytesPerPixel);
                    i += bytesPerPixel;
                }
                r += bytesPerPixel + 1;
            }
            else
            {
                if(r + num * bytesPerPixel + 1 >= imageSize)
                    return ; // corrupt image data!

                memcpy(&imageData[i], &rleData[r + 1], num * bytesPerPixel);
                i += num * bytesPerPixel;
                r += num * bytesPerPixel + 1;
            }
        }

        delete[] rleData;
    }

    QImage::Format format;
    switch(header.bits)
    {
    case 16 : format = QImage::Format_RGB16; break;
    case 24 : format = QImage::Format_RGB32; break;
    case 32 : format = QImage::Format_ARGB32; break;
    default : delete[] imageData; return; // any other than 16, 24 or 32 would be a broken image
    };
    QImage image(imageData, header.width, header.height, format);
    // deal with the TGA flipping of axis
    // bit5 == 0 : flip
    // bit5 == 1 : don't flip
    image = image.mirrored(0, !(header.descriptor&16)); // copies the image. performance loss, but who cares ;-)
    image = QGLWidget::convertToGLFormat(image);
    // Build A Texture From The Data
    glGenTextures(1, &textureID);					// Generate OpenGL texture IDs

    glBindTexture(GL_TEXTURE_2D, textureID);			// Bind Our Texture
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	// Linear Filtered
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	// Linear
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());

}

void BuildFont()									// Build Our Font Display List
{
    base=glGenLists(256);									// Creating 256 Display Lists
    glBindTexture(GL_TEXTURE_2D, textureID);		// Select Our Font Texture
    for (int loop1=0; loop1<256; loop1++)					// Loop Through All 256 Lists
    {
        float cx=float(loop1%16)/16.0f;						// X Position Of Current Character
        float cy=float(loop1/16)/16.0f;						// Y Position Of Current Character

        glNewList(base+loop1,GL_COMPILE);					// Start Building A List
            glBegin(GL_QUADS);								// Use A Quad For Each Character
                glTexCoord2f(cx,1.0f-cy-0.0625f);			// Texture Coord (Bottom Left)
                glVertex2d(0,16);							// Vertex Coord (Bottom Left)
                glTexCoord2f(cx+0.0625f,1.0f-cy-0.0625f);	// Texture Coord (Bottom Right)
                glVertex2i(16,16);							// Vertex Coord (Bottom Right)
                glTexCoord2f(cx+0.0625f,1.0f-cy-0.001f);	// Texture Coord (Top Right)
                glVertex2i(16,0);							// Vertex Coord (Top Right)
                glTexCoord2f(cx,1.0f-cy-0.001f);			// Texture Coord (Top Left)
                glVertex2i(0,0);							// Vertex Coord (Top Left)
            glEnd();										// Done Building Our Quad (Character)
            glTranslated(14,0,0);							// Move To The Right Of The Character
        glEndList();										// Done Building The Display List
    }														// Loop Until All 256 Are Built
}

void KillFont()										// Delete The Font From Memory
{
    glDeleteLists(base,256);								// Delete All 256 Display Lists
}

GLvoid glPrint(GLint x, GLint y, int set, const char *fmt, ...)	// Where The Printing Happens
{
    char		text[1024];									// Holds Our String
    va_list		ap;											// Pointer To List Of Arguments

    if (fmt == NULL)										// If There's No Text
        return;												// Do Nothing

    va_start(ap, fmt);										// Parses The String For Variables
        vsprintf(text, fmt, ap);							// And Converts Symbols To Actual Numbers
    va_end(ap);												// Results Are Stored In Text

    if (set>1)												// Did User Choose An Invalid Character Set?
    {
        set=1;												// If So, Select Set 1 (Italic)
    }

    glEnable(GL_TEXTURE_2D);								// Enable Texture Mapping
    glLoadIdentity();										// Reset The Modelview Matrix
    glTranslated(x,y,0);									// Position The Text (0,0 - Top Left)
    glListBase(base-32+(128*set));							// Choose The Font Set (0 or 1)

    glScalef(1.0f,2.0f,1.0f);								// Make The Text 2X Taller

    glCallLists(strlen(text),GL_UNSIGNED_BYTE, text);		// Write The Text To The Screen
    glDisable(GL_TEXTURE_2D);								// Disable Texture Mapping
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

MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(parent), fullscreen(false)
{
    setWindowTitle(tr("nehe----lesson24"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(10);
    fpsUpdater = QTime::currentTime();
    fpsUpdater.start();
}

void MyGLWidget::initializeGL()
{
    loadTGA(QString(":/Font.tga"));
    BuildFont();                // Build The Font
    glShadeModel(GL_SMOOTH);   // Enables Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);  // Black Background
    glClearDepth(1.0f);             // Depth Buffer Setup
    glBindTexture(GL_TEXTURE_2D, textureID);
}

void MyGLWidget::resizeGL(int width, int height)
{
    swidth = width;											// Set Scissor Width To Window Width
    sheight = height;											// Set Scissor Height To Window Height
    if (height==0) {    // Prevent A Divide By Zero By
        height=1;    // Making Height Equal One
    }
    glViewport(0, 0, width, height);    // Reset The Current Viewport
    glMatrixMode(GL_PROJECTION);       // Select The Projection Matrix
    glLoadIdentity();                  // Reset The Projection Matrix

    // Calculate The Aspect Ratio Of The Window
   // gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
    glOrtho(0.0f,width,height, 0,-1.0f,1.0f);

    glMatrixMode(GL_MODELVIEW);      // Select The Modelview Matrix
    glLoadIdentity();                // Reset The Modelview Matrix

}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clear The Screen And The Depth Buffer
    glLoadIdentity();       // Reset The Current Modelview Matrix

    char	*token;											// Storage For Our Token
    int		cnt=0;											// Local Counter Variable
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear Screen And Depth Buffer

    glColor3f(1.0f,0.5f,0.5f);								// Set Color To Bright Red
    glPrint(50,16,1,"Renderer");							// Display Renderer
    glPrint(80,48,1,"Vendor");								// Display Vendor Name
    glPrint(66,80,1,"Version");								// Display Version

    glColor3f(1.0f,0.7f,0.4f);								// Set Color To Orange
    glPrint(200,16,1,(char *)glGetString(GL_RENDERER));		// Display Renderer
    glPrint(200,48,1,(char *)glGetString(GL_VENDOR));		// Display Vendor Name
    glPrint(200,80,1,(char *)glGetString(GL_VERSION));		// Display Version

    glColor3f(0.5f,0.5f,1.0f);								// Set Color To Bright Blue
    glPrint(192,432,1,"NeHe Productions");					// Write NeHe Productions At The Bottom Of The Screen

    glLoadIdentity();										// Reset The ModelView Matrix
    glColor3f(1.0f,1.0f,1.0f);								// Set The Color To White
    glBegin(GL_LINE_STRIP);									// Start Drawing Line Strips (Something New)
        glVertex2d(639,417);								// Top Right Of Bottom Box
        glVertex2d(  0,417);								// Top Left Of Bottom Box
        glVertex2d(  0,480);								// Lower Left Of Bottom Box
        glVertex2d(639,480);								// Lower Right Of Bottom Box
        glVertex2d(639,128);								// Up To Bottom Right Of Top Box
    glEnd();												// Done First Line Strip
    glBegin(GL_LINE_STRIP);									// Start Drawing Another Line Strip
        glVertex2d(  0,128);								// Bottom Left Of Top Box
        glVertex2d(639,128);								// Bottom Right Of Top Box
        glVertex2d(639,  1);								// Top Right Of Top Box
        glVertex2d(  0,  1);								// Top Left Of Top Box
        glVertex2d(  0,417);								// Down To Top Left Of Bottom Box
    glEnd();												// Done Second Line Strip

    glScissor(1	,int(0.135416f*sheight),swidth-2,int(0.597916f*sheight));	// Define Scissor Region
    glEnable(GL_SCISSOR_TEST);								// Enable Scissor Testing

    char* text=(char *)malloc(strlen((char *)glGetString(GL_EXTENSIONS))+1);	// Allocate Memory For Our Extension String
    strcpy (text,(char *)glGetString(GL_EXTENSIONS));		// Grab The Extension List, Store In Text

    token=strtok(text," ");									// Parse 'text' For Words, Seperated By " " (spaces)
    while(token != NULL)										// While The Token Isn't NULL
    {
        cnt++;												// Increase The Counter
        if (cnt > maxtokens)									// Is 'maxtokens' Less Than 'cnt'
        {
            maxtokens = cnt;									// If So, Set 'maxtokens' Equal To 'cnt'
        }

        glColor3f(0.5f,1.0f,0.5f);							// Set Color To Bright Green
        glPrint(0,96+(cnt*32)-sc,0,"%i",cnt);			// Print Current Extension Number
        glColor3f(1.0f,1.0f,0.5f);							// Set Color To Yellow
        glPrint(50,96+(cnt*32)-sc,0,token);				// Print The Current Token (Parsed Extension Name)
        token=strtok(NULL," ");								// Search For The Next Token
    }

    glDisable(GL_SCISSOR_TEST);								// Disable Scissor Testing

    free(text);												// Free Allocated Memory

    glFlush();

    showFPS();
}

void MyGLWidget::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_Up:
        if (sc > 0)
            sc -= 2;
        break;
    case Qt::Key_Down:
        if (sc < 32*(maxtokens-9))
            sc += 2;
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
