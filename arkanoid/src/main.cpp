#include "game.h"
#include "input.h";
Game* game = nullptr;

int main(int argc, char* argv[])
{
	game = new Game();

	game->init("Arkanoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, false);

	while (game->running()) {
		game->handleEvents();
		game->update();
		game->draw();
	}

	game->clean();

	return 0;
}