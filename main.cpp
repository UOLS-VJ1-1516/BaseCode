#include "game.h"

int main(int argc, char* args[])
{
	Game::Instance()->init("Videjuegos 1 - bachelor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false);
	//Game::Instance()->init("Videjuegos 1 - bachelor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
	while (Game::Instance()->isRunning()) {
		Game::Instance()->handleEvents();
		Game::Instance()->update();
		Game::Instance()->render();
	}
	Game::Instance()->clean();
	return 0;
}