#include "game.h"
#include "delta_time.h"
#include "input.h"
#include "game_object.h"

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
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");

	render = new Renderer(window);

	event_handler = new GameEventHandler();
	event_handler->add_listener(SDL_QUIT, &exit_application);

	Level::init();
	Input::init(event_handler);
}


void Game::update() const
{
	DeltaTime::refresh_dt();

	auto& game_objects = Level::get_objects();
	for (const auto game_object : game_objects)
	{
		game_object->update();
	}
}

void Game::clean()
{
	delete render;

	Input::clean(event_handler);
	event_handler->remove_listener(SDL_QUIT, &exit_application);

	delete event_handler;

	SDL_DestroyWindow(window);
	SDL_Quit();
}