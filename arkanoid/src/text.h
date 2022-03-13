#pragma once
#include <string>

#include "rectangle_object.h"

class Text : public RectangleObject
{
public:
	Text(const std::string text, int offset_x = 0, int offset_y = 0, int font_size = 24);
	void draw(SDL_Renderer* render) const override;
	void update() override {}
private:
	std::string text;
	const int font_size;
};
