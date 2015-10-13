#include "game.h"


int main(int argc, char* args[])
{
	game gm;

	gm.init("Ejercicio 1 Videojuegos", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 720, SDL_WINDOW_FULLSCREEN);
	
	while (gm.isRunning()) {
		gm.render();
		gm.update();
		gm.handleEvents();
	}
	
	gm.clean();





	return 0;
}