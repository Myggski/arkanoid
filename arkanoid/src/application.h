#pragma once

#include <string>
#include "game.h"

class Application {
public:
	~Application();
	void init();
private:
	Game* game{ nullptr  };
	bool is_running{ true };
	int get_input(int min_value, int max_value);
	std::string get_string_input(int min_length, int max_length);
	void show_menu();
	void show_editor();
	void start_game();
	void start_level_editor();
	void remove_level();
	void quit();
};