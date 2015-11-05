#version 330

uniform mat4 projectionMatrix;
uniform mat4 modelViewMatrix;

layout (location = 0) in vec3 inPosition;

smooth out vec3 thePosition; // Interpolate position among fragments

void main()
{
	gl_Position = projectionMatrix*modelViewMatrix*vec4(inPosition, 1.0);
	thePosition = inPosition;
}
