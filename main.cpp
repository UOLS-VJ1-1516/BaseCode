#include "Game.h"

const long FIXED_TIME = 20;

int main(int argc, char* args[])
{
	//Game game = Game();
	

	if (Game::Instance()->init("Videjuegos 1 - bachelor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false)) {
		while (Game::Instance()->isRunning()) {
			long frameStart = SDL_GetTicks();

			Game::Instance()->render();
			Game::Instance()->handleEvents();
			Game::Instance()->update();
			long frameEnd = SDL_GetTicks();
			long frameTime = frameEnd - frameStart;
			if (frameTime < FIXED_TIME)
			{
				SDL_Delay((int)(FIXED_TIME - frameTime));
			}

		}
		Game::Instance()->clean();
	}
	return 0;
}