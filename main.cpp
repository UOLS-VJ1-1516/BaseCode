#include "Game.h"

int main(int argc, char* args[])
{
	Game game = Game();

	if (game.init("Videjuegos 1 - bachelor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, true)) {
		game.render();
		while (game.isRunning()) {
			game.clean();
			game.update();
			game.handleEvents();
		}
	}

	game.~Game();
	return 0;
}
