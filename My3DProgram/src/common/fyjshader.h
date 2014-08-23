#ifndef FYJ_SHADER_H
#define FYJ_SHADER_H
#include "fyjstring.h"
#include "fyjprogram.h"

namespace FYJ
{
	struct Shader
	{
		String VS;//vertex shader
		String FS; //fragment shader

		//attributes
		String POSITION;
		String NORMAL;
		String COLOR;
		String TEX_COORD0;
		String TEX_COORD1;
		String TEX_COORD2;
		String TEX_COORD3;

		//uniforms
		String COLOR2;
		String MV;
		String PROJECTION;
		String TEX_UNIT0;
		String TEX_UNIT1;
		String TEX_UNIT2;
		String TEX_UNIT3;

		public:
			String map(int type) {
				switch (type) {
				case Program::TEX_COORD0:
					return TEX_COORD0;
				case Program::TEX_COORD1:
					return TEX_COORD1;
				case Program::TEX_COORD2:
					return TEX_COORD2;
				case Program::TEX_COORD3:
					return TEX_COORD3;
				case Program::SAMPLER2D:
					return TEX_UNIT0;
				case Program::SAMPLER2D_1:
					return TEX_UNIT1;
				case Program::SAMPLER2D_2:
					return TEX_UNIT2;
				case Program::SAMPLER2D_3:
					return TEX_UNIT3;
				case Program::MV:
					return MV;
				case Program::PROJECT:
					return PROJECTION;
				}
			}
	};
	///////////////////////////////////////////////////////////////////////////////
	// Identity Shader (GLT_SHADER_IDENTITY)
	// This shader does no transformations at all, and uses the current
	// glColor value for fragments.
	// It will shade between verticies.
	static String sIdentityShaderVP = "attribute vec4 a_Position;\n"
							  	"void main(void) \n"
							 	"{ gl_Position = a_Position; \n"
							  	"}\n";
										
	static String sIdentityShaderFP = "#ifdef GL_ES \n"
							 "precision mediump float;\n"
							 "#endif \n"
							 "void main(void) \n"
							 "{ gl_FragColor = vec4(1.0, 0, 0, 1.0); \n"
							 "}";
	const Shader FYJ_SHADER_IDENTITY= {sIdentityShaderVP, 
										sIdentityShaderFP,
										//attributes
										"a_Position",  //POSITION
										"",    //NORMAL
										"",  //COLOR
										"", // TEX_COORD0
										"", //TEX_COORD1
										"", //TEX_COORD2
										"", //TEX_COORD3
										//uniforms
										"",//COLOR2
										"",  //MV
										"",  //PROJECTION
										"", //TEX_UNIT0
										"", //TEX_UNIT1
										"", //TEX_UNIT2
										""  //TEX_UNIT3
										};


	
	//color
	static String sColorShaderVP = "attribute vec4 a_Position;\n"
								"attribute vec4 a_Color;\n"
								"varying vec4 v_Color;\n"
							  	"void main(void) \n"
							 	"{ gl_Position = a_Position; \n"
							 	"v_Color = a_Color;\n"
							  	"}\n";
										
	static String sColorShaderFP = "#ifdef GL_ES \n"
							 "precision mediump float;\n"
							 "#endif \n"
							 "varying vec4 v_Color;\n"
							 "void main(void) \n"
							 "{ gl_FragColor = v_Color; \n"
							 "}";
	const Shader FYJ_SHADER_COLOR = {sColorShaderVP, 
										sColorShaderFP,
										//attributes
										"a_Position",  //POSITION
										"",    //NORMAL
										"a_Color",  //COLOR
										"", // TEX_COORD0
										"", //TEX_COORD1
										"", //TEX_COORD2
										"", //TEX_COORD3
										//uniforms
										"",//COLOR2
										"",  //MV
										"",  //PROJECTION
										"", //TEX_UNIT0
										"", //TEX_UNIT1
										"", //TEX_UNIT2
										""  //TEX_UNIT3
										};

		//color2
	static String sColor2ShaderVP = "attribute vec4 a_Position;\n"
							  	"void main(void) \n"
							 	"{ gl_Position = a_Position; \n"
							  	"}\n";
										
	static String sColor2ShaderFP = "#ifdef GL_ES \n"
							 "precision mediump float;\n"
							 "#endif \n"
							 "uniform vec4 u_Color;\n"
							 "void main(void) \n"
							 "{ gl_FragColor = u_Color; \n"
							 "}";
	const Shader FYJ_SHADER_COLOR2 = {sColor2ShaderVP, 
										sColor2ShaderFP,
										//attributes
										"a_Position",  //POSITION
										"",    //NORMAL
										"",  //COLOR
										"", // TEX_COORD0
										"", //TEX_COORD1
										"", //TEX_COORD2
										"", //TEX_COORD3
										//uniforms
										"u_Color",//COLOR2
										"",  //MV
										"",  //PROJECTION
										"", //TEX_UNIT0
										"", //TEX_UNIT1
										"", //TEX_UNIT2
										""  //TEX_UNIT3
										};

	//mvp
	static String sMVPShaderVP =      "uniform mat4 u_ProjectionMatrix;\n"
								"uniform mat4 u_ModelViewMatrix;\n"
								"attribute vec4 a_Position;\n"
								"attribute vec4 a_Color;\n"
								"varying vec4 v_Color;\n"
							  	"void main(void) \n"
							 	"{ gl_Position =u_ProjectionMatrix * u_ModelViewMatrix *  a_Position; \n"
							 	"v_Color = a_Color;\n"
							  	"}\n";
										
