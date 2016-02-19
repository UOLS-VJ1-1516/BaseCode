#include "InputHandler.h"
#include "game.h"

InputHandler * InputHandler::s_pInstance = 0;

InputHandler::InputHandler() {
	m_keystates = SDL_GetKeyboardState(0);
	for (int i = 0; i < 3; i++){
		m_mouseButtonStates.push_back(false);
	}
	m_mousePosition = new Vector2D(0,0);
}

InputHandler::~InputHandler() {
}

void InputHandler::update()
{
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
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
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				m_mouseButtonStates[LEFT] = false;
			}
			if (event.button.button == SDL_BUTTON_MIDDLE)
			{
				m_mouseButtonStates[MIDDLE] = false;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				m_mouseButtonStates[RIGHT] = false;
			}
		}
		if (event.type == SDL_MOUSEMOTION)
		{
			m_mousePosition->setX((float)event.motion.x);
			m_mousePosition->setY((float)event.motion.y);
		}
	}
	
}

void InputHandler::clean()
{
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
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

bool InputHandler::getMouseButtonState(int buttonNumber)
{
	return m_mouseButtonStates[buttonNumber];
}

Vector2D* InputHandler::GetMousePosition()
{
	return m_mousePosition;
}