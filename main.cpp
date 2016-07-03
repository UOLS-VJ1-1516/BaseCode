#include "game.h"

const int FPS = 60;
const float FIXED_TIME = 1000.0f / FPS;

int main(int argc, char* args[])
{
	Uint32 frameStart, frameTime, frameEnd;

	if (Game::Instance()->init("Videjuegos 1 - bachelor",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		1280, 720, 0)) {

		while (Game::Instance()->isRunning()) {

			frameStart = SDL_GetTicks();

			Game::Instance()->handleEvents();
			Game::Instance()->update();
			Game::Instance()->render();
		 
			frameEnd = SDL_GetTicks();
			frameTime = frameEnd - frameStart;
			if (frameTime < FIXED_TIME)
			{
				SDL_Delay((int)(FIXED_TIME - frameTime));
			}
			


		}

		Game::Instance()->clean();
	}
	return 0;
}