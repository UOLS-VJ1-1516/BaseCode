#include "game.h"

//SDL_Window* g_pWindow = 0;
//SDL_Renderer* g_pRenderer = 0;
const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* args[])
{
	//Game game;**NO SE PUEDE INSTANCIAR UNA CLASE SINGLETON!

	//game.init("videojocs 1", 100, 100, 1600, 900, false); 
	Uint32 frameStart, frameTime;
	SDL_Event event;
	//**asi se instancia un singleton!
	Game::Instance()->init("Videjuegos 1 - bachelor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);


	while (Game::Instance()->isRunning())//mentres s'esta corrent executa les seguentes funcions
	{
		frameStart = SDL_GetTicks();

		if (SDL_PollEvent(&event) == 1) {
			Game::Instance()->handleEvents(event); 

		}
		//game.handleEvents(event); 
		Game::Instance()->render(); 
		Game::Instance()->update(); 
		
		frameTime = SDL_GetTicks() - frameStart;
		if (frameStart < DELAY_TIME) {
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}


	}

	Game::Instance()->clean();//neteja el buffer abans de tancar la aplicacio

	return 0;

}