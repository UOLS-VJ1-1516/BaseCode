#pragma once
#ifndef GAME_H
#define GAME_H
#include "SDL.h"

class Game
{
public:
	Game();
	~Game();
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void pause();
	void clean();
	bool isRunning();
	bool isPaused();
private:
	int* pixelesDeAncho;
	int* pixelesDeAlto;
	SDL_Window* g_pWindow;
	SDL_Renderer* g_pRenderer;
	SDL_Event event;
	bool running;
	bool paused;
	int numeroDivisiones;
	int numeroPixelesDivision;
	Uint32 lastTime;
	int tiempo;
};
	
#endif
