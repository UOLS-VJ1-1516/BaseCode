#pragma once

#include "SDL.h"
#include "TextureManager.h"
#include <vector>
#include "GameObject.h"
#include "LoaderParams.h"

class Game {
	Game();
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	int red, green, blue, alpha;
	const int maxColorValue = 255;
	bool running;
	static Game* instance;
	std::vector< GameObject* > gameObjects;

public:
	static Game * getInstance() {
		if (instance == NULL)
		{
			instance = new Game();
		}
		return instance;
	}
	SDL_Renderer* getRenderer();
	SDL_Window* getWindow();
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool isRunning();
	~Game();
};