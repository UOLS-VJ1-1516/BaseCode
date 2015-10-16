#include "Game.h"

int main(int argc, char* args[])
{
	Game game = Game();
	game.pause(); //Para quitar pausa apretas cualquier tecla (menos escape, que es para cerrar).
	if (game.init("Videjuegos 1 - bachelor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, true)) {
		game.render(); //Pintamos una vez, por si esta pausado que no se vea negro.
		while (game.isRunning()) {
			game.handleEvents();
			while (!game.isPaused()) {
				game.handleEvents();
				game.update();
				game.render();
			}
		}
	}
	game.clean();
	return 0;
}
