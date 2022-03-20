#include "application_output.h"

#include <iostream>

void ApplicationOutput::show_menu() {
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

void ApplicationOutput::show_editor() {
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

void ApplicationOutput::invalid_input_message() {
	std::cout << "Invalid input. Try again with digits only:\n";
}

void ApplicationOutput::invalid_level_input_message() {
	std::cout << "Invalid input. Try again with 14 digits between 0-3 only:\n";
}

void ApplicationOutput::current_row_message(const int& current_row)
{
	std::cout << "Enter 14 digits for row " << current_row + 1 << ":\n";
}