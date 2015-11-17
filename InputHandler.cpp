#include "InputHandler.h"

InputHandler * InputHandler::s_pInstance = 0;
InputHandler::InputHandler()
{
	for (int i = 0; i < 3; i++)
	{
		m_mouseButtonStates[i] = false;
	}
	m_mousePosition = new Vector2D(0, 0);
}

void InputHandler::update(Uint32 key) {
	try {
		m_keystates[key] = 1;
	}
	catch (int e) {}
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

void InputHandler::onMouseButtonDown(Uint32 key) {
	m_mouseButtonStates[key] = true;
}
void InputHandler::onMouseButtonUp(Uint32 key)
{
	m_mouseButtonStates[key] = false;
}

void InputHandler::onMouseMotion(int x, int y)
{
	m_mousePosition->setX(x);
	m_mousePosition->setY(y);
}

Vector2D* InputHandler::getMousePosition()
{
	return m_mousePosition;
}

bool InputHandler::getMouseButtonState(Uint32 key) {
	return m_mouseButtonStates[key];
}

void InputHandler::clean() {}

