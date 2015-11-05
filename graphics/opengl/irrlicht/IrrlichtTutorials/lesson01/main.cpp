#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace video;

int main()
{
    //创建设备,颜色深度16,
    IrrlichtDevice *device = createDevice(EDT_OPENGL, dimension2d<u32>(640, 480), 16,
                 false/*不全屏*/, false/*关闭stencil buffer*/, false/*不与视频同步*/, 0);

    if (!device)
        return 1;

    device->setWindowCaption(L"不停变化的背景色");

    IVideoDriver* driver = device->getVideoDriver();

    f32 bg_r = 255.0f;
    f32 bg_g = 255.0f;
    f32 bg_b = 255.0f;

    bool fadeOut = true;

    int lastFPS = -1;

    u32 then = device->getTimer()->getTime();

    const f32 fadeRate = 0.1f;

    while(device->run())
    {
        const u32 now = device->getTimer()->getTime();
        const f32 frameDeltaTime = (f32)(now - then);
        then = now;

        if (bg_r <= 0.0f) fadeOut = false;
        else if (bg_r >= 255.0f) fadeOut = true;

        if (fadeOut)
        {
            bg_r-= fadeRate * frameDeltaTime;
            bg_g-= fadeRate * frameDeltaTime;
            bg_b-= fadeRate * frameDeltaTime;
        }
        else
        {
            bg_r+= fadeRate * frameDeltaTime;
            bg_g+= fadeRate * frameDeltaTime;
            bg_b+= fadeRate * frameDeltaTime;
        }

        driver->beginScene(true, true, SColor(255, (u32)bg_r, (u32)bg_g, (u32)bg_b));

        driver->endScene();
    }

    device->drop();

    return 0;
}
