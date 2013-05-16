#include "earthtest.h"
#include "platform.h"
#include "os.h"
#include "fyjstring.h"
#include "fyjprogram.h"
#include "fyjcamera.h"
#include "sphere_data.h"

using namespace MULTITEXTURE_TEST;
using namespace FYJ;
#if 1
static  const String gVertexShader = 
	"varying float Diffuse;\n"
	"varying vec3  Specular;\n"
	"varying vec3 normal;\n"
	"\n"
	"uniform vec3 LightPosition;\n"
	"\n"
	"uniform mat4 ModelViewMatrix;\n"
	"uniform mat3 NormalMatrix;\n"
	"\n"
	"attribute vec4 Vertex;\n"
	"attribute vec3 Normal;\n"
	"\n"
	"const vec3 Xunitvec = vec3(1.0, 0.0, 0.0);\n"
	"const vec3 Yunitvec = vec3(0.0, 1.0, 0.0);\n"
	"\n"
	"void main()\n"
	"{\n"
	"	normal = Normal;\n"
	"	 vec3 ecPosition = vec3(ModelViewMatrix * Vertex);\n"
	"	 vec3 tnorm 	 = normalize(NormalMatrix * Normal);\n"
	"	 vec3 lightVec	 = normalize(LightPosition - ecPosition);\n"
	"	 vec3 reflectVec = reflect(-lightVec, tnorm);\n"
	"	 vec3 viewVec	 = normalize(-ecPosition);\n"
	"\n"
	"	 float spec 	 = clamp(dot(reflectVec, viewVec), 0.0, 1.0);\n"
	"	 spec			 = pow(spec, 8.0);\n"
	"	 Specular		 = vec3(spec) * vec3(1.0, 0.941, 0.898) * 0.3;\n"
	"\n"
	"	 Diffuse		 = max(dot(lightVec, tnorm), 0.0);\n"
	"	 gl_Position	 = ModelViewMatrix * Vertex;\n"
	"}\n";



static const String gFragmentShader =
	"#ifdef GL_ES\n"
	"precision mediump float;\n"
	 "#endif\n"
	"#define PI  3.141592\n"
	"\n"
	"uniform sampler2D EarthDay;\n"
	"uniform sampler2D EarthNight;\n"
	"uniform sampler2D EarthCloudGloss;\n"
	"\n"
	"varying float Diffuse;\n"
	"varying vec3  Specular;\n"
	"varying vec3  normal;\n"
	"\n"
	"float aTan2(float y, float x) {\n"
	"	float coeff_1 = PI / 4.0;\n"
	"	float coeff_2 = 3.0 * coeff_1;\n"
	"	float abs_y = abs(y);\n"
	"	float angle;\n"
	"	if (x >= 0.0) {\n"
	"		float r = (x - abs_y) / (x + abs_y);\n"
	"		angle = coeff_1 - coeff_1 * r;\n"
	"	} else {\n"
	"		float r = (x + abs_y) / (abs_y - x);\n"
	"		angle = coeff_2 - coeff_1 * r;\n"
	"	}\n"
	"	return y < 0.0 ? -angle : angle;\n"
	"}\n"
	"\n"
	"void main()\n"
	"{\n"
	"	 vec2  TexCoord;\n"
	" \n"
	"	 TexCoord.x 	= aTan2(normal.x, normal.z)/(2.0 * PI) + 0.5;\n"
	"	 \n"
	"\n"
	"	 TexCoord.y 	 = asin(normal.y)/PI + 0.5;\n"
	"\n"
	"\n"
	"	 vec2 clouds	= texture2D(EarthCloudGloss, TexCoord).rg;\n"
	"	 vec3 daytime	= (texture2D(EarthDay, TexCoord).rgb * Diffuse + \n"
	"						   Specular * clouds.g) * (1.0 - clouds.r) +\n"
	"						   clouds.r * Diffuse;\n"
	"	 vec3 nighttime = texture2D(EarthNight, TexCoord).rgb * \n"
	"						  (1.0 - clouds.r) * 2.0;\n"
	"\n"
	"	 vec3 color = daytime;\n"
	"\n"
	"	 if (Diffuse < 0.1)\n"
	"		 color = mix(nighttime, daytime, (Diffuse + 0.1) * 5.0);\n"
	"\n"
	"	 gl_FragColor = vec4(1, 0, 0, 1.0);\n"
	"}\n";
#endif
#if 0
static  String gVertexShader = "uniform mat4 projectionMatrix;\n"
	    "uniform mat4 modelViewMatrix;\n"
	    "attribute vec4 aPosition;\n"    
	    "attribute vec2 aTexCoords;\n"
	    "varying vec2 vTexCoords;\n"
	    "void main() {\n" 
	    "vTexCoords = aTexCoords;\n"
	   "  gl_Position = projectionMatrix * modelViewMatrix * vPosition;\n"    
	   "}\n";
static  String gFragmentShader = 
             "#ifdef GL_ES\n"
    	    "precision mediump float;\n"
             "#endif\n"
             "varying vec2 vTexCoords;\n"
             "uniform Sampler2D uTexture;\n"
	    "void main() {\n"    
	   "  gl_FragColor = texture2D(uTexture, vTexCoords);\n"   
	   "}\n";
#endif

namespace
{
	static GLuint vboID[2];
	static GLfloat fRotateAngle = 0;
}

EarthTest::EarthTest():TestBase()
{
	INFO("Entering EarthTest...");
	program = fyj_new Program(gVertexShader, gFragmentShader);
	camera = fyj_new Camera;
}

EarthTest::~EarthTest()
{
	program->abandon();
	fyj_delete program;
	fyj_delete camera;
}

