#include "fpstest.h"
#include "platform.h"
#include "os.h"

using namespace FYJ;
using namespace FPS_TEST;

FpsTest::FpsTest()
{
	frames = 0;
	m_curTime = m_preTime = 0;
}

FpsTest::~FpsTest()
{

}

bool FpsTest::init() 
{
	return true;
}

bool FpsTest::resize(int w, int h) 
{
	glViewport(0, 0, w, h);
	
	return true;
}

bool FpsTest::render() 
{
	m_curTime = GetCurrentTime();
	double diff_time = m_curTime - m_preTime;	
//	INFO("diff_time = %f", diff_time);
	if (diff_time >= 2000) {
		double fps = (double)frames/diff_time * 2000;
		INFO("FPS: %f", fps);
		frames = 0;
		m_preTime = m_curTime;
	}
	
	frames++;

	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT );
}

