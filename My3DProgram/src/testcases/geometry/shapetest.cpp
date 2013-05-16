#include "shapetest.h"
#include "platform.h"
#include "os.h"
#include "fyjcamera.h"
#include "fyjgeometry.h"

using namespace FYJ;
using namespace GEOMETRY_TEST;

namespace {
	static float fRotateAngle = 0;

	//triangle
	FYJVector3D tri_vertices[] = {
		FYJVector3D(-1.0f, 0, 0),
		FYJVector3D(1.0f, 0, 0),
		FYJVector3D(0, 1.0f, 0)
	};
	FYJVector4D tri_colors[] = {
		FYJVector4D(1.0f, 0, 0, 1.0f),
		FYJVector4D(0.0f, 1, 0, 1.0f),
		FYJVector4D(0.0f, 0, 1.0f, 1.0f)
	};
	FYJVector2D tri_texCoords[] = {
		FYJVector2D(0, 0),
		FYJVector2D(1, 0),
		FYJVector2D(0.5f, 1)
	};

	//square
	FYJVector3D square_vertices[] = {
		FYJVector3D(-1, -1, 0),
		FYJVector3D(1, -1, 0),
		FYJVector3D(-1, 1, 0),
		FYJVector3D(1, 1, 0)
	};
	FYJVector4D square_colors[] = {
		FYJVector4D(1.0f, 0, 0, 1.0f),
		FYJVector4D(0.0f, 1, 0, 1.0f),
		FYJVector4D(0.0f, 0, 1.0f, 1.0f),
		FYJVector4D(1.0f, 0, 1.0f, 1.0f)
	};
	FYJVector2D square_texCoords[] = {
		FYJVector2D(0, 1),
		FYJVector2D(1, 1),
		FYJVector2D(0, 0),
		FYJVector2D(1, 0)
	};

	//cube
	FYJVector3D cube_vertices[] = {
		FYJVector3D(-1.0f, -1.0f,  1.0f), FYJVector3D(1.0f, -1.0f,  1.0f), FYJVector3D(-1.0f,  1.0f,  1.0f),FYJVector3D(1.0f,  1.0f,  1.0f),
		FYJVector3D(-1.0f, -1.0f, -1.0f), FYJVector3D(-1.0f,  1.0f, -1.0f), FYJVector3D(1.0f,  -1.0f, -1.0f), FYJVector3D(1.0f, 1.0f, -1.0f),
		FYJVector3D(-1.0f,  1.0f, -1.0f), FYJVector3D(-1.0f,  1.0f,  1.0f), FYJVector3D(1.0f,  1.0f,  -1.0f),FYJVector3D(1.0f,  1.0f, 1.0f),
		FYJVector3D(-1.0f, -1.0f, -1.0f), FYJVector3D(1.0f, -1.0f, -1.0f), FYJVector3D(-1.0f, -1.0f,  1.0f), FYJVector3D(1.0f, -1.0f,  1.0f),
		FYJVector3D(1.0f, -1.0f, -1.0f), FYJVector3D(1.0f,  1.0f, -1.0f), FYJVector3D(1.0f,  -1.0f,  1.0f), FYJVector3D(1.0f, 1.0f,  1.0f), 
		FYJVector3D(-1.0f, -1.0f, -1.0f), FYJVector3D(-1.0f, -1.0f,  1.0f), FYJVector3D(-1.0f,  1.0f,  -1.0f), FYJVector3D(-1.0f,  1.0f, 1.0f), 
	};
	
	FYJVector4D cube_colors[] = {
		FYJVector4D(1.0f, 0, 0, 1.0f), FYJVector4D(1.0f, 0, 0, 1.0f), FYJVector4D(1.0f, 0, 0, 1.0f),FYJVector4D(1.0f, 0, 0, 1.0f),
		FYJVector4D(0.0f, 1, 0, 1.0f), FYJVector4D(0.0f, 1, 0, 1.0f), FYJVector4D(0.0f, 1, 0, 1.0f), FYJVector4D(0.0f, 1, 0, 1.0f),
		FYJVector4D(0.0f, 0, 1.0f, 1.0f), FYJVector4D(0.0f, 0, 1.0f, 1.0f), FYJVector4D(0.0f, 0, 1.0f, 1.0f),FYJVector4D(0.0f, 0, 1.0f, 1.0f),
		FYJVector4D(1.0f, 0, 0, 1.0f), FYJVector4D(1.0f, 0, 0, 1.0f), FYJVector4D(1.0f, 0, 0, 1.0f),FYJVector4D(1.0f, 0, 0, 1.0f),
		FYJVector4D(0.0f, 1, 0, 1.0f), FYJVector4D(0.0f, 1, 0, 1.0f), FYJVector4D(0.0f, 1, 0, 1.0f), FYJVector4D(0.0f, 1, 0, 1.0f),
		FYJVector4D(0.0f, 0, 1.0f, 1.0f), FYJVector4D(0.0f, 0, 1.0f, 1.0f), FYJVector4D(0.0f, 0, 1.0f, 1.0f),FYJVector4D(0.0f, 0, 1.0f, 1.0f),
	};
	
