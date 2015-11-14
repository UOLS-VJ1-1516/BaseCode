#pragma once
#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include "SDL.h"
#include "Vector2D.h"

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
	//void update();
	void clean();
	// Métodos de acceso
	bool isKeyDown(SDL_Scancode key);
	bool Quit();
	bool getMouseButtonState();
	Vector2D* getMousePosition();
	void onMouseButtonDown();
	const Uint8* m_state = NULL;
private:
	InputHandler();
	static InputHandler* s_pInstance;
	Vector2D* m_mousePosition;
};
#endif INPUTHANDLER_H