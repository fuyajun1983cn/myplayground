#ifndef CSHADER_H
#define CSHADER_H

#include <GL/glew.h>
#include "Defines.h"

class CShader
{
    public:
       bool loadShader(string sFile, int a_iType);
       void deleteShader();

       bool isLoaded();
       GLuint getShaderID();

        CShader();
        virtual ~CShader();

     private:
       GLuint uiShader; // ID of shader
       int iType; // GL_VERTEX_SHADER, GL_FRAGMENT_SHADER...
       bool bLoaded; // Whether shader was loaded and compiled
};


#endif // CSHADER_H
