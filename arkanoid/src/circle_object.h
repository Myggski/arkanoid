#pragma once

#include <cstdint>
#include "object.h"

class CircleObject : Object {
public:
	void draw();
	CircleObject(float radius, SDL_Color color);
private:
	float radius;
};