	FYJVector2D cube_texCoords[] = {
		FYJVector2D(1.0f, 1.0f), FYJVector2D(1.0f, 0.0f), FYJVector2D(0.0f, 1.0f),FYJVector2D(0.0f, 0.0f),
		FYJVector2D(1.0f, 1.0f), FYJVector2D(1.0f, 0.0f), FYJVector2D(0.0f, 1.0f),FYJVector2D(0.0f, 0.0f),
		FYJVector2D(1.0f, 1.0f), FYJVector2D(1.0f, 0.0f), FYJVector2D(0.0f, 1.0f),FYJVector2D(0.0f, 0.0f),
		FYJVector2D(1.0f, 1.0f), FYJVector2D(1.0f, 0.0f), FYJVector2D(0.0f, 1.0f),FYJVector2D(0.0f, 0.0f),
		FYJVector2D(1.0f, 1.0f), FYJVector2D(1.0f, 0.0f), FYJVector2D(0.0f, 1.0f),FYJVector2D(0.0f, 0.0f),
		FYJVector2D(1.0f, 1.0f), FYJVector2D(1.0f, 0.0f), FYJVector2D(0.0f, 1.0f),FYJVector2D(0.0f, 0.0f),
	};

//	Triangle * tri ;
	
//	Square *square ;

//	Cube *cube;

//	Sphere *sphere;
	Torus *torus;

}

ShapeTest::ShapeTest()
{
	shape = NULL;
//	tri = fyj_new Triangle(false, false, true);
//	tri->setup(FYJ_SHADER_TEXTURE);

//	square = fyj_new Square(false, false, true);
//	square->setup(FYJ_SHADER_TEXTURE);

//	cube = fyj_new Cube(false, false, true);
//	cube->setup(FYJ_SHADER_TEXTURE);

//	sphere = fyj_new Sphere(1.0f, 30, 45, false, true, true);
//	sphere->setColor(FYJVector4D(0, 1, 1, 1));
//	sphere->setup(FYJ_SHADER_TEXTURE, false);
//	sphere->setup();

	torus = fyj_new Torus(2, 1, 40, 30);
	torus->setup(FYJ_SHADER_TEXTURE, false);

	camera = fyj_new Camera;
}

ShapeTest::~ShapeTest()
{
//	fyj_delete tri;
//	fyj_delete square;
//	fyj_delete cube;
//	fyj_delete sphere;
	fyj_delete torus;
	if (shape != NULL)
		fyj_delete shape;
	if (camera != NULL)
		fyj_delete camera;
}

bool ShapeTest::init() 
{
	shape = torus;
	if (shape->isTextured()) {
		Image *img = g_os->loadImage("earth_color.png");
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
	}
	

	glClearDepthf(1.0f);
	glDepthFunc(GL_LEQUAL); 
	glEnable(GL_DEPTH_TEST);
	glClearColor(0, 0, 0.5f, 1);

//	glEnable(GL_CULL_FACE);
	
//	glFrontFace(GL_CCW);
	
}

bool ShapeTest::resize(int w, int h) 
{
	glViewport(0, 0, w, h);
	Shader shader = shape->getShader();
	if (shader.PROJECTION.empty())
		return true;

	GLuint iProjectionLoc = shape->getProgram()->getUniform(Program::PROJECT,  shader.map(Program::PROJECT));
	INFO("iProjecttionLoc = %d", iProjectionLoc);
	
	camera->setPerspective(45.0f,  (float)w/h, 0.01f, 100.0f);
	glUniformMatrix4fv(iProjectionLoc, 1, GL_FALSE, (GLfloat*)camera->vPtrForProj());
	return true;
}

bool ShapeTest::render() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Shader shader = shape->getShader();
	if (!shader.MV.empty()) {
	GLuint iModelViewLoc = shape->getProgram()->getUniform(Program::MV,  shader.map(Program::MV));

	camera->setLookAt(0, 0, -5.0f, 0, 0, 0, 0.0f, 1.0f, 0.0f);

	camera->rotate(fRotateAngle, 1.0f, 1.0f, 1.0f);
   	glUniformMatrix4fv(iModelViewLoc, 1, GL_FALSE, (GLfloat*)camera->vPtrForMV());

	fRotateAngle += 0.2f;
	
	}

	shape->draw();

}
