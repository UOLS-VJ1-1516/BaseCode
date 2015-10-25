#pragma once
#include "SDL.h"
class Game
{

public:

	SDL_Window* g_pWindow;
	SDL_Renderer* g_pRenderer;
	
	int r;
	int b;
	int g;
	Game();
	~Game();
	bool init(const char* title, int xpos, int
		ypos, int width, int height, bool fullscreen);
	void Render();
	void Update();
	void EventHandler();
	void Clear();
	bool IsRunning();
	SDL_Event event;
	bool tancar;
	int idImatg;
};