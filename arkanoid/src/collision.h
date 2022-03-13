#pragma once

#include "circle_object.h"
#include "math_helper.h"
#include "rectangle_object.h"

namespace Collision
{
	struct RectangleCollider
	{
		RectangleCollider(const RectangleObject& rectangle_object) :
		min_x(rectangle_object.min_x()),
		min_y(rectangle_object.min_y()),
		max_x(rectangle_object.max_x()),
		max_y(rectangle_object.max_y()) {}
		const float min_x{ 0 };
		const float min_y{ 0 };
		const float max_x{ 0 };
		const float max_y{ 0 };
	};

	struct CircleCollider
	{
		CircleCollider(float radius, const float x, const float y) : radius(radius), x(x), y(y) {}
		CircleCollider(const CircleObject& circle_object, const float& dx, const float& dy) : radius(circle_object.get_radius()),
			x(circle_object.get_x() + dx), y(circle_object.get_y() + dy) {}
		float get_distance_aabb_x(const Collision::RectangleCollider& a) const
		{
			return x - Math::clamp(x, a.min_x, a.max_x);
		}
		const float radius{ 0 };
		const float x{ 0 };
		const float y{ 0 };
	};

	bool circle_intersect(const CircleCollider& a, const CircleCollider& b);
	bool aabb_intersect(const RectangleCollider& a, const RectangleCollider& b);
	bool aabb_circle_intersect(const RectangleCollider& a, const CircleCollider& b);
	float get_distance_aabb_circle(const Collision::RectangleCollider& a, const Collision::CircleCollider& b);
}
