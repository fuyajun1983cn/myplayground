#include "myglwidget.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>
#include <QApplication>
#include <QVector>
#include <QVector2D>
#include <QVector3D>
#include <QTime>
#include <QDebug>

#include <QGLWidget>
#include <phonon/AudioOutput>
#include <phonon/MediaObject>
#include <phonon/MediaSource>

#include <GL/glu.h>

namespace Music {
Phonon::MediaObject *complete;
Phonon::MediaObject *die;
Phonon::MediaObject *freeze;
Phonon::MediaObject *hglass;
Phonon::MediaObject *music;
Phonon::AudioOutput *completeOutput;
Phonon::AudioOutput *dieOutput;
Phonon::AudioOutput *freezeOutput;
Phonon::AudioOutput *hglassOutput;
Phonon::AudioOutput *musicOutput;
void init()
{
    completeOutput = new Phonon::AudioOutput(Phonon::GameCategory, 0);
    musicOutput = new Phonon::AudioOutput(Phonon::GameCategory, 0);
    dieOutput = new Phonon::AudioOutput(Phonon::GameCategory, 0);
    freezeOutput = new Phonon::AudioOutput(Phonon::GameCategory, 0);
    hglassOutput = new Phonon::AudioOutput(Phonon::GameCategory, 0);
    complete = new Phonon::MediaObject(0);
    die = new Phonon::MediaObject(0);
    freeze = new Phonon::MediaObject(0);
    hglass = new Phonon::MediaObject(0);
    music = new Phonon::MediaObject(0);
    Phonon::createPath(complete, completeOutput);
    Phonon::createPath(die, dieOutput);
    Phonon::createPath(freeze, freezeOutput);
    Phonon::createPath(hglass, hglassOutput);
    Phonon::createPath(music, musicOutput);
    QObject::connect(complete, SIGNAL(finished()), complete, SLOT(stop()));
    QObject::connect(die, SIGNAL(finished()), die, SLOT(stop()));
    QObject::connect(freeze, SIGNAL(finished()), freeze, SLOT(stop()));
    QObject::connect(hglass, SIGNAL(finished()), hglass, SLOT(stop()));
    complete->setCurrentSource(Phonon::MediaSource("Complete.wav"));
    die->setCurrentSource(Phonon::MediaSource("Die.wav"));
    freeze->setCurrentSource(Phonon::MediaSource("Freeze.wav"));
    hglass->setCurrentSource(Phonon::MediaSource("Hourglass.wav"));
    music->setCurrentSource(Phonon::MediaSource("lktheme.mod"));
}

void uinit()
{
    complete->stop();
    die->stop();
    freeze->stop();
    hglass->stop();
    music->stop();
}

}

