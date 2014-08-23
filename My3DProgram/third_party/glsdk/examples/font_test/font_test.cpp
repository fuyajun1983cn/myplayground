
#include <string>
#include <vector>
#include <deque>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <glload/gl_3_3.hpp>
#include <glload/gll.hpp>
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glutil/glutil.h>
#include <glmesh/glmesh.h>

GLint g_cameraToClipMatrixUnif = 0;

GLuint g_program = 0;

void InitializeProgram()
{
	const std::string vertexShader(
		"#version 330\n"
		"\n"
		"layout(location = 0) in vec4 position;\n"
		"layout(location = 1) in vec4 texCoord;\n"
		"\n"
		"smooth out vec2 glyphCoord;\n"
		"\n"
		"uniform mat4 cameraToClipMatrix;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	gl_Position = cameraToClipMatrix * position;\n"
		"	glyphCoord = texCoord.st;\n"
		"}\n"
		);

	const std::string fragmentShader(
		"#version 330\n"
		"\n"
		"smooth in vec2 glyphCoord;\n"
		"out vec4 outputColor;\n"
		"uniform sampler2D glyphTex;"
		"\n"
		"void main()\n"
		"{\n"
		"	outputColor = texture(glyphTex, glyphCoord).rrrr;\n"
		"}\n"
		);

	GLuint vertShader = glutil::CompileShader(gl::GL_VERTEX_SHADER, vertexShader);
	GLuint fragShader = glutil::CompileShader(gl::GL_FRAGMENT_SHADER, fragmentShader);

	g_program = glutil::LinkProgram(vertShader, fragShader);

	gl::DeleteShader(vertShader);
	gl::DeleteShader(fragShader);

	g_cameraToClipMatrixUnif = gl::GetUniformLocation(g_program, "cameraToClipMatrix");
	GLint samplerUnif = gl::GetUniformLocation(g_program, "glyphTex");
	gl::UseProgram(g_program);
	gl::Uniform1i(samplerUnif, 0);
	gl::UseProgram(0);
}

GLuint g_dataBufferObject;
GLuint g_vao;

glutil::Font *g_pFont = NULL;
glmesh::VertexFormat *g_pVertFmt = NULL;
glmesh::StreamBuffer *g_pStreamBuf = NULL;

GLuint g_numGlyphsToDraw = 0;

void PushGlyph( std::vector<GLfloat> &vecVertex, int loop, std::vector<glm::vec2> &positions,
			   std::vector<glm::vec2> &texCoords )
{
	vecVertex.push_back(positions[loop].x);
	vecVertex.push_back(positions[loop].y);
	vecVertex.push_back(texCoords[loop].x);
	vecVertex.push_back(texCoords[loop].y);
}

void AddGlyph(std::vector<GLfloat> &vecVertex, const glutil::GlyphQuad &theGlyph)
{
	std::vector<glm::vec2> positions = theGlyph.GetPositions();
	std::vector<glm::vec2> texCoords = theGlyph.GetTexCoords();

	PushGlyph(vecVertex, 0, positions, texCoords);
	PushGlyph(vecVertex, 1, positions, texCoords);
	PushGlyph(vecVertex, 2, positions, texCoords);

	PushGlyph(vecVertex, 1, positions, texCoords);
	PushGlyph(vecVertex, 3, positions, texCoords);
	PushGlyph(vecVertex, 2, positions, texCoords);
}

void SendVerts(glmesh::Draw &imm, int index, std::vector<glm::vec2> &positions,
			   std::vector<glm::vec2> &texCoords)
{
	imm.Attrib(positions[index]);
	imm.Attrib(texCoords[index]);
}

void DrawGlyph(glmesh::Draw &imm, const glutil::GlyphQuad &theGlyph)
{
	std::vector<glm::vec2> positions = theGlyph.GetPositions();
	std::vector<glm::vec2> texCoords = theGlyph.GetTexCoords();

	SendVerts(imm, 0, positions, texCoords);
	SendVerts(imm, 1, positions, texCoords);
	SendVerts(imm, 2, positions, texCoords);

	SendVerts(imm, 1, positions, texCoords);
	SendVerts(imm, 3, positions, texCoords);
	SendVerts(imm, 2, positions, texCoords);
}

