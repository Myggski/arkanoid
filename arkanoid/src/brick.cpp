#include "brick.h"
#include "level.h"

void Brick::hit()
{
	life--;

	if (life <= 0)
	{
		Level::remove_game_object(this);
		return;
	}

	color = get_color();
}
