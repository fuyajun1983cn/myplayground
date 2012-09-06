#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace video;
using namespace gui;


int main()
{
    IrrlichtDevice* device = createDevice(EDT_OPENGL, dimension2d<u32>(640, 480), 16,
            false, false, false, 0);

    if (!device)
        return 1;

    IVideoDriver* driver = device->getVideoDriver();
    IGUIEnvironment* guienv = device->getGUIEnvironment();
    IGUIFont* font = guienv->getFont("/home/fuyajun/Documents/irrlicht-1.7.2/media/lucida.xml");

    //使用内置的字体
    guienv->addStaticText(L"Hello World!", rect<s32>(100,20,200,30), true);

    while (device->run())
    {
        driver->beginScene(true, true, SColor(255,128,128,128));

        guienv->drawAll();

        //使用外部字体
        font->draw(L"Another text", rect<s32>(300,300,300,50), SColor(255,255,255,255));

        driver->endScene();
    }

    device->drop();

    return 0;
}
