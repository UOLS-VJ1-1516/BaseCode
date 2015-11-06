#pragma once
#ifndef GAME_H
#define GAME_H
#include "SDL.h"
#include "vector"
#include "Player.h"
#include "Ghost.h"

class Game
{

private:

	SDL_Window* win;
	SDL_Renderer* ren;
	SDL_Surface* bmp;
	SDL_Texture* tex;
	SDL_Rect dst;
	SDL_Event event;
	bool running;
	Player* p;
	Ghost* ghost;
	LoaderParams* loadghost;
	LoaderParams* lp;
	std::vector< GameObject* > m_gameObjects;

	Game();
	static Game* s_pInstance;

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
	int getP_ANC();
	int getP_ALT();
	SDL_Renderer* getRender();

protected:
	int m_PANC;
	int m_PALT;
	
	
};

#endif

