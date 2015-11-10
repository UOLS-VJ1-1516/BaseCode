#include "game.h"
#include "SDL.h"

const long FIXED_TIME = 20;
const int WIDTH = 800;
const int HEIGHT = 600;

int main(int argc, char* args[]) {
	Game::Instance()->init("Videojocs 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

	while (Game::Instance()->isRunning()) {
		long frameStart = SDL_GetTicks();
		Game::Instance()->handleEvents();
		Game::Instance()->update();
		Game::Instance()->render();
		long frameEnd = SDL_GetTicks();
		long frameTime = frameEnd - frameStart;
		if(frameTime < FIXED_TIME){
			SDL_Delay((int) (FIXED_TIME - frameTime));
		}
	}
	Game::Instance()->clean();

	return 0;
}