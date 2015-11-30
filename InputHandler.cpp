#include "InputHandler.h"
#include "game.h"

InputHandler * InputHandler::s_pInstance = 0;

InputHandler::InputHandler() {
	for (size_t i = 0; i < 3; i++) {
		m_mouseButtonStates.push_back(false);
	}
	m_mPosition = new Vector2D(0, 0);
	m_keystate = SDL_GetKeyboardState(0);
}
InputHandler::~InputHandler() {
}

void InputHandler::update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type) {
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				//Game::Instance()->quit();
				break;
			}
			break;
		default:
			break;
		}
		if (event.button.type == SDL_MOUSEBUTTONDOWN) {
			if (event.button.button == SDL_BUTTON_LEFT) {
				m_mouseButtonStates[LEFT] = true;
			}
			else if (event.button.button == SDL_BUTTON_MIDDLE) {
				m_mouseButtonStates[MIDDLE] = true;
			}
			else if (event.button.button == SDL_BUTTON_RIGHT) {
				m_mouseButtonStates[RIGHT] = true;
			}
		}
		else if (event.button.type == SDL_MOUSEBUTTONUP) {
			if (event.button.button == SDL_BUTTON_LEFT) {
				m_mouseButtonStates[LEFT] = false;
			}
			else if (event.button.button == SDL_BUTTON_MIDDLE) {
				m_mouseButtonStates[MIDDLE] = false;
			}
			else if (event.button.button == SDL_BUTTON_RIGHT) {
				m_mouseButtonStates[RIGHT] = false;
			}
		}
		if (event.button.type == SDL_MOUSEMOTION) {
			m_mPosition->setX((int)event.button.x);
			m_mPosition->setY((int)event.button.y);
			//printf("x= %d | y= %d\n", (int)event.button.x, (int)event.button.y);
		}
		
		
		
	}
}

void InputHandler::clean()
{
	m_mouseButtonStates[0] = false;
	m_mouseButtonStates[1] = false;
	m_mouseButtonStates[2] = false;
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (m_keystate != 0)
	{
		if (m_keystate[key] == 1)
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
Vector2D* InputHandler::getMousePosition() {
	return m_mPosition;
}
bool InputHandler::getMouseButtonState(int buttonNumber) {
	return m_mouseButtonStates[buttonNumber];

}
