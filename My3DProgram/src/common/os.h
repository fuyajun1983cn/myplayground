#ifndef OS_H
#define OS_H

#include "platform.h"

#define INFO(...)  FYJ::g_os->Log( __VA_ARGS__)
#define WARN(...)  FYJ::g_os->Log(FYJ::OS::LOG_WARN, __VA_ARGS__)
#define ERROR(...) FYJ::g_os->Log(FYJ::OS::LOG_ERROR, __VA_ARGS__)
#define GetCurrentTime() FYJ::g_os->getTimeMilliSec()
#define Sleep(x)  FYJ::g_os->sleep(x)

namespace FYJ
{
	class OS
	{
		public:
			enum {
				LOG_INFO = 1,
				LOG_WARN,
				LOG_ERROR
			};
			virtual void Log( const char *a, ...) = 0;
			virtual void Log(int prio, const char *a, ...) = 0;

			virtual Image *loadImage(String filename) = 0;

			virtual double getTimeMilliSec() = 0;

			virtual void sleep(uint32 millisec) = 0;

			static OS* CreateI();
			static void DestroyI( OS** os);
		protected:
			OS() {};
			virtual ~OS() {};
	};

	extern OS *g_os;
}

#endif