bool EarthTest::init()
{
	INFO("init EarthTest...");

	glClearColor(0, 0, 1, 1.0f);
    	glClearDepthf(1.0f);

	program->use();
/*	
	glGenBuffers(2, vboID);


	GLuint pos = program->getAttribute(Program::POSITION, "aPosition");
	
	glBindBuffer(GL_ARRAY_BUFFER, vboID[0]);
  	glBufferData(GL_ARRAY_BUFFER, 3 * SPHERE_VERTEX_COUNT*sizeof(GLfloat), gSphereVertices, GL_STATIC_DRAW);
	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);	
	program->enableVertexAttribArray();
*/

	
	

	GLuint pos = program->getAttribute(Program::POSITION, "Vertex");
	glVertexAttribPointer(pos, 2, GL_FLOAT, GL_FALSE, 0, gSphereVertices);	
	GLuint normal = program->getAttribute(Program::NORMAL, "Normal");
	glVertexAttribPointer(normal, 2, GL_FLOAT, GL_FALSE, 0, gSphereNormals);
	program->enableVertexAttribArray();


	GLuint iModelViewLoc = program->getUniform(Program::MV, "ModelViewMatrix");
	camera->setLookAt(0, 0, -5.0f, 0, 0, 0, 0.0f, 1.0f, 0.0f);
	glUniformMatrix4fv(iModelViewLoc, 1, GL_FALSE, (GLfloat*)camera->vPtrForMV());

	GLuint iNormalMatrixLoc = program->getUniform(Program::NM, "NormalMatrix");
	glUniformMatrix4fv(iNormalMatrixLoc, 1, GL_FALSE, (GLfloat*)camera->vPtrForNM());

	GLuint iLightPosLoc = program->getUniform(Program::LIGHT_POS, "LightPosition");
	camera->setLightPos(0, 0, 5, 1);
	glUniformMatrix4fv(iLightPosLoc, 1, GL_FALSE, (GLfloat*)camera->vPtrForLightPos());

#if 1
	Image *img = g_os->loadImage("earth_color.png");
	if (img == NULL) {
		WARN("failed to load earth_color.png!");
	} else {
		INFO("loading image successfully!");
		GLuint earth_day_textureID;
		glGenTextures(1, &earth_day_textureID);
		glActiveTexture(GL_TEXTURE0);
	  	glBindTexture(GL_TEXTURE_2D, earth_day_textureID);
	        // Set filtering
	        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	        glTexImage2D(GL_TEXTURE_2D, 0, img->format, img->width, img->height, 0, img->format, GL_UNSIGNED_BYTE, img->pixels);

		fyj_delete img;
		img = g_os->loadImage("earth_night.png");
		if (img != NULL) {
			GLuint earth_night_textureID;
			glGenTextures(1, &earth_night_textureID);
			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, earth_night_textureID);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		        glTexImage2D(GL_TEXTURE_2D, 0, img->format, img->width, img->height, 0, img->format, GL_UNSIGNED_BYTE, img->pixels);
			fyj_delete img;

			img = g_os->loadImage("cloudandgloss.png");
			if (img != NULL) {
				GLuint earth_cloud_textureID;
				glGenTextures(1, &earth_cloud_textureID);
				glActiveTexture(GL_TEXTURE2);
				glBindTexture(GL_TEXTURE_2D, earth_cloud_textureID);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			        glTexImage2D(GL_TEXTURE_2D, 0, img->format, img->width, img->height, 0, img->format, GL_UNSIGNED_BYTE, img->pixels);
				fyj_delete img;
			} else {
				WARN("failed to load cloudandgloss.png");
			}
		}else {
			WARN("failed to load earth_night.png");
		}
	}	
	INFO("~~~~~~~~~~~~~~~~~~~~~~~");
	GLuint texHandle = program->getUniform(Program::SAMPLER2D, "EarthDay");
	glActiveTexture(GL_TEXTURE0);
         glUniform1i(texHandle, 0);
	INFO("texHandle 1 : %d", texHandle);

	texHandle = program->getUniform(Program::SAMPLER2D, "EarthNight");
	glActiveTexture(GL_TEXTURE1);
         glUniform1i(texHandle, 1);
	INFO("texHandle 2 : %d", texHandle);

	texHandle = program->getUniform(Program::SAMPLER2D, "EarthCloudGloss");
	glActiveTexture(GL_TEXTURE2);
	glUniform1i(texHandle, 2);
	INFO("texHandle 3 : %d", texHandle);
#endif


        return true;
}

bool EarthTest::resize(int w, int h)
{
	INFO("resize EarthTest...");
	glViewport(0, 0, w, h);
/*	
	GLuint iProjectionLoc = program->getUniform(Program::PROJECT, "projectionMatrix");
	camera->setPerspective(45.0f,  (float)w/h, 0.01f, 100.0f);
	glUniformMatrix4fv(iProjectionLoc, 1, GL_FALSE, (GLfloat*)camera->vPtrForProj());
	*/
	return true;
}

bool EarthTest::render()
{
	INFO("render EarthTest");
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
/*
	glBindBuffer(GL_ARRAY_BUFFER, vboID);

	GLuint iModelViewLoc = program->getUniform(Program::MV, "modelViewMatrix");
	camera->setLookAt(0, 0, -5.0f, 0, 0, 0, 0.0f, 1.0f, 0.0f);

	camera->rotate(fRotateAngle, 0.0f, 1.0f, 0.0f);
   	glUniformMatrix4fv(iModelViewLoc, 1, GL_FALSE, (GLfloat*)camera->vPtrForMV());
   	*/
	glDrawArrays(GL_TRIANGLES, 0, SPHERE_VERTEX_COUNT);
//	fRotateAngle += 0.2f;
	
	return true;
}

