#include "game.h"

int main(int argc, char* args[])
{
	SDL_Event event;
	int r = 255, g = 255, b = 0;

	// Iniciamos el game
	Game::Instance()->init("Ejercicio 3", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 500, false);

	//Mientras no se quiera cerrar el game, se llama repetidamente a las funciones del while
	while (Game::Instance()->isRunning())
	{
		while (SDL_PollEvent(&event)) {
			Game::Instance()->handleEvents(event);
		}
		Game::Instance()->update();
		Game::Instance()->render(255,255,255);
	}
	Game::Instance()->clean();
	return 0;
}