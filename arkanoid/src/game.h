#pragma once

#include <iostream>

#include "game_event_handler.h"
#include "input.h"
#include "level.h"
#include "renderer.h"
#include "SDL.h"

class Level;
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
	void update();
	void clean();
	void setup();
	void quit();
	EventCallback exit_game_loop = [this](SDL_Event)
	{
		isRunning = false;
	};
	InputCallback quit_application = [this](SDL_EventType event_type)
	{
		if (event_type == SDL_KEYUP && Level::is_game_over())
		{
			isRunning = false;
		}
	};
	InputCallback restart_application = [this](SDL_EventType event_type)
	{
		if (event_type == SDL_KEYUP && Level::is_game_over())
		{
			clean();
			setup();
		}
	};
};