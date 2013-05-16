#ifndef TRIANGLE_TEST_H
#define TRIANGLE_TEST_H

#include "testbase.h"

namespace FYJ
{
	class Shape;
	class Camera;
}

using namespace FYJ;

namespace GEOMETRY_TEST
{

class ShapeTest : public TestBase
{
	public:
		ShapeTest();
		~ShapeTest();
		
		bool init() ;
		bool resize(int w, int h) ;
		bool render() ;

	private:
		Shape *shape;
		Camera *camera;
};
}


#endif
