#include "circle_object.h"

static constexpr float TAU = 6.283f;
static constexpr float CIRCLE_RESOLUTION = 32;
static constexpr float step = TAU / CIRCLE_RESOLUTION;

CircleObject::CircleObject(const SDL_Color color, const float radius) : GameObject(color), radius(radius) {}

void CircleObject::draw(SDL_Renderer* render) const
{
	SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);
	for (int width = 0; width < radius * 2; width++)
	{
		for (int height = 0; height < radius * 2; height++)
		{
			float dx = radius - width;
			float dy = radius - height;
			if ((dx * dx + dy * dy) <= (radius * radius))
			{
				SDL_RenderDrawPoint(render, x + dx, y + dy);
			}
		}
	}
	/*for (int i = 0; i < CIRCLE_RESOLUTION; ++i)
	{
		SDL_SetRenderDrawColor(render, color.r, color.g, color.b, 255);
		const float angle = step * i;
		const float x1 = cos(angle);
		const float y1 = sin(angle);

		const float next_angle = step * (i + 1);
		const float x2 = cos(next_angle);
		const float y2 = sin(next_angle);

		SDL_RenderDrawLine(
			render,
			x1 * radius + x,
			y1 * radius + y,
			x2 * radius + x,
			y2 * radius + y
		);
	}*/
}