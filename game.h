#pragma once
#include "SDL.h"
#include "vector"
#include "Player.h"
#include "enemy.h"

class game
{
private:
	game();
public:

	static game* Instance()
	{
		if (g_pInstance == 0)
		{
			g_pInstance = new game();
		}
		return g_pInstance;
	}
	~game();

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render(int r, int g, int b);
	void update();
	void handleEvents(SDL_Event event);
	void clean();
	bool isRunning();
	SDL_Renderer* getRenderer();
	int getTicks();

private:
	static game* g_pInstance;
	SDL_Window* g_pWindow = 0;
	SDL_Renderer* g_pRenderer = 0;
	bool running = true;
	std::vector< GameObject* > m_gameObjects;
	LoaderParams* params1;
	LoaderParams* params2;
	LoaderParams* params3;
	GameObject* player1;
	GameObject* enemy1;
	GameObject* enemy2;
};
