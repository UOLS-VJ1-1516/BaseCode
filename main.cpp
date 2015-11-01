#include "game.h"

int main(int argc, char* args[])
{

	Game::Instance()->init("videojocs 1", 100, 100, 800, 600, false);


	while (Game::Instance()->isRunning() == true) {
		Game::Instance()->handleEvents();
		Game::Instance()->update();
		Game::Instance()->render();
	}

	Game::Instance()->clean();

	return false;
}