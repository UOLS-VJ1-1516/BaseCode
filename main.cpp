#include "game.h"



int main(int argc, char* args[])
{
	bool ok;
	Game game;
	
	ok = game.init("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false);

	if (ok)
	{
		while (game.isRunning())
		{
			game.handleEvents();
			game.update();
			game.render();
		}
		game.clean();
	}

	return 0;
}