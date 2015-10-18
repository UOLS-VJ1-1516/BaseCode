#include "SDL.h"

class game
{

	//declaramos las variables tal y como estaban en el main.cpp
	SDL_Window* g_pWindow = 0;
	SDL_Renderer* g_pRenderer = 0;



public:
	game();
	~game();
	bool init( const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool isRunning();

};

