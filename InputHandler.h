#pragma once
#ifndef INPUTHANDLER
#define INPUTHANDLER
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
		void update();
		void clean();

		void onKeyDown();
		void onKeyUp();
		

		bool isKeyDown(SDL_Scancode key)const;

	private:
		InputHandler();
		~InputHandler();

		const Uint8 *m_keystates;

		static InputHandler *s_pInstance;
};

typedef InputHandler TheInputHandler;


#endif INPUTHANDLER