#include "game_settings.h"
#include "brick.h"

/* Game Settings */
const float WINDOW_WIDTH{ 800.f };
const float WINDOW_HEIGHT{ 600.f };

/* Level Level */
const int LEVEL_MAX_COLUMNS = (WINDOW_WIDTH / BRICK_WIDTH) - 2;
const int LEVEL_MAX_ROWS = 5;
const int BRICK_MAX_LIFE = 3;
const int TOTAL_BRICKS = LEVEL_MAX_COLUMNS * LEVEL_MAX_ROWS;
const int LEVEL_Y_OFFSET = BRICK_HEIGHT;
const int LEVEL_X_OFFSET = BRICK_WIDTH;