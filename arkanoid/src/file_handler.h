#pragma once

#include <string>
#include <vector>

namespace FileHandler {
	std::vector<std::string> load_from_file();
	void save_to_file(std::vector<std::string> level);
	void clear_file();
}