#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include "InputHandler.h"
#ifndef GAME_H
#define GAME_H
class Game
{
private:
	Game();
public:
	~Game();
	bool init(const char* title, int xpos, int
		ypos, int width, int height, bool fullscreen);
	SDL_Renderer* getRender();
	void render();
	void update();
	void handleEvents();
	void clean();
	bool isRunning();
	static Game* Instance();
	bool running = false;
private:
	SDL_Window* g_lWindow = 0;
	SDL_Renderer* g_lRenderer = 0;
	//bool running = false;
	//int spriteNum;
	/*
	int mov = 0;
	int pos = 0;
	int animacion = 1;
	int cont = 0;
	*/
	static Game* s_pInstanceG;
};
#endif GAME_H