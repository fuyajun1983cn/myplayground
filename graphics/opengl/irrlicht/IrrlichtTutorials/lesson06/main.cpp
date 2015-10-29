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
    ITexture* image = driver->getTexture("/home/fuyajun/Documents/irrlicht-1.7.2/media/robot.png");
    //设置背景透明
    driver->makeColorKeyTexture(image, position2d<s32>(0, 0));

    int currentFrame = 0;
    int row = 0;

    while (device->run())
    {
        u32 time = device->getTimer()->getTime();
        if ((time % 25) == 0) currentFrame++;
        if (currentFrame >= 31)
        {
            currentFrame = 0;
            row++;
        }
        if (row >= 7) row = 0;

        driver->beginScene(true, true, SColor(255,200,200,200));

        driver->draw2DImage(image, position2d<s32>(200, 200), rect<s32>(currentFrame * 64, row * 64, (currentFrame + 1) * 64, (row + 1) * 64), 0, SColor(255, 255, 255, 255), true);

        driver->endScene();
    }

    device->drop();

    return 0;
}
