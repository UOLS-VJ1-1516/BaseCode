#include "InputHandler.h"
#include "game.h"

InputHandler::InputHandler() {
	m_keystates = SDL_GetKeyboardState(0);
};

//Instancias
InputHandler* InputHandler::i_pInstance = 0;

bool InputHandler::isKeyDown(SDL_Scancode key) {
	if (m_keystates != 0)
	{
		if (m_keystates[key] == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
};

void InputHandler::update() {
	m_keystates = SDL_GetKeyboardState(0);

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type) {
			case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						Game::Instance()->exit();
						break;
				}
			break;
			default:
					break;		
		}
	}
};

void InputHandler::clean() {};