#include "game.h"

int main(int argc, char* args[])
{
	SDL_Event event;
	int r = 255, g = 255, b = 255;

	// Iniciamos el game
	game::Instance()->init("Ejercicio 3", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 800, true);

	//Mientras no se quiera cerrar el game, se llama repetidamente a las funciones del while
	while (game::Instance()->isRunning())
	{
		while (SDL_PollEvent(&event)) {
			game::Instance()->handleEvents(event);
		}
		game::Instance()->update();
		game::Instance()->render(r -= 1, g += 1, b);
	}
	game::Instance()->clean();
	return 0;
}