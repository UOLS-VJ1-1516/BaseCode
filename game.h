
#include "SDL.h"
#pragma once

class Game
{

	SDL_Window* m_pWindow = 0;
	SDL_Renderer* m_pRenderer = 0;
	int r;
	int g;
	int b;
	int quit;


public:
	Game();
	~Game();
	bool init(const char* title, int xpos, int
		ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool isRunning();
};