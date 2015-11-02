
#include "game.h"


int main(int argc, char* args[])
{
	SDL_Event event;
	
	Game::Instance()->init("videojocs 1 - PROJECTO", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	
	while(Game::Instance()->isRunning()){
		while (SDL_PollEvent(&event)) {
			Game::Instance()->handleEvents(event);
		}
		Game::Instance()->update();
		Game::Instance()->render();
		
	}
	Game::Instance()->clean();
	return 0;

}