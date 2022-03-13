#include "game.h"

#include <iostream>

#include "delta_time.h"
#include "input.h"
#include "game_object.h"
#include "level.h"

void Game::init(const char* title, int x_pos, int y_pos, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	const bool initialization = SDL_Init(SDL_INIT_EVERYTHING);
	const bool initialized = initialization == 0;

	if (initialized) {
		window = SDL_CreateWindow(title, x_pos, y_pos, width, height, flags);
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
		setup();
	}

	isRunning = initialized;

	while (isRunning) {
		event_handler->pull_events();
		update();
		render->draw();
	}

	quit();
}

void Game::setup()
{
	render = new Renderer(window);
	
	event_handler = new GameEventHandler();
	event_handler->add_listener(SDL_QUIT, &exit_game_loop);

	Level::init();

	Input::init(event_handler);
	Input::add_listener(SDL_SCANCODE_R, &restart_application);
	Input::add_listener(SDL_SCANCODE_Q, &quit_application);
}


void Game::update()
{
	DeltaTime::refresh_dt();

	auto& game_objects = Level::get_objects();
	for (const auto game_object : game_objects)
	{
		game_object->update();

		if (Level::is_game_over())
		{
			break;
		}
	}
}

void Game::clean()
{
	delete render;
	render = nullptr;

	Level::clean();

	Input::remove_listener(SDL_SCANCODE_R, &restart_application);
	Input::remove_listener(SDL_SCANCODE_Q, &quit_application);
	Input::clean(event_handler);

	event_handler->remove_listener(SDL_QUIT, &exit_game_loop);
	delete event_handler;
	event_handler = nullptr;
}

void Game::quit()
{
	clean();

	SDL_DestroyWindow(window);
	SDL_Quit();
}