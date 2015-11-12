#pragma once

#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "Player.h"
#include "Enemy.h"
#include "StaticObject.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "GameStateMachine.h"
#include "PlayState.h"
#include "vector"

class Game {
	private:
		Game();
		SDL_Window* m_pWindow;
		SDL_Renderer* m_pRenderer;
		SDL_Event event;
		bool running;
		static Game* s_pInstance;
		GameStateMachine* m_pGameStateMachine;
		/*std::vector<GameObject*> m_gameObjects;
		Player* player1;
		Enemy* enemy1;
		StaticObject* stObj1;
		LoaderParams* paramsPlayer1;
		LoaderParams* paramsEnemy1;
		LoaderParams* paramsStObj1;*/

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
};

#endif

