#pragma once
#include "game_object.h"

class RectangleObject : public GameObject
{
public:
	RectangleObject(const SDL_Color color, SDL_FRect rectangle);
	void draw(SDL_Renderer* render) const override;
	virtual void update(const float* dt) override = 0;
protected:
	SDL_FRect rectangle;
};