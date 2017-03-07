#include "game.h"

int main(int argc, char* args[])
{
	Game game;
	SDL_Event event;
	int r = 255, g = 255, b = 0;

	game.init("Ejercicio 2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 900, false);

	while(game.isRunning())
	{
		while (SDL_PollEvent(&event)) {
			game.handleEvents(event);	
		}
		game.update();
		game.render(r-=1,g+=1,b);
	}
	game.clean();
	return 0;
}