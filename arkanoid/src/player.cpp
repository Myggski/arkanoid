#include "player.h"
#include "input.h"
#include "game_settings.h"

static const SDL_Color PLAYER_COLOR = { 120, 25, 45, 255 };
static const float PLAYER_WIDTH = 80.f;
static const float PLAYER_HEIGHT = 25.f;
static const float START_Y_OFFSET_POSITION = 50.f;
static const float PLAYER_START_X = (WINDOW_WIDTH / 2) - (PLAYER_WIDTH / 2);
static const float PLAYER_START_Y = (WINDOW_HEIGHT - START_Y_OFFSET_POSITION) - (PLAYER_HEIGHT / 2);
static const float PLAYER_MOVEMENT = 500.f;

Player::Player() : RectangleObject(PLAYER_COLOR, { PLAYER_START_X, PLAYER_START_Y, PLAYER_WIDTH, PLAYER_HEIGHT })
{
	Input::add_listener(SDL_SCANCODE_A, &try_move_left);
	Input::add_listener(SDL_SCANCODE_D, &try_move_right);
	Input::add_listener(SDL_SCANCODE_SPACE, &try_activate_ball);
}

Player::~Player()
{
	Input::remove_listener(SDL_SCANCODE_A, &try_move_left);
	Input::remove_listener(SDL_SCANCODE_D, &try_move_right);
	Input::remove_listener(SDL_SCANCODE_SPACE, &try_activate_ball);
}

void Player::update()
{
	float next_position{ 0 };

	if (moving_left)
	{
		next_position = rectangle.x + (-PLAYER_MOVEMENT * DeltaTime::delta_time);
	}

	if (moving_right)
	{
		next_position = rectangle.x + (PLAYER_MOVEMENT * DeltaTime::delta_time);
	}

	if (next_position && next_position > 0 && (next_position + PLAYER_WIDTH) < WINDOW_WIDTH)
	{
		rectangle.x = next_position;
	}

	std::queue<Ball*> balls_temp = balls_to_activate;

	for (;!balls_temp.empty(); balls_temp.pop())
	{
		balls_temp.front()->follow_player((*this));
	}
}

void Player::add_ball_to_hold(Ball* ball) {
	balls_to_activate.push(ball);
}