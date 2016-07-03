#ifndef __INPUT_HANDLER_H__
#define __INPUT_HANDLER_H__

#include <vector>
#include "SDL.h"
#include "Vector2D.h"

class InputHandler {
	public:
		InputHandler();
		~InputHandler();

		static InputHandler* Instance() {
			if (s_pInstance == 0) {
				s_pInstance = new InputHandler();
			}
			return s_pInstance;
		}

		void update();

		bool isKeyDown(SDL_Scancode key);
		bool getMouseButtonState(int buttonNumber);
		Vector2D* getMousePosition();

		void clean();

	private:

		const Uint8 *m_keystates;

		static InputHandler *s_pInstance;
		std::vector<bool> m_mouseButtonStates;
		Vector2D* m_mousePosition;
};

#endif

