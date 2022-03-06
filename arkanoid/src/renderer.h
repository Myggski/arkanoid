#pragma once
#include <SDL_render.h>
#include "level.h"

class Renderer
{
public:
	Renderer(SDL_Window* window, Level* level);
	~Renderer();
	void draw() const;
private:
	Level* level = nullptr;
	SDL_Renderer* game_render = nullptr;
};
