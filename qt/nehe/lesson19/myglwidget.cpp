#include "myglwidget.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>
#include <QApplication>
#include <QVector>
#include <QVector2D>
#include <QVector3D>
#include <GL/glu.h>
#include <QDebug>

namespace {
bool    rainbow=true;           // Rainbow Mode?
bool    sp;             // Spacebar Pressed?
bool    rp;             // Return Key Pressed?

float   slowdown=2.0f;          // Slow Down Particles, 值越大，移动速度越慢
float   xspeed;             // Base X Speed (To Allow Keyboard Direction Of Tail)
float   yspeed;             // Base Y Speed (To Allow Keyboard Direction Of Tail)
float   zoom=-40.0f;            // Used To Zoom Out

GLuint  loop;               // Misc Loop Variable
GLuint  col = 0;                // Current Color Selection
GLuint  delay;              // Rainbow Effect Delay
GLuint  texture[1];         // Storage For Our Particle Texture

bool num8 = false; //Number 8键是否按下
bool num6 = false; //Number 6 is pressed
bool num2 = false; //Number 2 is pressed
bool num4 = false; //Number 4 is pressed
bool tab = false; //Table key is pressed
bool add = false; //Add key is pressed?
bool substract = false; //Substract key is pressed?
bool prior = false; //Prior Key is pressed?
bool next = false; //Next key is pressed?
bool enter = false; //Enter key is pressed?
bool up = false;//Up key
bool down = false; //Down key
bool left = false; //left key

//粒子属性定义
struct Particles
{
    bool    active;                 // Active (Yes/No)打开或关闭粒子
    float   life;                   // Particle Life
    float   fade;                   // Fade Speed
    //粒子颜色属性
    float   r;                  // Red Value
    float   g;                  // Green Value
    float   b;                  // Blue Value
    //粒子坐标
    float   x;                  // X Position
    float   y;                  // Y Position
    float   z;                  // Z Position
    //粒子移动方向
    float   xi;                 // X Direction
    float   yi;                 // Y Direction
    float   zi;                 // Z Direction
    //粒子重力属性
    float   xg;                 // X Gravity
    float   yg;                 // Y Gravity
    float   zg;                 // Z Gravity
};
const int MAX_PARTICLES = 1000;
Particles particle[MAX_PARTICLES];
static GLfloat colors[12][3]=               // Rainbow Of Colors
{
    {1.0f,0.5f,0.5f},{1.0f,0.75f,0.5f},{1.0f,1.0f,0.5f},{0.75f,1.0f,0.5f},
    {0.5f,1.0f,0.5f},{0.5f,1.0f,0.75f},{0.5f,1.0f,1.0f},{0.5f,0.75f,1.0f},
    {0.5f,0.5f,1.0f},{0.75f,0.5f,1.0f},{1.0f,0.5f,1.0f},{1.0f,0.5f,0.75f}
};
void drawParticle(float x, float y, float z)
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    QVector<QVector2D> texCoords;
    texCoords<<QVector2D(1, 1)
             <<QVector2D(0, 1)
             <<QVector2D(1, 0)
             <<QVector2D(0, 0);
    QVector<QVector3D> vertices;
    vertices<<QVector3D(x+0.5f,y+0.5f,z) //右上
            <<QVector3D(x-0.5f,y+0.5f,z) //左上
            <<QVector3D(x+0.5f,y-0.5f,z) //右下
            <<QVector3D(x-0.5f,y-0.5f,z); //左下
    glVertexPointer(3, GL_FLOAT, 0, vertices.constData());
    glTexCoordPointer(2, GL_FLOAT, 0, texCoords.constData());
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}
}

void MyGLWidget::loadTextures()
{
    texture[0] = bindTexture(QString(":/Particle.bmp"),
                             GL_TEXTURE_2D,
                             GL_RGBA,
                             QGLContext::DefaultBindOption);
    // Create Nearest Filtered Texture
    glBindTexture(GL_TEXTURE_2D, texture[0]);

}

MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(parent), fullscreen(false)
{
    setWindowTitle(tr("nehe----lesson19"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(10);
}

void MyGLWidget::initializeGL()
{
    loadTextures();
    glShadeModel(GL_SMOOTH);   // Enables Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);  // Black Background
    glClearDepth(1.0f);             // Depth Buffer Setup
    glDisable(GL_DEPTH_TEST);        // Disable Depth Testing
    glBlendFunc(GL_SRC_ALPHA,GL_ONE);
    glEnable(GL_BLEND);                         // Enable Blending

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations
    glHint(GL_POINT_SMOOTH_HINT,GL_NICEST);                 // Really Nice Point Smoothing
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping
    glBindTexture(GL_TEXTURE_2D,texture[0]);                // Select Our Texture

    for (loop=0;loop<MAX_PARTICLES;loop++)                   // Initialize All The Textures
    {
        particle[loop].active=true;                 // Make All The Particles Active
        particle[loop].life=1.0f;                   // Give All The Particles Full Life
        particle[loop].fade=float(rand()%100)/1000.0f+0.003f;       // Random Fade Speed
        particle[loop].r=colors[loop*(12/MAX_PARTICLES)][0];        // Select Red Rainbow Color
        particle[loop].g=colors[loop*(12/MAX_PARTICLES)][1];        // Select Red Rainbow Color
        particle[loop].b=colors[loop*(12/MAX_PARTICLES)][2];        // Select Red Rainbow Color
        particle[loop].xi=float((rand()%50)-26.0f)*10.0f;       // Random Speed On X Axis
        particle[loop].yi=float((rand()%50)-25.0f)*10.0f;       // Random Speed On Y Axis
        particle[loop].zi=float((rand()%50)-25.0f)*10.0f;       // Random Speed On Z Axis
        particle[loop].xg=0.0f;                     // Set Horizontal Pull To Zero
        particle[loop].yg=-0.8f;                    // Set Vertical Pull Downward
        particle[loop].zg=0.0f;                     // Set Pull On Z Axis To Zero
    }
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
    glLoadIdentity();       // Reset The Current Modelview Matrix
    glTranslatef(0, 0, -10);
    glBindTexture(GL_TEXTURE_2D,texture[0]);
    for (loop = 0; loop < MAX_PARTICLES; loop++) {
        if (particle[loop].active) {
            float x = particle[loop].x;
            float y = particle[loop].y;
            float z = particle[loop].z;
            glColor4f(particle[loop].r,particle[loop].g,particle[loop].b,particle[loop].life);
            drawParticle(x, y, z);

            particle[loop].x += particle[loop].xi/(slowdown*1000);    // Move On The X Axis By X Speed
            particle[loop].y += particle[loop].yi/(slowdown*1000);    // Move On The Y Axis By Y Speed
            particle[loop].z += particle[loop].zi/(slowdown*1000);    // Move On The Z Axis By Z Speed

            particle[loop].xi += particle[loop].xg;           // Take Pull On X Axis Into Account
            particle[loop].yi += particle[loop].yg;           // Take Pull On Y Axis Into Account
            particle[loop].zi += particle[loop].zg;           // Take Pull On Z Axis Into Account

            particle[loop].life-=particle[loop].fade;       // Reduce Particles Life By 'Fade'
            if (particle[loop].life < 0.0f) {
                particle[loop].life=1.0f;               // Give It New Life
                particle[loop].fade=float(rand()%100)/1000.0f+0.003f;   // Random Fade Value
                particle[loop].x=0.0f;                  // Center On X Axis
                particle[loop].y=0.0f;                  // Center On Y Axis
                particle[loop].z=0.0f;                  // Center On Z Axis
                particle[loop].xi=xspeed+float((rand()%60)-32.0f);  // X Axis Speed And Direction
                particle[loop].yi=yspeed+float((rand()%60)-30.0f);  // Y Axis Speed And Direction
                particle[loop].zi=float((rand()%60)-30.0f);     // Z Axis Speed And Direction
                particle[loop].r=colors[col][0];            // Select Red From Color Table
                particle[loop].g=colors[col][1];            // Select Green From Color Table
                particle[loop].b=colors[col][2];            // Select Blue From Color Table
            }
            if (num8 && (particle[loop].yg < 1.5f))
                particle[loop].yg += 0.01f;
            if (num2 && (particle[loop].yg > -1.5f))
                particle[loop].yg -= 0.01f;
            if (num6 && (particle[loop].xg < 1.5f))
                particle[loop].xg += 0.01f;
            if (num4 && (particle[loop].xg > -1.5f))
                particle[loop].xg -= 0.01f;
            if (tab) {
                particle[loop].x=0.0f;                  // Center On X Axis
                particle[loop].y=0.0f;                  // Center On Y Axis
                particle[loop].z=0.0f;                  // Center On Z Axis
                particle[loop].xi=float((rand()%50)-26.0f)*10.0f;   // Random Speed On X Axis
                particle[loop].yi=float((rand()%50)-25.0f)*10.0f;   // Random Speed On Y Axis
                particle[loop].zi=float((rand()%50)-25.0f)*10.0f;   // Random Speed On Z Axis
            }

        }
    }
    if (rainbow && delay > 25) {
        delay = 0;
        col++;
        if (col > 11)
            col = 0;
    }
    delay++;
}

void MyGLWidget::keyReleaseEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_Return:
        rp = false;
        break;
    case Qt::Key_Space:
        sp = false;
        break;
    case Qt::Key_8:
        num8 = false;
        break;
    case Qt::Key_2:
        num2 = false;
        break;
    case Qt::Key_6:
        num6 = false;
        break;
    case Qt::Key_4:
        num4 = false;
        break;
    case Qt::Key_Tab:
        tab = false;
        break;
    default:
        QWidget::keyReleaseEvent(e);
        break;
    }
}

void MyGLWidget::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_8:
        if (!num8)
            num8 = true;
        break;
    case Qt::Key_2:
        if (!num2)
            num2 = true;
        break;
    case Qt::Key_6:
        if (!num6)
            num6 = true;
        break;
    case Qt::Key_4:
        if (!num4)
            num4 = true;
        break;
    case Qt::Key_Tab:
        if (!tab)
            tab = true;
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
    case Qt::Key_Plus:
        if (slowdown > 1.0f)
            slowdown -= 0.01f;
        break;
    case Qt::Key_Minus:
        if (slowdown < 4.0f)
            slowdown += 0.01f;
        break;
    case Qt::Key_PageUp:
        zoom += 0.1f;
        break;
    case Qt::Key_PageDown:
        zoom -= 0.1f;
        break;
    case Qt::Key_Return:
        if (!rp) {
            rp = true;
            rainbow != rainbow;
        }
        break;
    case Qt::Key_Space:
        if (!sp) {
            rainbow = false;
            sp = true;
            delay = 0;
            col++;
            if (col > 11 )
                col = 0;
        }
        break;
    case Qt::UpArrow:
        if (yspeed < 200)
            yspeed += 1.0f;
        break;
    case Qt::DownArrow:
        if (yspeed > -200)
            yspeed -= 1.0f;
        break;
    case Qt::RightArrow:
        if (xspeed < 200)
            xspeed += 1.0f;
        break;
    case Qt::LeftArrow:
        if (xspeed > -200)
            xspeed -= 1.0f;
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
