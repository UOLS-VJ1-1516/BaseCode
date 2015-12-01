
#pragma once
#ifndef GAME_H
#define GAME_H
#include "SDL.h"
#include "vector"
#include "GameObject.h"
#include "Player.h"
#include "InputHandler.h"
#include "Enemy.h"
#include "StaticObject.h"
#include "GameStateMachine.h"
#include "MenuState.h"
#include "PlayState.h"
#include "PauseState.h"
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
	void setIsRunning(bool f);
	SDL_Renderer* getRender();
	int getScreenWidth();
	int getScreenHeight();
	int getTicks();
	GameStateMachine* Game::getStateMachine();
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
	InputHandler* TheInputHandler;
	
	GameStateMachine* m_pGameStateMachine;
	

};

#endif