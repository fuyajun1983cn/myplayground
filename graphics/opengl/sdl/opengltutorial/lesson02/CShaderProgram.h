#ifndef CSHADERPROGRAM_H
#define CSHADERPROGRAM_H

#include <GL/glew.h>
#include "CShader.h"

class CShaderProgram
{
    public:
        void createProgram();
        void deleteProgram();

        bool addShaderToProgram(CShader* shShader);
        bool linkProgram();

        void useProgram();

        GLuint getProgramID();
        CShaderProgram();
        virtual ~CShaderProgram();

    private:
        GLuint uiProgram; // ID of program
        bool bLinked; // Whether program was linked and is ready to use
};

#endif // CSHADERPROGRAM_H
