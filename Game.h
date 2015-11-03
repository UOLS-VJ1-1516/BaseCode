#pragma once
#include <iostream>
#include "Tools.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Loaders.h"
#include <ctime>
#include <random>
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"

class Game
{
private:
	SDL_Window * window;
	SDL_Renderer * renderer;
	SDL_Event event;

	Game();

	static Game * joc;

	std::vector<Entity *> entitats;
	Player * player;

	int width, height;
	void HandleKeys(SDL_Scancode);
	bool Fullscreen;
	bool Running;
	bool takeScreenshot;
	int r, g, b, a;
public:
	static Game * GetInstance() 
	{
		if (joc == NULL)
		{
			joc = new Game();
		}
		return joc;
	};
	~Game();
	bool Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	bool IsRunning();
	void Clear();
	void EventHandler();
	void Update();
	void Render();
	void Close();
	SDL_Renderer * GetRenderer() { return this->renderer; }
	SDL_Window * GetWindow() { return this->window; }
};
