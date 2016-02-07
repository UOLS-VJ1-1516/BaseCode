//#include "SDL.h"
#include "game.h"

//SDL_Window* g_pWindow = 0;
//SDL_Renderer* g_pRenderer = 0;
//const int FIXED_TIME = 35;


int main(int argc, char* args[])
{

	int running = Game::Instance()->init("SDL_RenderCopy Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0);

	if (running == 1) return 0;

	while (Game::Instance()->isRunning())
	{
		Game::Instance()->render();
		Game::Instance()->handleEvents();
		Game::Instance()->update(100);

			//int frameStart = SDL_GetTicks();
	//int frameEnd = SDL_GetTicks();
	//int frameTime = frameEnd - frameStart;
	//if (frameTime < FIXED_TIME)
	//{
		//SDL_Delay((int)(FIXED_TIME - frameTime));
	//}

	}

	Game::Instance()->clean();

	return 0;

}