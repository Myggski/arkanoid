#pragma once

#include "game_event_handler.h"
#include "renderer.h"
#include "SDL.h"

class Game {
public:
	Game() = default;
	~Game() = default;

	void init(const char* title, int x_pos, int y_pos, int with, int height, bool fullscreen);

private:
	bool isRunning = false;
	SDL_Window* window = nullptr;
	Renderer* render = nullptr;
	GameEventHandler* event_handler = nullptr;
	void update() const;
	void clean();
	void setup();
	EventCallback exit_application = [this](SDL_Event)
	{
		isRunning = false;
	};
};