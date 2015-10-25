#pragma once
#ifndef GAME_H
#define GAME_H
#include "SDL.h"

class Game {
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool running;
	int mov;

public: 
	Game();
	~Game();
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool isRunning();
}
;

#endif

