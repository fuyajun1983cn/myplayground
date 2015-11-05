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

   float fPyramid[54];
   float fPyramidColor[54];

// Setup pyramid vertices
   fPyramid[0] = -0.2f; fPyramid[1] = 0.0f; fPyramid[2] = 0.2f;
   fPyramid[3] = 0.2f; fPyramid[4] = 0.0f; fPyramid[5] = 0.2f;
   fPyramid[6] = 0.2f; fPyramid[7] = 0.0f; fPyramid[8] = -0.2f;

   fPyramid[9] = -0.2f; fPyramid[10] = 0.0f; fPyramid[11] =-0.2f;
   fPyramid[12] = 0.2f; fPyramid[13] = 0.0f; fPyramid[14] = -0.2f;
   fPyramid[15] = -0.2f; fPyramid[16] = 0.0f; fPyramid[17] = 0.2f;

    fPyramid[18] = -0.2f; fPyramid[19] = 0.0f; fPyramid[20] = 0.2f;
   fPyramid[21] = 0.2f; fPyramid[22] = 0.0f; fPyramid[23] = 0.2f;
   fPyramid[24] = 0.0f; fPyramid[25] = 0.5f; fPyramid[26] = 0.0f;

   fPyramid[27] =  -0.2f; fPyramid[28] = 0.0f; fPyramid[29] = -0.2f;
   fPyramid[30] = 0.2f; fPyramid[31] = 0.0f; fPyramid[32] = -0.2f;
   fPyramid[33] = 0.0f; fPyramid[34] = 0.5f; fPyramid[35] = 0.0f;

   fPyramid[36] = -0.2f; fPyramid[37] = 0.0f; fPyramid[38] =0.2f;
   fPyramid[39] = -0.2f; fPyramid[40] = 0.0f; fPyramid[41] =-0.2f;
   fPyramid[42] = 0.0f; fPyramid[43] = 0.5f; fPyramid[44] = 0.0f;

    fPyramid[45] = 0.2f; fPyramid[46] = 0.0f; fPyramid[47] =0.2f;
   fPyramid[48] = 0.2f; fPyramid[49] = 0.0f; fPyramid[50] =-0.2f;
   fPyramid[51] = 0.0f; fPyramid[52] = 0.5f; fPyramid[53] = 0.0f;

   // Setup pyramid color

   fPyramidColor[0] = 1.0f; fPyramidColor[1] = 0.0f; fPyramidColor[2] = 0.0f;
   fPyramidColor[3] = 0.0f; fPyramidColor[4] = 1.0f; fPyramidColor[5] = 0.0f;
   fPyramidColor[6] = 0.0f; fPyramidColor[7] = 0.0f; fPyramidColor[8] = 1.0f;

   fPyramidColor[9] = 1.0f; fPyramidColor[10] = 0.0f; fPyramidColor[11] = 0.0f;
   fPyramidColor[12] = 0.0f; fPyramidColor[13] = 1.0f; fPyramidColor[14] = 0.0f;
   fPyramidColor[15] = 1.0f; fPyramidColor[16] = 1.0f; fPyramidColor[17] = 1.0f;


    fPyramidColor[18] = 1.0f; fPyramidColor[19] = 0.0f; fPyramidColor[20] = 0.0f;
   fPyramidColor[21] = 0.0f; fPyramidColor[22] = 1.0f; fPyramidColor[23] = 0.0f;
   fPyramidColor[24] = 0.0f; fPyramidColor[25] = 0.0f; fPyramidColor[26] = 0.0f;

   fPyramidColor[27] = 0.0f; fPyramidColor[28] = 0.0f; fPyramidColor[29] = 1.0f;
   fPyramidColor[30] = 1.0f; fPyramidColor[31] = 1.0f; fPyramidColor[32] = 1.0f;
   fPyramidColor[33] = 0.0f; fPyramidColor[34] = 0.0f; fPyramidColor[35] = 0.0f;

   fPyramidColor[36] = 1.0f; fPyramidColor[37] = 0.0f; fPyramidColor[38] = 0.0f;
   fPyramidColor[39] = 0.0f; fPyramidColor[40] = 0.0f; fPyramidColor[41] = 1.0f;
   fPyramidColor[42] = 0.0f; fPyramidColor[43] = 0.0f; fPyramidColor[44] = 0.0f;

   fPyramidColor[45] = 0.0f; fPyramidColor[46] = 1.0f; fPyramidColor[47] = 0.0f;
   fPyramidColor[48] = 1.0f; fPyramidColor[49] = 1.0f; fPyramidColor[50] = 1.0f;
   fPyramidColor[51] = 0.0f; fPyramidColor[52] = 0.0f; fPyramidColor[53] = 0.0f;

   glGenVertexArrays(1, uiVAO); // Generate two VAOs, one for triangle and one for quad
   glGenBuffers(2, uiVBO); // And four VBOs

   // Setup whole triangle
   glBindVertexArray(uiVAO[0]);

   glBindBuffer(GL_ARRAY_BUFFER, uiVBO[0]);
   glBufferData(GL_ARRAY_BUFFER, 54*sizeof(float), fPyramid, GL_STATIC_DRAW);
   glEnableVertexAttribArray(0);
   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

   glBindBuffer(GL_ARRAY_BUFFER, uiVBO[1]);
   glBufferData(GL_ARRAY_BUFFER, 54*sizeof(float), fPyramidColor, GL_STATIC_DRAW);
   glEnableVertexAttribArray(1);
   glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

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
