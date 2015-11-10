#pragma once
#include "Player.h"
#include "TextureManager.h"
#include "game.h"
#include "SDL.h"

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
private:
	InputHandler();
	static InputHandler* s_pInstanceI;
};

