#pragma once
#ifndef GAME_H
#define GAME_H
#include <vector>
#include <SDL.h>
#include "SDL_image.h"
#include "time.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SDL_image.h"
#include "Player.h"
#include "Enemy.h"





class Game {

private:
	SDL_Window* g_lWindow;
	SDL_Renderer* g_lRenderer;
	std::vector <GameObject* > m_gameObjects;
	bool running;
	



public:
	
	Game();
	static Game* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Game();
		}
		return s_pInstance;

	}
	~Game();
	static Game* s_pInstance;
	bool init(const char* title, int xpos, int
		ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	int handleEvents();
	void clean();
	bool isRunning();

	SDL_Rect dst;
	SDL_Rect org;
	
	SDL_Renderer* GetRenderer() const {
		return g_lRenderer;
	}

};
#endif GAME_H


