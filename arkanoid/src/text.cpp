#include "text.h"
#include <SDL_ttf.h>
#include "game_settings.h"

Text::Text(const std::string text, int offset_x, int offset_y, int font_size) :
	RectangleObject(
		{255, 255, 255, 255},
		{ offset_x + (WINDOW_WIDTH / 2), offset_y + (WINDOW_HEIGHT / 2), 0, 0}
    ),
	text(text),
	font_size(font_size) { }

void Text::draw(SDL_Renderer* render) const
{
	TTF_Init();

	TTF_Font* font = TTF_OpenFont("./res/roboto.ttf", font_size);

	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), { 255, 255, 255, 255 });
	SDL_Texture* texture = SDL_CreateTextureFromSurface(render, surface);

	SDL_FreeSurface(surface);

	SDL_Rect message_rect;
	message_rect.x = rectangle.x - (surface->clip_rect.w / 2.f);
	message_rect.y = rectangle.y - (surface->clip_rect.h / 2.f);
	message_rect.w = surface->clip_rect.w;
	message_rect.h = surface->clip_rect.h;
	SDL_RenderCopy(render, texture, NULL, &message_rect);
	
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);
	TTF_Quit();
}

