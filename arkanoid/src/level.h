#pragma once

#include <vector>
#include "ball.h"
#include "player.h"

class Brick;
class GameObject;
class Level
{
public:
	Level();
	const std::vector<GameObject*>& get_objects() const;
	void create_level();
	void remove_brick(Brick* brick);
private:
	std::vector<Ball*> balls;
	std::vector<Brick*> bricks;
	Player* player;
	std::vector<GameObject*> game_objects;
};
