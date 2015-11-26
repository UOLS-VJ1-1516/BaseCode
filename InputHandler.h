#pragma once
#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include "SDL.h"
#include "Vector2D.h"
#include "vector"

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
	void clean();
	~InputHandler() {};
	InputHandler();
	SDL_Scancode update();

	bool getMouseButtonState(int buttonNumber);
	Vector2D * getMousePosition();
	bool isKeyDown(SDL_Scancode key);
	static InputHandler* s_pInstance;
	bool Quit();
	const Uint8* m_estado = NULL;
private:
	Vector2D* m_mPosition;
	bool m_exitClik;
	std::vector<bool> m_mouseButtonStates;

};
enum mouse_buttons {
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

#endif INPUTHANDLER_H