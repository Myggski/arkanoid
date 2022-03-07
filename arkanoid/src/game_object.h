#pragma once

#include "SDL.h"

class Level;
class GameObject {
public:
	virtual ~GameObject() = default;
	virtual void draw(SDL_Renderer* render) const = 0;
	virtual void update(const float* dt) = 0;
protected:
	GameObject(SDL_Color color, Level* level) : color(color), level(level) {}
	SDL_Color color { 255, 0, 0, 255};
	Level* level;
};