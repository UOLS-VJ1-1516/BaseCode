
#pragma once
#ifndef GAME_H
#define GAME_H
#include "SDL.h"
#include "string.h"
#include "SDL_image.h"
#include "Player.h"
#include <vector>




class Game {

private:
	SDL_Window* g_lWindow;
	SDL_Renderer* g_lRenderer;
	std::vector< GameObject* > m_gameObjects;
	bool running;




public:
	~Game() {};
	Game() {};

	static Game* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Game();
		}
		return s_pInstance;

	}
	bool init(const char* title, int xpos, int
		ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	int handleEvents();
	void clean();
	bool isRunning();

	SDL_Rect dst;
	SDL_Rect org;
	static Game* s_pInstance;
	SDL_Renderer* GetRenderer() const {
		return g_lRenderer;
	}

}
#endif GAME_H


