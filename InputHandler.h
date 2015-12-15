#pragma once
#include "game.h"
#include "Vector2D.h"
#include <vector>


enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:

	/*
		~InputHandler() {};
	void update();
	void clean();
	bool isKeyDown(SDL_Scancode key);
	bool getMouseButtonState(int buttonNumber) { return m_mouseButtonStates[buttonNumber]; };
	Vector2D getMousePosition() { return m_mousePosition; };
	InputHandler();
	static InputHandler* i_pInstance;
	const Uint8* m_keystates;
	std::vector<bool> m_mouseButtonStates;
	Vector2D m_mousePosition;
	
	
	*/
	static InputHandler* Instance()
	{
		if (i_pInstance == 0)
		{
			i_pInstance = new InputHandler();
		}
		return i_pInstance;
	}


	~InputHandler() {};
	void update();
	void clean();
	bool isKeyDown(SDL_Scancode key);
	bool getMouseButtonState(int buttonNumber) { return m_mouseButtonStates[buttonNumber]; };
	Vector2D getMousePosition() { return m_mousePosition; };
	InputHandler();
	static InputHandler* i_pInstance;
	const Uint8* m_keystates;
	std::vector<bool> m_mouseButtonStates;
	Vector2D m_mousePosition;
};