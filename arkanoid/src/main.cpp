#include "game.h"
#include "application.h"
#include "input.h"
#include "file_handler.h"

#include <vector>
#include <string>

Game* game = nullptr;
Application* application;

int main(int argc, char* argv[])
{
	application = new Application();
	application->init();

	/*
	game = new Game();

	game->init("Arkanoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, false);
	*/

	return 0;
}