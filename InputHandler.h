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
	~InputHandler();
	void update();
	void clean();
	// Métodos de acceso
//	void onKeyUp();
//	void onKeyDown();
	bool isKeyDown(SDL_Scancode key);
	InputHandler();
	static InputHandler* s_pInstance;
private:
	const Uint8* m_keystates;

};