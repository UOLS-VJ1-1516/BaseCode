#include "InputHandler.h"

InputHandler* InputHandler::s_pInstance = 0;

InputHandler::InputHandler() {
	m_keystates = NULL;
	m_exitClicked = false;
}

InputHandler::~InputHandler() {

}

void InputHandler::update() {
	m_keystates = SDL_GetKeyboardState(NULL);

	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			m_exitClicked = true;
		}
	}
}

void InputHandler::clean() {
	m_exitClicked = false;
	m_keystates = NULL;
}

bool InputHandler::isKeyDown(SDL_Scancode key) {
	return m_keystates[key];
}

bool InputHandler::isExitClicked() {
	return m_exitClicked;
}