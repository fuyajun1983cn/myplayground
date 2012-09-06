#version 330

smooth in vec3 thePosition;
out vec4 outputColor;

void main()
{
	outputColor = vec4(0.0, thePosition.y/12.0, 0.0, 1.0);
}
