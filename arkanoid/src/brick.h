#include <SDL_pixels.h>

#include "rectangle_object.h"

static constexpr float BRICK_WIDTH = 50.f;
static constexpr float BRICK_HEIGHT = 37.5f;
static constexpr uint8_t BRICK_MAX_LIFE = 3;
static constexpr SDL_Color BRICK_COLOR_1 = { 156, 64, 64, 255 };
static constexpr SDL_Color BRICK_COLOR_2 = { 64, 156, 64, 255 };
static constexpr SDL_Color BRICK_COLOR_3 = { 64, 64, 156, 255 };

class Level;
class Brick : public RectangleObject
{
public:
	Brick(const float x, const float y, const uint8_t life, Level* level) :
	RectangleObject(
		get_color(), 
		{ x, y, BRICK_WIDTH, BRICK_HEIGHT }, 
		level
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
	void update(const float* dt) override;
	void hit();

private:
	uint8_t life{ 1 };
};