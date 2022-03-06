#pragma once

#include "rectangle_object.h"
#include "input.h"

#define PLAYER_MOVEMENT 200.f

class Player final : public RectangleObject
{
public:
	Player(const SDL_Color color, SDL_FRect rectangle);
	~Player();
	void update(const float* dt) override;
private:
	bool moving_left{ false };
	bool moving_right{ false };
	float velocity_x{ 0 };
	InputCallback try_move_left = [this](SDL_EventType event_type)
	{
		moving_left = event_type == SDL_KEYDOWN;
	};
	InputCallback try_move_right = [this](SDL_EventType event_type)
	{
		moving_right = event_type == SDL_KEYDOWN;
	};
};
