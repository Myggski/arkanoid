#pragma once

namespace Math
{
	inline float clamp(float a, float min, float max)
	{
		if (a < min)
			return min;
		if (a > max)
			return max;

		return a;
	}
}