#include "Texture.h"

namespace Engine
{
	namespace Graphics
	{

		Texture::Texture()
		{
			m_id = -1;
		}

		Texture::Texture(int _id)
		{
			m_id = _id;

			if (m_id > 0)
			{
				int miplevel = 0;
				glBindTexture(GL_TEXTURE_2D, m_id);
				glGetTexLevelParameteriv(GL_TEXTURE_2D, miplevel, GL_TEXTURE_HEIGHT, &m_height);
				glGetTexLevelParameteriv(GL_TEXTURE_2D, miplevel, GL_TEXTURE_WIDTH, &m_width);
			}
		}

		Texture::Texture(string path)
		{
			cout << SOIL_LOAD_AUTO << endl;
			cout << SOIL_CREATE_NEW_ID << endl;
			cout << path.c_str() << endl;
			cout << SOIL_FLAG_MULTIPLY_ALPHA << endl;
			m_id = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MULTIPLY_ALPHA | SOIL_FLAG_INVERT_Y);
			if (!GetTextureParams())
			{
				cout << "Erreur lors du chargement de l'image : " << path << endl;
			}
		}

		int Texture::GetId()
		{
			return m_id;
		}

		int Texture::GetWidth()
		{
			return m_width;
		}

		int Texture::GetHeight()
		{
			return m_height;
		}

		bool Texture::GetTextureParams()
		{
			if (m_id > 0)
			{
				int miplevel = 0;
				glBindTexture(GL_TEXTURE_2D, m_id);
				glGetTexLevelParameteriv(GL_TEXTURE_2D, miplevel, GL_TEXTURE_HEIGHT, &m_height);
				glGetTexLevelParameteriv(GL_TEXTURE_2D, miplevel, GL_TEXTURE_WIDTH, &m_width);
				return true;
			}

			return false;
		}

	}
}