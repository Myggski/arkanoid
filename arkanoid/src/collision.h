#pragma once

#include "circle_object.h"
#include "rectangle_object.h"

bool circle_intersect(const CircleObject& a, const CircleObject& b);
bool aabb_intersect(const RectangleObject& a, const RectangleObject& b);
bool aabb_circle_intersect(const RectangleObject& a, const CircleObject& b);