#include "CShaderProgram.h"

CShaderProgram::CShaderProgram()
{
	bLinked = false;
}

CShaderProgram::~CShaderProgram()
{
    //dtor
}

void CShaderProgram::createProgram()
{
	uiProgram = glCreateProgram();
}

bool CShaderProgram::addShaderToProgram(CShader* shShader)
{
	if(!shShader->isLoaded())return false;

	glAttachShader(uiProgram, shShader->getShaderID());

	return true;
}

bool CShaderProgram::linkProgram()
{
	glLinkProgram(uiProgram);
	int iLinkStatus;
	glGetProgramiv(uiProgram, GL_LINK_STATUS, &iLinkStatus);
	bLinked = iLinkStatus == GL_TRUE;
	return bLinked;
}

void CShaderProgram::deleteProgram()
{
	if(!bLinked)return;
	bLinked = false;
	glDeleteProgram(uiProgram);
}

void CShaderProgram::useProgram()
{
	if(bLinked)glUseProgram(uiProgram);
}
