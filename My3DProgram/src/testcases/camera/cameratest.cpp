#include "cameratest.h"
#include "fyjstring.h"
#include "fyjprogram.h"
#include "os.h"
#include "platform.h"
#include "fyjcamera.h"


using namespace FYJ;
using namespace CAMERA_TEST;

static  String gVertexShader = "uniform mat4 projectionMatrix;\n"
	    "uniform mat4 modelViewMatrix;\n"
	    "attribute vec4 vPosition;\n"    
	    "void main() {\n" 
	   "  gl_Position = projectionMatrix * modelViewMatrix * vPosition;\n"    
	   "}\n";
static  String gFragmentShader = 
             "#ifdef GL_ES\n"
    	    "precision mediump float;\n"
             "#endif\n"
	    "void main() {\n"    
	   "  gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"   
	   "}\n";

static const GLfloat gTriangleVertices[] = { 0.0f, 0.5f, -0.5f, -0.5f,        0.5f, -0.5f };

CameraTest::CameraTest():TestBase()
{
	INFO("Entering MyFirstTest...");
	program = fyj_new Program(gVertexShader, gFragmentShader);

	camera = fyj_new Camera;

	fRotateAngle = 0;
}

CameraTest::~CameraTest()
{
	program->abandon();
	fyj_delete program;
	fyj_delete camera;
}

bool CameraTest::init()
{
	INFO("init MyFirstTest...");

	glClearColor(0, 0, 1, 1.0f);
    	glClearDepthf(1.0f);

	program->use();
	GLuint pos = program->getAttribute(Program::POSITION, "vPosition");
	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
  	glBufferData(GL_ARRAY_BUFFER, 6*sizeof(float), gTriangleVertices, GL_STATIC_DRAW);
	glVertexAttribPointer(pos, 2, GL_FLOAT, GL_FALSE, 0, 0);	
	program->enableVertexAttribArray();

        return true;
}

bool CameraTest::resize(int w, int h)
{
	INFO("resize MyFirstTest...");
	glViewport(0, 0, w, h);
	GLuint iProjectionLoc = program->getUniform(Program::PROJECT, "projectionMatrix");

	camera->setPerspective(45.0f,  (float)w/h, 0.01f, 100.0f);
	glUniformMatrix4fv(iProjectionLoc, 1, GL_FALSE, (GLfloat*)camera->vPtrForProj());
	return true;
}

bool CameraTest::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);

	GLuint iModelViewLoc = program->getUniform(Program::MV, "modelViewMatrix");

	camera->setLookAt(0, 0, -5.0f, 0, 0, 0, 0.0f, 1.0f, 0.0f);

	camera->rotate(fRotateAngle, 0.0f, 1.0f, 0.0f);
   	glUniformMatrix4fv(iModelViewLoc, 1, GL_FALSE, (GLfloat*)camera->vPtrForMV());
	glDrawArrays(GL_TRIANGLES, 0, 3);

	fRotateAngle += 0.2f;

	camera->reset();
	camera->translate(1.0f, 0, 0);
	camera->scale( 1.5f, 2.0f,  1.5f);
	glUniformMatrix4fv(iModelViewLoc, 1, GL_FALSE, (GLfloat*)camera->vPtrForMV());
	glDrawArrays(GL_TRIANGLES, 0, 3);
	
	return true;
}

