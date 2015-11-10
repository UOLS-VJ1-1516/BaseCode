
#include "InputHandler.h"

const Uint8* m_keystates;
InputHandler* InputHandler::s_pInstanceI = 0;
void InputHandler::update() {
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		m_keystates = SDL_GetKeyboardState(0);
	}
	if (isKeyDown(SDL_SCANCODE_ESCAPE)) {
		Game::Instance()->running = false;
	}
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
InputHandler::InputHandler() {}
