#pragma once
#include <map>
#include <stdint.h>
#include <iostream>
#include <vector>
#include "Vector2D.h"

typedef uint32_t Uint32;

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	enum mouse_buttons { LEFT = 0, MIDDLE = 1, RIGHT = 2 };
	~InputHandler() {};
	void update(Uint32 key);
	void clean();
	// Métodos de acceso
	bool isKeyDown(Uint32 key);
	void updateKeyUp(Uint32 key);
	bool isKeyUp(Uint32 key);
	void InputHandler::removeKeyUp(Uint32 key);
	void InputHandler::onMouseButtonDown(Uint32 key);
	void InputHandler::onMouseButtonUp(Uint32 key);
	void InputHandler::onMouseMotion(int x, int y);
	Vector2D* getMousePosition();
	bool getMouseButtonState(Uint32 key);

private:

	static InputHandler* s_pInstance;
	InputHandler();
	std::map< Uint32, int > m_keystates;
	std::map< Uint32, bool >m_mouseButtonStates;
	Vector2D* m_mousePosition;
};
