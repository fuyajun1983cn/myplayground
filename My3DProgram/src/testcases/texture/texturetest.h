#ifndef TEXTURE_TEST_H
#define TEXTURE_TEST_H
#include "testbase.h"

namespace FYJ
{
	class Program;
}

using namespace FYJ;

namespace TEXTURE_TEST
{

class TextureTest : public TestBase
{
	public:
		TextureTest();
		~TextureTest();
		
		bool init() ;
		bool resize(int w, int h) ;
		bool render() ;

	private:
		Program *program;
};
}

#endif
