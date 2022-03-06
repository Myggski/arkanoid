#include "player.h"
#include "input.h"

Player::Player(const SDL_Color color, SDL_FRect rectangle) : RectangleObject(color, rectangle)
{
	Input::add_listener(SDL_SCANCODE_A, &try_move_left);
	Input::add_listener(SDL_SCANCODE_D, &try_move_right);
}

Player::~Player()
{
	Input::remove_listener(SDL_SCANCODE_A, &try_move_left);
	Input::remove_listener(SDL_SCANCODE_D, &try_move_right);
}

void Player::update(const float* dt)
{
	float next_position{ 0 };

	if (moving_left)
	{
		next_position = rectangle.x + (-PLAYER_MOVEMENT * (*dt));
	}

	if (moving_right)
	{
		next_position = rectangle.x + (PLAYER_MOVEMENT * (*dt));
	}

	if (next_position)
	{
		rectangle.x = next_position;
	}
}
