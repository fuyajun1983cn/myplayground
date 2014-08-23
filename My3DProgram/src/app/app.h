#include "testbase.h"
#include "fyjlist.h"
#include "fyjstring.h"

namespace FYJ
{

	class Application
	{
		public:
			Application();
			virtual ~Application();
			
			bool init();
			
			bool resize(int w, int h);
			
			bool render();
			
			void setInputParameter(const char *key, const char *value);
			void setInputParameter(const char *key, int value);

			void parseParameters();

			void quit();

			TestBase *createTest(TestIds id);
			
		private:

			struct Pair
			{
				String key;
				String value;
			};
			List<Pair> m_input_parameters;

			TestBase *currentTest;

			int m_current_viewport_width;
			int m_current_viewport_height;
	};
}