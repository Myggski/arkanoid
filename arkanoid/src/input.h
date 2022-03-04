#pragma once

#include "SDL.h"

class Input {
public:
	static void set_key_press(SDL_Scancode scancode, SDL_EventType eventType);
	static bool is_key_down(SDL_Scancode scancode);
private:
	static bool keys[SDL_NUM_SCANCODES];
};