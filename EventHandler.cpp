#include "EventHandler.h"
#include "Game.h"

EventHandler * EventHandler::handler = NULL;

EventHandler::EventHandler() {}

void EventHandler::HandleKeys(SDL_Scancode code)
{
	switch (code) {
	case SDL_SCANCODE_ESCAPE:
		Game::GetInstance()->Close();
		break;
	case SDL_SCANCODE_F11:
		Game::GetInstance()->ToggleFullscreen();
		break;
	case SDL_SCANCODE_F2:
		Game::GetInstance()->TakeScreenshot();
		break;
	case SDL_SCANCODE_A:
		Game::GetInstance()->GetPlayer()->xAccel = NEGATIVE;
		break;
	case SDL_SCANCODE_D:
		Game::GetInstance()->GetPlayer()->xAccel = POSITIVE;
		break;
	}
}

void EventHandler::HandleUps(SDL_Scancode code)
{
	if (code == SDL_SCANCODE_A || code == SDL_SCANCODE_D)
	{
		Game::GetInstance()->GetPlayer()->xAccel = NULL;
	}
}

EventHandler::~EventHandler()
{
}

void EventHandler::HandleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (&event == NULL)
			return;
		switch (event.type) {
		case SDL_KEYDOWN:
			HandleKeys(event.key.keysym.scancode);
			break;
		case SDL_KEYUP:
			HandleUps(event.key.keysym.scancode);
			break;
		case SDL_MOUSEBUTTONDOWN:
			break;
		default:
			break;
		}
	}
}
