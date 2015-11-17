#include "game.h"

const int FPS = 60;
const float DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* args[])
{
	Game* game = Game::Instance();

	// Iniciamos el game
	game->init("Ejercicio 5", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 500, false);

	//Mientras no se quiera cerrar el game, se llama repetidamente a las funciones del while
	while (game->isRunning())
	{
		Uint32 frameStart = SDL_GetTicks();
		game->render();
		game->handleEvents();
		game->update();

		Uint32 frameEnd = SDL_GetTicks();
		Uint32 frameTime = frameEnd - frameStart;
		if (frameTime < DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}
	}
	game->clean();
	return 0;
}