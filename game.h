#pragma once
#include <SDL.h>
#include "Player.h"
#include "Player2.h"
#include <vector>

class Game
{

private:
	SDL_Window* g_pWindow;
	SDL_Renderer* imgRender;
	std::vector< GameObject* > m_gameObjects;
	bool running;
	int sprite;
	Game();

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

	static Game* s_pInstance;
	bool init(const char * titulo, int xpos, int ypos, int typeWindow);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool isRunning();
	SDL_Renderer * getRenderer();
	int getTicks();
	SDL_Renderer* getRenderer() const { return imgRender; }
};
