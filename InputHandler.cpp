#pragma once
#include "SDL_image.h"
#include "InputHandler.h"

InputHandler* InputHandler::s_pInstance = 0;
bool exitok = false;
InputHandler::InputHandler(	){
	m_estado = SDL_GetKeyboardState(NULL);
	for (size_t i = 0; i < 3; i++) {
		m_mouseButtonStates.push_back(false);
	}
	m_mPosition = new Vector2D(0, 0);
}

bool InputHandler::Quit() {
	return exitok;

}
SDL_Scancode InputHandler::update()
{
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
			}			if (event.button.type == SDL_MOUSEBUTTONDOWN) {
				if (event.button.button == SDL_BUTTON_LEFT) {
					m_mouseButtonStates[LEFT] = true;
				}
				else if (event.button.button == SDL_BUTTON_MIDDLE) {
					m_mouseButtonStates[MIDDLE] = true;
				}
				else if (event.button.button == SDL_BUTTON_RIGHT) {
					m_mouseButtonStates[RIGHT] = true;
				}			}			else if (event.button.type == SDL_MOUSEBUTTONUP) {
					if (event.button.button == SDL_BUTTON_LEFT) {
						m_mouseButtonStates[LEFT] = false;
					}
					else if (event.button.button == SDL_BUTTON_MIDDLE) {
						m_mouseButtonStates[MIDDLE] = false;
					}
					else if (event.button.button == SDL_BUTTON_RIGHT) {
						m_mouseButtonStates[RIGHT] = false;
					}
				}			if (event.button.type == SDL_MOUSEMOTION) {
				m_mPosition->setX((int)event.button.x);
				m_mPosition->setY((int)event.button.y);
				//printf("x= %d | y= %d\n", (int)event.button.x, (int)event.button.y);
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
	bool InputHandler::getMouseButtonState(int buttonNumber) {
		return m_mouseButtonStates[buttonNumber];

	}
	Vector2D* InputHandler::getMousePosition() {
		return m_mPosition;
	}

	void InputHandler::clean()
	{
		m_mouseButtonStates[0] = false;
		m_mouseButtonStates[1] = false;
		m_mouseButtonStates[2] = false;
	}