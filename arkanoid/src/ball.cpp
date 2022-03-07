#include "ball.h"
#include "game_settings.h"
#include "player.h"
#include "level.h"
#include "collision.h"
#include <iostream>

static const SDL_Color BALL_COLOR = { 255, 255, 255, 255 };
static const float BALL_RADIUS = 8.f;

Ball::Ball(Level* level) : CircleObject(BALL_COLOR, BALL_RADIUS, level) {}

void Ball::update(const float* dt)
{
	if (!step(velocity_x * (*dt), 0)) {
		velocity_x = -velocity_x;
	}

	if (!step(0, velocity_y * (*dt))) {
		velocity_y = -velocity_y;
	}
}

Ball Ball::get_collision_check_ball(const Ball& ball, const float& dx, const float& dy) {
	Ball temp_ball = ball;
	temp_ball.x += dx;
	temp_ball.x += dx;

	return temp_ball;
}

void Ball::follow_player(const Player& player) {
	x = player.center_x();
	y = player.min_y() - (radius * 4);
}

bool Ball::step(const float& dx, const float& dy)
{
	Ball collision_ball_temp = Ball::get_collision_check_ball(*this, dx, dy);

	if ((collision_ball_temp.x - radius) < 0 || (collision_ball_temp.x + radius) >= WINDOW_WIDTH
		|| (collision_ball_temp.y - radius) < 0 || (collision_ball_temp.y + radius) >= WINDOW_HEIGHT) {
		return false;
	}

	auto game_objects = level->get_objects();
	for (auto game_object : game_objects) {
		const Player* player = dynamic_cast<const Player*>(game_object);

		if (player != nullptr) {
			if (aabb_circle_intersect((*player), collision_ball_temp)) {
				return false;
			}
		}
	}

	x += dx;
	y += dy;

	return true;
}