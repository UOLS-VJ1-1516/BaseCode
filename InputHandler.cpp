
#include "InputHandler.h"

const Uint8* m_keystates;
InputHandler* InputHandler::s_pInstanceI = 0;
Vector2D m_mousePosition;
std::vector<bool> m_mouseButtonStates;
void InputHandler::update() {
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		m_keystates = SDL_GetKeyboardState(0);
		//comprovar/////////////////////////////////////////////////////////////
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				m_mouseButtonStates[LEFT] = true;
			}
			if (event.button.button == SDL_BUTTON_MIDDLE)
			{
				m_mouseButtonStates[MIDDLE] = true;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				m_mouseButtonStates[RIGHT] = true;
			}
		}
		if (event.type == SDL_MOUSEBUTTONUP)
			{
				if (event.button.button == SDL_BUTTON_MIDDLE)
				{
					m_mouseButtonStates[MIDDLE] = false;
				}
				if (event.button.button == SDL_BUTTON_RIGHT)
				{
					m_mouseButtonStates[RIGHT] = false;
				}
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					m_mouseButtonStates[LEFT] = false;
				}
		}

		if (event.type == SDL_MOUSEMOTION)
		{
			m_mousePosition.setX(event.motion.x);
			m_mousePosition.setY(event.motion.y);
		}

		//////////////////////////////////////////////////////////////////
	}
	if (event.type == SDL_MOUSEBUTTONUP)
	{
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			m_mouseButtonStates[LEFT] = false;
		}
	}
	/*
	if (isKeyDown(SDL_SCANCODE_ESCAPE)) {
		Game::Instance()->running = false;
	}
	*/
}
void InputHandler::clean() {}
// Métodos de acceso
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

InputHandler::InputHandler() {
	for (int i = 0; i < 3; i++)
	{
		m_mouseButtonStates.push_back(false);
	}
}


bool InputHandler::getMouseButtonState(int buttonNumber)
{
	return m_mouseButtonStates[buttonNumber];
}

Vector2D InputHandler::getMousePosition()
{
	return m_mousePosition;
}

void InputHandler::reset() {
	m_mouseButtonStates[MIDDLE] = false;
	m_mouseButtonStates[RIGHT] = false;
	m_mouseButtonStates[LEFT] = false;
}



