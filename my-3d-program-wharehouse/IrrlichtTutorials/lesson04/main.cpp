#include <irrlicht.h>

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;


class MyAnimationEndCallback : public IAnimationEndCallBack
{
public:

    bool isRunning;

    MyAnimationEndCallback()
    {
        isRunning = false;
    }

    virtual void OnAnimationEnd(IAnimatedMeshSceneNode* node)
    {
        if (isRunning)
        {
            node->setMD2Animation(scene::EMAT_STAND);
            isRunning = false;
        }
        else
        {
            node->setMD2Animation(scene::EMAT_RUN);
            isRunning = true;
        }
    }
};

int main()
{
    IrrlichtDevice *device =
        createDevice( video::EDT_SOFTWARE, dimension2d<u32>(640, 480), 16,
            false, false, false, 0);

    if (!device)
        return 1;

    device->setWindowCaption(L"Have a go here: Chapter 3");

    IVideoDriver* driver = device->getVideoDriver();
    ISceneManager* smgr = device->getSceneManager();

    IAnimatedMesh* mesh = smgr->getMesh("/home/fuyajun/Documents/irrlicht-1.7.2/media/sydney.md2");
    if (!mesh)
    {
        device->drop();
        return 1;
    }
    IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode( mesh );

    MyAnimationEndCallback animEndCallback;

    //连续动画
    if (node)
    {
        node->setMaterialFlag(EMF_LIGHTING, false);
        node->setMD2Animation(scene::EMAT_STAND);
        node->setMaterialTexture( 0, driver->getTexture("/home/fuyajun/Documents/irrlicht-1.7.2/media/sydney.bmp") );

        node->setLoopMode(false);
        node->setAnimationEndCallback(&animEndCallback);
    }

    smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));

    while(device->run())
    {
        driver->beginScene(true, true, SColor(255,100,101,140));

        smgr->drawAll();

        driver->endScene();
    }

    device->drop();
    return 0;
}
