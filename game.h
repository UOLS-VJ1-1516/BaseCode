#pragma once

#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "GameObject.h"
#include "vector"

class Game{
	private:
		Game();

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

	private:
		SDL_Window* m_pWindow;
		SDL_Renderer* m_pRenderer;
		bool running;
		int mov;
		static Game* s_pInstance;
		std::vector<GameObject*> m_gameObjects;
		GameObject* m_pGo;
};

#endif