std::string GetString()
{
	return "Test string";
}

void InitializeVertexData()
{
	glmesh::AttributeList attribs;
	//First attribute is attribute index 0, a vec4 of floats.
	attribs.push_back(glmesh::AttribDesc(0, 2, glmesh::VDT_SINGLE_FLOAT, glmesh::ADT_FLOAT));
	//Second attribute is attribute index 1, a vec4 of normalized, unsigned bytes.
	attribs.push_back(glmesh::AttribDesc(1, 2, glmesh::VDT_SINGLE_FLOAT, glmesh::ADT_FLOAT));

	g_pVertFmt = new glmesh::VertexFormat(attribs);
	g_pStreamBuf = new glmesh::StreamBuffer(1024 * 1024);

	

	std::vector<GLfloat> vecVertex;

	std::string theText = GetString();

	std::vector<glutil::GlyphQuad> glyphs = g_pFont->LayoutLine(theText.c_str(), theText.size(),
		glm::vec2(50.0f, 250.0f), glutil::REF_BASELINE);

	vecVertex.reserve(24 * glyphs.size());

	assert(glyphs.size());

	for(size_t loop = 0; loop < glyphs.size(); ++loop)
		AddGlyph(vecVertex, glyphs[loop]);

	g_numGlyphsToDraw = glyphs.size();

	gl::GenBuffers(1, &g_dataBufferObject);

	gl::BindBuffer(gl::GL_ARRAY_BUFFER, g_dataBufferObject);
	gl::BufferData(gl::GL_ARRAY_BUFFER, sizeof(GLfloat) * vecVertex.size(), &vecVertex[0], gl::GL_STATIC_DRAW);

	gl::GenVertexArrays(1, &g_vao);

	gl::BindVertexArray(g_vao);
	gl::BindBuffer(gl::GL_ARRAY_BUFFER, g_dataBufferObject);
	gl::EnableVertexAttribArray(0);
	gl::VertexAttribPointer(0, 2, gl::GL_FLOAT, gl::GL_FALSE, 4 * sizeof(GLfloat), (void*)0);
	gl::EnableVertexAttribArray(1);
	gl::VertexAttribPointer(1, 2, gl::GL_FLOAT, gl::GL_FALSE, 4 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));

	gl::BindVertexArray(0);
	gl::BindBuffer(gl::GL_ARRAY_BUFFER, 0);
}

//Called after the window and OpenGL are initialized. Called exactly once, before the main loop.
void init()
{
	g_pFont = glutil::GenerateFont(glutil::FONT_SIZE_LARGE);

	InitializeProgram();
	InitializeVertexData();
}

glm::ivec2 g_windowSize(500, 500);

typedef std::deque<std::string> StringQueue;

std::string g_currString;
StringQueue g_strings;

void DrawTextString(const std::string &text, const glm::vec2 &location)
{
	std::vector<glutil::GlyphQuad> glyphs = g_pFont->LayoutLine(text.c_str(), text.size(),
		location, glutil::REF_BOTTOM);

	glmesh::Draw imm(gl::GL_TRIANGLES, glyphs.size() * 6, *g_pVertFmt, *g_pStreamBuf);

	for(size_t loop = 0; loop < glyphs.size(); ++loop)
	{
		DrawGlyph(imm, glyphs[loop]);
	}
}

