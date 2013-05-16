#ifndef TEST_INTERFACE_H
#define TEST_INTERFACE_H

class TestBase;

namespace TEST_INTERFACE
{
	 TestBase* CreateTest( const int id);
	 void InitTest(FYJ::OS *os);
}


#endif
