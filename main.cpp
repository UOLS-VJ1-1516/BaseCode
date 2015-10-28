#include "Game.h"

int main(int argc, char* args[])
{
	//Game game = Game();

	if (Game::Instance()->init("Videjuegos 1 - bachelor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false)) {
		while (Game::Instance()->isRunning()) {
			Game::Instance()->render();
			Game::Instance()->handleEvents();
			Game::Instance()->update();
		}
		Game::Instance()->clean();
	}
	return 0;
}