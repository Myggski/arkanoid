#pragma once

#include "delta_time.h"
#include "game_event_handler.h"
#include "level.h"
#include "renderer.h"
#include "SDL.h"

class Game {
public:
	Game() = default;
	~Game() = default;

	void init(const char* title, int x_pos, int y_pos, int with, int height, bool fullscreen);

private:
	bool isRunning = false;
	Level* level = nullptr;
	SDL_Window* window = nullptr;
	Renderer* render = nullptr;
	DeltaTime* delta_time = nullptr;
	GameEventHandler* event_handler = nullptr;
	void update() const;
	void clean();
	void setup();
	EventCallback exit_application = [this](SDL_Event)
	{
		isRunning = false;
	};
};