#pragma once
#include <SDL.h>
class game{
	SDL_Window* g_pWindow;
	SDL_Renderer* g_pRenderer;
	bool running;

public:
	game();
	~game();
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool isRunning();

	
	}
;

