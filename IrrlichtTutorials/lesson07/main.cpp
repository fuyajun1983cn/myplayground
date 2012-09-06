#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace video;

//绘制2D几何图形

int main()
{
    IrrlichtDevice* device = createDevice(EDT_OPENGL, dimension2d<u32>(640, 480), 16,
            false, false, false, 0);

    if (!device)
        return 1;

      IVideoDriver* driver = device->getVideoDriver();

    int vertexCount = 3;

    while (device->run())
    {
        u32 time = device->getTimer()->getTime();
        if ((time % 1000) == 0) vertexCount++;
        if (vertexCount >= 16) vertexCount = 3;

        driver->beginScene(true, true, SColor(255,200,200,200));

        driver->draw2DPolygon(position2d<s32>(320, 240), 50.0 + (vertexCount * 10.0), SColor(255, 0, 0, 0), vertexCount);

        //draw 2d primitives
        driver->draw2DRectangle(SColor(255, 255, 128, 64), rect<s32>(40,
        40, 200, 200));
        driver->draw2DRectangle(rect<s32>(250, 150, 500, 450), SColor(64,
        128, 128, 128), SColor(128, 192, 192,
        192), SColor(255, 0, 255, 0), SColor(255,
        255, 0, 0));
        driver->draw2DPolygon(position2d<s32>(100, 300), 50.0f,
        SColor(128, 40, 80, 160), 6);
        driver->draw2DLine(position2d<s32>(20, 20), position2d<s32>(620,
        460), SColor(255, 0, 255, 255));


        driver->endScene();
    }

    device->drop();

    return 0;
}
