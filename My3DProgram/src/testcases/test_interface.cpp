#include "testbase.h"
#include "texture/texturetest.h"
#include "transform/transformtest.h"
#include "camera/cameratest.h"
#include "texture/earthtest.h"
#include "multitexture/earthtest.h"
#include "multitexture/multitexturetest.h"
#include "geometry/shapetest.h"
#include "geometry/geometrytest.h"
#include "fps/fpstest.h"
#include "os.h"
#include "test_interface.h"

using namespace TEST_INTERFACE;

FYJ::OS *FYJ::g_os = 0;

TestBase* TEST_INTERFACE::CreateTest( const int id)
{
	TestBase *test;

	switch (id) {
	case FYJ_TextureTest:
		test = fyj_new TEXTURE_TEST::TextureTest();
		break;
	case FYJ_TextureEarthTest:
		test = fyj_new TEXTURE_TEST::EarthTest();
		break;
	case FYJ_TransformTest:
		test = fyj_new TRANSFORM_TEST::TransformTest();
		break;
	case FYJ_CameraTest:
		test = fyj_new CAMERA_TEST::CameraTest();
		break;
	case FYJ_MultiTextureTest:
		test = fyj_new MULTITEXTURE_TEST::MultiTextureTest();
		break;
	case FYJ_MultiTextureEarthTest:
		test = fyj_new MULTITEXTURE_TEST::EarthTest();
		break;
	case FYJ_ShapeTest:
		test = fyj_new GEOMETRY_TEST::ShapeTest();
		break;
	case FYJ_GeometryTest:
		test = fyj_new GEOMETRY_TEST::GeometryTest();
		break;
	case FYJ_FpsTest:
		test = fyj_new FPS_TEST::FpsTest();
		break;
	default:
		test = NULL;
		break;
	}
	return test;
}

void TEST_INTERFACE::InitTest(FYJ::OS * os)
{
	FYJ::g_os = os;
}

