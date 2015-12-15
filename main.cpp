#include "game.h"
#include "cstdlib" //libreria para random


//aqui ajustamos la cantida de frames por segundo en los que se movera nuestro juego
const int FPS = 60;

//aqui ajustamos el tiempo de espera
const float DELAY_TIME = 1000.0f / FPS;



int main(int argc, char* args[])
{


	Game* game = Game::Instance();


	game->init("Videojuegos VictorCordobes", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 900, false);


	while (game->isRunning())
	{
		Uint32 frameStart = SDL_GetTicks();

		//
		//
		//
		//game::Instance()->render(rand() % 255) + 1, rand() % 255) + 1, rand() % 255) + 1);


		game->render();
		game->handleEvents();
		game->update();



		Uint32 frameEnd = SDL_GetTicks();
		Uint32 frameTime = frameEnd - frameStart;

		//formula para calcular el tiempo de Delay


		if (frameTime < DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}
	}

	game->clean();


	return 0;
}



//Entrega de Victor Cordobés ls31253