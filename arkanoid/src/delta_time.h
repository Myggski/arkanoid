#pragma once

#include <SDL_timer.h>

struct DeltaTime final {
public:
	static void refresh_dt();
	static const float& delta_time;
private:
	static Uint64 previous_ticks;
	static float dt;
};