#include "game_event_handler.h"

void GameEventHandler::pull_events() const
{
	SDL_Event ev;
	while (SDL_PollEvent(&ev)) {
		trigger_event(ev);
	}
}

void GameEventHandler::trigger_event(const SDL_Event& event) const
{
	const auto it = registered_events.find(static_cast<SDL_EventType>(event.type));
	if (it != registered_events.end())
	{
		const std::vector<EventCallback*>& callbacks = registered_events.at(static_cast<SDL_EventType>(event.type));
		for (const EventCallback* callback : callbacks)
		{
			(*callback)(event);
		}
	}
}

void GameEventHandler::add_listener(const SDL_EventType& eventType, EventCallback* callback) {
	if (!registered_events.count(eventType))
	{
		registered_events.insert(std::make_pair(eventType, std::vector<EventCallback*>(1, { callback })));
	}
	else
	{
		registered_events.at(eventType).push_back(callback);
	}
}

void GameEventHandler::remove_listener(const SDL_EventType& eventType, EventCallback* callback) {

	std::vector<EventCallback*>& callbacks = registered_events[eventType];

	callbacks.erase(
		std::remove_if(callbacks.begin(), callbacks.end(), [&](const EventCallback* event_data) {
			return (*event_data).target<EventCallback>() == (*callback).target<EventCallback>();
			}),
		callbacks.end());
}