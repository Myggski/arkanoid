#pragma once

#include <vector>
#include "ball.h"
#include "player.h"

class GameObject;
class Level
{
public:
	Level();
	const std::vector<GameObject*>& get_objects() const;
private:
	std::vector<Ball*> balls;
	// std::vector<Brick*> bricks;
	Player* player;
	std::vector<GameObject*> game_objects;
};
