#include "game.h"
const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;
const int SIZE_WINDOW_HEIGHT = 900;
const int SIZE_WINDOWS_WIDTH = 1600;

Game joc;


int main(int argc, char* args[])
{
	Uint32 frameStart, frameTime;
	joc.init("Videojocs1 - bachelor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SIZE_WINDOWS_WIDTH, SIZE_WINDOW_HEIGHT, true); //SDL_WINDOW_SHOWN

	while (joc.isRunning()) { 
		frameStart = SDL_GetTicks();
		joc.handleEvents();	
		joc.update();
		joc.render();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime< DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}


	}

	joc.clean();

	return 0;
};



