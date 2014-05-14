#include "app.h"
#include "os.h"
#include "test_interface.h"

using namespace FYJ;

OS *FYJ::g_os = 0;

Application::Application():m_current_viewport_height(0), m_current_viewport_width(0)
{
	g_os = OS::CreateI();
	TEST_INTERFACE::InitTest(g_os);

	currentTest = NULL;
	
}

Application::~Application()
{
	if (currentTest != NULL)
		fyj_delete currentTest;
	OS::DestroyI(&g_os);
}

TestBase* Application::createTest(TestIds id)
{
	return TEST_INTERFACE::CreateTest(id);
}

void Application::parseParameters()
{
	List<Pair>::ListEntry *temp = m_input_parameters.getHead();

	while(temp != NULL) {
		Pair *param = temp->data;
		if (param->key == "CurrentTest" && param->value == "MyFirstTest") {
			currentTest = createTest(FYJ_TextureEarthTest);
		} else if (param->key == "width") {
		 	INFO("Width = %s", param->value.c_str());
			m_current_viewport_width = param->value.toInt();
		} else if (param->key == "height") {
			INFO("Height = %s", param->value.c_str());
			m_current_viewport_height = param->value.toInt();
		}
		temp = temp->next;
	}

}

bool Application::init()
{
	parseParameters();
	if (currentTest == NULL) {
		WARN("Forget to Init Test Case????????");
	} else { 
		currentTest->init();
	}

	resize(m_current_viewport_width, m_current_viewport_height);

	return true;
}

bool Application::resize(int w, int h)
{
	currentTest->resize(w, h);
	return true;
}

bool Application::render()
{
	currentTest->render();
	return true;
}

void Application::setInputParameter(const char *key, const char *value)
{
	Pair *p = fyj_new Pair;

	p->key = key;
	p->value = value;
	m_input_parameters.insert( p);
}

void Application::setInputParameter(const char *key, int value)
{
	char tmp[128];
	Pair *p = fyj_new Pair;

	fyj_sprintf( tmp, "%d", value);
	p->key = key;
	p->value = tmp;
	m_input_parameters.insert( p);
}

void Application::quit()
{
	if (currentTest != NULL) {
		fyj_delete currentTest;
	}
}
