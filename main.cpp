#include "SDL.h"
#include "game.h"
#include "cstdlib" //libreria para random


int main(int argc, char* args[])
{
	
	int a = 0;
	int b = 0;
	int c = 0;

	game::Instance()->init("Juego classe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 800 , false);

	while (game::Instance()->isRunning())
	{
		
		game::Instance()->update();

		

		//game::Instance()->render(rand() % 255) + 1, rand() % 255) + 1, rand() % 255) + 1);

		game::Instance()->render(250, 150, 100);
	}
	game::Instance()->clean();
	return 0;
}


//Entrega deVictor Cordobés ls31253.zip
