#pragma once

#include "circle_object.h"
#include "game_settings.h"

static const float BALL_START_VELOCITY = cos(45) * 400.f;
class Player;
class Ball final : public CircleObject {
public:
	Ball();
	inline void activate() {
		is_activated = true;
		
		velocity_x = x <= (WINDOW_WIDTH / 2) ? -BALL_START_VELOCITY : BALL_START_VELOCITY;
		velocity_y = -BALL_START_VELOCITY;
	}
	bool step(const float& dx, const float& dy);
	void update() override;
	void follow_player(const Player& player);
	static Ball get_collision_check_ball(const Ball& ball, const float& dx, const float& dy);
private:
	bool is_activated = false;
	float velocity_x{ 0 };
	float velocity_y{ 0 };
};