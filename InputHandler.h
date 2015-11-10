#pragma once
#include "game.h"

class InputHandler
{
	public:
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
		// Métodos de acceso
		bool isKeyDown(SDL_Scancode key);
	private:
		InputHandler();
		static InputHandler* i_pInstance;
		const Uint8* m_keystates;
};
