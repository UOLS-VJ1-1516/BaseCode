#include "game.h"

int main(int argc, char* args[])
{

	Game game;

	game.init("videojocs 1", 100, 100, 800, 600, true);

	while (game.isRunning() == true) {
		game.handleEvents();
		game.update();
		game.render();
	}

	game.clean();

	return false;
}