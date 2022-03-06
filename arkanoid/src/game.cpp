#include "game.h"
#include "input.h"
#include "delta_time.h"

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
		setup();
	}

	isRunning = initialized;

	while (isRunning) {
		event_handler->pull_events();
		update();
		render->draw();
	}

	clean();
}

void Game::setup()
{
	level = new Level();
	render = new Renderer(window, level);

	event_handler = new GameEventHandler();
	event_handler->add_listener(SDL_QUIT, &exit_application);

	Input::init(event_handler);
}


void Game::update() const
{
	DeltaTime::refresh_dt();
	auto& game_objects = level->get_objects();

	for (const auto game_object : game_objects)
	{
		game_object->update(&DeltaTime::dt);
	}
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	
	delete render;

	Input::clean(event_handler);

	event_handler->remove_listener(SDL_QUIT, &exit_application);
	delete event_handler;
	SDL_Quit();
}