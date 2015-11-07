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
		~InputHandler() {};
		void update();
		void clean();

		// M�todos de acceso
		bool isKeyDown(SDL_Scancode key);

	private:
		InputHandler();
		static InputHandler* s_pInstance;

		Uint8* m_keystates;
};