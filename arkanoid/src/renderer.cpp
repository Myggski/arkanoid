#include "renderer.h"
#include "game_object.h"

Renderer::Renderer(SDL_Window* window) : game_render(SDL_CreateRenderer(window, -1, 0)) {}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(game_render);
}

void Renderer::draw() const
{
	SDL_SetRenderDrawColor(game_render, 25, 25, 40, 255);
	SDL_RenderClear(game_render);

	auto& game_objects = Level::get_objects();
	for (const auto& game_object : game_objects)
	{
		if (game_object)
		{
			game_object->draw(game_render);
		}
	}

	SDL_RenderPresent(game_render);
}

