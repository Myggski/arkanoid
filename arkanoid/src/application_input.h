#pragma once

#include <string>

namespace ApplicationInput 
{
	int get_input(const int min_value, const int max_value);
	std::string get_brick_level_input(int min_length, int max_length, int brick_max_life);
}