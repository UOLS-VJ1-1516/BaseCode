#include "InputHandler.h"

//Constructor
InputHandler::InputHandler() {
	m_keystates = SDL_GetKeyboardState(0);
	for (int i = 0; i < 3; i++)
	{
		m_mouseButtonStates.push_back(false);
	}
};

//Instancias
InputHandler* InputHandler::i_pInstance = 0;

//Función para el control de si se ha pulsado una tecla
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
};

//Función que updatea los diferentes estados de las entradas del usuario
void InputHandler::update() {
	m_keystates = SDL_GetKeyboardState(0);

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type) {
		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_mouseButtonStates[LEFT] = true;
				break;
			case SDL_BUTTON_MIDDLE:
				m_mouseButtonStates[MIDDLE] = true;
				break;
			case SDL_BUTTON_RIGHT:
				m_mouseButtonStates[RIGHT] = true;
				break;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_mouseButtonStates[LEFT] = false;
				break;
			case SDL_BUTTON_MIDDLE:
				m_mouseButtonStates[MIDDLE] = false;
				break;
			case SDL_BUTTON_RIGHT:
				m_mouseButtonStates[RIGHT] = false;
				break;
			}
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.setX(event.motion.x);
			m_mousePosition.setY(event.motion.y);
			break;
		default:
			break;
		}
	}
};