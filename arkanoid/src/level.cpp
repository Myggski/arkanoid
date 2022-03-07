#pragma once

#include "level.h"
#include "game_object.h"

Level::Level()
{
	balls = std::vector<Ball*>(1, { new Ball(this) });

	player = new Player(this);
	player->add_ball_to_hold(balls[0]);
	
	game_objects.push_back(player);
	game_objects.push_back(balls[0]);
}

const std::vector<GameObject*>& Level::get_objects() const
{
	return game_objects;
}
