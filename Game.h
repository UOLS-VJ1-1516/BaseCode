#pragma once
#include <SDL.h>
#include "SDL_image.h"

class Game
{
	
	SDL_Window* g_pWindow ;
	SDL_Renderer* g_pRenderer;
	bool state;
	int sprit;

public:
	Game();
	~Game();
	
	bool init(const char* tittle, int xPos, int yPos, int typeWindow);
	void render();
	void update(int delay);
	void handleEvents();
	void clean();
	bool isRunning();
};

