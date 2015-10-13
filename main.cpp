#include "game.h"

//SDL_Window* g_pWindow = 0;
//SDL_Renderer* g_pRenderer = 0;

int main(int argc, char* args[])
{
	/*	// initialize SDL


	// everything succeeded lets draw the window
	// set to black // This function expects Red, Green, Blue and
	// Alpha as color values
	SDL_SetRenderDrawColor(g_pRenderer, 0, 10, 40, 255);

	// clear the window to black
	SDL_RenderClear(g_pRenderer);

	// show the window
	SDL_RenderPresent(g_pRenderer);

	// set a delay before quitting
	SDL_Delay(5000);

	// clean up SDL
	SDL_Quit();

	return 0;
	}*/

	Game game;
	game.init("Videojocs 1", 0, 0, 800, 600, true);

	while (game.isRunning()) {
		game.handleEvents();
		game.update();
		game.render();
	}
	game.clean();

	return 0;
}