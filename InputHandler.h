#pragma once
#include "SDL.h"
#include "game.h"
#include "Vector2D.h"
#include <vector>


class InputHandler
{
	int quit = 0;

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
		bool isKeyDown(SDL_Scancode key);
		Vector2D* getMousePosition();
		bool getMouseButtonState(int buttonNumber);

	private:
		InputHandler();
		static InputHandler* s_pInstance;
		const Uint8* m_keystates;
		std::vector<bool> m_mouseButtonStates;
		Vector2D* m_mousePosition;
};