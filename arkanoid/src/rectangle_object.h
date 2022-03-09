#pragma once
#include "game_object.h"

class RectangleObject : public GameObject
{
public:
	RectangleObject(const SDL_Color color, SDL_FRect rectangle);
	void draw(SDL_Renderer* render) const override;
	virtual void update() override = 0;
	const float& const min_x() const {
		return rectangle.x;
	};
	const float& const max_x() const {
		return rectangle.x + rectangle.w;
	};
	const float& const min_y() const {
		return rectangle.y;
	};
	const float& const max_y() const {
		return rectangle.y + rectangle.h;
	};
	const float& const center_x() const {
		return rectangle.x + (rectangle.w / 2);
	};
	const float& const center_y() const {
		return rectangle.y + (rectangle.h / 2);
	};

protected:
	SDL_FRect rectangle;
};