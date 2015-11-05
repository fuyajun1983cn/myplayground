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

    if ((Surf_Display = SDL_SetVideoMode(600, 600, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL)) == NULL) {
        return false;
    }

    if(glewInit()  !=  GLEW_OK)
    {
        printf("Failed to init glew!\n");
        return false;
    }

    glClearColor(0, 0, 0, 0);
    glClearDepth(1.0f);

    glViewport(0, 0, 640, 480);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-1, 1, -1, 1, 1, -1);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

   glClearColor(0.0f, 0.5f, 1.0f, 1.0f);

   float fTriangle[9]; // Data to render triangle (3 vertices, each has 3 floats)
   float fQuad[12]; // Data to render quad using triangle strips (4 vertices, each has 3 floats)
    float fTriangleColor[9];
    float fQuadColor[12];

// Setup triangle vertices
   fTriangle[0] = -0.4f; fTriangle[1] = 0.1f; fTriangle[2] = 0.0f;
   fTriangle[3] = 0.4f; fTriangle[4] = 0.1f; fTriangle[5] = 0.0f;
   fTriangle[6] = 0.0f; fTriangle[7] = 0.7f; fTriangle[8] = 0.0f;

   // Setup triangle color

   fTriangleColor[0] = 1.0f; fTriangleColor[1] = 0.0f; fTriangleColor[2] = 0.0f;
   fTriangleColor[3] = 0.0f; fTriangleColor[4] = 1.0f; fTriangleColor[5] = 0.0f;
   fTriangleColor[6] = 0.0f; fTriangleColor[7] = 0.0f; fTriangleColor[8] = 1.0f;

   // Setup quad vertices

   fQuad[0] = -0.2f; fQuad[1] = -0.1f; fQuad[2] = 0.0f;
   fQuad[3] = -0.2f; fQuad[4] = -0.6f; fQuad[5] = 0.0f;
   fQuad[6] = 0.2f; fQuad[7] = -0.1f; fQuad[8] = 0.0f;
   fQuad[9] = 0.2f; fQuad[10] = -0.6f; fQuad[11] = 0.0f;

   // Setup quad color

   fQuadColor[0] = 1.0f; fQuadColor[1] = 0.0f; fQuadColor[2] = 0.0f;
   fQuadColor[3] = 0.0f; fQuadColor[4] = 1.0f; fQuadColor[8] = 0.0f;
   fQuadColor[6] = 0.0f; fQuadColor[7] = 0.0f; fQuadColor[5] = 1.0f;
   fQuadColor[9] = 1.0f; fQuadColor[10] = 1.0f; fQuadColor[11] = 0.0f;

   glGenVertexArrays(2, uiVAO); // Generate two VAOs, one for triangle and one for quad
   glGenBuffers(4, uiVBO); // And four VBOs

   // Setup whole triangle
   glBindVertexArray(uiVAO[0]);

   glBindBuffer(GL_ARRAY_BUFFER, uiVBO[0]);
   glBufferData(GL_ARRAY_BUFFER, 9*sizeof(float), fTriangle, GL_STATIC_DRAW);
   glEnableVertexAttribArray(0);
   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

   glBindBuffer(GL_ARRAY_BUFFER, uiVBO[1]);
   glBufferData(GL_ARRAY_BUFFER, 9*sizeof(float), fTriangleColor, GL_STATIC_DRAW);
   glEnableVertexAttribArray(1);
   glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

   // Setup whole quad
   glBindVertexArray(uiVAO[1]);

   glBindBuffer(GL_ARRAY_BUFFER, uiVBO[2]);
   glBufferData(GL_ARRAY_BUFFER, 12*sizeof(float), fQuad, GL_STATIC_DRAW);
   glEnableVertexAttribArray(0);
   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

   glBindBuffer(GL_ARRAY_BUFFER, uiVBO[3]);
   glBufferData(GL_ARRAY_BUFFER, 12*sizeof(float), fQuadColor, GL_STATIC_DRAW);
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

    return true;
}
