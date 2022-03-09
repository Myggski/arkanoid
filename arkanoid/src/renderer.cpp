#include "renderer.h"

#include <iostream>

Renderer::Renderer(SDL_Window* window, Level* level) : level(level), game_render(SDL_CreateRenderer(window, -1, 0)) {}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(game_render);
}

void Renderer::draw() const
{
	std::cout << level->get_objects().size() << "\n";
	SDL_SetRenderDrawColor(game_render, 25, 25, 40, 255);
	SDL_RenderClear(game_render);

	for (const auto& game_object : level->get_objects())
	{
		if (game_object)
		{
			game_object->draw(game_render);
		}
	}

	SDL_RenderPresent(game_render);
}

