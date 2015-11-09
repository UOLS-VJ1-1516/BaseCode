#pragma once
#ifndef GAME_H
#define GAME_H
#include "SDL.h"
#include "TextureManager.h"
#include "vector"
#include "Player.h"
#include "Enemy.h"
#include "Enemy2.h"

class Game {
private:
	Game();
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Surface * img;
	static Game* s_pInstance;
	LoaderParams* load;
	Player* player;
	LoaderParams* load2;
	Enemy* enemy1;
	LoaderParams* load3;
	Enemy2* enemy2;
	int spriteNum;
	bool running = true;

public:
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
		}
		return s_pInstance;
	}

	~Game();
	bool init(const char* title, int xpos, int
		ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents(SDL_Event event);
	void clean();
	void quit() {running == false; }
	bool isRunning();
	SDL_Renderer* getRender();
	int getTicks();
	std::vector<GameObject*> m_gameObjects;
};
#endif