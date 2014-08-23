#include "texturetest.h"
#include "platform.h"
#include "os.h"
#include "fyjstring.h"
#include "fyjprogram.h"

using namespace TEXTURE_TEST;
using namespace FYJ;

static  const String gVertexShader = 
	"attribute vec4 a_Position;\n"
	"attribute vec2 a_TexCoords; \n"
	"varying vec2 v_TexCoords; \n"
         "void main() {\n"
         "  gl_Position = a_Position;\n"
	"  v_TexCoords = a_TexCoords; \n"
         "}\n";

static const String gFragmentShader =
	"#ifdef GL_ES\n"
	"precision mediump float;\n"
	 "#endif\n"
    "uniform sampler2D u_Texture; \n"
    "varying vec2 v_TexCoords; \n"
    "void main() {\n"
    "  gl_FragColor = texture2D(u_Texture, v_TexCoords);\n"
    "}\n";


//data
const GLfloat gVertices[] = { -1, -1, 1, -1, -1, 1, 1, 1 };
const GLfloat gTexCoords[] = { 0, 1, 1, 1, 0, 0, 1, 0};


TextureTest::TextureTest():TestBase()
{
	INFO("Entering MyFirstTest...");
	program = fyj_new Program(gVertexShader, gFragmentShader);
}

TextureTest::~TextureTest()
{
	program->abandon();
	fyj_delete program;
}
static GLuint texHandle;
bool TextureTest::init()
{
	INFO("init MyFirstTest...");

	glClearColor(0, 0, 1, 1.0f);
    	glClearDepthf(1.0f);

	program->use();
	GLuint pos = program->getAttribute(Program::POSITION, "a_Position");
	glVertexAttribPointer(pos, 2, GL_FLOAT, GL_FALSE, 0, gVertices);	
	GLuint texCoords = program->getAttribute(Program::TEX_COORD0, "a_TexCoords");
	glVertexAttribPointer(texCoords, 2, GL_FLOAT, GL_FALSE, 0, gTexCoords);
	program->enableVertexAttribArray();

	Image *img = g_os->loadImage("android_test.png");
	if (img == NULL) {
		WARN("failed to load image data!");
	} else {
		INFO("loading image successfully!");
		GLuint textureID;
		glGenTextures(1, &textureID);
	  	glBindTexture(GL_TEXTURE_2D, textureID);
	        // Set filtering
	        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	        glTexImage2D(GL_TEXTURE_2D, 0, img->format, img->width, img->height, 0, img->format, GL_UNSIGNED_BYTE, img->pixels);
	        INFO("Image width: %d, Image height: %d", img->width, img->height);
	}	

	texHandle = program->getUniform(Program::SAMPLER2D, "u_Texture");



        return true;
}

bool TextureTest::resize(int w, int h)
{
	INFO("resize MyFirstTest...");
	glViewport(0, 0, w, h);
	return true;
}

bool TextureTest::render()
{
	INFO("render MyFirstTest");
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glActiveTexture(GL_TEXTURE0);
         glUniform1i(texHandle, 0);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	
	return true;
}

