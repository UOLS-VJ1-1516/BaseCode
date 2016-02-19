
#include "InputHandler.h"

InputHandler* InputHandler::s_pInstance = 0;

InputHandler::InputHandler() {
	m_mouseButtonStates = std::vector<bool>(3, false);
	m_mousePosition = new Vector2D();
	m_state = NULL;
	m_mousePosition->setX(0);
	m_mousePosition->setY(0);
	salida = false;
}

bool InputHandler::Quit() {
	return salida;

}
void InputHandler::update()
{
	m_state = SDL_GetKeyboardState(NULL);

	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT)
		{
			salida = true;
		}

		else if (event.button.type == SDL_MOUSEMOTION) {
			m_mousePosition->setX(event.button.x);
			m_mousePosition->setY(event.button.y);
		}
		else if (event.button.type == SDL_MOUSEBUTTONDOWN) {
			if (event.button.button== SDL_BUTTON_LEFT) {
				m_mouseButtonStates[0] = true;
			}
			else if (event.button.button == SDL_BUTTON_MIDDLE) {
				m_mouseButtonStates[1] = true;
			}
			else if(event.button.button == SDL_BUTTON_RIGHT) {
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

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	return m_state[key];
}

bool InputHandler::getMouseButtonState(int buttonNumber)
{
	return m_mouseButtonStates[buttonNumber];
}
Vector2D* InputHandler::getMousePosition()
{
	return m_mousePosition;
}
void InputHandler::clean()
{
	m_state = NULL;
	m_mousePosition->setX(0);
	m_mousePosition->setY(0);
	salida = false;
	m_mouseButtonStates[0] = false;
	m_mouseButtonStates[1] = false;
	m_mouseButtonStates[2] = false;
}
//void InputHandler::onMouseButtonDown(SDL_Event& event)
//{
//	if (event.button.button == SDL_BUTTON_LEFT)
//	{
//
//		m_mouseButtonStates[LEFT] = true;
//	}
//
//}