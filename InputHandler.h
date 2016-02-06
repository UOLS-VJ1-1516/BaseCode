#pragma once
#include "Player.h"
#include "TextureManager.h"
#include "game.h"
#include "SDL.h"
#include <vector>
#include "Vector2D.h"
#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstanceI == 0)
		{
			s_pInstanceI = new InputHandler();
		}
		return s_pInstanceI;
	}
	~InputHandler() {};
	void update();
	void clean();
	// Métodos de acceso
	bool isKeyDown(SDL_Scancode key);
	bool getMouseButtonState(int buttonNumber);
	Vector2D getMousePosition();
	void reset();
private:
	InputHandler();
	static InputHandler* s_pInstanceI;

	enum mouse_buttons
	{
		LEFT = 0,
		MIDDLE = 1,
		RIGHT = 2
	};

	std::vector<bool> m_mouseButtonStates;

};
#endif INPUTHANDLER_H

