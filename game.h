#pragma once
#include "SDL.h"
#include "TextureManager.h"

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
private:
	SDL_Window* g_lWindow = 0;
	SDL_Renderer* g_lRenderer = 0;
	bool running = false;
	int spriteNum;
	int mov = 0;
	int pos = 0;
	int animacion = 1;
	int cont = 0;
};