#include "game.h"
#include "SDL.h"

int main(int argc, char* args[]) {
	Game::Instance()->init("Videojocs 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

	while (Game::Instance()->isRunning()) {
		Game::Instance()->handleEvents();
		Game::Instance()->update();
		Game::Instance()->render();
	}
	Game::Instance()->clean();

	return 0;
}