#version 330

in vec2 theTexCoord;
out vec4 outputColor;

uniform sampler2D gSampler;

void main()
{
   outputColor = texture2D(gSampler, theTexCoord);
}
