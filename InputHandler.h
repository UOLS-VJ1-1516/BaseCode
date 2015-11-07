#pragma once
#include "SDL.h"
#include "game.h"


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

		~InputHandler() {}
		
		void update() {
			
			SDL_Event esc_event;

			while (SDL_PollEvent(&esc_event)) {
				m_keystates = SDL_GetKeyboardState(0);
				switch (esc_event.type) {
				case SDL_KEYUP:
					switch (esc_event.key.keysym.sym) {
					case SDLK_ESCAPE:
						SDL_Quit();
						break;
					}
				}
			}

		}
		void clean() {};
		// Métodos de acceso
		bool isKeyDown(SDL_Scancode key) {
			if (m_keystates != 0)
			{
				if (m_keystates[key] == 1)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			return false;

		}

	private:
		InputHandler() {}
		static InputHandler* s_pInstance;
		const Uint8* m_keystates;
};