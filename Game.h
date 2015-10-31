#pragma once
#ifndef GAME_H
#define GAME_H
#include "SDL.h"
#include "vector"
#include "Player.h"
#include "StaticObjects.h"
#include "Enemy.h"

class Game
{
private:
	Game();
	SDL_Window* g_pWindow;
	SDL_Renderer* g_pRenderer;
	SDL_Event event;
	bool flag;
	int screenWidth;
	int screenHeigth;
	static Game* s_pInstance;
	LoaderParams* lp;
	Player* p;
	LoaderParams* lo;
	StaticObjects* o;
	LoaderParams* le;
	Enemy* e;
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
	std::vector<Player*> m_players;
	std::vector<Enemy*> m_enemies;
	std::vector<StaticObjects*> m_objects;
	int getScreenWidth();
	int getScreenHeight();
};

#endif
