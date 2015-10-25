
#pragma once
#include "SDL.h"
#include "TextureManager.h"


class Game
{

	SDL_Window* m_pWindow = 0;
	SDL_Renderer* m_pRenderer = 0;
	SDL_Surface* image;
	int quit;
	int spriteNum;
	int numRow;

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