	static String sMVPShaderFP = "#ifdef GL_ES \n"
							 "precision mediump float;\n"
							 "#endif \n"
							 "varying vec4 v_Color;\n"
							 "void main(void) \n"
							 "{ gl_FragColor = v_Color; \n"
							 "}";
	const Shader FYJ_SHADER_MVP = {sMVPShaderVP, 
										sMVPShaderFP,
										//attributes
										"a_Position",  //POSITION
										"",    //NORMAL
										"a_Color",  //COLOR
										"", // TEX_COORD0
										"", //TEX_COORD1
										"", //TEX_COORD2
										"", //TEX_COORD3
										//uniforms
										"",//COLOR2
										"u_ModelViewMatrix",  //MV
										"u_ProjectionMatrix",  //PROJECTION
										"", //TEX_UNIT0
										"", //TEX_UNIT1
										"", //TEX_UNIT2
										""  //TEX_UNIT3
										};

	//texture
	static String sTextureShaderVP =  "uniform mat4 u_ProjectionMatrix;\n"
								"uniform mat4 u_ModelViewMatrix;\n"
								"attribute vec4 a_Position;\n"
								"attribute vec2 a_TexCoords;\n"
								"varying vec2 v_TexCoords;\n"
							  	"void main(void) \n"
							 	"{ gl_Position =u_ProjectionMatrix * u_ModelViewMatrix *  a_Position; \n"
							 	"v_TexCoords = a_TexCoords;\n"
							  	"}\n";
										
	static String sTextureShaderFP = "#ifdef GL_ES \n"
							 "precision mediump float;\n"
							 "#endif \n"
							 "uniform sampler2D u_Texture; \n"
							 "varying vec2 v_TexCoords;\n"
							 "void main(void) \n"
							 "{ gl_FragColor = texture2D(u_Texture, v_TexCoords); \n"
							 "}";

	const Shader FYJ_SHADER_TEXTURE = {sTextureShaderVP, 
									sTextureShaderFP,
									//attributes
									"a_Position",  //POSITION
									"",    //NORMAL
									"",  //COLOR
									"a_TexCoords", // TEX_COORD0
									"", //TEX_COORD1
									"", //TEX_COORD2
									"", //TEX_COORD3
									"",//COLOR2
									//uniforms
									"u_ModelViewMatrix",  //MV
									"u_ProjectionMatrix",  //PROJECTION
									"u_Texture", //TEX_UNIT0
									"", //TEX_UNIT1
									"", //TEX_UNIT2
									""  //TEX_UNIT3
									};

	//texture and lighting
	static String sTextureLightingShaderVP =  "uniform mat4 u_ProjectionMatrix;\n"
								"uniform mat4 u_ModelViewMatrix;\n"
								"uniform mat3 u_NormalMatrix;\n"
								"uniform vec3 u_LightPosition;\n"
								"const float c_SpecularContribution = 0.1;\n"
								"const float c_DiffuseContribution = 1.0 - specularContribution;\n"
								"attribute vec4 a_Position;\n"
								"attribute vec3 a_Normal;\n"
								"attribute vec2 a_TexCoords;\n"
								"varying vec3 v_LightIntensity;\n"
								"varying vec2 v_TexCoords;\n"
								"varying vec3 v_LightIntensity;\n"
							  	"void main(void) \n"
							 	"{  \n"
							 	"vec3 ecPosition = vec3(u_ModelViewMatrix * a_Position);\n"
							 	"vec3 tnorm = normalize(u_NormalMatrix * a_Normal);\n"
							 	"vec3 lightVec = normalize(u_LightPosition - ecPosition);\n"
							 	"vec3 reflectVec = reflect(-lightVec, tnorm);\n"
							 	"vec3 viewVec = normalize(-ecPosition);\n"
							 	"float spec = clamp(dot(reflectVec, viewVec), 0.0, 1.0);\n"
							 	"spec = pow(spec, 16.0);\n"
							 	"v_LightIntensity = c_DiffuseContribution *  max(dot(lightVec, tnorm), 0.0) + c_SpecularContribution * spec;\n"
							 	"v_TexCoords = a_TexCoords;\n"
							 	"gl_Position = u_ProjectionMatrix * u_ModelViewMatrix *  a_Position; \n"
							  	"}\n";
										
	static String sTextureLightingShaderFP = "#ifdef GL_ES \n"
							 "precision mediump float;\n"
							 "#endif \n"
							 "uniform sampler2D u_Texture; \n"
							 "varying vec2 v_TexCoords;\n"
							 "varying float v_LightIntensity;\n"
							 "void main(void) \n"
							 "{ \n"
							 "vec3 lightColor = vec3(texture(u_Texture, v_TexCoords));\n"
							 "gl_FragColor = vec4(lightColor * v_LightIntensity, 1.0); \n"
							 "}";

	const Shader FYJ_SHADER_TEXTURE_LIGHTING = {sTextureLightingShaderVP, 
									sTextureLightingShaderFP,
									//attributes
									"a_Position",  //POSITION
									"a_Normal",    //NORMAL
									"",  //COLOR
									"a_TexCoords", // TEX_COORD0
									"", //TEX_COORD1
									"", //TEX_COORD2
									"", //TEX_COORD3
									"",//COLOR2
									//uniforms
									"u_ModelViewMatrix",  //MV
									"u_ProjectionMatrix",  //PROJECTION
									"u_Texture", //TEX_UNIT0
									"", //TEX_UNIT1
									"", //TEX_UNIT2
									""  //TEX_UNIT3
									};

}

#endif
