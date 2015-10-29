#include "CApp.h"

bool CApp::OnInit()
{
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

    if ((Surf_Display = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL)) == NULL) {
        return false;
    }

    if(glewInit()  !=  GLEW_OK)
    {
        printf("Failed to init glew!\n");
        return false;
    }

    glClearDepth(1.0f);

    glViewport(0, 0, 640, 480);

   glClearColor(0.0f, 0.5f, 1.0f, 1.0f);

   glGenVertexArrays(1, &uiVAOHeightmap);
   glGenBuffers(1, &uiVBOHeightmapData);
   glGenBuffers(1, &uiVBOIndices);

    glBindVertexArray(uiVAOHeightmap);
    glBindBuffer(GL_ARRAY_BUFFER, uiVBOHeightmapData);

    glm::vec3 vHeightmapData[HM_SIZE_X*HM_SIZE_Y]; // Here the heightmap vertices will be stored temporarily

    float fHeights[HM_SIZE_X*HM_SIZE_Y] =
    {
       4.0f, 2.0f, 3.0f, 1.0f,
       3.0f, 5.0f, 8.0f, 2.0f,
       7.0f, 10.0f, 12.0f, 6.0f,
       4.0f, 6.0f, 8.0f, 3.0f
    };

    float fSizeX = 40.0f, fSizeZ = 40.0f;

    FOR(i, HM_SIZE_X*HM_SIZE_Y)
    {
       float x = float(i%HM_SIZE_X), z = float(i/HM_SIZE_X);
       vHeightmapData[i] = glm::vec3(
          -fSizeX/2+fSizeX*x/float(HM_SIZE_X-1), // X Coordinate
          fHeights[i],                           // Y Coordinate (it's height)
          -fSizeZ/2+fSizeZ*z/float(HM_SIZE_Y-1)   // Z Coordinate
          );
    }

    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*HM_SIZE_X*HM_SIZE_Y, vHeightmapData, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, uiVBOIndices);
    int iIndices[] =
    {
       0, 4, 1, 5, 2, 6, 3, 7, 7, 4 ,// First row, then restart
       4, 8, 5, 9, 6, 10, 7, 11, 11, 8, // Second row, then restart
       8, 12, 9, 13, 10, 14, 11, 15 // Third row, no restart
    };
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(iIndices), iIndices, GL_STATIC_DRAW);
  //  glEnable(GL_PRIMITIVE_RESTART);
  //  glPrimitiveRestartIndex(HM_SIZE_X*HM_SIZE_Y);

   // Load shaders and create shader program
   shVertex.loadShader("shaders/shader.vert", GL_VERTEX_SHADER);
   shFragment.loadShader("shaders/shader.frag", GL_FRAGMENT_SHADER);

   spMain.createProgram();
   spMain.addShaderToProgram(&shVertex);
   spMain.addShaderToProgram(&shFragment);

   spMain.linkProgram();
   spMain.useProgram();

   fRotationAngle = 0;

    return true;
}
