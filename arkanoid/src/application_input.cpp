#include "application_input.h"
#include "application_output.h"

#include <iostream>
#include <algorithm>

static bool is_brick_number(const char c, const int brick_max_life) {
	int number_value = c - '0';
	return std::isdigit(c) && (number_value >= 0 && number_value <= brick_max_life);
}

static bool contains_brick_life_values_only(const std::string& str, int brick_max_life)
{
	return std::all_of(str.begin(), str.end(), [&brick_max_life](char c) { return is_brick_number(c, brick_max_life); });
}

int ApplicationInput::get_input(const int min_value, const int max_value) {
	int value{ 0 };
	bool validInput{ false };

	while (!validInput) {
		std::cin >> value;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		validInput = value <= max_value && value >= min_value;

		if (!validInput) {
			ApplicationOutput::invalid_input_message();
		}
	}

	return value;
}

std::string ApplicationInput::get_brick_level_input(int min_length, int max_length, int brick_max_life) {
	std::string value{ "" };
	bool validInput{ false };

	while (!validInput) {
		std::cin >> value;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		validInput = value.length() <= min_length && value.length() >= max_length && contains_brick_life_values_only(value, brick_max_life);

		if (!validInput) {
			ApplicationOutput::invalid_level_input_message();
		}
	}

	return value;
}