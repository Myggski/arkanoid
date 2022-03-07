#include "circle_object.h"

static constexpr float TAU = 6.283f;
static constexpr float CIRCLE_RESOLUTION = 32;
static constexpr float step = TAU / CIRCLE_RESOLUTION;

CircleObject::CircleObject(SDL_Color color, const float radius, Level* level) : GameObject(color, level), radius(radius) {}

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
}