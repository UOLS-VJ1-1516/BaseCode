#include "game.h"

//SDL_Window* g_pWindow = 0;
//SDL_Renderer* g_pRenderer = 0;

int main(int argc, char* args[])
{
	bool fullscreen = true;
	Game* game = Game::getInstance();
	game->init("Videojocs 1", 100, 100, 800, 600, !fullscreen);

	while (game->isRunning()) {
		game->handleEvents();
		game->update();
		game->render();
	}
	game->clean();

	return 0;
}