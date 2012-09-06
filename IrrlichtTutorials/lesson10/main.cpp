#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace video;

IrrlichtDevice* device;
ITexture* image;

vector2d<f32> position; //current position
vector2d<f32> target; //mouse click positions
vector2d<f32> direction;

f32 speed = 0.2f; //球的移动速度
s32 screenWidth = 640;
s32 screenHeight = 480;

class MyEventReceiver: public IEventReceiver
{
public:
    virtual bool OnEvent(const SEvent& event)
    {
        if (event.EventType == EET_MOUSE_INPUT_EVENT)
        {
            if (event.MouseInput.isLeftPressed())
            {
                target.X = (f32)event.MouseInput.X;
                target.Y = (f32)event.MouseInput.Y;

                direction = target - position;
                direction.normalize();//方向向量
            }
        }
        return false;
    }
};

void update(f32 deltaTime)
{
    position += (speed * deltaTime) * direction;
    if (position.X > screenWidth - image->getSize().Width ||
        position.X < 0)
        direction.X *= -1;

    if (position.Y > screenHeight - image->getSize().Height ||
        position.Y < 0)
        direction.Y *= -1;
}

int main()
{
    device = createDevice(EDT_OPENGL, dimension2d<u32>(screenWidth, screenHeight), 16,
                                          false, false, false, 0);
    if (!device)
        return 1;

    IVideoDriver* driver = device->getVideoDriver();

    MyEventReceiver receiver;
    device->setEventReceiver(&receiver);

    image = driver->getTexture("/home/fuyajun/Documents/irrlicht-1.7.2/media/fireball.bmp");

    position.set(0,0);
    direction.set(1,1);

    u32 then = device->getTimer()->getTime();

    while (device->run())
    {
        const u32 now = device->getTimer()->getTime();
        const f32 deltaTime = (f32)(now - then);
        then = now;

        update(deltaTime);

        driver->beginScene(true, true, SColor(255,255,255,255));

        driver->draw2DImage(image, position2d<s32>((s32)position.X, (s32)position.Y), rect<s32>(0, 0, 32, 32), 0, SColor(255, 255, 255, 255), true);

        driver->endScene();

        core::stringw str = L"x: ";
        str += target.X;
        str += ", y: ";
        str += target.Y;
        str += ", posX: ";
        str += position.X;
        str += ", posY: ";
        str += position.Y;

        device->setWindowCaption(str.c_str());
    }

    device->drop();

    return 0;
}
