#include "Game.h"


int main(int argc, char* args[])
{
	Game game;

	int state  = game.init("SDL_RenderCopy Example" , SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0);

	if (state == 1) return 0;

	while(game.isRunning())
	{
		game.render();
		game.handleEvents();
		game.update(100);
		
	}
	
	game.clean();

	return 0;
}