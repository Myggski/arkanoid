#pragma once

#include "game.h"

#include <string>

class Application {
public:
	~Application();
	void init();
private:
	Game* game{ nullptr  };
	bool is_running{ true };
	void start_game();
	void start_level_editor();
	void remove_level();
	void quit();
};