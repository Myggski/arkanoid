#pragma once

#include <unordered_map>
#include <vector>
#include "SDL.h"
#include "game_event_handler.h"

using InputCallback = std::function<void(const SDL_EventType&)>;
using KeyEventMap = std::unordered_map<SDL_Scancode, std::vector<InputCallback*>>;

class Input final {
public:
	static void init(GameEventHandler* eventHandler);
	static void clean(GameEventHandler* eventHandler);
	static void add_listener(const SDL_Scancode& scancode, InputCallback* callback);
	static void remove_listener(const SDL_Scancode& scancode, InputCallback* callback);
private:
	static KeyEventMap registered_events;
	static EventCallback invoke_key_press;
};