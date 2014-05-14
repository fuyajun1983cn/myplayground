#ifndef GEOMETRY_TEST_H 
#define GEOMETRY_TEST_H 
#include "testbase.h"
#include "platform.h"

namespace FYJ
{
	class Program;
	class Camera;
}

using namespace FYJ;

namespace GEOMETRY_TEST
{

class GeometryTest : public TestBase
{
	public:
		GeometryTest();
		~GeometryTest();
		
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
