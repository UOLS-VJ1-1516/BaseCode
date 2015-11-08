#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "InputHandler.h"

InputHandler* InputHandler::s_pInstance = 0;
bool exitok = false;
InputHandler::InputHandler(){}

bool InputHandler::Quit() {
	return exitok;

}
SDL_Scancode InputHandler::update()
{
	m_estado = SDL_GetKeyboardState(NULL);
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
		{
			exitok = true;
			return SDL_SCANCODE_ESCAPE;

		}
		
		
			if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
			{
				return SDL_SCANCODE_RIGHT;
				
			}
			if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
			{
				return SDL_SCANCODE_LEFT;

			}
			
			if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
			{
				return SDL_SCANCODE_UP;
			}
			if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
			{
				return SDL_SCANCODE_DOWN;
			}
			
	}
	
}


bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (m_estado != 0)
	{
		if (m_estado[key] == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}


