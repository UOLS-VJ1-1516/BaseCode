#pragma once
#ifndef GAME_H
#define GAME_H
#include "SDL.h"
#include <vector>
#include "SDL_image.h"
#include "texturemanager.h"
#include "GameObject.h"
#include "LoaderParams.h"
#include "PlayState.h"
#include "MenuState.h"
#include "GameStateMachine.h"

class Game
{
	private:
		Game();
		~Game();
		bool running;
	
		SDL_Window* g_pWindow;
		SDL_Renderer* g_pRenderer;
		
		std::vector< GameObject* > m_gameObjects;
		
		GameStateMachine* m_pGameStateMachine;
	
		
	public:
		static Game* Instance()
		{
			if (s_pInstance == 0)
			{
				s_pInstance = new Game();
			}
			return s_pInstance;
		}

		static Game* s_pInstance;
		bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
		void render();
		void handleEvents();
		void update();
		void clean();
		bool isRunning();
		SDL_Renderer * getRender();
		int getP();

		
		GameStateMachine * getStateMachine();

};

#endif

