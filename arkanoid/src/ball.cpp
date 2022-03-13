#include "ball.h"
#include "game_settings.h"
#include "player.h"
#include "level.h"
#include "collision.h"
#include "brick.h"
#include "delta_time.h"

static const SDL_Color BALL_COLOR = { 255, 255, 255, 255 };
static const float BALL_RADIUS = 8.f;
static const float BALL_MAX_SPEED = 400.f;

float sign(float a) { return a > 0.f ? 1.f : -1.f; }

Ball::Ball() : CircleObject(BALL_COLOR, BALL_RADIUS) {}

void Ball::update()
{
	if (!step(velocity_x * (DeltaTime::delta_time), 0)) {
		velocity_x = -velocity_x + sign(-velocity_x) * 5.f;
		
		if (abs(velocity_x) > BALL_MAX_SPEED) {
			velocity_x = sign(velocity_x) * BALL_MAX_SPEED;
		}
	}

	if (!step(0, velocity_y * (DeltaTime::delta_time))) {
		velocity_y = -velocity_y + sign(-velocity_y) * 5.f;
		
		if (abs(velocity_y) > BALL_MAX_SPEED) {
			velocity_y = sign(velocity_y) * BALL_MAX_SPEED;
		}
	}

	if (Level::is_ball_out_of_play(this)) {
		Level::remove_ball(this);
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
	y = player.min_y() - (radius * 3);
}

bool Ball::step(const float& dx, const float& dy)
{
	const Collision::CircleCollider collision_ball_temp = Collision::CircleCollider(*this, dx, dy);

	// Check wall
	if ((collision_ball_temp.x - radius) < 0 || (collision_ball_temp.x + radius) >= WINDOW_WIDTH
		|| (collision_ball_temp.y - radius) < 0 || (collision_ball_temp.y + radius) >= WINDOW_HEIGHT) {
		return false;
	}

	auto& game_objects = Level::get_objects();
	for (const auto& game_object : game_objects) {
		const Player* player = dynamic_cast<const Player*>(game_object);

		if (player && Collision::aabb_circle_intersect(Collision::RectangleCollider((*player)), collision_ball_temp)) {
			if (abs(dx) > 0)
			{
				x += collision_ball_temp.get_distance_aabb_x(Collision::RectangleCollider((*player)));
			}

			return false;
		}

		Brick* brick = dynamic_cast<Brick*>(game_object);

		if (brick && Collision::aabb_circle_intersect(Collision::RectangleCollider((*brick)), collision_ball_temp)) {
			brick->hit();
			return false;
		}
	}

	x += dx;
	y += dy;

	return true;
}