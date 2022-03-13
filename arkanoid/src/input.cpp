#include "input.h"

KeyEventMap Input::registered_events;

EventCallback Input::invoke_key_press = [](SDL_Event event)
{
	const SDL_Scancode scancode = event.key.keysym.scancode;
	const SDL_EventType event_type = static_cast<SDL_EventType>(event.type);

	if (registered_events.count(scancode))
	{
		const std::vector<InputCallback*>& callbacks = registered_events.at(scancode);
		for (const InputCallback* callback : callbacks)
		{
			(*callback)(event_type);
		}
	}
};

void Input::init(GameEventHandler* event_handler)
{
	event_handler->add_listener(SDL_KEYDOWN, &invoke_key_press);
	event_handler->add_listener(SDL_KEYUP, &invoke_key_press);
}

void Input::clean(GameEventHandler* event_handler)
{
	event_handler->remove_listener(SDL_KEYDOWN, &invoke_key_press);
	event_handler->remove_listener(SDL_KEYUP, &invoke_key_press);

	for (const auto& registered_event : registered_events)
	{
		for (auto* callback : registered_event.second)
		{
			remove_listener(registered_event.first, callback);
		}
	}

	registered_events.clear();
}

void Input::add_listener(const SDL_Scancode& scancode, InputCallback* callback) {
	if (!registered_events.count(scancode))
	{
		registered_events.insert(std::make_pair(scancode, std::vector<InputCallback*>(1, { callback })));
	} else 
	{
		registered_events.at(scancode).push_back(callback);
	}
}

void Input::remove_listener(const SDL_Scancode& scancode, InputCallback* callback) {
	std::vector<InputCallback*>& callbacks = registered_events.at(scancode);

	callbacks.erase(
		std::remove_if(callbacks.begin(), callbacks.end(), [&](const InputCallback* event_data) {
			return (*event_data).target<InputCallback>() == (*callback).target<InputCallback>();
			}),
		callbacks.end());

	if (callbacks.empty())
	{
		registered_events.erase(registered_events.find(scancode));
	}
}