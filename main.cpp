#include "SDL.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int main(int argc, char* args[])
{
	// initialize SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
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

	int r = 0, g = 0, b = 0, a = 0;

	// Alpha as color values
	SDL_SetRenderDrawColor(g_pRenderer, 255, 0, 0, 10);

	// clear the window to black
	SDL_RenderClear(g_pRenderer);

	// show the window
	SDL_RenderPresent(g_pRenderer);

	while (true) {

		r = rand() % 255 + 0; 
		g = rand() % 255 + 0;
		b = rand() % 255 + 0;


		for (a = 0; a < 255; a += 5) {
			// Alpha as color values
			SDL_SetRenderDrawColor(g_pRenderer, r, g, b, a);

			// clear the window to black
			SDL_RenderClear(g_pRenderer);

			// show the window
			SDL_RenderPresent(g_pRenderer);

			SDL_Delay(10);
		}
	}

	// clean up SDL
	SDL_Quit();

	return 0;
}