#pragma once

#include <vector>
#include "game_object.h"

class Level
{
public:
	Level();
	const std::vector<GameObject*>& get_objects() const;
private:
	std::vector<GameObject*> game_objects;
};
