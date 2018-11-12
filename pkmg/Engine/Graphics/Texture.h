#ifndef TEXTURE
#define TEXTURE

#include "GLFW/glfw3.h"
#include "SOIL/src/SOIL.h"

#include <iostream>
#include <string>
using namespace std;

namespace Engine
{
	namespace Graphics
	{
		class Texture
		{
		public:
			Texture();
			Texture(int _id);
			Texture(string path);


			int GetHeight();
			int GetWidth();
			int GetId();

		private:
			bool GetTextureParams();

			int m_id;
			int m_height;
			int m_width;

		};

#endif

	}
}