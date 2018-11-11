#ifndef PKMG_ENGINE
#define PkMG_ENGINE

#include "GLFW/glfw3.h"
#pragma comment(lib, "opengl32.lib")

#include <string>
#include <iostream>
using namespace std;

class Engine
{
public:
	static int m_screen_width;
	static int m_screen_height;
	Engine();
	~Engine();

	bool Initialise(const char* window_title);

	void Update();
	void BeginRender();
	void EndRender();


private:
	static GLFWwindow* m_window;

};

#endif
