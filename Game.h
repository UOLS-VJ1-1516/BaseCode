#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include "vector"
#include "Player.h"
#include "Enemy.h"


class Game {
public:

	Game();
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Surface * img;
	static Game* s_pInstance;

	Params* load;
	Params* load2;
	Player* player;
	Enemy* enemigo;
	
	int spriteNum;
	bool running = true;
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents(SDL_Event event);
	void clean();
	void quit() { running == false; }
	bool isRunning();
	SDL_Renderer* getRender();
	int getTicks();
	std::vector<GameObject*> m_gameObjects;

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
		}
		return s_pInstance;
	}

	~Game();

	
};
