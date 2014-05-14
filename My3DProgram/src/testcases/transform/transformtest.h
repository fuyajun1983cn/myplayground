#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "testbase.h"
#include "platform.h"

namespace FYJ
{
	class OS;
	class Program;
}

using namespace FYJ;

namespace TRANSFORM_TEST
{
	class TransformTest : public TestBase
	{
	public:
		TransformTest();
		~TransformTest();
		
		bool init() ;
		bool resize(int w, int h) ;
		bool render() ;

	private:
		Program *program;
		GLuint vboID;
		float fRotateAngle;
	};
}

#endif
