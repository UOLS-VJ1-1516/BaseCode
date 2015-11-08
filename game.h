#pragma once

#include "SDL.h"
#include "vector"

class Game
{
	SDL_Window* m_pWindow;
	private:
		Game();
	public:
	static Game* Instance()
	{
		if (g_pInstance == 0)
		{
			g_pInstance = new Game();
		}
		return g_pInstance;
	}
	~Game();
	bool init( const char* title , int xpos , int
		ypos , int width, int height , bool fullscreen );
	void render();
	void update();
	void handleEvents();
	void clean();
	void quit() { running = false; };
	bool isRunning();
	SDL_Renderer* getRenderer();

private:
	bool running = true;

	static Game* g_pInstance;
	SDL_Renderer* m_pRenderer;

	
};
