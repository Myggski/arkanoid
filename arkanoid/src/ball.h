#pragma once

#include "circle_object.h"

class Ball final : public CircleObject {
public:
	Ball(const SDL_Color color, float radius);
	void update(const float* dt) override;
private:
	float velocity_x{ 0 };
	float velocity_y{ 0 };
};