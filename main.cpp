#include "Game.h"


int main(int argc, char* args[])
{
	
	int state  = Game::Instance()->init("SDL_RenderCopy Example" , SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0);

	if (state == 1) return 0;

	while(Game::Instance()->isRunning())
	{
		Game::Instance()->render();
		Game::Instance()->handleEvents();
		Game::Instance()->update(100);
		
	}
	
	Game::Instance()->clean();

	return 0;
}