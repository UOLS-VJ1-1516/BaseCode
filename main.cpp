#include "game.h"
const int SIZE_WINDOW_HEIGHT = 900;
const int SIZE_WINDOWS_WIDTH = 1600;

Game joc;


int main(int argc, char* args[])
{

	joc.init("Videojocs1 - bachelor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SIZE_WINDOWS_WIDTH, SIZE_WINDOW_HEIGHT, true); //SDL_WINDOW_SHOWN

	while (joc.isRunning()) { 
		joc.handleEvents();	
		joc.update();
		joc.render();
		SDL_Delay(40); 
	}

	joc.clean();

	return 0;
};



