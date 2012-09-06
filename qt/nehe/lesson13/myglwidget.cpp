#include "myglwidget.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>
#include <QApplication>
#include <QDebug>
#include <GL/glu.h>

#include <math.h>

namespace {

#define USE_DISPLAY_LIST //使用显示列表

struct FyjFont
{
    char *name;     //字体名称
    int quality;    //字体中的字符数量
    int height;     //字符高度
    const GLubyte **characters;  //字符表
    float xorig, yorig;  //字符的原点
};

//字体字符位图描述定义
static const GLubyte Character_000[] = {  8,  0,  0,  0,  0,170,  0,130,  0,130,  0,170,  0,  0,  0};
static const GLubyte Character_001[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_002[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_003[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_004[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_005[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_006[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_007[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_008[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_009[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_010[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_011[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_012[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_013[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_014[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_015[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_016[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_017[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_018[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_019[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_020[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_021[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_022[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_023[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_024[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_025[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_026[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_027[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_028[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_029[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_030[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_031[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_032[] = {  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_033[] = {  3,  0,  0,  0,  0, 64,  0, 64, 64, 64, 64, 64,  0,  0,  0};
static const GLubyte Character_034[] = {  4,  0,  0,  0,  0,  0,  0,  0,  0,  0,160,160,  0,  0,  0};
static const GLubyte Character_035[] = {  5,  0,  0,  0,  0, 80, 80,248, 80,248, 80, 80,  0,  0,  0};
static const GLubyte Character_036[] = {  5,  0,  0,  0, 32,224,144, 16, 96,128,144,112, 32,  0,  0};
static const GLubyte Character_037[] = {  8,  0,  0,  0,  0, 68, 42, 42, 86,168,164,126,  0,  0,  0};
static const GLubyte Character_038[] = {  8,  0,  0,  0,  0,118,141,152,116,110, 80, 48,  0,  0,  0};
static const GLubyte Character_039[] = {  3,  0,  0,  0,  0,  0,  0,  0,  0,  0, 64,192,  0,  0,  0};
static const GLubyte Character_040[] = {  4,  0,  0, 32, 64, 64,128,128,128, 64, 64, 32,  0,  0,  0};
static const GLubyte Character_041[] = {  4,  0,  0,128, 64, 64, 32, 32, 32, 64, 64,128,  0,  0,  0};
static const GLubyte Character_042[] = {  5,  0,  0,  0,  0,  0,  0,  0,  0,160, 64,160,  0,  0,  0};
static const GLubyte Character_043[] = {  6,  0,  0,  0,  0, 32, 32,248, 32, 32,  0,  0,  0,  0,  0};
static const GLubyte Character_044[] = {  3,  0,  0, 64, 64, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_045[] = {  7,  0,  0,  0,  0,  0,  0,120,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_046[] = {  3,  0,  0,  0,  0, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_047[] = {  3,  0,  0,  0,  0,128,128, 64, 64, 64, 32, 32,  0,  0,  0};
static const GLubyte Character_048[] = {  5,  0,  0,  0,  0, 96,144,144,144,144,144, 96,  0,  0,  0};
static const GLubyte Character_049[] = {  5,  0,  0,  0,  0,112, 32, 32, 32, 32, 96, 32,  0,  0,  0};
static const GLubyte Character_050[] = {  5,  0,  0,  0,  0,240, 64, 32, 32, 16,144, 96,  0,  0,  0};
static const GLubyte Character_051[] = {  5,  0,  0,  0,  0,224, 16, 16, 96, 16,144, 96,  0,  0,  0};
static const GLubyte Character_052[] = {  5,  0,  0,  0,  0, 16, 16,248,144, 80, 48, 16,  0,  0,  0};
static const GLubyte Character_053[] = {  5,  0,  0,  0,  0,224,144, 16, 16,224, 64,112,  0,  0,  0};
static const GLubyte Character_054[] = {  5,  0,  0,  0,  0, 96,144,144,144,224, 64, 48,  0,  0,  0};
static const GLubyte Character_055[] = {  5,  0,  0,  0,  0, 64, 64, 64, 32, 32,144,240,  0,  0,  0};
static const GLubyte Character_056[] = {  5,  0,  0,  0,  0, 96,144,144, 96,144,144, 96,  0,  0,  0};
static const GLubyte Character_057[] = {  5,  0,  0,  0,  0,192, 32,112,144,144,144, 96,  0,  0,  0};
static const GLubyte Character_058[] = {  3,  0,  0,  0,  0, 64,  0,  0,  0, 64,  0,  0,  0,  0,  0};
static const GLubyte Character_059[] = {  3,  0,  0, 64, 64, 64,  0,  0,  0, 64,  0,  0,  0,  0,  0};
static const GLubyte Character_060[] = {  5,  0,  0,  0,  0, 16, 32, 64, 32, 16,  0,  0,  0,  0,  0};
static const GLubyte Character_061[] = {  6,  0,  0,  0,  0,  0,248,  0,248,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_062[] = {  5,  0,  0,  0,  0,128, 64, 32, 64,128,  0,  0,  0,  0,  0};
static const GLubyte Character_063[] = {  4,  0,  0,  0,  0, 64,  0, 64, 64, 32,160,224,  0,  0,  0};
static const GLubyte Character_064[] = {  9,  0,  0,  0,  0, 62,  0, 64,  0,146,  0,173,  0,165,  0,165,  0,157,  0, 66,  0, 60,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_065[] = {  8,  0,  0,  0,  0,238, 68,124, 40, 40, 56, 16,  0,  0,  0};
static const GLubyte Character_066[] = {  6,  0,  0,  0,  0,240, 72, 72,112, 72, 72,240,  0,  0,  0};
static const GLubyte Character_067[] = {  7,  0,  0,  0,  0,120,196,128,128,128,196,124,  0,  0,  0};
static const GLubyte Character_068[] = {  7,  0,  0,  0,  0,248, 76, 68, 68, 68, 76,248,  0,  0,  0};
static const GLubyte Character_069[] = {  6,  0,  0,  0,  0,248, 72, 64,112, 64, 72,248,  0,  0,  0};
static const GLubyte Character_070[] = {  6,  0,  0,  0,  0,224, 64, 64,112, 64, 72,248,  0,  0,  0};
static const GLubyte Character_071[] = {  7,  0,  0,  0,  0,120,196,132,156,128,196,124,  0,  0,  0};
static const GLubyte Character_072[] = {  8,  0,  0,  0,  0,238, 68, 68,124, 68, 68,238,  0,  0,  0};
static const GLubyte Character_073[] = {  4,  0,  0,  0,  0,224, 64, 64, 64, 64, 64,224,  0,  0,  0};
static const GLubyte Character_074[] = {  4,  0,  0,  0,  0,192,160, 32, 32, 32, 32,112,  0,  0,  0};
static const GLubyte Character_075[] = {  7,  0,  0,  0,  0,236, 72, 80, 96, 80, 72,236,  0,  0,  0};
static const GLubyte Character_076[] = {  6,  0,  0,  0,  0,248, 72, 64, 64, 64, 64,224,  0,  0,  0};
static const GLubyte Character_077[] = { 10,  0,  0,  0,  0,  0,  0,  0,  0,235,128, 73,  0, 85,  0, 85,  0, 99,  0, 99,  0,227,128,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_078[] = {  8,  0,  0,  0,  0,228, 76, 76, 84, 84,100,238,  0,  0,  0};
static const GLubyte Character_079[] = {  7,  0,  0,  0,  0,120,204,132,132,132,204,120,  0,  0,  0};
static const GLubyte Character_080[] = {  6,  0,  0,  0,  0,224, 64, 64,112, 72, 72,240,  0,  0,  0};
static const GLubyte Character_081[] = {  7,  0,  0, 12, 24,112,204,132,132,132,204,120,  0,  0,  0};
static const GLubyte Character_082[] = {  7,  0,  0,  0,  0,236, 72, 80,112, 72, 72,240,  0,  0,  0};
static const GLubyte Character_083[] = {  5,  0,  0,  0,  0,224,144, 16, 96,192,144,112,  0,  0,  0};
static const GLubyte Character_084[] = {  6,  0,  0,  0,  0,112, 32, 32, 32, 32,168,248,  0,  0,  0};
static const GLubyte Character_085[] = {  8,  0,  0,  0,  0, 56,108, 68, 68, 68, 68,238,  0,  0,  0};
static const GLubyte Character_086[] = {  8,  0,  0,  0,  0, 16, 16, 40, 40,108, 68,238,  0,  0,  0};
static const GLubyte Character_087[] = { 10,  0,  0,  0,  0,  0,  0,  0,  0, 34,  0, 34,  0, 85,  0, 85,  0,201,128,136,128,221,192,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_088[] = {  8,  0,  0,  0,  0,238, 68, 40, 16, 40, 68,238,  0,  0,  0};
static const GLubyte Character_089[] = {  8,  0,  0,  0,  0, 56, 16, 16, 40, 40, 68,238,  0,  0,  0};
static const GLubyte Character_090[] = {  6,  0,  0,  0,  0,248,136, 64, 32, 16,136,248,  0,  0,  0};
static const GLubyte Character_091[] = {  3,  0,  0,192,128,128,128,128,128,128,128,192,  0,  0,  0};
static const GLubyte Character_092[] = {  3,  0,  0,  0,  0, 32, 32, 64, 64, 64,128,128,  0,  0,  0};
static const GLubyte Character_093[] = {  3,  0,  0,192, 64, 64, 64, 64, 64, 64, 64,192,  0,  0,  0};
static const GLubyte Character_094[] = {  5,  0,  0,  0,  0,  0,  0,  0,  0, 80, 80, 32,  0,  0,  0};
static const GLubyte Character_095[] = {  5,  0,248,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_096[] = {  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,128,  0,  0};
static const GLubyte Character_097[] = {  4,  0,  0,  0,  0,224,160, 96, 32,192,  0,  0,  0,  0,  0};
static const GLubyte Character_098[] = {  5,  0,  0,  0,  0,224,144,144,144,224,128,128,  0,  0,  0};
static const GLubyte Character_099[] = {  4,  0,  0,  0,  0, 96,128,128,128, 96,  0,  0,  0,  0,  0};
static const GLubyte Character_100[] = {  5,  0,  0,  0,  0,104,144,144,144,112, 16, 48,  0,  0,  0};
static const GLubyte Character_101[] = {  4,  0,  0,  0,  0, 96,128,192,160, 96,  0,  0,  0,  0,  0};
static const GLubyte Character_102[] = {  4,  0,  0,  0,  0,224, 64, 64, 64,224, 64, 48,  0,  0,  0};
static const GLubyte Character_103[] = {  5,  0,  0,224,144, 96, 64,160,160,112,  0,  0,  0,  0,  0};
static const GLubyte Character_104[] = {  5,  0,  0,  0,  0,216,144,144,144,224,128,128,  0,  0,  0};
static const GLubyte Character_105[] = {  3,  0,  0,  0,  0, 64, 64, 64, 64,192,  0, 64,  0,  0,  0};
static const GLubyte Character_106[] = {  3,  0,  0,128, 64, 64, 64, 64, 64,192,  0, 64,  0,  0,  0};
static const GLubyte Character_107[] = {  5,  0,  0,  0,  0,152,144,224,160,144,128,128,  0,  0,  0};
static const GLubyte Character_108[] = {  4,  0,  0,  0,  0,224, 64, 64, 64, 64, 64,192,  0,  0,  0};
static const GLubyte Character_109[] = {  8,  0,  0,  0,  0,219,146,146,146,236,  0,  0,  0,  0,  0};
static const GLubyte Character_110[] = {  5,  0,  0,  0,  0,216,144,144,144,224,  0,  0,  0,  0,  0};
static const GLubyte Character_111[] = {  5,  0,  0,  0,  0, 96,144,144,144, 96,  0,  0,  0,  0,  0};
static const GLubyte Character_112[] = {  5,  0,  0,192,128,224,144,144,144,224,  0,  0,  0,  0,  0};
static const GLubyte Character_113[] = {  5,  0,  0, 56, 16,112,144,144,144,112,  0,  0,  0,  0,  0};
static const GLubyte Character_114[] = {  4,  0,  0,  0,  0,224, 64, 64, 96,160,  0,  0,  0,  0,  0};
static const GLubyte Character_115[] = {  4,  0,  0,  0,  0,224, 32, 96,128,224,  0,  0,  0,  0,  0};
static const GLubyte Character_116[] = {  4,  0,  0,  0,  0, 48, 64, 64, 64,224, 64,  0,  0,  0,  0};
static const GLubyte Character_117[] = {  5,  0,  0,  0,  0,104,144,144,144,144,  0,  0,  0,  0,  0};
static const GLubyte Character_118[] = {  5,  0,  0,  0,  0, 32, 96, 80,144,216,  0,  0,  0,  0,  0};
static const GLubyte Character_119[] = {  8,  0,  0,  0,  0, 40,108, 84,146,219,  0,  0,  0,  0,  0};
static const GLubyte Character_120[] = {  6,  0,  0,  0,  0,216, 80, 32, 80,216,  0,  0,  0,  0,  0};
static const GLubyte Character_121[] = {  5,  0,  0,128,128, 64, 96,160,144,184,  0,  0,  0,  0,  0};
static const GLubyte Character_122[] = {  5,  0,  0,  0,  0,240,144, 64, 32,240,  0,  0,  0,  0,  0};
static const GLubyte Character_123[] = {  4,  0,  0, 32, 64, 64, 64,128, 64, 64, 64, 32,  0,  0,  0};
static const GLubyte Character_124[] = {  2,  0,  0,128,128,128,128,128,128,128,128,128,  0,  0,  0};
static const GLubyte Character_125[] = {  4,  0,  0,128, 64, 64, 64, 32, 64, 64, 64,128,  0,  0,  0};
static const GLubyte Character_126[] = {  7,  0,  0,  0,  0,  0,  0,152,100,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_127[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_128[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_129[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_130[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_131[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_132[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_133[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_134[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_135[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_136[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_137[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_138[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_139[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_140[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_141[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_142[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_143[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_144[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_145[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_146[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_147[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_148[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_149[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_150[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_151[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_152[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_153[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_154[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_155[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_156[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_157[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_158[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_159[] = { 13,  0,  0,  0,  0,  0,  0,  0,  0,170,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,170,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_160[] = {  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_161[] = {  3,  0,  0, 64, 64, 64, 64, 64,  0, 64,  0,  0,  0,  0,  0};
static const GLubyte Character_162[] = {  5,  0,  0,  0,128,224,144,128,144,112, 16,  0,  0,  0,  0};
static const GLubyte Character_163[] = {  5,  0,  0,  0,  0,240,200, 64,224, 64, 80, 48,  0,  0,  0};
static const GLubyte Character_164[] = {  5,  0,  0,  0,  0,  0,136,112, 80, 80,112,136,  0,  0,  0};
static const GLubyte Character_165[] = {  5,  0,  0,  0,  0,112, 32,248, 32,216, 80,136,  0,  0,  0};
static const GLubyte Character_166[] = {  2,  0,  0,  0,  0,128,128,128,  0,128,128,128,  0,  0,  0};
static const GLubyte Character_167[] = {  5,  0,  0,  0,224,144, 32, 80,144,160, 64,144,112,  0,  0};
static const GLubyte Character_168[] = {  5,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 80,  0,  0,  0};
static const GLubyte Character_169[] = {  9,  0,  0,  0,  0,  0,  0,  0,  0, 28,  0, 34,  0, 77,  0, 81,  0, 77,  0, 34,  0, 28,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_170[] = {  4,  0,  0,  0,  0,  0,  0,224,  0,160, 32,192,  0,  0,  0};
static const GLubyte Character_171[] = {  5,  0,  0,  0,  0,  0, 80,160,160, 80,  0,  0,  0,  0,  0};
static const GLubyte Character_172[] = {  7,  0,  0,  0,  0,  0,  4,  4,124,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_173[] = {  4,  0,  0,  0,  0,  0,  0,224,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_174[] = {  9,  0,  0,  0,  0,  0,  0,  0,  0, 28,  0, 34,  0, 85,  0, 89,  0, 93,  0, 34,  0, 28,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_175[] = {  4,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,224,  0,  0,  0};
static const GLubyte Character_176[] = {  4,  0,  0,  0,  0,  0,  0,  0, 96,144,144, 96,  0,  0,  0};
static const GLubyte Character_177[] = {  6,  0,  0,  0,  0,248,  0, 32, 32,248, 32, 32,  0,  0,  0};
static const GLubyte Character_178[] = {  3,  0,  0,  0,  0,  0,  0,  0,224, 64,160, 96,  0,  0,  0};
static const GLubyte Character_179[] = {  3,  0,  0,  0,  0,  0,  0,  0,192, 32, 64,224,  0,  0,  0};
static const GLubyte Character_180[] = {  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,128, 64,  0,  0,  0};
static const GLubyte Character_181[] = {  5,  0,  0,128,128,232,144,144,144,144,  0,  0,  0,  0,  0};
static const GLubyte Character_182[] = {  6,  0,  0, 40, 40, 40, 40,104,232,232,232,124,  0,  0,  0};
static const GLubyte Character_183[] = {  2,  0,  0,  0,  0,  0,  0,128,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_184[] = {  4,  0,192, 32, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_185[] = {  3,  0,  0,  0,  0,  0,  0,  0,224, 64,192, 64,  0,  0,  0};
static const GLubyte Character_186[] = {  4,  0,  0,  0,  0,  0,  0,224,  0, 64,160, 64,  0,  0,  0};
static const GLubyte Character_187[] = {  5,  0,  0,  0,  0,  0,160, 80, 80,160,  0,  0,  0,  0,  0};
static const GLubyte Character_188[] = {  8,  0,  0,  0,  0, 68, 62, 44,244, 72,200, 68,  0,  0,  0};
static const GLubyte Character_189[] = {  8,  0,  0,  0,  0, 78, 36, 42,246, 72,200, 68,  0,  0,  0};
static const GLubyte Character_190[] = {  8,  0,  0,  0,  0, 68, 62, 44,212, 40, 72,228,  0,  0,  0};
static const GLubyte Character_191[] = {  4,  0,  0,224,160,128, 64, 64,  0, 64,  0,  0,  0,  0,  0};
static const GLubyte Character_192[] = {  8,  0,  0,  0,  0,238, 68,124, 40, 40, 56, 16,  0, 16, 32};
static const GLubyte Character_193[] = {  8,  0,  0,  0,  0,238, 68,124, 40, 40, 56, 16,  0, 16,  8};
static const GLubyte Character_194[] = {  8,  0,  0,  0,  0,238, 68,124, 40, 40, 56, 16,  0, 40, 16};
static const GLubyte Character_195[] = {  8,  0,  0,  0,  0,238, 68,124, 40, 40, 56, 16,  0, 40, 20};
static const GLubyte Character_196[] = {  8,  0,  0,  0,  0,238, 68,124, 40, 40, 56, 16,  0, 40,  0};
static const GLubyte Character_197[] = {  8,  0,  0,  0,  0,238, 68,124, 40, 40, 56, 16, 16, 40, 16};
static const GLubyte Character_198[] = {  9,  0,  0,  0,  0,  0,  0,  0,  0,239,  0, 73,  0,120,  0, 46,  0, 40,  0, 57,  0, 31,  0,  0,  0,  0,  0,  0,  0};
static const GLubyte Character_199[] = {  7,  0, 96, 16, 32,120,196,128,128,128,196,124,  0,  0,  0};
static const GLubyte Character_200[] = {  6,  0,  0,  0,  0,248, 72, 64,112, 64, 72,248,  0, 32, 64};
static const GLubyte Character_201[] = {  6,  0,  0,  0,  0,248, 72, 64,112, 64, 72,248,  0, 32, 16};
static const GLubyte Character_202[] = {  6,  0,  0,  0,  0,248, 72, 64,112, 64, 72,248,  0, 80, 32};
static const GLubyte Character_203[] = {  6,  0,  0,  0,  0,248, 72, 64,112, 64, 72,248,  0, 80,  0};
static const GLubyte Character_204[] = {  4,  0,  0,  0,  0,224, 64, 64, 64, 64, 64,224,  0, 64,128};
static const GLubyte Character_205[] = {  4,  0,  0,  0,  0,224, 64, 64, 64, 64, 64,224,  0, 64, 32};
static const GLubyte Character_206[] = {  4,  0,  0,  0,  0,224, 64, 64, 64, 64, 64,224,  0,160, 64};
static const GLubyte Character_207[] = {  4,  0,  0,  0,  0,224, 64, 64, 64, 64, 64,224,  0,160,  0};
static const GLubyte Character_208[] = {  7,  0,  0,  0,  0,248, 76, 68,228, 68, 76,248,  0,  0,  0};
static const GLubyte Character_209[] = {  8,  0,  0,  0,  0,228, 76, 76, 84, 84,100,238,  0, 80, 40};
static const GLubyte Character_210[] = {  7,  0,  0,  0,  0,120,204,132,132,132,204,120,  0, 32, 64};
static const GLubyte Character_211[] = {  7,  0,  0,  0,  0,120,204,132,132,132,204,120,  0, 16,  8};
static const GLubyte Character_212[] = {  7,  0,  0,  0,  0,120,204,132,132,132,204,120,  0, 80, 32};
static const GLubyte Character_213[] = {  7,  0,  0,  0,  0,120,204,132,132,132,204,120,  0, 80, 40};
static const GLubyte Character_214[] = {  7,  0,  0,  0,  0,120,204,132,132,132,204,120,  0, 80,  0};
static const GLubyte Character_215[] = {  6,  0,  0,  0,  0,136, 80, 32, 80,136,  0,  0,  0,  0,  0};
static const GLubyte Character_216[] = {  8,  0,  0,  0,128,124,102, 82, 82, 74,102, 62,  1,  0,  0};
static const GLubyte Character_217[] = {  8,  0,  0,  0,  0, 56,108, 68, 68, 68, 68,238,  0, 16, 32};
static const GLubyte Character_218[] = {  8,  0,  0,  0,  0, 56,108, 68, 68, 68, 68,238,  0, 16,  8};
static const GLubyte Character_219[] = {  8,  0,  0,  0,  0, 56,108, 68, 68, 68, 68,238,  0, 40, 16};
static const GLubyte Character_220[] = {  8,  0,  0,  0,  0, 56,108, 68, 68, 68, 68,238,  0, 40,  0};
static const GLubyte Character_221[] = {  8,  0,  0,  0,  0, 56, 16, 16, 40, 40, 68,238,  0, 16,  8};
static const GLubyte Character_222[] = {  6,  0,  0,  0,  0,224, 64,112, 72,112, 64,224,  0,  0,  0};
static const GLubyte Character_223[] = {  5,  0,  0,  0,  0,224, 80, 80, 96, 80, 80, 32,  0,  0,  0};
static const GLubyte Character_224[] = {  4,  0,  0,  0,  0,224,160, 96, 32,192,  0, 64,128,  0,  0};
static const GLubyte Character_225[] = {  4,  0,  0,  0,  0,224,160, 96, 32,192,  0, 64, 32,  0,  0};
static const GLubyte Character_226[] = {  4,  0,  0,  0,  0,224,160, 96, 32,192,  0,160, 64,  0,  0};
static const GLubyte Character_227[] = {  4,  0,  0,  0,  0,224,160, 96, 32,192,  0,160, 80,  0,  0};
static const GLubyte Character_228[] = {  4,  0,  0,  0,  0,224,160, 96, 32,192,  0,160,  0,  0,  0};
static const GLubyte Character_229[] = {  4,  0,  0,  0,  0,224,160, 96, 32,192, 64,160, 64,  0,  0};
static const GLubyte Character_230[] = {  6,  0,  0,  0,  0,216,160,112, 40,216,  0,  0,  0,  0,  0};
static const GLubyte Character_231[] = {  4,  0,192, 32, 64, 96,128,128,128, 96,  0,  0,  0,  0,  0};
static const GLubyte Character_232[] = {  4,  0,  0,  0,  0, 96,128,192,160, 96,  0, 64,128,  0,  0};
static const GLubyte Character_233[] = {  4,  0,  0,  0,  0, 96,128,192,160, 96,  0, 64, 32,  0,  0};
static const GLubyte Character_234[] = {  4,  0,  0,  0,  0, 96,128,192,160, 96,  0,160, 64,  0,  0};
static const GLubyte Character_235[] = {  4,  0,  0,  0,  0, 96,128,192,160, 96,  0,160,  0,  0,  0};
static const GLubyte Character_236[] = {  4,  0,  0,  0,  0,224, 64, 64, 64,192,  0, 64,128,  0,  0};
static const GLubyte Character_237[] = {  4,  0,  0,  0,  0,224, 64, 64, 64,192,  0, 64, 32,  0,  0};
static const GLubyte Character_238[] = {  4,  0,  0,  0,  0,224, 64, 64, 64,192,  0,160, 64,  0,  0};
static const GLubyte Character_239[] = {  4,  0,  0,  0,  0,224, 64, 64, 64,192,  0,160,  0,  0,  0};
static const GLubyte Character_240[] = {  5,  0,  0,  0,  0, 96,144,144,144,112,160,112, 64,  0,  0};
static const GLubyte Character_241[] = {  5,  0,  0,  0,  0,216,144,144,144,224,  0,160, 80,  0,  0};
static const GLubyte Character_242[] = {  5,  0,  0,  0,  0, 96,144,144,144, 96,  0, 32, 64,  0,  0};
static const GLubyte Character_243[] = {  5,  0,  0,  0,  0, 96,144,144,144, 96,  0, 64, 32,  0,  0};
static const GLubyte Character_244[] = {  5,  0,  0,  0,  0, 96,144,144,144, 96,  0,160, 64,  0,  0};
static const GLubyte Character_245[] = {  5,  0,  0,  0,  0, 96,144,144,144, 96,  0,160, 80,  0,  0};
static const GLubyte Character_246[] = {  5,  0,  0,  0,  0, 96,144,144,144, 96,  0,160,  0,  0,  0};
static const GLubyte Character_247[] = {  6,  0,  0,  0,  0, 32,  0,248,  0, 32,  0,  0,  0,  0,  0};
static const GLubyte Character_248[] = {  5,  0,  0,  0,  0,224,144,144,144,112,  8,  0,  0,  0,  0};
static const GLubyte Character_249[] = {  5,  0,  0,  0,  0,104,144,144,144,144,  0, 32, 64,  0,  0};
static const GLubyte Character_250[] = {  5,  0,  0,  0,  0,104,144,144,144,144,  0, 64, 32,  0,  0};
static const GLubyte Character_251[] = {  5,  0,  0,  0,  0,104,144,144,144,144,  0, 80, 32,  0,  0};
static const GLubyte Character_252[] = {  5,  0,  0,  0,  0,104,144,144,144,144,  0, 80,  0,  0,  0};
static const GLubyte Character_253[] = {  5,  0,  0,128,192, 64, 96,160,144,184,  0, 32, 16,  0,  0};
static const GLubyte Character_254[] = {  5,  0,  0,192,128,224,144,144,144,224,128,128,  0,  0,  0};
static const GLubyte Character_255[] = {  5,  0,  0,128,192, 64, 96,160,144,184,  0,160,  0,  0,  0};

//字符映射表
static const GLubyte *Character_Map[] = {
      Character_000,Character_001,Character_002,Character_003,Character_004,Character_005,Character_006,Character_007,Character_008,Character_009,Character_010,Character_011,Character_012,Character_013,Character_014,Character_015,
      Character_016,Character_017,Character_018,Character_019,Character_020,Character_021,Character_022,Character_023,Character_024,Character_025,Character_026,Character_027,Character_028,Character_029,Character_030,Character_031,
      Character_032,Character_033,Character_034,Character_035,Character_036,Character_037,Character_038,Character_039,Character_040,Character_041,Character_042,Character_043,Character_044,Character_045,Character_046,Character_047,
      Character_048,Character_049,Character_050,Character_051,Character_052,Character_053,Character_054,Character_055,Character_056,Character_057,Character_058,Character_059,Character_060,Character_061,Character_062,Character_063,
      Character_064,Character_065,Character_066,Character_067,Character_068,Character_069,Character_070,Character_071,Character_072,Character_073,Character_074,Character_075,Character_076,Character_077,Character_078,Character_079,
      Character_080,Character_081,Character_082,Character_083,Character_084,Character_085,Character_086,Character_087,Character_088,Character_089,Character_090,Character_091,Character_092,Character_093,Character_094,Character_095,
      Character_096,Character_097,Character_098,Character_099,Character_100,Character_101,Character_102,Character_103,Character_104,Character_105,Character_106,Character_107,Character_108,Character_109,Character_110,Character_111,
      Character_112,Character_113,Character_114,Character_115,Character_116,Character_117,Character_118,Character_119,Character_120,Character_121,Character_122,Character_123,Character_124,Character_125,Character_126,Character_032,
      Character_032,Character_032,Character_032,Character_032,Character_032,Character_032,Character_032,Character_032,Character_032,Character_032,Character_032,Character_032,Character_032,Character_032,Character_032,Character_032,
      Character_032,Character_032,Character_032,Character_032,Character_032,Character_032,Character_032,Character_032,Character_032,Character_032,Character_032,Character_032,Character_032,Character_032,Character_032,Character_032,
      Character_160,Character_161,Character_162,Character_163,Character_164,Character_165,Character_166,Character_167,Character_168,Character_169,Character_170,Character_171,Character_172,Character_173,Character_174,Character_175,
      Character_176,Character_177,Character_178,Character_179,Character_180,Character_181,Character_182,Character_183,Character_184,Character_185,Character_186,Character_187,Character_188,Character_189,Character_190,Character_191,
      Character_192,Character_193,Character_194,Character_195,Character_196,Character_197,Character_198,Character_199,Character_200,Character_201,Character_202,Character_203,Character_204,Character_205,Character_206,Character_207,
      Character_208,Character_209,Character_210,Character_211,Character_212,Character_213,Character_214,Character_215,Character_216,Character_217,Character_218,Character_219,Character_220,Character_221,Character_222,Character_223,
      Character_224,Character_225,Character_226,Character_227,Character_228,Character_229,Character_230,Character_231,Character_232,Character_233,Character_234,Character_235,Character_236,Character_237,Character_238,Character_239,
      Character_240,Character_241,Character_242,Character_243,Character_244,Character_245,Character_246,Character_247,Character_248,Character_249,Character_250,Character_251,Character_252,Character_253,Character_254,Character_255,
      NULL
};
const  FyjFont fyjFont = { "-a-fyj-test-font", 256, 14, Character_Map, 0, 4 };

 /**
  * @param character 0~255
  */
void renderCharacter(int character)
{
    Q_ASSERT_X(character >= 0 && character <= 255,
               "renderCharacter", "invalid parameter");

    const FyjFont *font = &fyjFont;
    const GLubyte *face = font->characters[character];

    glPushClientAttrib( GL_CLIENT_PIXEL_STORE_BIT );
    glPixelStorei( GL_UNPACK_SWAP_BYTES,  GL_FALSE );
    glPixelStorei( GL_UNPACK_LSB_FIRST,   GL_FALSE );
    glPixelStorei( GL_UNPACK_ROW_LENGTH,  0        );
    glPixelStorei( GL_UNPACK_SKIP_ROWS,   0        );
    glPixelStorei( GL_UNPACK_SKIP_PIXELS, 0        );
    glPixelStorei( GL_UNPACK_ALIGNMENT,   1        );
    glBitmap(
        face[ 0 ], font->height,      /* The bitmap's width and height  */
        font->xorig, font->yorig,     /* The origin in the font glyph   */
        ( float )( face[ 0 ] ), 0.0,  /* The raster advance -- inc. x,y */
        ( face + 1 )                  /* The packed bitmap data...      */
    );
    glPopClientAttrib( );
}

void renderString(const unsigned char *string)
{
    unsigned char c;
    float x = 0.0f ;
    const FyjFont* font = &fyjFont;

    glPushClientAttrib( GL_CLIENT_PIXEL_STORE_BIT );
    glPixelStorei( GL_UNPACK_SWAP_BYTES,  GL_FALSE );
    glPixelStorei( GL_UNPACK_LSB_FIRST,   GL_FALSE );
    glPixelStorei( GL_UNPACK_ROW_LENGTH,  0        );
    glPixelStorei( GL_UNPACK_SKIP_ROWS,   0        );
    glPixelStorei( GL_UNPACK_SKIP_PIXELS, 0        );
    glPixelStorei( GL_UNPACK_ALIGNMENT,   1        );

    while( ( c = *string++) )
        if( c == '\n' )
        {
            //画回车符时，设置宽，高为0, bitmap数据为空
            glBitmap ( 0, 0, 0, 0, -x, (float) -font->height, NULL );
            x = 0.0f;
        }
        else
        {
            const GLubyte* face = font->characters[ c ];

            glBitmap(
                face[ 0 ], font->height,     /* Bitmap's width and height    */
                font->xorig, font->yorig,    /* The origin in the font glyph */
                ( float )( face[ 0 ] ), 0.0, /* The raster advance; inc. x,y */
                ( face + 1 )                 /* The packed bitmap data...    */
            );

            x += ( float )( face[ 0 ] );
        }

    glPopClientAttrib( );
}

#ifdef USE_DISPLAY_LIST
//利用显示列表来重新实现上述函数
GLuint fontOffset;
void makeRasterFyjFont(void)
{
    GLuint i, j;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    fontOffset = glGenLists(256);
    for (i = 0; i < 256; i++,j++) {
        glNewList(fontOffset + i, GL_COMPILE);
        renderCharacter(i);
        glEndList();
    }
}

void printString(const unsigned char *s)
{
    glPushAttrib(GL_LIST_BIT);
    glListBase(fontOffset);
    glCallLists(strlen(reinterpret_cast<const char *>(s)), GL_UNSIGNED_BYTE, (GLubyte *)(s));
    glPopAttrib();
}
#endif

void glPrint(const char *fmt, ...)
{
    char   text[256];              // Holds Our String
    va_list     ap;                 // Pointer To List Of Arguments
    if (fmt == NULL)                    // If There's No Text
        return;                     // Do Nothing
    va_start(ap, fmt);                  // Parses The String For Variables
        vsprintf(text, fmt, ap);                // And Converts Symbols To Actual Numbers
    va_end(ap);                     // Results Are Stored In Text

#ifdef USE_DISPLAY_LIST
    printString(reinterpret_cast<unsigned char *>(text));
#else
    renderString(reinterpret_cast<unsigned char *>(text));
#endif
}


    GLfloat cnt1;           // 1st counter used to move text & for coloring.
    GLfloat cnt2;           // 2nd counter used to move text & for coloring.
}


MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(parent), fullscreen(false)
{
    setWindowTitle(tr("nehe----lesson13"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(10);
}

void MyGLWidget::initializeGL()
{
    glShadeModel(GL_SMOOTH);   // Enables Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  // Black Background
    glClearDepth(1.0f);             // Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);        // Enables Depth Testing
    glDepthFunc(GL_LEQUAL);        // The Type Of Depth Test To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations

#ifdef USE_DISPLAY_LIST
    makeRasterFyjFont();
#endif
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

    glTranslatef(0, 0, -1.0f);

    // Pulsing Colors Based On Text Position
      glColor3f(qAbs(1.0f*((float)(cos(cnt1)))),qAbs(1.0f*((float)(sin(cnt2)))),qAbs(1.0f-0.5f*((float)(cos(cnt1+cnt2)))));

      // Position The Text On The Screen
      glRasterPos2f(-0.45f+0.05f*float(cos(cnt1)), 0.35f*float(sin(cnt2)));

 //     renderCharacter(97);

      glPrint("Active OpenGL Text With NeHe - %7.2f", cnt1);

      cnt1 += 0.01f;
      cnt2 += 0.0081f;

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
