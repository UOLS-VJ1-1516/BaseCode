#include "SDL.h"
#include "game.h"


int main(int argc, char* args[])
{
	Game game;
	SDL_Event event;
	
	game.init("videojocs 1 - PROJECTO", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, true);
	
	while(game.isRunning()){
		while (SDL_PollEvent(&event)) {
			game.handleEvents(event);
		}
		game.update();
		game.render();
		
	}
	game.clean();
	return 0;

}