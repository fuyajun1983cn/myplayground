#include "fyjprogram.h"

using namespace FYJ;


 void checkGlError(const char* op) 
{	 
	for (GLint error = glGetError(); error; error = glGetError()) { 	   
		ERROR("after %s() glError (0x%x)\n", op, error);	
	}
}


Program::Program(const String & vertex,const String & fragment):m_initialized(false) {
	vertexShader = buildShader(vertex, GL_VERTEX_SHADER);
	if (vertexShader) {
		fragmentShader = buildShader(fragment,  GL_FRAGMENT_SHADER);
		if (fragmentShader) {
			id = glCreateProgram();
			checkGlError("glCreateProgram");
			glAttachShader(id, vertexShader);
			glAttachShader(id, fragmentShader);
			glLinkProgram(id);

			GLint status;
			glGetProgramiv(id, GL_LINK_STATUS, &status);
			if (status != GL_TRUE) {
				ERROR("Error while linking shaders!");
				GLint infoLen = 0;
				glGetProgramiv(id, GL_INFO_LOG_LENGTH, &infoLen);
				if (infoLen > 0) {
					GLchar log[infoLen];
					glGetProgramInfoLog(id, infoLen, 0, log);
					ERROR("%s", log);
				}

				glDeleteShader(vertexShader);
				glDeleteShader(fragmentShader);
				glDeleteProgram(id);
			} else {
				m_initialized = true;
			}
		}
	}

	for (int i = 0; i < AttributeType_COUNT; i++)
		attributes[i] = -1;
	for (int i = AttributeType_COUNT; i < UniformType_COUNT; i++)
		uniforms[i - AttributeType_COUNT] = -1;
	
}

Program::~Program()
{
	if (m_initialized) {
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		glDeleteProgram(id);
	}
}

GLuint Program::buildShader(const String & source,GLenum type)
{
	GLuint shader = glCreateShader(type);
	const char *src = source.c_str();
	glShaderSource(shader, 1, &src, 0);
	glCompileShader(shader);

	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE) {
		ERROR("Error while compiling shaders!");
		GLint infoLen = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &infoLen);
		if (infoLen > 0) {
			GLchar log[infoLen];
			glGetShaderInfoLog(id, infoLen, 0, log);
			ERROR("%s", log);
		}
		glDeleteShader(shader);
	}
	return shader;
}

void Program::use()
{
	glUseProgram(id);
	checkGlError("glUseProgram");
	INFO("%d, %s", id, __FILE__);
}

void Program::enableVertexAttribArray()
{
	for (int i = 0; i < AttributeType_COUNT; i++) {
		if (attributes[i] != -1)
			glEnableVertexAttribArray(attributes[i]);
	}
}


void Program::abandon()
{
	glUseProgram(0);
	checkGlError("glUseProgram");
}

GLuint Program::addAttribute(AttributeType type, const String & name)
{
	attributes[type] = glGetAttribLocation(id, name.c_str());
	checkGlError("glGetAttribLocation");
	return attributes[type];
}

GLuint Program::getAttribute(AttributeType type,const String & name)
{
	if (attributes[type] != -1)
		return attributes[type];
	else
		return addAttribute(type, name);
}

GLuint Program::addUniform(UniformType type, const String & name)
{
	INFO("%s", name.c_str());
	uniforms[type-AttributeType_COUNT] = glGetUniformLocation(id, name.c_str());
	checkGlError("glGetUniformLocation");
	return uniforms[type-AttributeType_COUNT];
}

GLuint Program::getUniform(UniformType type,const String & name)
{
	if (uniforms[type-AttributeType_COUNT] != -1)
		return uniforms[type-AttributeType_COUNT];
	else
		return addUniform(type, name);
}


