#pragma once
#include "SDL.h"
class InputHandler
{
	Uint8* m_keystate;
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
	// Métodos de acceso
	bool isKeyDown(SDL_Scancode key) {
		if (m_keystate != 0) {
			if (m_keystate[key] == 1) {
				return true;
			}
			else {
				return false;
			}
			return false;
		}
	}
private:
	InputHandler();
	static InputHandler* s_pInstance;
};