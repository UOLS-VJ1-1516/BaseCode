#pragma once
#include "Game.h"
#include "InputHandler.h"


InputHandler* InputHandler::s_pInstance = 0;


InputHandler::InputHandler() {
	for (int i = 0; i < 3; i++)
	{
		m_mouseButtonStates.push_back(false);
	}

	m_mousePosition = new Vector2D(0, 0);
}


InputHandler::~InputHandler() {
}

bool InputHandler::getMouseButtonState(int buttonNumber) {
	return m_mouseButtonStates[buttonNumber];
}

Vector2D* InputHandler::getMousePosition() {
	return m_mousePosition;
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


void InputHandler::update() {
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		m_keystates = SDL_GetKeyboardState(0);

		if (event.type == SDL_QUIT)
		{
			//funciona amb els dos
			//Game::Instance()->clean();
			quit = 1;
		}
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				m_mouseButtonStates[0] = true;
			}
			if (event.button.button == SDL_BUTTON_MIDDLE)
			{
				m_mouseButtonStates[1] = true;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				m_mouseButtonStates[2] = true;
			}
		}
		if (event.type == SDL_MOUSEBUTTONUP)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				m_mouseButtonStates[0] = false;
			}
			if (event.button.button == SDL_BUTTON_MIDDLE)
			{
				m_mouseButtonStates[1] = false;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				m_mouseButtonStates[2] = false;
			}
		}
		if (event.type == SDL_MOUSEMOTION)
		{
			m_mousePosition->setX((float)event.motion.x);
			m_mousePosition->setY((float)event.motion.y);
		}

	}

}

void InputHandler::clean() {};