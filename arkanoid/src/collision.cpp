#include "collision.h"

static float clamp(float a, float min, float max)
{
	if (a < min)
		return min;
	if (a > max)
		return max;

	return a;
}

bool Collision::circle_intersect(const Collision::CircleCollider& a, const Collision::CircleCollider& b)
{
	float dx = b.x - a.x;
	float dy = b.y - a.y;

	float dist_sqrd = dx * dx + dy * dy;
	float dist = sqrt(dist_sqrd);

	float radius_sum = a.radius + b.radius;
	return dist < radius_sum;
}

bool Collision::aabb_intersect(const Collision::RectangleCollider& a, const Collision::RectangleCollider& b)
{
	return (a.max_x > b.min_x &&
		b.max_x > a.min_x &&
		a.max_x > b.min_y &&
		b.max_y > a.min_y);
} 

bool Collision::aabb_circle_intersect(const Collision::RectangleCollider& a, const Collision::CircleCollider& b)
{
	float clamped_x = clamp(b.x, a.min_x, a.max_x);
	float clamped_y = clamp(b.y, a.min_y, a.max_y);

	float dx = b.x - clamped_x;
	float dy = b.y - clamped_y;

	float dist_sqrd = dx * dx + dy * dy;
	float dist = sqrt(dist_sqrd);

	return dist < b.radius;
}