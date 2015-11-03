#pragma once
#include "SDL.h"
#include "vector"
#include "Player.h"
#include "Enemy.h"

class Game
{

	public:
		Game();
		static Game* Instance()
		{
			if (g_pInstance == 0)
			{
				g_pInstance = new Game();
			}
			return g_pInstance;
		}
		~Game();

		bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
		void render(int r, int g, int b);
		void update();
		void handleEvents(SDL_Event event);
		void clean();
		bool isRunning();
		SDL_Renderer* getRenderer();
		int getTicks();
		static Game* g_pInstance;
		SDL_Window* g_pWindow = 0;
		SDL_Renderer* g_pRenderer = 0;
		bool running = true;
		std::vector< GameObject* > m_gameObjects;
		LoaderParams* p1;
		LoaderParams* p2;
		LoaderParams* p3;
		GameObject* goku;
		GameObject* freezer;
		GameObject* shenron;
};
