#include "game.h"

int main(int argc, char* args[]) {
	Game game;
	game.init("Videojocs 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 720, SDL_WINDOW_FULLSCREEN);

	while (game.isRunning()) {
		game.handleEvents();
		game.update();
		game.render();
	}
	game.clean();

	return 0;
}