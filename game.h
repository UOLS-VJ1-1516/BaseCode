
#include "SDL.h"
#include "SDL_image.h"
#pragma once

class Game
{

	SDL_Window* m_pWindow = 0;
	SDL_Renderer* m_pRenderer = 0;
	SDL_Surface* load_Surf;
	//SDL_Texture* player;
	SDL_Texture* texture;
	SDL_Surface* walker;
	SDL_Rect Src;
	SDL_Rect Dest;
	int quit;
	int spriteNum;


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