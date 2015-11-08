#pragma once
#include "SDL.h"
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
	InputHandler();
	void update();
	void clean();
	// Métodos de acceso
	bool isKeyDown(SDL_Scancode key);
	static InputHandler* s_pInstance;
	~InputHandler();
private:
	Uint8* m_keystate;
};