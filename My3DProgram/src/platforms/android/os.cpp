#include "os.h"

using namespace FYJ;

namespace FYJ
{
	class AndroidOS : public OS
	{
		public:
			AndroidOS();
			void Log( const char *a, ...);
			void Log(int prio, const char *a, ...);

			Image *loadImage(String filename);

			double getTimeMilliSec();

			void sleep(uint32 millisec) ;
	};

	AndroidOS::AndroidOS()
	{
		Log("Testing application on Android!");
	}

	void AndroidOS::sleep(uint32 millisec)
	{
		usleep(millisec*1000);
	}

	double AndroidOS::getTimeMilliSec()
	{
		struct timeval nowtime;
		double s;
		double u;

		gettimeofday( &nowtime, NULL );

		s = nowtime.tv_sec;
		u = nowtime.tv_usec;

		return ( s*1000 + u/1000 );
	}
	void AndroidOS::Log(const char *fmt, ...)
	{
		char buffer[8192];
		int ret;
		va_list args;
		va_start (args, fmt);
		vsprintf (buffer, fmt, args);
		__android_log_print(ANDROID_LOG_INFO, "My3DProgram", "%s ",  buffer);
		va_end (args);
	}

	void AndroidOS::Log(int prio, const char *fmt, ...)
	{
		char buffer[8192];
		int ret;
		va_list args;
		va_start (args, fmt);
		vsprintf (buffer, fmt, args);
		if (prio == OS::LOG_INFO)
			__android_log_print(ANDROID_LOG_INFO, "My3DProgram",  buffer);
		else if (prio == OS::LOG_WARN)
			__android_log_print(ANDROID_LOG_WARN, "My3DProgram", "%s",  buffer);
		else if (prio == OS::LOG_ERROR)
			__android_log_print(ANDROID_LOG_ERROR, "My3DProgram", "%s",  buffer);
		else
			__android_log_print(ANDROID_LOG_INFO, "My3DProgram", "%s ",  buffer);
		va_end (args);
	}

	Image *AndroidOS::loadImage(String filename)
	{
		return loadImageFileFromJava(filename);
	}

	OS* OS::CreateI ()
	{
		AndroidOS *osi = new AndroidOS();		

		return osi;
	}

	void OS::DestroyI( OS** os)
	{
		delete *os;
	}
}
