
#pragma once
#ifndef GAME_H
#define GAME_H
#include "SDL.h"
#include "vector"
#include "GameObject.h"
#include "Player.h"

class Game
{
public:

private:
	Game();
public:
	static Game* Instance()
	{
		if (g_Instance == 0)
		{
			g_Instance = new Game();
		}
		return g_Instance;
	}
	
	~Game();
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool isRunning();
	SDL_Renderer* getRender();
	int getScreenWidth();
	int getScreenHeight();
	int getTicks();
	//std::vector<Player*> m_players;
private:
	SDL_Window* g_pWindow;
	SDL_Renderer* g_pRenderer;
	SDL_Event event;
	bool flag;
	int spriteNum;
	std::vector< GameObject* > m_gameObjects;
	static Game* g_Instance;
	int screenWidth;
	int screenHeigth;
	
	LoaderParams* lp;
	LoaderParams* lp2;
	LoaderParams* lp3;
	Player* p1;
	Player* p2;
	Player* p3;
	

};

#endif