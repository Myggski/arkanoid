#include "input.h"

void Input::set_key_press(SDL_Scancode scancode, SDL_EventType eventType) {
	keys[scancode] = eventType == SDL_KEYDOWN;
}

bool Input::is_key_down(SDL_Scancode scancode) {
	return keys[scancode];
}