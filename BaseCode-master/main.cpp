#include "SDL.h"
#include "game.h"

//SDL_Window* g_pWindow = 0;
//SDL_Renderer* g_pRenderer = 0;

int main(int argc, char* args[])
{
	// initialize SDL

	/*if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
	// if succeeded create our window
	g_pWindow = SDL_CreateWindow("Videjuegos 1 - bachelor",
	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	640, 480,
	SDL_WINDOW_SHOWN);

	// if the window creation succeeded create our renderer
	if(g_pWindow != 0)
	{
	g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
	}
	}
	else
	{
	return 1; // sdl could not initialize
	}

	// everything succeeded lets draw the window
	// set to black // This function expects Red, Green, Blue and
	// Alpha as color values
	SDL_SetRenderDrawColor(g_pRenderer, 0, 10, 40, 255);

	// clear the window to black
	SDL_RenderClear(g_pRenderer);

	// show the window
	SDL_RenderPresent(g_pRenderer);

	// set a delay before quitting
	SDL_Delay(5000);

	// clean up SDL
	SDL_Quit();
	*/

	Game game;

	game.init("videojocs 1", 100, 100, 1600, 900, true);

	while (game.isRunning() == true)//mentres s'esta corrent executa les seguentes funcions
	{
		SDL_Event event;
		
		while (SDL_PollEvent(&event)) {
			game.handleEvents(event);
			
		}
		//game.handleEvents(event);
		game.update();
		game.render();

	}

	game.clean();//neteja el buffer abans de tancar la aplicacio

	return 0;

}