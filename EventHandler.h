#pragma once
#define NULL 0
#include <SDL.h>

class EventHandler
{
private:
	EventHandler();
	static EventHandler * handler;
	void HandleKeys(SDL_Scancode);
	void HandleUps(SDL_Scancode);
public:
	static EventHandler * GetInstance() 
	{
		if (handler == NULL)
		{
			handler = new EventHandler();
		}
		return handler;
	}
	~EventHandler();
	void HandleEvents();
};

