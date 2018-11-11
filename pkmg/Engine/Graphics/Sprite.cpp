#include "Sprite.h"

Sprite::Sprite()
{
	m_xPos = 0;
	m_yPos = 0;
	m_texture = Texture();
}

Sprite::Sprite(string imagePath)
{
	m_xPos = 0;
	m_yPos = 0;
	m_texture = Texture(imagePath);
}

Sprite::Sprite(string imagePath, float xPos, float yPos)
{
	m_xPos = xPos;
	m_yPos = yPos;
	m_texture = Texture(imagePath);
}

void Sprite::Update()
{

}

void Sprite::Render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_texture.GetId());
	glLoadIdentity();

	//Translation
	glTranslatef(m_xPos, m_yPos, 0);


	//Changement d'echelle
	//Rotation

	//Rendu
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);


	glTexCoord2f(0, 0);
	glVertex2f(0, 0);

	glTexCoord2f(1, 0);
	glVertex2f(m_texture.GetWidth(), 0);

	glTexCoord2f(1, 1);
	glVertex2f(m_texture.GetWidth(), m_texture.GetHeight());

	glTexCoord2f(0, 1);
	glVertex2f(0, m_texture.GetHeight());

	glEnd();
	glDisable(GL_TEXTURE_2D);

}

