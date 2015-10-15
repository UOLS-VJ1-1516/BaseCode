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
	void clean();
	bool isRunning();
private:
	int* pixelesDeAncho;
	int* pixelesDeAlto;
	SDL_Window* g_pWindow;
	SDL_Renderer* g_pRenderer;
	SDL_Event event;
	bool flag;
	int numeroDivisiones;
	int numeroPixelesDivision;
	int pixel;
	int divisionActual;
	Uint32 lastTime;
	int tiempo;
};
	
#endif
