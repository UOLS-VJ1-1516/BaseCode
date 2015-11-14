#include "InputHandler.h"
#include "game.h"

InputHandler * InputHandler::s_pInstance = 0;
InputHandler::InputHandler() {
	m_keystate = SDL_GetKeyboardState(0);
}
InputHandler::~InputHandler() {
}

void InputHandler::update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type) {
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				Game::Instance()->quit();
				break;
			}
			break;
		default:
			break;
		}
		if (event.button.type == SDL_MOUSEBUTTONDOWN) {
			if (event.button.button == SDL_BUTTON_LEFT) {
				m_mouseButtonStates[0] = true;
			}
			else if (event.button.button == SDL_BUTTON_MIDDLE) {
				m_mouseButtonStates[1] = true;
			}
			else if (event.button.button == SDL_BUTTON_RIGHT) {
				m_mouseButtonStates[2] = true;
			}
		}
		else if (event.button.type == SDL_MOUSEBUTTONUP) {
			if (event.button.button == SDL_BUTTON_LEFT) {
				m_mouseButtonStates[0] = false;
			}
			else if (event.button.button == SDL_BUTTON_MIDDLE) {
				m_mouseButtonStates[1] = false;
			}
			else if (event.button.button == SDL_BUTTON_RIGHT) {
				m_mouseButtonStates[2] = false;
			}
		}
	}
}

void InputHandler::clean()
{
	m_mouseButtonStates[0] = false;
	m_mouseButtonStates[1] = false;
	m_mouseButtonStates[2] = false;
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (m_keystate != 0)
	{
		if (m_keystate[key] == 1)
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
bool InputHandler::getMouseButtonState(int buttonNumber) {
	return m_mouseButtonStates[buttonNumber];

}
