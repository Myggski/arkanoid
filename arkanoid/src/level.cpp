#pragma once

#include "level.h"
#include "game_object.h"
#include "ball.h"
#include "brick.h"
#include "level_generator.h"
#include "player.h"
#include "text.h"

int Level::number_of_balls{ 0 };
int Level::total_balls_spawned{ 0 };
int Level::number_of_bricks{ 0 };
unsigned long long Level::total_number_of_bricks{ 0 };
bool Level::game_lost{ false };
bool Level::game_won{ false };
std::vector<GameObject*> Level::game_objects;
Player* Level::player;

void Level::init() 
{
	player = new Player();
	game_objects.push_back(player);
	add_ball();

	const auto& bricks = LevelGenerator::create_level();
	number_of_bricks = bricks.size();
	total_number_of_bricks = number_of_bricks;

	for (const auto& brick : bricks)
	{
		game_objects.push_back(brick);
	}
}

void Level::clean()
{
	while (!game_objects.empty())
	{
		remove_game_object(game_objects[game_objects.size() - 1]);
	}

	number_of_balls = 0;
	total_balls_spawned = 0;
	number_of_bricks = 0;
	total_number_of_bricks = 0;
	game_lost = false;
	game_won = false;
	player = nullptr;
}

const std::vector<GameObject*>& Level::get_objects()
{
	return game_objects;
}

int Level::get_number_of_bricks_percentage()
{
	return ceil(100.f * (static_cast<float>(number_of_bricks) / static_cast<float>(total_number_of_bricks)));
}

void Level::add_ball()
{
	Ball* ball = new Ball();
	player->add_ball_to_hold(ball);
	game_objects.push_back(ball);
	number_of_balls++;
	total_balls_spawned++;
}

void Level::remove_ball(Ball* ball)
{
	remove_game_object(ball);
	number_of_balls--;

	if (number_of_balls <= 0)
	{
		game_lost = true;
		game_over();
	}
}

void Level::remove_brick(Brick* brick) 
{
	remove_game_object(brick);
	number_of_bricks--;

	if (number_of_bricks <= 0)
	{
		game_won = true;
		game_over();
		return;
	}

	const int bricks_left_percentage = get_number_of_bricks_percentage();
	const float spawn_after_percentage = ((100.f / MAX_BALLS_TO_SPAWN) * total_balls_spawned);

	if (100 - bricks_left_percentage >= spawn_after_percentage && total_balls_spawned < MAX_BALLS_TO_SPAWN)
	{
		add_ball();
	}
}

void Level::remove_game_object(GameObject* game_object)
{
	Level::game_objects.erase(std::remove(game_objects.begin(), game_objects.end(), game_object), game_objects.end());
	delete game_object;
	game_object = nullptr;
}

bool Level::is_ball_out_of_play(const Ball* ball)
{
	return ball->get_y() - ball->get_radius() > player->max_y();
};

void Level::game_over()
{
	
	if (game_lost)
	{
		game_objects.push_back(new Text("Game Over!"));
	} else if (game_won)
	{
		for (const auto& game_object : game_objects)
		{
			if (!dynamic_cast<Player*>(game_object))
			{
				remove_game_object(game_object);
			}
		}

		game_objects.push_back(new Text("You won!"));
	}

	game_objects.push_back(new Text("Press [R] To Restart", 0, 64, 18));
	game_objects.push_back(new Text("Press [Q] To Quit", 0, 90, 18));
}
