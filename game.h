#pragma once
#include "SDL.h"
class Game
{
	SDL_Window* _window = 0;
	SDL_Renderer* _renderer = 0;
	bool _isRunning;
	SDL_Event event;
	int r, g, b;

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