namespace Font {
GLuint  texture[1];     // Storage For Our Font Texture

struct FyjBitmapChar
{
    QVector<QVector2D> texCoords;
    int right; //字符宽度
    int height;//字符高度
    int ascillValue;
};

struct FyjBitmapFont
{
    char *name;
    int quality;
    FyjBitmapChar *characters;
};

static FyjBitmapChar chars1[128];
static FyjBitmapChar chars2[128];

const FyjBitmapFont font1 = {"standard", 128, chars1};
const FyjBitmapFont font2 = {"Itatic", 128, chars2};

void buildFont()
{
    float   cx;                      // Holds Our X Character Coord
    float   cy;                     // Holds Our Y Character Coord

    for (int loop = 0; loop < 256; loop++) {
        cx = float(loop%16)/16.0f; //当前字符的x纹理坐标
        cy = float(loop/16)/16.0f; //当前字符的y纹理坐标
        if (loop < 128) {
            chars1[loop].texCoords<<QVector2D(cx, cy + 0.0625f)
                 <<QVector2D(cx+0.0625f, cy+0.0625f)
                 <<QVector2D(cx+0.0625f, cy)
                 <<QVector2D(cx, cy);
            chars1[loop].height = 16;
            chars1[loop].right = 10;
            chars1[loop].ascillValue = loop+32;
        } else {
            chars2[loop-128].texCoords<<QVector2D(cx, cy + 0.0625f)
                                     <<QVector2D(cx+0.0625f, cy+0.0625f)
                                     <<QVector2D(cx+0.0625f, cy)
                                     <<QVector2D(cx, cy);
            chars2[loop-128].height = 12;
            chars2[loop-128].right = 10;
            chars2[loop-128].ascillValue = loop-128+32;
       }
    }
}

void renderBitmapCharacter(FyjBitmapChar c, int fontSize)
{
    Q_ASSERT_X(c.ascillValue >= 32 && c.ascillValue <= 127,
               "renderBitmapCharacter", "unspported char");
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    QVector<QVector2D> vertices;
    vertices<<QVector2D(0, 0)
            <<QVector2D(fontSize, 0)
            <<QVector2D(fontSize, fontSize)
            <<QVector2D(0, fontSize);
    glVertexPointer(2, GL_FLOAT, 0, vertices.constData());
    glTexCoordPointer(2, GL_FLOAT, 0, c.texCoords.constData());
    glDrawArrays(GL_QUADS, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void renderBitmapString(GLint x, GLint y, QString string, int set, int fontSize)
{
    int numOfReturnChar = 0;
    if (string.isNull() || string.isEmpty())
        return;
    if (set > 1)
        set = 1;
    FyjBitmapFont currentFont;
    if (set == 0)
        currentFont = font1;
    else
        currentFont = font2;

    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glPushMatrix();
    glLoadIdentity();
    glTranslated(x, y, 0);
    for(int i = 0; i < string.length(); i++) {
        char c = string.at(i).toAscii();
        if (c == '\n') {
            numOfReturnChar++;
            glLoadIdentity();
            glTranslated(x, y - numOfReturnChar * currentFont.characters[0].height, 0);
            continue;
        }
        renderBitmapCharacter(currentFont.characters[c-32], fontSize);
        glTranslated(currentFont.characters[c-32].right * fontSize/16, 0, 0);
    }
    glPopMatrix();
}

void glPrint(GLint x, GLint y, int set, int fontSize, const char *fmt, ...)
{
    char   text[256];              // Holds Our String
    va_list     ap;                 // Pointer To List Of Arguments
    if (fmt == NULL)                    // If There's No Text
        return;                     // Do Nothing
    va_start(ap, fmt);                  // Parses The String For Variables
        vsprintf(text, fmt, ap);                // And Converts Symbols To Actual Numbers
    va_end(ap);                     // Results Are Stored In Text

    renderBitmapString(x, y, QString(text), set, fontSize);
}
}

namespace Game{
QTime       startTime ;
GLint       texture[1];
bool        vline[11][10];                  // Keeps Track Of Verticle Lines
bool        hline[10][11];                  // Keeps Track Of Horizontal Lines
bool        ap;                             // 'A' Key Pressed?
bool        filled;                         // Done Filling In The Grid?
bool        gameover;                       // Is The Game Over?
bool        anti = true;                      // Antialiasing?
bool        active = true;                         //电脑对手是否处于活跃状态

int     delay;                              // Enemy Delay
int     adjust = 4;                           // Speed Adjustment For Really Slow Video Cards
int     lives = 5;                            // Player Lives
int     level = 1;                            // Internal Game Level
int     level2 = level;                       // Displayed Game Level
int     stage = 1;                            // Game Stage

/**
  * 对于hourglass来说，x,y代表方格坐标，fx=1的时间显示hourglass，
  * fx = 2的时候，冻结电脑对手（不能移动）fy是计时器
  */
struct GameObject                           // Create A Structure For Our Player
{
    int fx, fy;                             // Fine Movement Position(在屏幕上的相对坐标)
    int x, y;                               // Current Player Position(在方格上的坐标)
    float   spin;                           // Spin Direction （旋转角度）
};

struct  GameObject  player;                 // Player Information
struct  GameObject  enemy[9];               // Enemy Information
struct  GameObject  hourglass;              // Hourglass Information

int     steps[6]={ 1, 2, 4, 5, 10, 20 };    // Stepping Values For Slow Video Adjustment

void resetGameObjects()
{
    player.x = 0;
    player.y = 0;
    player.fx = 0;
    player.fy = 0;

    for (int loop=0; loop < (stage*level); loop++)              // Loop Through All The Enemies
    {
        enemy[loop].x = 5+rand()%6;                  // Select A Random X Position
        enemy[loop].y = rand() % 11;                   // Select A Random Y Position
        enemy[loop].fx = enemy[loop].x*60;              // Set Fine X To Match
        enemy[loop].fy = enemy[loop].y*40;              // Set Fine Y To Match
    }

    hourglass.x = rand()%10+1;
    hourglass.y = rand()%11;
    hourglass.fx = 0;//
    hourglass.fy = 0;//计时器

    startTime = QTime::currentTime();
    startTime.start();
}

void drawGameObject(GLenum mode, QVector<QVector2D> vertices,  QVector<QVector2D> texCoords = QVector<QVector2D>())
{
    if (!vertices.isEmpty()) {
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(2, GL_FLOAT, 0, vertices.constData());
    }
    if (!texCoords.isEmpty()) {
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glTexCoordPointer(2, GL_FLOAT, 0, texCoords.constData());
    }
    glDrawArrays(mode, 0, vertices.size());
    if (!vertices.isEmpty()) {
        glDisableClientState(GL_VERTEX_ARRAY);
    }
    if (!texCoords.isEmpty()) {
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    }
}


}

void MyGLWidget::loadTextures()
{
    Font::texture[0] = bindTexture(QString(":/Font.bmp"),
                             GL_TEXTURE_2D,
                             GL_RGBA,
                             QGLContext::LinearFilteringBindOption);
    // Create Nearest Filtered Texture
    glBindTexture(GL_TEXTURE_2D, Font::texture[0]);
    Game::texture[0] = bindTexture(QString(":/Image.bmp"),
                             GL_TEXTURE_2D,
                             GL_RGBA,
                             QGLContext::DefaultBindOption);
    // Create Nearest Filtered Texture
    glBindTexture(GL_TEXTURE_2D, Game::texture[0]);
}

MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(parent), fullscreen(false)
{
    setWindowTitle(tr("nehe----lesson21"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(10);

    Music::init();
    Music::music->play();
    Game::resetGameObjects();
}

void MyGLWidget::initializeGL()
{
    loadTextures();
    glEnable(GL_TEXTURE_2D);
    Font::buildFont();
    glShadeModel(GL_SMOOTH);   // Enables Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);  // Black Background
    glClearDepth(1.0f);             // Depth Buffer Setup
    glEnable(GL_BLEND);                         // Enable Blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);          // Type Of Blending To Use
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST); // Really Nice Perspective Calculations
}

void MyGLWidget::resizeGL(int width, int height)
{
    if (height==0) {    // Prevent A Divide By Zero By
        height=1;    // Making Height Equal One
    }
    glViewport(0, 0, width, height);    // Reset The Current Viewport
    glMatrixMode(GL_PROJECTION);       // Select The Projection Matrix
    glLoadIdentity();                  // Reset The Projection Matrix

    glOrtho(0.0f,width,0,height,-1.0f,1.0f);

    glMatrixMode(GL_MODELVIEW);      // Select The Modelview Matrix
    glLoadIdentity();                // Reset The Modelview Matrix

}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clear The Screen And The Depth Buffer
    glLoadIdentity();       // Reset The Current Modelview Matrix
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, Font::texture[0]);
    glColor3f(1.0f,0.5f,1.0f);
    Font::glPrint(207,428,0, 36, "GRID CRAZY");
    glColor3f(1.0f,1.0f,0.0f);                      // Set Color To Yellow
    Font::glPrint(20,450,1,16,"Level:%2i",Game::level2);            // Write Actual Level Stats
    Font::glPrint(20,430,1,16,"Stage:%2i",Game::stage);            // Write Stage Stats
    if (Game::gameover)                               // Is The Game Over?
    {
        glColor3ub(rand()%255,rand()%255,rand()%255);   // Pick A Random Color
        Font::glPrint(472,450,1,16, "GAME OVER");                  // Write GAME OVER To The Screen
        Font::glPrint(456,430,1, 16, "PRESS SPACE");                // Write PRESS SPACE To The Screen
    }

    glDisable(GL_TEXTURE_2D);

    for (int loop1=0; loop1<Game::lives-1; loop1++)                    // Loop Through Lives Minus Current Life
    {
        glLoadIdentity();                       // Reset The View
        glTranslatef(490+(loop1*40.0f),450.0f,0.0f);         // Move To The Right Of Our Title Text
        glRotatef(-Game::player.spin,0.0f,0.0f,1.0f);             // Rotate Counter Clockwise
        glColor3f(0.0f,1.0f,0.0f);                  // Set Player Color To Light Green

        QVector<QVector2D> points;
        points<<QVector2D(-5,-5)
              <<QVector2D( 5, 5)
              <<QVector2D( 5, -5)
              <<QVector2D(-5, 5);
        Game::drawGameObject(GL_LINES, points);
        glRotatef(-Game::player.spin*0.5f,0.0f,0.0f,1.0f);            // Rotate Counter Clockwise
        glColor3f(0.0f,0.75f,0.0f);                 // Set Player Color To Dark Green
        points.clear();
        points<<QVector2D(-7, 0)
              <<QVector2D( 7, 0)
              <<QVector2D( 0, -7)
              <<QVector2D( 0, 7);
        Game::drawGameObject(GL_LINES, points);
    }

    Game::filled = true;              // Set Filled To True Before Testing
    glLineWidth(2.0f);              // Set Line Width For Cells To 2.0f
    glDisable(GL_LINE_SMOOTH);  	// Disable Antialiasing
    glLoadIdentity();               // Reset The Current Modelview Matrix

    for (int loop1 = 0; loop1 < 11; loop1++)					// Loop From Left To Right
    {
        for (int loop2 = 0; loop2 < 11; loop2++)				// Loop From Top To Bottom
        {
            glColor3f(0.0f,0.5f,1.0f);				// Set Line Color To Blue
            if (Game::hline[loop1][loop2])				// Has The Horizontal Line Been Traced
            {
                glColor3f(1.0f,1.0f,1.0f);			// If So, Set Line Color To White
            }
            if (loop1 < 10)						// Dont Draw To Far Right
            {
                if (!Game::hline[loop1][loop2])			// If A Horizontal Line Isn't Filled
                {
                    Game::filled = false;				// filled Becomes False
                }
                QVector<QVector2D> points;
                points<<QVector2D(20+(loop1*60),25+(loop2*40))// Left Side Of Horizontal Line
                      <<QVector2D(80+(loop1*60),25+(loop2*40));// Right Side Of Horizontal Line
                Game::drawGameObject(GL_LINES, points);
            }
            glColor3f(0.0f,0.5f,1.0f);				// Set Line Color To Blue
            if (Game::vline[loop1][loop2])				// Has The Horizontal Line Been Traced
            {
                glColor3f(1.0f,1.0f,1.0f);			// If So, Set Line Color To White
            }
            if (loop2 < 10)						// Dont Draw To Far Down
            {
                if (!Game::vline[loop1][loop2])			// If A Verticle Line Isn't Filled
                {
                    Game::filled=false;				// filled Becomes False
                }
                QVector<QVector2D> points;
                points<<QVector2D(20+(loop1*60),25+(loop2*40))// Left Side Of Horizontal Line
                      <<QVector2D(20+(loop1*60),65+(loop2*40));// Right Side Of Horizontal Line
                Game::drawGameObject(GL_LINES, points);
            }

            glEnable(GL_TEXTURE_2D);                // Enable Texture Mapping
            glColor3f(1.0f,1.0f,1.0f);              // Bright White Color
            glBindTexture(GL_TEXTURE_2D, Game::texture[0]);       // Select The Tile Image
            if ((loop1 < 10) && (loop2 < 10))             // If In Bounds, Fill In Traced Boxes
            {
                // Are All Sides Of The Box Traced?
                if (Game::hline[loop1][loop2] && Game::hline[loop1][loop2+1] && Game::vline[loop1][loop2] && Game::vline[loop1+1][loop2])
                {
                    QVector<QVector2D> points;
                    QVector<QVector2D> texCoords;
                    texCoords<<QVector2D(float(loop1/10.0f)+0.1f,1.0f-(float(loop2/10.0f)))
                          <<QVector2D(float(loop1/10.0f),1.0f-(float(loop2/10.0f)))
                          <<QVector2D(float(loop1/10.0f),1.0f-(float(loop2/10.0f)+0.1f))
                          <<QVector2D(float(loop1/10.0f)+0.1f,1.0f-(float(loop2/10.0f)+0.1f));
                    points<<QVector2D(20+(loop1*60)+59,(25+loop2*40+1))
                          <<QVector2D(20+(loop1*60)+1,(25+loop2*40+1))
                          <<QVector2D(20+(loop1*60)+1,(25+loop2*40)+39)
                          <<QVector2D(20+(loop1*60)+59,(25+loop2*40)+39);
                    Game::drawGameObject(GL_QUADS, points, texCoords);
                }
            }
            glDisable(GL_TEXTURE_2D);               // Disable Texture Mapping
        }
    }
    glLineWidth(1.0f);                          // Set The Line Width To 1.0f

    if (Game::anti)                               // Is Anti TRUE?
    {
        glEnable(GL_LINE_SMOOTH);                   // If So, Enable Antialiasing
    }

    if (Game::hourglass.fx == 1)                            // If fx=1 Draw The Hourglass
    {
        glLoadIdentity();                       // Reset The Modelview Matrix
        glTranslatef(20.0f+(Game::hourglass.x*60),25.0f+(Game::hourglass.y*40),0.0f);   // Move To The Fine Hourglass Position
        glRotatef(Game::hourglass.spin,0.0f,0.0f,1.0f);           // Rotate Clockwise
        glColor3ub(rand()%255,rand()%255,rand()%255);           // Set Hourglass Color To Random Color
        QVector<QVector2D> points;

        points<<QVector2D(-5,-5)                  // Top Left Of Hourglass
              <<QVector2D( 5, 5)                  // Bottom Right Of Hourglass
              <<QVector2D( 5,-5)                  // Top Right Of Hourglass
              <<QVector2D(-5, 5)                  // Bottom Left Of Hourglass
              <<QVector2D(-5, 5)                  // Bottom Left Of Hourglass
              <<QVector2D( 5, 5)                  // Bottom Right Of Hourglass
              <<QVector2D(-5,-5)                  // Top Left Of Hourglass
              <<QVector2D( 5,-5);                  // Top Right Of Hourglass
        Game::drawGameObject(GL_LINES, points);

    }
    //draw player
    Game::player.spin += 0.5 * Game::steps[Game::adjust];
    if (Game::player.spin > 360)
        Game::player.spin -= 360;
    glLoadIdentity();                           // Reset The Modelview Matrix
    glTranslatef(Game::player.fx+20.0f, Game::player.fy + 25.0f,0.0f);         // Move To The Fine Player Position
    glRotatef(Game::player.spin,0.0f,0.0f,1.0f);                  // Rotate Clockwise
    glColor3f(0.0f,1.0f,0.0f);                      // Set Player Color To Light Green
    QVector<QVector2D> points;                         // Start Drawing Our Player Using Lines
    points<<QVector2D(-5,-5)                      // Top Left Of Player
          <<QVector2D( 5, 5)                      // Bottom Right Of Player
          <<QVector2D( 5,-5)                      // Top Right Of Player
          <<QVector2D(-5, 5);                      // Bottom Left Of Player
    Game::drawGameObject(GL_LINES, points);                              // Done Drawing The Player
    glRotatef(Game::player.spin*0.5f,0.0f,0.0f,1.0f);             // Rotate Clockwise
    glColor3f(0.0f,0.75f,0.0f);                     // Set Player Color To Dark Green
    points.clear();                          // Start Drawing Our Player Using Lines
    points<<QVector2D(-7, 0)                      // Left Center Of Player
          <<QVector2D( 7, 0)                      // Right Center Of Player
          <<QVector2D( 0,-7)                      // Top Center Of Player
          <<QVector2D( 0, 7);                      // Bottom Center Of Player
    Game::drawGameObject(GL_LINES, points);                                // Done Drawing The Player

    //绘制电脑对手
    for (int loop1=0; loop1 < (Game::stage*Game::level); loop1++)              // Loop To Draw Enemies
    {
        glLoadIdentity();                       // Reset The Modelview Matrix
        glTranslatef(Game::enemy[loop1].fx+20.0f, Game::enemy[loop1].fy+25.0f,0.0f);
        glColor3f(1.0f,0.5f,0.5f);                  // Make Enemy Body Pink
        QVector<QVector2D> points;                      // Start Drawing Enemy
        points<<QVector2D( 0,-7)                  // Top Point Of Body
              <<QVector2D(-7, 0)                  // Left Point Of Body
              <<QVector2D(-7, 0)                  // Left Point Of Body
              <<QVector2D( 0, 7)                  // Bottom Point Of Body
              <<QVector2D( 0, 7)                  // Bottom Point Of Body
              <<QVector2D( 7, 0)                  // Right Point Of Body
              <<QVector2D( 7, 0)                  // Right Point Of Body
              <<QVector2D( 0,-7);                 // Top Point Of Body
        Game::drawGameObject(GL_LINES, points) ;                           // Done Drawing Enemy Body
        glRotatef(Game::enemy[loop1].spin,0.0f,0.0f,1.0f);            // Rotate The Enemy Blade
        glColor3f(1.0f,0.0f,0.0f);                  // Make Enemy Blade Red
        points.clear();                      // Start Drawing Enemy Blade
        points<<QVector2D(-7,-7)                  // Top Left Of Enemy
              <<QVector2D( 7, 7)                  // Bottom Right Of Enemy
              <<QVector2D(-7, 7)                  // Bottom Left Of Enemy
              <<QVector2D( 7,-7);                  // Top Right Of Enemy
        Game::drawGameObject(GL_LINES, points);                            // Done Drawing Enemy Blade
    }

    if (Game::startTime.elapsed() < Game::steps[Game::adjust] * 2.0f) {
        Game::active = false;
    } else {
        Game::startTime.restart();
        Game::active = true;
    }
    if (!Game::gameover && Game::active) {

        for (int loop1=0; loop1 < (Game::stage*Game::level); loop1++) {
            //电脑对手在player的左边
            if (Game::enemy[loop1].x < Game::player.x &&
                Game::enemy[loop1].fy == Game::enemy[loop1].y * 40) {
                Game::enemy[loop1].x++;
            }
            //电脑对手在player的右边
            if (Game::enemy[loop1].x > Game::player.x &&
                Game::enemy[loop1].fy == Game::enemy[loop1].y * 40) {
                Game::enemy[loop1].x--;
            }
            //电脑对手在player下方
            if (Game::enemy[loop1].y < Game::player.y &&
                Game::enemy[loop1].fx == Game::enemy[loop1].x * 60) {
                Game::enemy[loop1].y++;
            }
            //电脑对手在player上方
            if (Game::enemy[loop1].y > Game::player.y &&
                Game::enemy[loop1].fx == Game::enemy[loop1].x * 60) {
                Game::enemy[loop1].y--;
            }

            if (Game::delay > (3 - Game::level) && (Game::hourglass.fx != 2)) {
                Game::delay = 0;
                //遍历所有的电脑对手，调整其fx, fy的值
                for (int loop2 = 0; loop2 < (Game::stage * Game::level); loop2++) {
                    if (Game::enemy[loop2].fx < Game::enemy[loop2].x * 60) {
                        Game::enemy[loop2].fx += Game::steps[Game::adjust];
                        Game::enemy[loop2].spin += Game::steps[Game::adjust];
                    }
                    if (Game::enemy[loop2].fx > Game::enemy[loop2].x * 60) {
                        Game::enemy[loop2].fx -= Game::steps[Game::adjust];
                        Game::enemy[loop2].spin -= Game::steps[Game::adjust];
                    }
                    if (Game::enemy[loop2].fy < Game::enemy[loop2].y * 40) {
                        Game::enemy[loop2].fy += Game::steps[Game::adjust];
                        Game::enemy[loop2].spin += Game::steps[Game::adjust];
                    }
                    if (Game::enemy[loop2].fy > Game::enemy[loop2].y * 40) {
                        Game::enemy[loop2].fy -= Game::steps[Game::adjust];
                        Game::enemy[loop2].spin += Game::steps[Game::adjust];
                    }
                }
            }
            //电脑对手与player的位置重叠？
            if (Game::enemy[loop1].fx == Game::player.fx &&
                Game::enemy[loop1].fy == Game::player.fy) {
                Game::lives--;
                if (Game::lives == 0)
                    Game::gameover = true;
                Game::resetGameObjects();
                Music::die->play();
            }
        }
        //移动player位置
        if (Game::player.fx < Game::player.x * 60)
            Game::player.fx += Game::steps[Game::adjust];
        if (Game::player.fx > Game::player.x * 60)
            Game::player.fx -= Game::steps[Game::adjust];
        if (Game::player.fy < Game::player.y * 40)
            Game::player.fy += Game::steps[Game::adjust];
        if (Game::player.fy > Game::player.y * 40)
            Game::player.fy -= Game::steps[Game::adjust];
    } else {
        //过关了
        if (Game::filled) {
            Music::complete->play();
            Game::stage++;
            if (Game::stage > 3) {
                Game::stage = 1;
                Game::level++;
                Game::level2++;
                if (Game::level > 3) {
                    Game::level = 3;
                    Game::lives++;
                    if (Game::lives > 5)
                        Game::lives = 5;
                }
            }
            Game::resetGameObjects();
            //清屏
            for (int loop1 = 0; loop1 < 11; loop1++) {
                for (int loop2 = 0; loop2 < 11; loop2++) {
                    if (loop1 < 10)
                        Game::hline[loop1][loop2] = false;
                    if (loop2 < 10)
                        Game::vline[loop1][loop2] = false;
                }
            }
        }
        Game::hourglass.spin -= 0.25 * Game::steps[Game::adjust];
        if (Game::hourglass.spin < 0)
            Game::hourglass.spin += 360;
        Game::hourglass.fy += Game::steps[Game::adjust];
        if (Game::hourglass.fx == 0 && Game::hourglass.fy > 6000/Game::level) {
            Music::hglass->play();
            Game::hourglass.x = rand()%10+1;
            Game::hourglass.y = rand()%11;
            Game::hourglass.fx = 1;
            Game::hourglass.fy = 0;
        }
        if (Game::hourglass.fx == 1) {
            //消失
            if (Game::hourglass.fy > 6000 / Game::level) {
                Game::hourglass.fx = 0;
                Game::hourglass.fy = 0;
            }
            //player与hourglass位置是否重合
            if (Game::hourglass.x * 60 == Game::player.fx
                && Game::hourglass.y * 40 == Game::player.fy) {
                Music::freeze->play();
                Game::hourglass.fx = 2;
                Game::hourglass.fy = 0;
            }
        }
        //freeze the enemy
        if (Game::hourglass.fx == 2
                && Game::hourglass.fy > (500 + 500 * Game::level)) {
            Game::hourglass.fx = 0;
            Game::hourglass.fy = 0;
        }
        Game::delay++;
    }
}

void MyGLWidget::keyReleaseEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_A:
        Game::ap = false;
        break;
    }
    QWidget::keyReleaseEvent(e);
}