//Called to update the display.
//You should call glutSwapBuffers after all of your rendering to display what you rendered.
//If you need continuous updates of the screen, call glutPostRedisplay() at the end of the function.
void display()
{
	gl::ClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	gl::Clear(gl::GL_COLOR_BUFFER_BIT);

	gl::Enable(gl::GL_BLEND);
	gl::BlendEquation(gl::GL_FUNC_ADD);
	gl::BlendFunc(gl::GL_ONE, gl::GL_ONE_MINUS_SRC_ALPHA);

	gl::UseProgram(g_program);
	gl::ActiveTexture(gl::GL_TEXTURE0);
	gl::BindTexture(gl::GL_TEXTURE_2D, g_pFont->GetTexture());

	glutil::MatrixStack persMatrix;
	persMatrix.PixelPerfectOrtho(g_windowSize, glm::vec2(-1.0f, 1.0f), false);

	gl::UniformMatrix4fv(g_cameraToClipMatrixUnif, 1, gl::GL_FALSE, glm::value_ptr(persMatrix.Top()));

	glm::vec2 currPt(50.0f, 5.0f);
	if(!g_currString.empty())
		DrawTextString(g_currString, currPt);

	for(StringQueue::const_iterator startIt = g_strings.begin();
		startIt != g_strings.end();
		++startIt)
	{
		currPt.y += g_pFont->GetLinePixelHeight();

		DrawTextString(*startIt, currPt);
	}

/*
	gl::BindVertexArray(g_vao);
	gl::DrawArrays(gl::GL_TRIANGLES, 0, 6 * g_numGlyphsToDraw);
	gl::BindVertexArray(0);
*/

	gl::BindTexture(gl::GL_TEXTURE_2D, 0);
	gl::UseProgram(0);

	glfwSwapBuffers();
}

//Called whenever the window is resized. The new window size is given, in pixels.
//This is an opportunity to call glViewport or glScissor to keep up with the change in size.
void GLFWCALL reshape(int w, int h)
{
	gl::Viewport(0, 0, (GLsizei) w, (GLsizei) h);

	g_windowSize.x = w;
	g_windowSize.y = h;
}

int GLFWCALL close_cb()
{
	delete g_pFont;
	g_pFont = NULL;

	delete g_pVertFmt;
	g_pVertFmt = NULL;

	delete g_pStreamBuf;
	g_pStreamBuf = NULL;

	return gl::GL_TRUE;
}

void GLFWCALL CharFunc(int unicodepoint, int action)
{
	if(action == GLFW_RELEASE)
		return;

	if(unicodepoint < 128)
		g_currString.push_back(static_cast<char>(unicodepoint));
}

void GLFWCALL KeyFunc(int key, int action)
{
	if(action == GLFW_PRESS)
		return;

	switch(key)
	{
	case GLFW_KEY_ENTER:
	case GLFW_KEY_KP_ENTER:
		if(!g_currString.empty())
		{
			g_strings.push_front(std::string());
			std::swap(g_strings.front(), g_currString);
			if(g_strings.size() > 10)
				g_strings.pop_back();
		}

		std::cout << g_strings.size() << std::endl;
		break;
	case GLFW_KEY_BACKSPACE:
		g_currString.erase(g_currString.size() - 1, 1);
		break;
	}
}

int main(int argc, char** argv)
{
	if(!glfwInit())
		return -1;

	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef DEBUG
	glfwOpenWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, gl::GL_TRUE);
#endif

	if(!glfwOpenWindow(g_windowSize.x, g_windowSize.y, 8, 8, 8, 8, 24, 8, GLFW_WINDOW))
	{
		glfwTerminate();
		return -1;
	}

	GLFWvidmode desktopMode;
	glfwGetDesktopMode(&desktopMode);

	glm::ivec2 desktopSize(desktopMode.Width, desktopMode.Height);
	glm::ivec2 wndPos = glutil::CalcWindowPosition(g_windowSize, desktopSize,
		glutil::WH_CENTER, glutil::WV_CENTER);

	glfwSetWindowPos(wndPos.x, wndPos.y);

	if(glload::LoadFunctions() == glload::LS_LOAD_FAILED)
	{
		glfwTerminate();
		return -1;
	}

	glfwSetWindowTitle("GLFW Demo");

	glutil::RegisterDebugOutput(glutil::STD_OUT);

	init();

	glfwSetWindowSizeCallback(reshape);
	glfwSetWindowCloseCallback(close_cb);
	glfwSetCharCallback(CharFunc);
	glfwSetKeyCallback(KeyFunc);
	glfwEnable(GLFW_KEY_REPEAT);

	//Main loop
	while(true)
	{
		display();

		if(glfwGetKey(GLFW_KEY_ESC))
		{
			close_cb();
			glfwCloseWindow();
		}

		if(!glfwGetWindowParam(GLFW_OPENED))
			break;

		glfwSleep(0.010);
	}

	glfwTerminate();
	return 0;
}
