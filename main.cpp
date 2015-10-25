#include "game.h"


int main(int argc, char* args[])
{
	Game game;

	game.init("Videjuegos 1 - bachelor",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		640, 480,
		true);

	while (game.isRunning() == true) {

		game.handleEvents();
		game.update();
		game.render();
	}

	game.clean();

	//SDL_Delay(1000);
	SDL_Quit();

	return 0;
}