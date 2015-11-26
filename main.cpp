#include "Game.h"
#include<iostream>

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;
const int SIZE_WINDOW_HEIGHT = 900;
const int SIZE_WINDOWS_WIDTH = 1600;

int main(int argc, char** argv) {
	Uint32 frameStart, frameTime;
	Game::Instance()->init("Videojocs1 - bachelor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SIZE_WINDOWS_WIDTH, SIZE_WINDOW_HEIGHT, true); //SDL_WINDOW_SHOWN
	while (Game::Instance()->isRunning()) {
		frameStart = SDL_GetTicks();
		Game::Instance()->handleEvents();
		Game::Instance()->update();
		Game::Instance()->render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < DELAY_TIME) {
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}
	}
	
	Game::Instance()->clean();
	return 0;
}




