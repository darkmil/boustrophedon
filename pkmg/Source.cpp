#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"

#include <iostream>
using namespace std;


int main()
{
	string a_path = "";
	cout << "Yo ma boy" << endl;
	
	Engine::Engine engine;

	engine.Initialize("Pute");

	Engine::Graphics::Sprite testSprite = Engine::Graphics::Sprite(a_path + "Engine/Graphics/SOIL/img_cheryl.jpg", 100, 100);

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