#pragma once
#ifndef _Game_H
#define _Game_H
#include "SDL.h"

class Game
{
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

	SDL_Window* g_pWindow;
	SDL_Renderer* g_pRenderer;
	SDL_Event events;
	bool flag;
	int red;
	int green;
	int blue;
};

#endif