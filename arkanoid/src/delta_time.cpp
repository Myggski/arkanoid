#include "delta_time.h"

float DeltaTime::delta_time{ 0 };
Uint64 DeltaTime::previous_ticks{ 0 };
const float& DeltaTime::dt = DeltaTime::delta_time;

void DeltaTime::refresh_dt()
{
	const Uint64 ticks = SDL_GetPerformanceCounter();
	const Uint64 delta_ticks = ticks - previous_ticks;
	previous_ticks = ticks;
	delta_time = static_cast<float>(delta_ticks) / static_cast<float>(SDL_GetPerformanceFrequency());
}