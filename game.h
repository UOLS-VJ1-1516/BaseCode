#pragma once
#include "SDL.h"
#include "vector"
#include "Player.h"
#include "Enemy.h"
#include "TextureManager.h"
#include "LoaderParams.h"
#include "InputHandler.h"

class Game
{
	private:
		Game();
	public:

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
		void render();
		void update();
		void handleEvents();
		void clean();
		bool isRunning();
		SDL_Renderer* getRenderer();
		int getTicks();
		int getScreenHeight();
		int getScreenWidth();
		void exit();

	private:
		static Game* g_pInstance;
		SDL_Window* g_pWindow = 0;
		SDL_Renderer* g_pRenderer = 0;
		bool running = true;
		int screenWidth;
		int screenHeigth;
		std::vector< GameObject* > m_gameObjects;
		LoaderParams* params1;
		LoaderParams* params2;
		GameObject* player1;
		GameObject* enemy1;
		GameObject* enemy2;
		GameObject* enemy3;
};
