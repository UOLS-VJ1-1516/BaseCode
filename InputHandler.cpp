#include "InputHandler.h"
#include "Game.h"

InputHandler* InputHandler::s_pInstance = 0;

InputHandler::InputHandler() {
	for (int i = 0; i < 3; i++)
	{
		m_mouseButtonStates.push_back(false);
	}

	m_mousePosition = new Vector2D(0, 0);
}

InputHandler::~InputHandler() {}

void InputHandler::update()
{
	m_keystates = SDL_GetKeyboardState(NULL);
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
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
		else if (event.button.type == SDL_MOUSEMOTION) {
			m_mousePosition->setX(event.button.x);
			m_mousePosition->setY(event.button.y);
		}
		else if (event.type == SDL_QUIT) {
			break;
			//m_exitClicked = true;
		}
	}
}

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
}

bool InputHandler::getMouseButtonState(int buttonNumber) {
	return m_mouseButtonStates[buttonNumber];
}

Vector2D* InputHandler::getMousePosition() {
	return m_mousePosition;
}

void InputHandler::clean() {};
