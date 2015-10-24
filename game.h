#pragma once
#include <SDL.h>
//#include "SDL_image.h"


class game{
	SDL_Window* g_pWindow;
	SDL_Renderer* imgRender;
	bool running;
	int mov;

public:
	game();
	~game();
	bool init(const char * titulo, int xpos, int ypos, int typeWindow);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool isRunning();

	
	}
;

