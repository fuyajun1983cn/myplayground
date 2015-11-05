#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace video;
using namespace scene;

int main()
{
    IrrlichtDevice* device = createDevice(EDT_OPENGL, dimension2d<u32>(640, 480), 16,
            false, false, false, 0);

    if (!device)
        return 1;

    IVideoDriver* driver = device->getVideoDriver();
    ISceneManager* smgr = device->getSceneManager();

    //加载mesh
    IMesh* mesh = smgr->getMesh("/home/fuyajun/Documents/irrlicht-1.7.2/media/sydney.md2");
    IMeshSceneNode* node = smgr->addMeshSceneNode(mesh);

    //贴上纹理
    if (node)
    {
       node->setMaterialFlag(EMF_LIGHTING, false);
       node->setMaterialTexture(0, driver->getTexture("/home/fuyajun/Documents/irrlicht-1.7.2/media/sydney.bmp"));

       //操纵对象
       node->setRotation(vector3df(0.0f, -70.0f, 0.0f));
       node->setPosition(vector3df(10.0f, -10.0f, 0.0f));
       node->setScale(vector3df(0.5f, 1.4f, 1.0f));
    }

    smgr->addCameraSceneNode(0, vector3df(0, 30, -40), vector3df(0, 5, 0));

    while (device->run())
    {
        driver->beginScene(true, true, SColor(255,255,255,255));

        smgr->drawAll();

        driver->endScene();
    }

    device->drop();

    return 0;
}
