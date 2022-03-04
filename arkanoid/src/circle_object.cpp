#include "circle_object.h"

static constexpr float TAU = 6.283;
static constexpr float CIRCLE_RESOLUTION = 24;

CircleObject::CircleObject(float radius, SDL_Color color) : radius(radius), Object(color) {}

void CircleObject::draw() {
	float step = TAU / CIRCLE_RESOLUTION;

	for (int i = 0; i < CIRCLE_RESOLUTION; ++i)
	{
		float angle = step * i;
		float x1 = cos(angle);
		float y1 = sin(angle);

		float next_angle = step * (i + 1);
		float x2 = cos(next_angle);
		float y2 = sin(next_angle);

		SDL_RenderDrawLine(
			render,
			x1 * c.radius + c.x,
			y1 * c.radius + c.y,
			x2 * c.radius + c.x,
			y2 * c.radius + c.y
		);
	}
}