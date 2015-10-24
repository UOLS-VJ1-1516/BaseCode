#pragma once
#include "Tools.h"
#include "SDL.h"
#include "Loaders.h"
#include <ctime>
#include <random>
#include "Player.h"

class Game
{
private:
	SDL_Window * window;
	SDL_Renderer * renderer;
	SDL_Event event;

	Player player;
	int width, height;
	void HandleKeys(SDL_Scancode);
	bool Fullscreen;
	bool Running;
	bool takeScreenshot;
	int r, g, b, a;
public:
	Game();
	~Game();
	bool Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	bool IsRunning();
	void Clear();
	void EventHandler();
	void Update();
	void Render();
	void Close();
};
