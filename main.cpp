#include "game.h"

int main(int argc, char* args[])
{

	Game game = Game();

	if (game.init("Videjuegos 1 - bachelor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false)) {

		while (game.IsRunning()) {

			game.EventHandler();
			game.Update();
			game.Render();
		}
		game.Clear();
	}
		
	return 0;
}