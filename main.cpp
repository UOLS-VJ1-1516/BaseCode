#include "SDL.h"

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
SDL_KeyboardEvent;

int r = 0;
int b = 0;
int g = 0;
bool cerrar = true;


int main(int argc, char* args[])
{
	// initialize SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create our window
		g_pWindow = SDL_CreateWindow("Videjuegos 1 - bachelor",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		640, 480,
			SDL_WINDOW_ALLOW_HIGHDPI/*SDL_WINDOW_FULLSCREEN*/);

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

	//Bucle per fer que la pantalla canvii de colors
	while (cerrar) {
		if (r < 255) { //Color vermell
			r = r + 1;
		}
		else if(g < 255) { //Color verd
			g = g + 1;
		}
		else if(b < 255) { //Color blau
			b = b + 1;
		}
		else { //Tornem a començar
			r = 0;
			g = 0;
			b = 0;
		}

		//Fer que apretant esc srti del bucle i és tenqui l'aplicació
		if (SDL_KEYDOWN*SDLK_ESCAPE == true) {
			cerrar = false;
		}

		// everything succeeded lets draw the window
		// set to black // This function expects Red, Green, Blue and
		// Alpha as color values
		SDL_SetRenderDrawColor(g_pRenderer, r, g, b, 255);

		SDL_Delay(50); //Temps per que és noti el canvi de color


		// clear the window to black
		SDL_RenderClear(g_pRenderer);

		// show the window
		SDL_RenderPresent(g_pRenderer);

	}

	// set a delay before quitting
	//SDL_Delay(99999);

	// clean up SDL
	SDL_Quit();

	return 0;
}