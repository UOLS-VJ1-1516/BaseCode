#pragma once
#ifndef INPUTHANDLER
#define INPUTHANDLER
#include "SDL.h"
#include <vector>
#include "Vector2D.h"

class InputHandler
{
	public:
		enum mouse_buttons
		{
			LEFT = 0,
			MIDDLE = 1,
			RIGHT = 2
		};

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

		void onKeyDown();
		void onKeyUp();

		bool isKeyDown(SDL_Scancode key)const;
		bool getMouseButtonState(int buttonNumber);

		Vector2D* getMousePosition();

	private:
		
		InputHandler();
		Vector2D* m_mousePosition;		
		std::vector<bool> m_mouseButtonStates;
		const Uint8 *m_keystates;
		static InputHandler *s_pInstance;
};

typedef InputHandler TheInputHandler;


#endif INPUTHANDLER