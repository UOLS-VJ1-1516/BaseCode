#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include "vector"
#include "Player.h"


class Game
{
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Surface * img;
	static Game* s_pInstance;
	LoaderParams* l;
	Player* p;
	LoaderParams* l2;
	Player* e1;
	LoaderParams* l3;
	Player* e2;
	int spriteNum;


	bool running = true;
public:
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
		}
		return s_pInstance;
	}
	Game();
	~Game();
	bool init(const char* title, int xpos, int
		ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents(SDL_Event event);
	void clean();
	bool isRunning();
	SDL_Renderer* getRender();
	int getTicks();
	std::vector<Player*> m_gameObjects;
};