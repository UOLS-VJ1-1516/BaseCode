#include "Game.h"


int main(int argc, char* args[])
{
	Game game;

	game.init("Ejercicio Videojuegos 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500,00  , SDL_WINDOW_FULLSCREEN);

	while(game.isRunning())
	{
		game.handleEvents();
		game.update(10);
		game.render();
	}
	
	game.clean();

	return 0;
}