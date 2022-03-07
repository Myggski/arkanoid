#pragma once

#include <SDL_render.h>
#include "game_object.h"

class CircleObject : public GameObject {
public:
	CircleObject(SDL_Color color, const float radius, Level* level);
	void draw(SDL_Renderer* render) const override;
	const float& get_radius() const {
		return radius;
	};
	const float& get_x() const {
		return x;
	};
	const float& get_y() const {
		return y;
	};
	virtual void update(const float* dt) override = 0;
protected:
	float radius;
	float x{ 100.f };
	float y{ 100.f };
};