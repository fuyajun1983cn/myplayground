#ifndef _EARTH_TEST_H
#define _EARTH_TEST_H

#include "testbase.h"

namespace FYJ
{
	class Sphere;
	class Camera;
}

using namespace FYJ;

namespace TEXTURE_TEST
{

class EarthTest : public TestBase
{
	public:
		EarthTest();
		~EarthTest();
		
		bool init() ;
		bool resize(int w, int h) ;
		bool render() ;

	private:
		Sphere *sphere;
		Camera *camera;
};
}


#endif
