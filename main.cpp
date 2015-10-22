#include "game.h"


Game joc;

int main(int argc, char* args[])
{

	joc.init("Videojocs1 - bachelor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 900, true); //SDL_WINDOW_SHOWN

	while (joc.isRunning()) { 
		joc.handleEvents();	
		joc.update();
		joc.render();
		SDL_Delay(500); 
	}

	joc.clean();

	return 0;
}



