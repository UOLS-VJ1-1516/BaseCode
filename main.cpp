#include "Game.h"

int main(int argc, char* args[])
{
	Game game = Game();
	//if (game.init("Videjuegos 1 - bachelor", 0, 0, 640, 480, true)) {

	game.init("Videjuegos 1 - bachelor", 0, 0, 1200, 720, true);
		game.render();
		while (game.isRunning()) {

			game.clean();
			game.update();
			game.handleEvents();
		}
		
	//}
	game.~Game();
	return 0;
}