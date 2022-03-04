#pragma once

#include <SDL.h>
#include <stdio.h>

class Game {
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int with, int height, bool fullscreen);
	void handleEvents();
	void update();
	void draw();
	void clean();

	bool running() { return isRunning; }

private:
	bool isRunning = false;
	SDL_Window* window;
	SDL_Renderer* render;
};