#include "delta_time.h"

Uint64 DeltaTime::previous_ticks{ 0 };
float DeltaTime::dt{ 0 };
const float& DeltaTime::delta_time{ dt };

void DeltaTime::refresh_dt()
{
	const Uint64 ticks = SDL_GetPerformanceCounter();
	const Uint64 delta_ticks = ticks - previous_ticks;
	previous_ticks = ticks;
	dt = static_cast<float>(delta_ticks) / static_cast<float>(SDL_GetPerformanceFrequency());
};
