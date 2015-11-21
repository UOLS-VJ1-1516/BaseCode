#pragma once
#ifndef GAME_H
#define GAME_H
#include "SDL.h"
#include "vector"
#include "Player.h"
#include "Ghost.h"
#include "PlayState.h"
#include "MenuState.h"
#include "GameStateMachine.h"
#include "InputHandler.h"
#include "TextureManager.h"


class Game
{

private:
	Game();
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
	GameStateMachine * state;
	PlayState * play;
	MenuState * menu;
	//PauseState * pauseState;

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
	void quit();

	int getP_ANC();
	int getP_ALT();
	SDL_Renderer* getRender();

	GameStateMachine * getGameStateMachine();


protected:
	int m_PANC;
	int m_PALT;
	
	
};

#endif

