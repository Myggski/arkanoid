#pragma once

#include <vector>

class Ball;
class Brick;
class Player;
class GameObject;
class Level
{
public:
	static const std::vector<GameObject*>& get_objects();
	static void init();
	static void clean();
	static std::vector<GameObject*> create_level();
	static bool is_ball_out_of_play(const Ball* ball);
	static void remove_ball(Ball* ball);
	static void add_ball();
	static void remove_brick(Brick* brick);
	static bool is_game_lost()
	{
		return game_lost;
	}
	static bool is_game_won()
	{
		return game_won;
	}
	static bool is_game_over()
	{
		return game_won || game_lost;
	}
private:
	Level();
	static int number_of_balls;
	static int total_balls_spawned;
	static int number_of_bricks;
	static unsigned long long total_number_of_bricks;
	static Player* player;
	static std::vector<GameObject*> game_objects;
	static bool game_lost;
	static bool game_won;
	static void remove_game_object(GameObject* game_object);
	static int get_number_of_bricks_percentage();
	static void game_over();
};
