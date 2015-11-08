#pragma once
#include "InputHandler.h"
#include "Game.h"




InputHandler* InputHandler::s_pInstance = 0;
InputHandler::InputHandler() { InputHandler::m_keystate = 0; };
InputHandler::~InputHandler() {};




void InputHandler::update() {

	
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
		}
	

};
void InputHandler::clean() {

};
// Métodos de acceso
bool InputHandler::isKeyDown(SDL_Scancode key) {
	if (m_keystate != 0) {
		if (m_keystate[key] == 1) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}