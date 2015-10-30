#include "game.h"

int main(int argc, char* args[])
{
	SDL_Event event;
	int r = 255, g = 255, b = 0;

	// Iniciamos el game
	Game::Instance()->init("Ejercicio 3", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 800, true);

	//Mientras no se quiera cerrar el game, se llama repetidamente a las funciones del while
	while(Game::Instance()->isRunning())
	{
		while (SDL_PollEvent(&event)) {
			Game::Instance()->handleEvents(event);
		}
		Game::Instance()->update();
		Game::Instance()->render(r -= 1, g += 1, b);
	}
	Game::Instance()->clean();
	return 0;
}