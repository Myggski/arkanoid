#pragma once

#include <SDL_render.h>

class Renderer
{
public:
	Renderer(SDL_Window* window);
	~Renderer();
	void draw() const;
private:
	SDL_Renderer* game_render{ nullptr };
};
