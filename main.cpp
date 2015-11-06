#include "game.h"

const int FIXED_TIME = 60;

int main(int argc, char* args[])
{
	Uint32 frameStart, frameEnd, frameTime;

	Game::Instance()->init("videojocs 1", 100, 100, 800, 600, false);


	while (Game::Instance()->isRunning() == true) {
		frameStart = SDL_GetTicks();
		
		Game::Instance()->handleEvents();
		Game::Instance()->update();
		Game::Instance()->render();

		frameEnd = SDL_GetTicks();
		frameTime = frameEnd - frameStart;
		if (frameTime< FIXED_TIME)
		{
			SDL_Delay((int)(FIXED_TIME - frameTime));
		}

	}

	Game::Instance()->clean();

	return false;
}