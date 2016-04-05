#include "game.h"

const int P_ANC = 1280;
const int P_ALT = 720;
const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;
 
int main(int argc, char* args[])
{
	Uint32 frameStart, frameTime;
	
	if (Game::Instance()->init("Videjuegos 1 - bachelor",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		P_ANC, P_ALT,0)) {

		while (Game::Instance()->isRunning())
		{
			frameStart = SDL_GetTicks();

			Game::Instance()->handleEvents();
			Game::Instance()->update();
			Game::Instance()->render();
			

			frameTime = SDL_GetTicks() - frameStart;

			if (frameTime< DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
		}

		Game::Instance()->clean();
	}
	return 0;
}
