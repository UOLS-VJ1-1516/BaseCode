#pragma once
#include <SDL.h>

class Game
{
	
	SDL_Window* g_pWindow ;
	SDL_Renderer* g_pRenderer;
	bool state;

public:
	Game();
	~Game();
	
	bool init(const char* tittle, int xPos, int yPos, int width, int height, int typeWindow);
	void render();
	void update(int delay);
	void handleEvents();
	void clean();
	bool isRunning();
};

