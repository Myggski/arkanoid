#include "application.h"
#include <iostream>
#include <queue>
#include "game_settings.h"
#include "game.h"
#include "file_handler.h"

bool is_digits(const std::string& str)
{
	return std::all_of(str.begin(), str.end(), ::isdigit); // C++11
}

Application::~Application() {
	delete game;
	game = nullptr;
}

void Application::init() {
	int menu_option{};

	while (is_running) {
		show_menu();
		menu_option = get_input(1, 4);

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
	if (game) {
		delete game;
		game = nullptr;
	}

	game = new Game();
	game->init("Arkanoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, false);
}

void Application::start_level_editor() {
	show_editor();
	int current_row = 0;
	std::string column_value;
	std::vector<std::string> level;

	while (current_row < LEVEL_MAX_ROWS) {
		std::cout << "Enter 14 digits for row " << current_row + 1 << ":\n";
		column_value = get_string_input(14, 14);
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

int Application::get_input(int min_value, int max_value) {
	int value{ 0 };
	bool validInput{ false };

	while (!validInput) {
		std::cin >> value;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		validInput = value <= max_value && value >= min_value;

		if (!validInput) {
			std::cout << "Invalid input. Try again with digits only:\n";
		}
	}

	return value;
}

std::string Application::get_string_input(int min_length, int max_length) {
	std::string value{ "" };
	bool validInput{ false };

	while (!validInput) {
		std::cin >> value;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		validInput = value.length() <= min_length && value.length() >= max_length;

		if (!validInput) {
			std::cout << "Invalid input. Try again with digits only:\n";
		}
	}

	return value;
}

void Application::show_menu() {
	system("cls");

	std::cout << "Welcome to Arkanoid\n";
	std::cout << "-------------------\n";
	std::cout << "1. Play Game\n";
	std::cout << "2. Edit Level\n";
	std::cout << "3. Remove Level\n";
	std::cout << "4. Exit\n";
	std::cout << "-------------------\n\n";
	std::cout << "Select an option:\n";
}

void Application::show_editor() {
	system("cls");

	std::cout << "                             Arkanoid Level Editor\n";
	std::cout << "----------------------------------------------------------------------------------\n";
	std::cout << "|                                                                                |\n";
	std::cout << "|    A level can contain 14 columns and 5 rows of bricks (70 bricks in total)    |\n";
	std::cout << "|    This means you have to enter 14 digits (Between 0-3) in a row 5 times.      |\n";
	std::cout << "|    The number represents number of times it takes to destroy the brick.        |\n";
	std::cout << "|                                                                                |\n";
	std::cout << "|    0 = Empty Space (No Brick).                                                 |\n";
	std::cout << "|    1 = Brick with 1hp (Red Brick).                                             |\n";
	std::cout << "|    2 = Brick with 2hp (Green Brick).                                           |\n";
	std::cout << "|    3 = Brick with 3hp (Blue Brick).                                            |\n";
	std::cout << "|                                                                                |\n";
	std::cout << "----------------------------------------------------------------------------------\n\n";
}