#pragma once
#include "SDL.h"


class Game
{
	bool running;
public:
	Game();
	~Game();
	bool init(const char* title, int xpos, int
		ypos, int width, int height, bool fullscreen);
	void render(int red, int green, int blue);
	//void update();
	void handleEvents();
	void clean();
	bool isRunning();
};