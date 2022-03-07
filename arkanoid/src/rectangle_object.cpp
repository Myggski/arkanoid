#include "rectangle_object.h"

RectangleObject::RectangleObject(const SDL_Color color, SDL_FRect rectangle, Level* level) : GameObject(color, level), rectangle(rectangle) {}

void RectangleObject::draw(SDL_Renderer* render) const
{
	SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);
	SDL_RenderFillRectF(render, &rectangle);
}