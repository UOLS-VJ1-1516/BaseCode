#include "InputHandler.h"
#include <SDL.h>

const int SIZE_WINDOW_HEIGHT = 800;
const int SIZE_WINDOW_WIDTH = 800;
const int FIXED_TIME = 35;
InputHandler * InputHandler::s_pInstance = 0;
InputHandler::InputHandler()
{
}

void InputHandler::update(Uint32 key) {
	try {		
		m_keystates[key] = 1;
	}
	catch (int e){}
}

void InputHandler::updateKeyUp(Uint32 key) {
	try {
		m_keystates[key] = 2;
	}
	catch (int e) {}
}


bool InputHandler::isKeyDown(Uint32 key) {
	try {
		if (m_keystates[key] == 1) return true;				
	}
	catch (int e) {}
	return false;
}


bool InputHandler::isKeyUp(Uint32 key) {
	try {
		if (m_keystates[key] == 2) {
			m_keystates[key] = 0;
			return true;
		}		
	}
	catch (int e) {}
	return false;
}

void InputHandler::clean() {}
