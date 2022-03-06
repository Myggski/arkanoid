#pragma once

#include <SDL_timer.h>

struct DeltaTime final
{
public:
	static void refresh_dt();
	static const float& dt;
private:
	static Uint64 previous_ticks;
	static float delta_time;
};

/**

static Uint64 previous_ticks{ 0 };
static float dt{ 0 };

inline void refresh_dt()
{
	const Uint64 ticks = SDL_GetPerformanceCounter();
	const Uint64 delta_ticks = ticks - previous_ticks;
	previous_ticks = ticks;
	dt = static_cast<float>(delta_ticks) / static_cast<float>(SDL_GetPerformanceFrequency());
}

inline const float& get_dt()
{
	return dt;
}


inline const Uint64& get_previous_ticks()
{
	return previous_ticks;
}
*/