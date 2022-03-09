#pragma once

#include "level.h"
#include "game_object.h"
#include "game_settings.h"
#include "ball.h"
#include "brick.h"
#include "player.h"

static const int MAX_COLUMNS = (WINDOW_WIDTH / BRICK_WIDTH) - 1;
static const int MAX_ROWS = 5;

std::vector<GameObject*> Level::game_objects;
Player* Level::player;

void Level::init() 
{
	Ball* startBall = new Ball();
	player = new Player();;
	player->add_ball_to_hold(startBall);

	game_objects.push_back(player);
	game_objects.push_back(startBall);

	auto bricks = create_level();

	for (const auto& brick : bricks)
	{
		game_objects.push_back(brick);
	}
}

const std::vector<GameObject*>& Level::get_objects()
{
	return game_objects;
}

std::vector<GameObject*> Level::create_level()
{
	std::vector<GameObject*> game_objects = std::vector<GameObject*>();

	for (int y = 0; y < MAX_ROWS; y++)
	{
		for (int x = 1; x < MAX_COLUMNS; x++)
		{
			game_objects.push_back(new Brick(x * BRICK_WIDTH, BRICK_HEIGHT + y * BRICK_HEIGHT, 1 + (x + y) % BRICK_MAX_LIFE));
		}
	}

	return game_objects;
}

void Level::remove_game_object(GameObject* game_object)
{
	Level::game_objects.erase(std::remove(game_objects.begin(), game_objects.end(), game_object), game_objects.end());
	game_object = nullptr;
}

bool Level::is_ball_out_of_play(Ball* ball)
{
	return ball->get_y() - ball->get_radius() > player->max_y();
};