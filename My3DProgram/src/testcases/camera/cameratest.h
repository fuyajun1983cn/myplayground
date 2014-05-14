#ifndef CAMERA_TEST_H
#define CAMERA_TEST_H

#include "testbase.h"
#include "platform.h"

namespace FYJ
{
	class Program;
	class Camera;
}

using namespace FYJ;

namespace CAMERA_TEST
{

class CameraTest : public TestBase
{
	public:
		CameraTest();
		~CameraTest();
		
		bool init() ;
		bool resize(int w, int h) ;
		bool render() ;

	private:
		Program *program;
		GLuint vboID;
		float fRotateAngle;
		Camera *camera;
};
}


#endif
