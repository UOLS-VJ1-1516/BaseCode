#include "game.h"

//SDL_Window* g_pWindow = 0;
//SDL_Renderer* g_pRenderer = 0;

int main(int argc, char* args[])
{
	Game game;

	game.init("videojocs 1", 100, 100, 1600, 900, false); 
	SDL_Event event;


	while (game.isRunning() == true)//mentres s'esta corrent executa les seguentes funcions
	{

		if (SDL_PollEvent(&event) == 1) {
			game.handleEvents(event);

		}
		//game.handleEvents(event);
		game.render();
		game.update();


	}

	game.clean();//neteja el buffer abans de tancar la aplicacio

	return 0;

}