#pragma once

#include <vector>

class Ball;
class Player;
class GameObject;
class Level
{
public:
	static const std::vector<GameObject*>& get_objects();
	static void init();
	static std::vector<GameObject*> create_level();
	static void remove_game_object(GameObject* game_object);
	static bool is_ball_out_of_play(Ball* ball);
private:
	Level();
	static Player* player;
	static std::vector<GameObject*> game_objects;
};
