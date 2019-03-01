#include <ctime>
#include <iostream>

using namespace std;

#include <Core/Engine.h>

#include <Tema/Game.h>

extern const int SCREEN_WIDTH = 1280;
extern const int SCREEN_HEIGHT = 720;

int main(int argc, char **argv)
{
	srand((unsigned int)time(NULL));

	// Create a window property structure
	WindowProperties wp;
	wp.resolution = glm::ivec2(SCREEN_WIDTH, SCREEN_HEIGHT);

	// Init the Engine and create a new window with the defined properties
	WindowObject* window = Engine::Init(wp);

	// Create a new 3D world and start running it
	World *world = new Game();
	world->Init();
	world->Run();
	delete world;

	// Signals to the Engine to release the OpenGL context
	Engine::Exit();

	return 0;
}