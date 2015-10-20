#pragma once

#include "SDL.h"

class Game
{
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

public:
	Game();
	~Game();
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents(SDL_Event event);
	void clean();
	bool isRunning();
};