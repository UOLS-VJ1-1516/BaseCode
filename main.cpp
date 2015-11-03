#include "game.h"

int main(int argc, char* args[])
{
	SDL_Event event;
	int r = 0, g = 0, b = 0;

	Game::Instance()->init("Juego classe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while(Game::Instance()->isRunning())
	{
		while (SDL_PollEvent(&event)) {
			Game::Instance()->handleEvents(event);
		}
		Game::Instance()->update();
		Game::Instance()->render(0, 0, 0);
	}
	Game::Instance()->clean();
	return 0;
}