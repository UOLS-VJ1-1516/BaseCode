#pragma once
#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include "SDL.h"
#include "Vector2D.h"
#include <vector>

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
	~InputHandler() {};
	void update();
	void clean();
	bool isKeyDown(SDL_Scancode key);
	bool Quit();
	bool getMouseButtonState(int buttonNumber);
	Vector2D* getMousePosition();
	
private:
	InputHandler();
	static InputHandler* s_pInstance;
	Vector2D* m_mousePosition;
	std::vector<bool> m_mouseButtonStates;
	bool salida;
	const Uint8* m_state;
};
#endif INPUTHANDLER_H