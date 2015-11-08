#pragma once
#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
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
	~InputHandler() {};
	SDL_Scancode update();
	void clean();
	bool isKeyDown(SDL_Scancode key);
	bool Quit();
const Uint8* m_estado=NULL;
private:
	
	
	static InputHandler* s_pInstance;
	
	InputHandler();
};

#endif INPUTHANDLER_H