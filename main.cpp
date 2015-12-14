#include "game.h"

const int FPS = 60;
const float DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* args[]){

	// Iniciamos el game
	Game::Instance()->init("Ejercicio 5", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 512, false);

	//Mientras no se quiera cerrar el game, se llama repetidamente a las funciones del while
	while (Game::Instance()->isRunning())
	{
		Uint32 frameStart = SDL_GetTicks();
		Game::Instance()->handleEvents();
		Game::Instance()->update();
		Game::Instance()->render();

		Uint32 frameEnd = SDL_GetTicks();
		Uint32 frameTime = frameEnd - frameStart;
		if (frameTime < DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}
	}
	Game::Instance()->clean();
	return 0;
}