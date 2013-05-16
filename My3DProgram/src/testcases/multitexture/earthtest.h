#ifndef EARTH_TEST_H
#define EARTH_TEST_H

#include "testbase.h"

namespace FYJ
{
	class Program;
	class Camera;
}

using namespace FYJ;

namespace MULTITEXTURE_TEST
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
		Program *program;
		Camera *camera;
};
}


#endif
