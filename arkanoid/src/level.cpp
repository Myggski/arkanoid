#pragma once

#include "level.h"

#include <iostream>

#include "game_object.h"
#include "game_settings.h"
#include "brick.h"

static const int MAX_COLUMNS = (WINDOW_WIDTH / BRICK_WIDTH) - 1;
static const int MAX_ROWS = 5;

Level::Level() :
balls(std::vector<Ball*>(1, {new Ball(this)})),
player(new Player(this))
{
	create_level();

	for (const auto& brick : bricks)
	{
		game_objects.push_back(brick);
	}

	player->add_ball_to_hold(balls[0]);
	
	game_objects.push_back(player);
	game_objects.push_back(balls[0]);
}

const std::vector<GameObject*>& Level::get_objects() const
{
	return game_objects;
}

void Level::create_level()
{
	bricks = std::vector<Brick*>();

	for (int y = 0; y < MAX_ROWS; y++)
	{
		for (int x = 1; x < MAX_COLUMNS; x++)
		{
			bricks.push_back(new Brick(x * BRICK_WIDTH, BRICK_HEIGHT + y * BRICK_HEIGHT, 1 + (x + y) % BRICK_MAX_LIFE, this));
		}
	}
}

void Level::remove_brick(Brick* brick)
{
	std::cout << "REMOVE\n";
	bricks.erase(std::remove(bricks.begin(), bricks.end(), brick), bricks.end());
	game_objects.erase(std::remove(game_objects.begin(), game_objects.end(), brick), game_objects.end());
	//delete brick;
	brick = nullptr;
}
