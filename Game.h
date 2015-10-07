#pragma once
#include "SDL.h"
#include <ctime>
#include <random>

class Game
{
private:
	SDL_Window * window;
	SDL_Renderer * renderer;
	SDL_Event event;
	void HandleKeys(SDL_Scancode);
	bool Fullscreen;
	bool Running;
	int r, g, b;
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

