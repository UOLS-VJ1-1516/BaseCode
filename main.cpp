#include "game.h"

Game Joc;

int main(int argc, char* args[])
{
	Joc.init("Videjuegos 1 - bachelor",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,640, 480,SDL_WINDOW_SHOWN);
	//Joc.init("Videjuegos 1 - bachelor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false);
	while(Joc.isRunning()){
		Joc.handleEvents();
		Joc.update();
		Joc.render();
	}
	Joc.clean();
	return 0;
}