#pragma once
#ifndef GAME_H
#define GAME_H
#include "SDL.h"
#include "vector"
#include "Player.h"

class Game
{
private:
	Game();
	SDL_Window* g_pWindow;
	SDL_Renderer* g_pRenderer;
	SDL_Event event;
	bool flag;
	static Game* s_pInstance;
	LoaderParams* l;
	Player* p;
	LoaderParams* l2;
	Player* p2;
	LoaderParams* l3;
	Player* p3;
public:
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
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
	std::vector<Player*> m_gameObjects;
};

#endif
