#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"

#include <iostream>
using namespace std;


int main()
{
	string a_path = "C:/Users/Milan/source/repos/pkmg/pkmg/";
	cout << "Yo ma boy" << endl;
	
	Engine engine;

	engine.Initialise("Pute");

	Sprite testSprite = Sprite(a_path + "Engine/Graphics/SOIL/img_cheryl.jpg", 100, 100);

	while (true)
	{
		engine.Update();
		testSprite.Update();

		engine.BeginRender();
		testSprite.Render();
		engine.EndRender();
	}
	

	return 0;
}