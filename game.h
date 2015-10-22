
#pragma once
#include "SDL.h"
#include "SDL_image.h"






class Game
{
	bool running;
public:
	Game();
	~Game();
	bool init(const char* title, int xpos, int
		ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	int handleEvents();
	void clean();
	bool isRunning();
	SDL_Rect dst;
	SDL_Rect org;


};



