#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "InputHandler.h"

InputHandler* InputHandler::s_pInstance = 0;
bool salida = false;
InputHandler::InputHandler() {}

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

	}

}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	return m_state[key];
}

bool getMouseButtonState(int buttonNumber)
{
	return m_mouseButtonStates[buttonNumber];
}
Vector2D* getMousePosition()
{
	return m_mousePosition;
}
void InputHandler::onMouseButtonDown(SDL_Event& event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{

		m_mouseButtonStates[LEFT] = true;
	}

}