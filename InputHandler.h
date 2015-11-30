#pragma once
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
	bool isExitRequired();
	bool getMouseButtonState(int buttonNumber);
	Vector2D* getMousePosition();

private:
	InputHandler();
	static InputHandler* s_pInstance;
	const Uint8* m_keystates;
	std::vector<bool> m_mouseButtonStates;
	Vector2D* m_mousePosition;
	bool m_exitClicked;

};