#include "game.h"
#include "SDL.h"
#include "cstdlib" //libreria para random

const int frameRate = 60;
const int DELAY_TIME = 100 / frameRate;


int main(int argc, char* args[]) { 
	Uint32 frameStart, frameTime;
	SDL_Event event;
	Game::Instance()->init("Videjuegos Victor Cordobés", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1800, 600, false);

	while (Game::Instance()->isRunning()) {
		frameStart = SDL_GetTicks();

		if (SDL_PollEvent(&event) == 1) {
			Game::Instance()->handleEvents(event); 
		}
		//
		//
		//
		//game::Instance()->render(rand() % 255) + 1, rand() % 255) + 1, rand() % 255) + 1);


		Game::Instance()->render(); 
		Game::Instance()->update(); 
		frameTime = SDL_GetTicks() - frameStart;

		if (frameStart < DELAY_TIME) {
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}
	}
	Game::Instance()->clean();
	return 0;


}

//Entrega de Victor Cordobés ls31253