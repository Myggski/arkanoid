#pragma once

#include <functional>
#include <unordered_map>
#include <SDL_events.h>

using EventCallback = std::function<void(const SDL_Event&)>;
using EventMap = std::unordered_map<SDL_EventType, std::vector<EventCallback*>>;

class GameEventHandler final
{
public:
	GameEventHandler();
	~GameEventHandler();
	void pull_events() const;
	void add_listener(const SDL_EventType& eventType, EventCallback* callback);
	void remove_listener(const SDL_EventType& eventType, EventCallback* callback);
private:
	EventMap registered_events;
	void trigger_event(const SDL_Event& event) const;
};