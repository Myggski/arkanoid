#pragma once

#include <SDL_render.h>
#include "game_object.h"

class CircleObject : public GameObject {
public:
	CircleObject(const SDL_Color color, float radius);
	void draw(SDL_Renderer* render) const override;
	virtual void update(const float* dt) override = 0;
private:
	float radius;
	float x{ 100.f };
	float y{ 100.f };
};