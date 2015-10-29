#include "CShader.h"

CShader::CShader()
{
    //ctor
    bLoaded = false;
}

CShader::~CShader()
{
    //dtor
}

bool CShader::loadShader(string sFile, int a_iType)
{
   FILE* fp = fopen(sFile.c_str(), "rt");
   if(!fp)return false;

   // Get all lines from a file

   vector<string> sLines;
   char sLine[255];
   while(fgets(sLine, 255, fp))sLines.push_back(sLine);
   fclose(fp);

   const char** sProgram = new const char*[ESZ(sLines)];
   FOR(i, ESZ(sLines))sProgram[i] = sLines[i].c_str();

   uiShader = glCreateShader(a_iType);

   glShaderSource(uiShader, ESZ(sLines), sProgram, NULL);
   glCompileShader(uiShader);

   delete[] sProgram;

   int iCompilationStatus;
   glGetShaderiv(uiShader, GL_COMPILE_STATUS, &iCompilationStatus);

   if(iCompilationStatus == GL_FALSE)return false;
   iType = a_iType;
   bLoaded = true;

   return 1;
}

bool CShader::isLoaded()
{
	return bLoaded;
}

GLuint CShader::getShaderID()
{
	return uiShader;
}

void CShader::deleteShader()
{
	if(!isLoaded())return;
	bLoaded = false;
	glDeleteShader(uiShader);
}
