#pragma once
#include "SDL.h"
#include "vector"
#include "Player.h"
#include "Enemy.h"

class game {
	
public:
		game();
	
			
	static game* Instance() {

			if (g_pInstance == 0){

				g_pInstance = new game();
	}
				
return g_pInstance;
}
	~game();
			
	 bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
     void render(int r, int g, int b);
	 void update();
	 void clean();
	 bool isRunning();
	 SDL_Renderer* getRenderer();
	 int getTicks();

 public:

		static game* g_pInstance;
		SDL_Window* g_pWindow = 0;
		SDL_Renderer* g_pRenderer = 0;
		bool on = true;
		std::vector< GameObject* > m_gameObjects;

		Param* para1;
		Param* para2;
		Param* para3;


		GameObject* player1;
		GameObject* enemy1;
		GameObject* enemy2;
	};