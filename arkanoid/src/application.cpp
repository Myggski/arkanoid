#include "application.h"
#include "application_input.h"
#include "application_output.h"
#include "game_settings.h"
#include "game.h"
#include "file_handler.h"

#include <iostream>
#include <queue>

Application::~Application() {
	delete game;
	game = nullptr;
}

void Application::init() {
	int menu_option{};

	while (is_running) {
		ApplicationOutput::show_menu();
		menu_option = ApplicationInput::get_input(1, 4);

		switch (menu_option) {
		case 1:
			start_game();
			break;
		case 2:
			start_level_editor();
			break;
		case 3:
			remove_level();;
			break;
		case 4:
			quit();
			break;
		}
	}
}

void Application::start_game() {
	system("cls");

	if (game) {
		delete game;
		game = nullptr;
	}

	game = new Game();
	game->init("Arkanoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, false);
}

void Application::start_level_editor() {
	ApplicationOutput::show_editor();
	int current_row = 0;
	std::string column_value;
	std::vector<std::string> level;

	while (current_row < LEVEL_MAX_ROWS) {
		ApplicationOutput::current_row_message(current_row);
		column_value = ApplicationInput::get_brick_level_input(LEVEL_MAX_COLUMNS, LEVEL_MAX_COLUMNS, BRICK_MAX_LIFE);
		level.push_back(column_value);
		current_row++;
	}

	FileHandler::save_to_file(level);
}

void Application::remove_level() {
	FileHandler::clear_file();
}

void Application::quit() {
	is_running = false;
}