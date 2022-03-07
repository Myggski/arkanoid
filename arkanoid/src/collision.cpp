#include "collision.h"

float clamp(float a, float min, float max)
{
	if (a < min)
		return min;
	if (a > max)
		return max;

	return a;
}

bool circle_intersect(const CircleObject& a, const CircleObject& b)
{
	float dx = b.get_x() - a.get_x();
	float dy = b.get_y() - a.get_y();

	float dist_sqrd = dx * dx + dy * dy;
	float dist = sqrt(dist_sqrd);

	float radius_sum = a.get_radius() + b.get_radius();
	return dist < radius_sum;
}

bool aabb_intersect(const RectangleObject& a, const RectangleObject& b)
{
	return (a.max_x() > b.min_x() &&
		b.max_x() > a.min_x() &&
		a.max_x() > b.min_y() &&
		b.max_y() > a.min_y());
} 

bool aabb_circle_intersect(const RectangleObject& a, const CircleObject& b)
{
	float clamped_x = clamp(b.get_x(), a.min_x(), a.max_x());
	float clamped_y = clamp(b.get_y(), a.min_y(), a.max_y());

	float dx = b.get_x() - clamped_x;
	float dy = b.get_y() - clamped_y;

	float dist_sqrd = dx * dx + dy * dy;
	float dist = sqrt(dist_sqrd);

	return dist < b.get_radius();
}