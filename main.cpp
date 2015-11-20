#include "game.h"

//SDL_Window* g_pWindow = 0;
//SDL_Renderer* g_pRenderer = 0;

int main(int argc, char* args[])
{
	bool fullscreen = true;
	const int FIXED_TIME = 16;
	int frameStart, frameEnd;
	Game* game = Game::getInstance();
	game->init("Videojocs 1", 100, 100, 800, 600, !fullscreen);
	
	while (game->isRunning()) {
		frameStart = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();
		frameEnd = SDL_GetTicks();
		if (frameEnd - frameStart < FIXED_TIME)
			SDL_Delay(FIXED_TIME - (frameEnd - frameStart));
	}
	game->clean();

	return 0;
}