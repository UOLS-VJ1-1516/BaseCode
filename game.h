#pragma once
#include "SDL.h"
#include "SDL_image.h"

class game
{
	SDL_Window* g_pWindow;
	SDL_Renderer* g_pRenderer;
	int spriteNum;
	int rowNum = 0;
	bool running = true;

public:
	game();
	~game();

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render(int r, int g, int b);
	void update();
	void handleEvents(SDL_Event event);
	void clean();
	bool isRunning();

};

