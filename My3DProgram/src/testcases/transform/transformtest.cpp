#include "transformtest.h"
#include "platform.h"
#include "os.h"
#include "fyjstring.h"
#include "fyjprogram.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


using namespace TRANSFORM_TEST;
using namespace FYJ;

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

TransformTest::TransformTest():TestBase()
{
	INFO("Entering MyFirstTest...");
	program = fyj_new Program(gVertexShader, gFragmentShader);

	fRotateAngle = 0;
}

TransformTest::~TransformTest()
{
	program->abandon();
	fyj_delete program;
}

bool TransformTest::init()
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

bool TransformTest::resize(int w, int h)
{
	INFO("resize MyFirstTest...");
	glViewport(0, 0, w, h);
	GLuint iProjectionLoc = program->getUniform(Program::PROJECT, "projectionMatrix");
	glUniformMatrix4fv(iProjectionLoc, 1, GL_FALSE, glm::value_ptr(glm::perspective(45.0f,  (float)w/h, 0.01f, 100.0f)));
	return true;
}

bool TransformTest::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);

	GLuint iModelViewLoc = program->getUniform(Program::MV, "modelViewMatrix");
	glm::mat4 mModelView = glm::lookAt(glm::vec3(0, 0, -5.0f), glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	glm::mat4 mCurrent = glm::rotate(mModelView, fRotateAngle, glm::vec3(0.0f, 1.0f, 0.0f));
   	glUniformMatrix4fv(iModelViewLoc, 1, GL_FALSE, glm::value_ptr(mCurrent));
	glDrawArrays(GL_TRIANGLES, 0, 3);

	mCurrent = glm::translate(mModelView, glm::vec3(-2.0f, 0, 0));
	glUniformMatrix4fv(iModelViewLoc, 1, GL_FALSE, glm::value_ptr(mCurrent));
	glDrawArrays(GL_TRIANGLES, 0, 3);

	mCurrent = glm::translate(mModelView, glm::vec3(2.0f, 0, 0));
	mCurrent = glm::scale(mCurrent, glm::vec3(2.0f, 1.5f, 1.0f));
	glUniformMatrix4fv(iModelViewLoc, 1, GL_FALSE, glm::value_ptr(mCurrent));
	glDrawArrays(GL_TRIANGLES, 0, 3);

	fRotateAngle += 0.2f;
	
	return true;
}
