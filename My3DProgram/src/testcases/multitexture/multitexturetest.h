#ifndef MULTI_TEXTURE_TEST_H
#define MULTI_TEXTURE_TEST_H

#include "testbase.h"

namespace FYJ
{
	class Program;
}

using namespace FYJ;

namespace MULTITEXTURE_TEST
{

class MultiTextureTest : public TestBase
{
	public:
		MultiTextureTest();
		~MultiTextureTest();
		
		bool init() ;
		bool resize(int w, int h) ;
		bool render() ;

	private:
		Program *program;
};
}


#endif
