#include "Game.h"


int main(int argc, char* args[])
{
	Game game;

	int state  = game.init("Ejercicio Videojuegos 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200,1200  , SDL_WINDOW_FULLSCREEN);

	if (state == 1) return 0;

	while(game.isRunning())
	{
		game.handleEvents();
		game.update(10);
		game.render();
	}
	
	game.clean();

	return 0;
}