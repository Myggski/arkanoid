#pragma once

#include "rectangle_object.h"
#include "input.h"
#include "queue"
#include "ball.h"

class Player final : public RectangleObject
{
public:
	Player();
	~Player();
	void add_ball_to_hold(Ball* ball);;
	void update() override;
private:
	bool moving_left{ false };
	bool moving_right{ false };
	float velocity_x{ 0 };
	std::queue<Ball*> balls_to_activate;
	InputCallback try_move_left = [this](SDL_EventType event_type)
	{
		moving_left = event_type == SDL_KEYDOWN;
	};
	InputCallback try_move_right = [this](SDL_EventType event_type)
	{
		moving_right = event_type == SDL_KEYDOWN;
	};
	InputCallback try_activate_ball = [this](SDL_EventType event_type) {
		if (event_type == SDL_KEYDOWN && !balls_to_activate.empty()) {
			Ball* ball = balls_to_activate.front();
			balls_to_activate.pop();
			ball->activate();
		}
	};
};
