#include "game.h"

const int P_ANC = 1280;
const int P_ALT = 720;

 
int main(int argc, char* args[])
{
	
	if (Game::Instance()->init("Videjuegos 1 - bachelor",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		P_ANC, P_ALT, SDL_WINDOW_FULLSCREEN)) {

		while (Game::Instance()->isRunning())
		{
			Game::Instance()->handleEvents();
			Game::Instance()->render();
			Game::Instance()->update();

		}

		Game::Instance()->clean();
	}
	return 0;
}
