#pragma once

#include "game_settings.h"
#include "rectangle_object.h"

static const float BRICK_WIDTH = 50.f;
static const float BRICK_HEIGHT = 37.5f;
static constexpr SDL_Color BRICK_COLOR_1 = { 156, 64, 64, 255 };
static constexpr SDL_Color BRICK_COLOR_2 = { 64, 156, 64, 255 };
static constexpr SDL_Color BRICK_COLOR_3 = { 64, 64, 156, 255 };

class Brick : public RectangleObject
{
public:
	Brick(const float x, const float y, const uint8_t life) :
	RectangleObject(
		get_color(), 
		{ x, y, BRICK_WIDTH, BRICK_HEIGHT }
	),
	life(life > BRICK_MAX_LIFE ? BRICK_MAX_LIFE : life)
	{
		color = get_color();
	}
	SDL_Color get_color() const
	{
		switch (life)
		{
		case 1:
			return BRICK_COLOR_1;
		case 2:
			return BRICK_COLOR_2;
		case 3:
			return BRICK_COLOR_3;
		default:
			return BRICK_COLOR_1;
		}
	}
	void update() override;
	void hit();

private:
	uint8_t life{ 1 };
	float destory_timer{ 0 };
	const float destroy_delay{ 0.1f };
};
