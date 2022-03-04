#include "game.h"
#include "input.h"

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;

	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	bool initialization = SDL_Init(SDL_INIT_EVERYTHING);
	bool initialized = initialization == 0;

	if (initialized) {
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		render = SDL_CreateRenderer(window, -1, 0);

		SDL_SetRenderDrawColor(render, 25, 25, 40, 255);
	}

	isRunning = initialized;
}

void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;

		case SDL_KEYDOWN:
			Input::set_key_press(event.key.keysym.scancode, SDL_KEYDOWN);
			break;

		case SDL_KEYUP:
			Input::set_key_press(event.key.keysym.scancode, SDL_KEYUP);
			break;
		}
	}
}

void Game::update() {

}

void Game::draw() {
	SDL_RenderClear(render);
	SDL_RenderPresent(render);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(render);
	SDL_Quit();
}