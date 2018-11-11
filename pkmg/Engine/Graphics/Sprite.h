#ifndef _SPRITE_
#define _SPRITE_

#include "GLFW/glfw3.h"
#include "Texture.h"

#include <iostream>
#include <string>
using namespace std;

class Sprite
{
public:
	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, float xPos, float yPos);


	void Render();
	void Update();


private:
	Texture m_texture;
	float m_xPos;
	float m_yPos;


};



#endif
