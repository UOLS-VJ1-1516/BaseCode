#pragma once

#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "Player.h"
#include "vector"

class Game {
	private:
		Game();
		SDL_Window* m_pWindow;
		SDL_Renderer* m_pRenderer;
		SDL_Event event;
		bool running;
		static Game* s_pInstance;
		std::vector<GameObject*> m_gameObjects;
		Player* player1;
		Player* player2;
		Player* player3;
		LoaderParams* paramsPlayer1;
		LoaderParams* paramsPlayer2;
		LoaderParams* paramsPlayer3;

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

};

#endif

