#include "brick.h"

#include "delta_time.h"
#include "level.h"

void Brick::update()
{
	destory_timer += DeltaTime::delta_time;
}

void Brick::hit()
{
	if (destory_timer <= destroy_delay)
	{
		return;
	}

	life--;
	destory_timer = 0;

	if (life <= 0)
	{
		Level::remove_brick(this);
		return;
	}

	color = get_color();
}
