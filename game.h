#pragma once

#include "SDL.h"
#include <vector>
#include "GameStateMachine.h"

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
	int getVisibleWidth() const{return m_viewWidth;}
	int getVisibleHeight() const {return m_viewHeight;}
	SDL_Renderer* getRenderer();
	GameStateMachine* getStateMachine();

private:
	bool running = true;
	int m_viewWidth, m_viewHeight;
	static Game* g_pInstance;
	SDL_Renderer* m_pRenderer;
	GameStateMachine* m_gameStateMachine;
	
};
