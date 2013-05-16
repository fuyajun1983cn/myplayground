#ifndef FPS_TEST_H
#define FPS_TEST_H
#include "testbase.h"

namespace FPS_TEST
{

class FpsTest : public TestBase
{
	public:
		FpsTest();
		~FpsTest();
		
		bool init() ;
		bool resize(int w, int h) ;
		bool render() ;

	private:
		int frames;
		double m_preTime;
		double m_curTime;
};
}

#endif
