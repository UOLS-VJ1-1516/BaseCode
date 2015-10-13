#pragma once

#include "SDL.h"

class Game {
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	int red, green, blue, alpha;
	const int maxColorValue = 255;
	bool running;

public:
	Game();
	~Game();
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool isRunning();
};