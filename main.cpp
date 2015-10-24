#include "SDL.h"
#include "game.h"

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int main(int argc, char* args[])
{	
	game gm;

	int running = gm.init("SDL_RenderCopy Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,0);

	if (running == 1) return 0;

	while (gm.isRunning())
	{
		gm.render();
		gm.handleEvents();
		gm.update();

	}

	gm.clean();

	return 0;
}