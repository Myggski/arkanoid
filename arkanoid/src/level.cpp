#pragma once

#include "level.h"
#include "ball.h"
#include "player.h"

Level::Level()
{
	Player* player = new Player({ 120, 25, 45, 255 }, { 400-40, 500-25, 80, 25 });
	Ball* ball = new Ball({255, 255, 255, 255}, 8.f);
	game_objects.push_back(player);
	game_objects.push_back(ball);
}

const std::vector<GameObject*>& Level::get_objects() const
{
	return game_objects;
}
