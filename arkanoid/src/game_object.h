#pragma once

#include "SDL.h"

class GameObject {
public:
	virtual ~GameObject() = default;
	virtual void draw(SDL_Renderer* render) const = 0;
	virtual void update() = 0;
protected:
	GameObject(SDL_Color color) : color(color) {}
	SDL_Color color { 255, 0, 0, 255};
};