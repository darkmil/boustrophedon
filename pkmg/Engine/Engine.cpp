#include "Engine.h"


namespace Engine
{
	Engine::Engine()
	{
		m_screen_height = 800;
		m_screen_width = 800;
	}

	Engine::~Engine()
	{

	}

	bool Engine::Initialize(const char* window_title)
	{
		if (!glfwInit())
		{
			cout << "Erreur lors de l'initialisation de glfw" << endl;
			return false;
		}

		m_window = glfwCreateWindow(m_screen_height, m_screen_height, window_title, NULL, NULL);
		if (m_window == NULL)
		{
			cout << "Erreur lors de l'initialisation de la fenêtre" << endl;
			return false;
		}

		//démarrage de GLWF

		glfwMakeContextCurrent(m_window);
		int width;
		int height;
		glfwGetFramebufferSize(m_window, &width, &height);
		glfwSwapInterval(1);

		const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		int xPos = (mode->width - m_screen_width) / 2;
		int yPos = (mode->height - m_screen_height) / 2;
		glfwSetWindowPos(m_window, xPos, yPos);

		//Démarrage de GL
		//Fenêtre d'affichage
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, width, 0, height, -10, 10);
		glDepthRange(-10, 10);
		glMatrixMode(GL_MODELVIEW);

		//Alpha blending
		glEnable(GL_ALPHA_TEST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		return true;

	}

	void Engine::Update()
	{
		glfwPollEvents();

	}

	void Engine::BeginRender()
	{
		glClearColor(0, 1, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Engine::EndRender()
	{
		glfwSwapBuffers(m_window);
	}
}