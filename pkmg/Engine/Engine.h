#ifndef PKMG_ENGINE
#define PkMG_ENGINE

#include "GLFW/glfw3.h"
#pragma comment(lib, "opengl32.lib")

#include <string>
#include <iostream>
using namespace std;

namespace Engine
{
	class Engine
	{
	public:
		Engine();
		~Engine();

		bool Initialize(const char* window_title);

		void Update();
		void BeginRender();
		void EndRender();


	private:
		int m_screen_width;
		int m_screen_height;
		GLFWwindow* m_window;

	};
}
#endif
