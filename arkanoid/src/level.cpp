#pragma once

#include "level.h"
#include "game_object.h"
#include "ball.h"
#include "brick.h"
#include "player.h"
#include "text.h"
#include "file_handler.h"

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

	const auto& bricks = create_level();

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

const std::vector<Brick*> Level::create_level_from_file(std::vector<std::string>& stringed_level) {
	std::vector<Brick*> bricks = std::vector<Brick*>();

	if (!stringed_level.empty()) {
		int max_columns = stringed_level.size() < LEVEL_MAX_ROWS ? stringed_level.size() : LEVEL_MAX_ROWS;

		for (int y = 0; y < max_columns; y++) {
			std::string current_row = stringed_level[y];
			int max_columns = current_row.length() < LEVEL_MAX_COLUMNS ? current_row.length() : LEVEL_MAX_COLUMNS;

			for (int x = 0; x < max_columns; x++) {
				char current_column = current_row.at(x);

				if (current_column) {
					int brick_life = current_column - '0';

					if (brick_life < 0) {
						brick_life = 0;
					}
					else if (brick_life > 3) {
						brick_life = 3;
					}

					if (brick_life > 0) {
						bricks.push_back(new Brick(LEVEL_X_OFFSET + x * BRICK_WIDTH, LEVEL_Y_OFFSET + y * BRICK_HEIGHT, brick_life));
					}
				}
			}
		}
	}

	return bricks;
}

const std::vector<Brick*> Level::create_default_level() {
	std::vector<Brick*> bricks = std::vector<Brick*>();

	for (int y = 0; y < LEVEL_MAX_ROWS; y++)
	{
		for (int x = 0; x < LEVEL_MAX_COLUMNS; x++)
		{
			game_objects.push_back(new Brick(LEVEL_X_OFFSET + x * BRICK_WIDTH, LEVEL_Y_OFFSET + y * BRICK_HEIGHT, 1 + (x + y) % BRICK_MAX_LIFE));
		}
	}

	return bricks;
}

const std::vector<Brick*> Level::create_level()
{
	std::vector<std::string> stringed_level = FileHandler::load_from_file();
	std::vector<Brick*> level = stringed_level.empty()
		? create_default_level() 
		: create_level_from_file(stringed_level);

	number_of_bricks = level.size();
	total_number_of_bricks = number_of_bricks;

	return level;
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
