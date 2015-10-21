#include "game.h"

Game joc;

int main(int argc, char* args[])
{

	joc.init("Videojocs1 - bachelor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, true); //SDL_WINDOW_SHOWN

	while (joc.isRunning()) { 
		joc.handleEvents();	
		joc.update();
		joc.render();
		SDL_Delay(550); 
	}

	joc.clean();

	return 0;
}