void MyGLWidget::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_Right:
        if (Game::player.x < 10 &&
            Game::player.fx == Game::player.x * 60 &&
            Game::player.fy == Game::player.y * 40) {

            Game::hline[Game::player.x][Game::player.y] = true;
            Game::player.x++;

        }
        break;
    case Qt::Key_Left:
        if (Game::player.x > 0 &&
            Game::player.fx == Game::player.x * 60 &&
            Game::player.fy == Game::player.y * 40) {

            Game::player.x--;
            Game::hline[Game::player.x][Game::player.y] = true;

        }
        break;
    case Qt::Key_Down:
        if (Game::player.y > 0 &&
            Game::player.fx == Game::player.x * 60 &&
            Game::player.fy == Game::player.y * 40) {

            Game::player.y--;
            Game::vline[Game::player.x][Game::player.y] = true;

        }
        break;
    case Qt::Key_Up:
        if (Game::player.y < 10 &&
            Game::player.fx == Game::player.x * 60 &&
            Game::player.fy == Game::player.y * 40) {

            Game::vline[Game::player.x][Game::player.y] = true;
            Game::player.y++;

        }
        break;
    case Qt::Key_A:
        if (!Game::ap) {
            Game::ap = true;
            Game::anti = !Game::anti;
        }
        break;
    case Qt::Key_Space:
        if (Game::gameover) {
            Game::gameover = false;
            Game::filled = false;
            Game::level = 1;
            Game::level2 = 1;
            Game::stage = 1;
            Game::lives = 5;
            Game::resetGameObjects();
            //清屏
            for (int loop1 = 0; loop1 < 11; loop1++) {
                for (int loop2 = 0; loop2 < 11; loop2++) {
                    if (loop1 < 10)
                        Game::hline[loop1][loop2] = false;
                    if (loop2 < 10)
                        Game::vline[loop1][loop2] = false;
                }
            }
        }
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
