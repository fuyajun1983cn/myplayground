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

    //作为动态的Mesh加载
    IAnimatedMesh* mesh = smgr->getMesh("/home/fuyajun/Documents/irrlicht-1.7.2/media/sydney.md2");
    IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode(mesh);

    if (node)
    {
       node->setMD2Animation(EMAT_ATTACK);
       node->setAnimationSpeed(25);
       node->setMaterialFlag(EMF_LIGHTING, false);
       node->setMaterialTexture(0, driver->getTexture("/home/fuyajun/Documents/irrlicht-1.7.2/media/sydney.bmp"));
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
