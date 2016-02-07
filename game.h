#pragma once

#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "Player.h"
#include "Enemy.h"
#include "StaticObject.h"
#include "StaticText.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "GameStateMachine.h"
#include "MenuState.h"
#include "vector"

class Game {
	private:
		Game();
		SDL_Window* m_pWindow;
		SDL_Renderer* m_pRenderer;
		bool running;
		static Game* s_pInstance;
		GameStateMachine* m_pGameStateMachine;

	public:
		static Game* Instance() {
			if (s_pInstance == 0) {
				s_pInstance = new Game();
			}
			return s_pInstance;
		}
		~Game();

		bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
		void render();
		void update();
		void handleEvents();
		void clean();
		bool isRunning();
		SDL_Renderer* getRender();
		int getTicks();
		int getWindowWidth();
		int getWindowHeight();
		void setIsRunning(bool run);
		GameStateMachine* getGameStateMachine();
};

#endif

