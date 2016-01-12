#pragma once
#include <SDL.h>
#include "Player.h"
#include "Enemy.h"
#include "InputHandler.h"
#include "GameStateMachine.h"
#include "MenuState.h"
#include "PlayState.h"
#include "MenuStateOnPause.h"
#include <vector>


class Game
{

private :
	SDL_Window* g_pWindow ;
	SDL_Renderer* g_pRenderer;
	std::vector< GameObject* > m_gameObjects;
	bool state;
	int sprit;
	Game();
	static Game* s_pInstance;
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
	~Game();
	bool init(const char* tittle, int xPos, int yPos, int typeWindow);
	void render();
	void update(int delay);
	void handleEvents();
	void clean();
	bool isRunning();
	SDL_Renderer* getRenderer() const{ return g_pRenderer; }
	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }
	int getTicks();
	const int getwidthWindow() const;
	const int getHeightWindow() const;
};

