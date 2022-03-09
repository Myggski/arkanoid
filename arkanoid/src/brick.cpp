#include "brick.h"
#include "level.h"

void Brick::update(const float* dt) { }

void Brick::hit()
{
	life--;

	if (life <= 0)
	{
		level->remove_brick(this);
		return;
	}

	color = get_color();
}
