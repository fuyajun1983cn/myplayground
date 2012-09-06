#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace video;


int main()
{
    IrrlichtDevice* device = createDevice(EDT_OPENGL, dimension2d<u32>(640, 480), 16,
            false, false, false, 0);

    if (!device)
        return 1;

    IVideoDriver* driver = device->getVideoDriver();
    ITexture* image = driver->getTexture("/home/fuyajun/Documents/irrlicht-1.7.2/media/irrlichtlogo2.png");

    while (device->run())
    {
        driver->beginScene(true, true, SColor(255,255,255,255));
#if 0
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                driver->draw2DImage(image, position2d<s32>(i * 130,
                                                           j * 120),rect<s32>(0, 0, 128,
                                                                              128), 0, SColor(255, 255, 255,
                                                                                              255),true);
            }
        }
 #endif
        driver->draw2DImage(image, position2d<s32>(400, 20),
                                                    rect<s32>(0, 0, 128, 128),
                                                            0, SColor(85, 255, 0, 0), true);
        driver->draw2DImage(image, position2d<s32>(400, 170),
                            rect<s32>(0, 0, 128, 128), 0, SColor(170,
                                                                 0, 255, 0), true);
        driver->draw2DImage(image, position2d<s32>(400, 320),
                            rect<s32>(0, 0, 128, 128), 0, SColor(255,
                                                                 0, 0, 255), true);
        driver->draw2DImage(image, rect<s32>(50, 50, 300, 450),
                            rect<s32>(0, 0, 128, 128),0 , 0, true);

        driver->endScene();
    }

    device->drop();

    return 0;
}
