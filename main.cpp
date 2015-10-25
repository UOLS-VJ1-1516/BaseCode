#include "game.h"

const int P_ANC = 1280;
const int P_ALT = 720;

 
int main(int argc, char* args[])
{
	Game game;
	
	if (game.init("Videjuegos 1 - bachelor",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		P_ANC, P_ALT, SDL_WINDOW_FULLSCREEN)) {

		while (game.isRunning())
		{
			game.handleEvents();
			game.render();
			game.update();

		}

		game.clean();
	}
	return 0;
}
