#ifndef TESTBASE_H
#define TESTBASE_H

enum TestIds 
{
	FYJ_UnknownTest							= 0,
	FYJ_TextureTest							= 1001,
	FYJ_TextureEarthTest                                              = 1002,
	FYJ_MultiTextureTest                                               = 1003,
	FYJ_MultiTextureEarthTest                                     = 1004,
	FYJ_TransformTest						= 2001,
	FYJ_CameraTest							= 3001,
	FYJ_LightingTest                                                       = 4001,
	//geometry test
	FYJ_ShapeTest						= 5001,
	FYJ_GeometryTest                                            =5002,
	//fps
	FYJ_FpsTest                                                      = 6001,

};


class TestBase
{
	public:
		TestBase() {}
		virtual ~TestBase() {}
		
		virtual bool init() = 0;
		virtual bool resize(int w, int h) = 0;
		virtual bool render() = 0;
		virtual int getTestID() { return testID; }
		virtual void setTestID(int ID) { testID = ID; }
		
	protected:
		int testID;
};

#endif
