#pragma once

#include "SDL.h"

class Object {
protected:
	Object(SDL_Color color) : color(color) {}
	float x;
	float y;
	SDL_Color color;
};