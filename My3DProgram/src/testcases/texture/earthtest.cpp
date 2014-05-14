#include "earthtest.h"
#include "platform.h"
#include "os.h"
#include "fyjcamera.h"
#include "fyjgeometry.h"


using namespace TEXTURE_TEST;
using namespace FYJ;

namespace
{
	static GLfloat fRotateAngle = 0;
}

EarthTest::EarthTest():TestBase()
{
	INFO("Entering EarthTest...");	
	camera = fyj_new Camera;

	sphere = fyj_new Sphere(1.0f, 30, 45, false, true, true);
	sphere->setup(FYJ_SHADER_TEXTURE, false);
}

EarthTest::~EarthTest()
{
	if (sphere != NULL)
		fyj_delete sphere;
	if (camera != NULL)
		fyj_delete camera;

}

bool EarthTest::init()
{
	INFO("init EarthTest...");

	if (sphere->isTextured()) {
		Image *img = g_os->loadImage("earth_color.png");
		if (img == NULL) {
			WARN("failed to load image data!");
		} else {
			INFO("loading image successfully!");
			GLuint textureID;
			glGenTextures(1, &textureID);
		  	glBindTexture(GL_TEXTURE_2D, textureID);
		        // Set filtering
		        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		         glTexImage2D(GL_TEXTURE_2D, 0, img->format, img->width, img->height, 0, img->format, GL_UNSIGNED_BYTE, img->pixels);
		}	
	}	

	glClearDepthf(1.0f);
	glDepthFunc(GL_LEQUAL); 
	glEnable(GL_DEPTH_TEST);
	glClearColor(0, 0, 0.5f, 1);

        return true;
}

bool EarthTest::resize(int w, int h)
{
	INFO("resize EarthTest...");

	glViewport(0, 0, w, h);
	Shader shader = sphere->getShader();
	if (shader.PROJECTION.empty())
		return true;

	GLuint iProjectionLoc = sphere->getProgram()->getUniform(Program::PROJECT,  shader.map(Program::PROJECT));
	INFO("iProjecttionLoc = %d", iProjectionLoc);
	
	camera->setPerspective(45.0f,  (float)w/h, 0.01f, 100.0f);
	glUniformMatrix4fv(iProjectionLoc, 1, GL_FALSE, (GLfloat*)camera->vPtrForProj());
	return true;
}

bool EarthTest::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Shader shader = sphere->getShader();
	if (!shader.MV.empty()) {
		GLuint iModelViewLoc = sphere->getProgram()->getUniform(Program::MV,  shader.map(Program::MV));

		camera->setLookAt(0, 0, -5.0f, 0, 0, 0, 0.0f, 1.0f, 0.0f);

		camera->rotate(fRotateAngle, 1.0f, 1.0f, 1.0f);
	   	glUniformMatrix4fv(iModelViewLoc, 1, GL_FALSE, (GLfloat*)camera->vPtrForMV());

		fRotateAngle += 0.2f;
	
	}

	sphere->draw();

	
	return true;
}

