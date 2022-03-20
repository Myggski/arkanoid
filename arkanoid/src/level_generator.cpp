#include "level_generator.h"
#include "game_settings.h"
#include "file_handler.h"
#include "brick.h"

#include <string>

static const std::vector<Brick*> create_level_from_file(std::vector<std::string>& stringed_level) {
	std::vector<Brick*> bricks = std::vector<Brick*>();

	if (!stringed_level.empty()) {
		int max_columns = stringed_level.size() < LEVEL_MAX_ROWS ? stringed_level.size() : LEVEL_MAX_ROWS;

		for (int y = 0; y < max_columns; y++) {
			std::string current_row = stringed_level[y];
			int max_columns = current_row.length() < LEVEL_MAX_COLUMNS ? current_row.length() : LEVEL_MAX_COLUMNS;

			for (int x = 0; x < max_columns; x++) {
				char current_column = current_row.at(x);

				if (current_column) {
					int brick_life = current_column - '0';

					if (brick_life < 0) {
						brick_life = 0;
					}
					else if (brick_life > 3) {
						brick_life = 3;
					}

					if (brick_life > 0) {
						bricks.push_back(new Brick(LEVEL_X_OFFSET + x * BRICK_WIDTH, LEVEL_Y_OFFSET + y * BRICK_HEIGHT, brick_life));
					}
				}
			}
		}
	}

	return bricks;
}

static const std::vector<Brick*> create_default_level() {
	std::vector<Brick*> bricks = std::vector<Brick*>();

	for (int y = 0; y < LEVEL_MAX_ROWS; y++)
	{
		for (int x = 0; x < LEVEL_MAX_COLUMNS; x++)
		{
			bricks.push_back(new Brick(LEVEL_X_OFFSET + x * BRICK_WIDTH, LEVEL_Y_OFFSET + y * BRICK_HEIGHT, 1 + (x + y) % BRICK_MAX_LIFE));
		}
	}

	return bricks;
}

const std::vector<Brick*> LevelGenerator::create_level()
{
	std::vector<std::string> stringed_level = FileHandler::load_from_file();
	std::vector<Brick*> level = stringed_level.empty()
		? create_default_level()
		: create_level_from_file(stringed_level);

	return level;
}