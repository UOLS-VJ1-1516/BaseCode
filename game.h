#pragma once

#include "SDL.h"
#include "TextureManager.h"
#include <vector>
#include "GameObject.h"
#include "LoaderParams.h"
#include "GameStateMachine.h"

class Game {
	const int MAX_COLOR_VALUE = 255;

	Game();
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	int red, green, blue, alpha;
	bool running;
	static Game* instance;
	std::vector< GameObject* > gameObjects;
	GameStateMachine * gs_machine;

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
	void setRunning(bool running);
	GameStateMachine * getGameStateMachine();
	~Game();
};