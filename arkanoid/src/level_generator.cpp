#include "level_generator.h"
#include <iostream>
#include "file_handler.h"
#include "game_settings.h"

const std::vector<Brick*>& LevelGenerator::get_level_from_file() {
	std::vector<std::string> stringed_level = FileHandler::load_from_file();
	std::vector<Brick*> level;

	if (!stringed_level.empty()) {
		for (int y = 0; y < LEVEL_MAX_ROWS; y++) {
			std::string current_row = stringed_level[y];

			for (int x = 0; x < LEVEL_MAX_COLUMNS; x++) {
				char current_column = current_row.at(x);

				if (current_column) {
					int brick_life = current_column - '0';

					if (brick_life < 0) {
						brick_life = 0;
					}
					else if (brick_life > 3) {
						brick_life = 3;
					}

					if (brick_life == 0) {
						level.push_back(NULL);
					}
					else {
						level.push_back(new Brick(LEVEL_X_OFFSET + x * BRICK_WIDTH, LEVEL_Y_OFFSET + y * BRICK_HEIGHT, brick_life));
					}
				}
			}
		}
	}

	return level;
}