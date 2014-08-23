#include "multitexturetest.h"
#include "platform.h"
#include "os.h"
#include "fyjstring.h"
#include "fyjprogram.h"

using namespace MULTITEXTURE_TEST;
using namespace FYJ;

static  const String gVertexShader = 
	"attribute vec4 a_position;   \n" 
	"attribute vec2 a_texCoord;   \n" 
	"varying vec2 v_texCoord;	  \n" 
	"void main()				  \n" 
	"{							  \n" 
	"	gl_Position = a_position; \n" 
	"	v_texCoord = a_texCoord;  \n" 
	"}							  \n";


static const String gFragmentShader =
	"#ifdef GL_ES\n"
	"precision mediump float;\n"
	 "#endif\n"
	"varying vec2 v_texCoord;							 \n" 
	"uniform sampler2D s_baseMap;						 \n" 
	"uniform sampler2D s_lightMap;						 \n" 
	"void main()										 \n" 
	"{												 \n" 
	"  vec4 baseColor;									 \n" 
	"  vec4 lightColor; 								 \n" 
	"											 \n" 
	"  baseColor = texture2D( s_baseMap, v_texCoord );	 \n" 
	"  lightColor = texture2D( s_lightMap, v_texCoord ); \n" 
	"  gl_FragColor = baseColor * (lightColor + 0.25);	 \n" 
	"}											 \n";	 



//data
const GLfloat gVertices[] = { -1, -1, 1, -1, -1, 1, 1, 1 };
const GLfloat gTexCoords[] = { 0, 1, 1, 1, 0, 0, 1, 0};


MultiTextureTest::MultiTextureTest():TestBase()
{
	INFO("Entering MyFirstTest...");
	program = fyj_new Program(gVertexShader, gFragmentShader);
}

MultiTextureTest::~MultiTextureTest()
{
	program->abandon();
	fyj_delete program;
}

bool MultiTextureTest::init()
{
	INFO("init MultiTextureTest...");

	glClearColor(0, 0, 1, 1.0f);
    	glClearDepthf(1.0f);

	program->use();
	GLuint pos = program->getAttribute(Program::POSITION, "a_position");
	glVertexAttribPointer(pos, 2, GL_FLOAT, GL_FALSE, 0, gVertices);	
	GLuint texCoords = program->getAttribute(Program::TEX_COORD0, "a_texCoord");
	glVertexAttribPointer(texCoords, 2, GL_FLOAT, GL_FALSE, 0, gTexCoords);
	program->enableVertexAttribArray();

	Image *img = g_os->loadImage("basemap.png");
	if (img == NULL) {
		WARN("failed to load image data!");
	} else {
		INFO("loading image successfully!");
		GLuint basemap_textureID;
		glGenTextures(1, &basemap_textureID);
		glActiveTexture(GL_TEXTURE0);
	  	glBindTexture(GL_TEXTURE_2D, basemap_textureID);
	        // Set filtering
	        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	        glTexImage2D(GL_TEXTURE_2D, 0, img->format, img->width, img->height, 0, img->format, GL_UNSIGNED_BYTE, img->pixels);

		fyj_delete img;
		img = g_os->loadImage("lightmap.png");
		if (img != NULL) {
			GLuint lightmap_textureID;
			glGenTextures(1, &lightmap_textureID);
			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, lightmap_textureID);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		        glTexImage2D(GL_TEXTURE_2D, 0, img->format, img->width, img->height, 0, img->format, GL_UNSIGNED_BYTE, img->pixels);
			fyj_delete img;
		}
	}	

	GLuint texHandle = program->getUniform(Program::SAMPLER2D, "s_baseMap");
	glActiveTexture(GL_TEXTURE0);
         glUniform1i(texHandle, 0);

	texHandle = program->getUniform(Program::SAMPLER2D_1, "s_lightMap");
	glActiveTexture(GL_TEXTURE1);
         glUniform1i(texHandle, 1);



        return true;
}

bool MultiTextureTest::resize(int w, int h)
{
	INFO("resize MultiTextureTest...");
	glViewport(0, 0, w, h);
	return true;
}

bool MultiTextureTest::render()
{
	INFO("render MultiTextureTest");
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	
	return true;
}

