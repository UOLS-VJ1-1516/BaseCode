#pragma once

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "SDL.h"
#include "Vector2D.h"
#include "vector"

class InputHandler {
	private:
		InputHandler();
		static InputHandler* s_pInstance;
		const Uint8* m_keystates;
		std::vector<bool> m_mouseButtonStates;
		Vector2D m_mousePosition;
		bool m_exitClicked;

	public:
		static InputHandler* Instance() {
			if (s_pInstance == 0) {
				s_pInstance = new InputHandler();
			}
			return s_pInstance;
		}
		~InputHandler();

		void update();
		void clean();

		//Metodos de acceso
		bool isKeyDown(SDL_Scancode key);
		bool isExitClicked();
		bool getMouseButtonState(int buttonNumber);
		Vector2D getMousePosition();

};

#endif