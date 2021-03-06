#include "CApp.h"

bool CApp::OnInit()
{
    //设置工程目录
    putenv("PROJECT_PATH=/home/fuyajun/myplayground/qt/morrowland/morrowland/lesson10");

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,            8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,          8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,           8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,          8);

    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,          16);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,            32);

    SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,        8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,    8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,        8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE,    8);

    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,  1);

    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,  2);

    if ((Surf_Display = SDL_SetVideoMode(600, 480, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL)) == NULL) {
        return false;
    }

    if(glewInit()  !=  GLEW_OK)
    {
        CLogger::err("Failed to init glew!");
        return false;
    }

    SDL_WM_SetCaption("Stencil Shadow", NULL);

    groundplane[0] = 0.0f; // The normal of the floor
    groundplane[1] = 1.0f;
    groundplane[2] = 0.0f;
    groundplane[3] = 1.0f;

    lightPosition[0] = 20.0f;
    lightPosition[1] = 50.0f;
    lightPosition[2] = -20.0f;
    lightPosition[3] = 1.0f;

    lightAmbient[0] = 0.5f;
    lightAmbient[1] = 0.5f;
    lightAmbient[2] = 0.5f;
    lightAmbient[3] = 1.0f;

    lightDiffuse[0] = 10.0f;
    lightDiffuse[1] = 10.0f;
    lightDiffuse[2] = 10.0f;
    lightDiffuse[3] = 1.0f;

    lightSpecular[0] = 10.0f;
    lightSpecular[1] = 10.0f;
    lightSpecular[2] = 10.0f;
    lightSpecular[3] = 1.0f;

    CLogger::info("Initializing GL...");

    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


    glEnable(GL_TEXTURE_2D);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Enable light
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR,lightSpecular);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    // set the light posision
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    glPointSize(5);			// Set point size to 5x5


    objCamera.Position_Camera(0,20,100,  0,0,0,  0,1,0);

    if (tex[0].loadTexture2D("texture/image1.bmp")) {
        tex[0].setFiltering(TEXTURE_FILTER_MAG_NEAREST, TEXTURE_FILTER_MIN_NEAREST);
        CLogger::info("load texture 1 successfully!");
    } else {
        CLogger::warn("failed to load texture 1");
    }

    if (tex[1].loadTexture2D("texture/image2.bmp")) {
        tex[1].setFiltering(TEXTURE_FILTER_MAG_NEAREST, TEXTURE_FILTER_MIN_NEAREST);
        CLogger::info("load texture 2 successfully!");
    } else {
        CLogger::warn("failed to load texture 2");
    }


    OnResize(640, 480);

    return true;
}
