#include "game.h"
#include "SDL.h"

int main(int argc, char* args[]) {
	Game game;
	game.init("Videojocs 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, 0);

	while (game.isRunning()) {
		game.handleEvents();
		game.update();
		game.render();
	}
	game.clean();

	return 0;
}