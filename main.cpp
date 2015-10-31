#include "game.h"

//SDL_Window* g_pWindow = 0;
//SDL_Renderer* g_pRenderer = 0;

int main(int argc, char* args[])
{
	//Game game;**NO SE PUEDE INSTANCIAR UNA CLASE SINGLETON!

	//game.init("videojocs 1", 100, 100, 1600, 900, false); 

	SDL_Event event;
	//**asi se instancia un singleton!
	Game::Instance()->init("Videjuegos 1 - bachelor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);


	while (Game::Instance()->isRunning())//mentres s'esta corrent executa les seguentes funcions
	{

		if (SDL_PollEvent(&event) == 1) {
			Game::Instance()->handleEvents(event); //**SINGLETON

		}
		//game.handleEvents(event); //**NEVER!! NO SE PUEDE CREAR OBJETOS DE UN SINGLETON
		Game::Instance()->render(); //**SINGLETON
		Game::Instance()->update(); //**SINGLETON


	}

	Game::Instance()->clean();//neteja el buffer abans de tancar la aplicacio

	return 0;

}