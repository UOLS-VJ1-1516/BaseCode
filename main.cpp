#include "SDL.h"
#include "windows.h"
#pragma comment(lib, "user32.lib")


SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;


class colores {

public:void cambio() {

}

};



int main(int argc, char* args[])
{

	int r=255;
	int g=0;
	int b=0;


	// initialize SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create our window
		g_pWindow = SDL_CreateWindow("Videjuegos 1 - bachelor",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		640, 480,SDL_WINDOW_FULLSCREEN);

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

	do {
	
		SDL_SetRenderDrawColor(g_pRenderer, r, g, b, 255);

		// clear the window to black
		SDL_RenderClear(g_pRenderer);

		// show the window
		SDL_RenderPresent(g_pRenderer);

		// set a delay before quitting
		SDL_Delay(10);

		
		if ((r > 0) && (b == 0))  {
			r--;
			g++;
		}

		if ((g > 0) && (r == 0)){
			g--;
			b++;
		}

		if ((g == 0) && (b > 0)) {
			b--;
			r++;
		}


	} while (GetAsyncKeyState(VK_ESCAPE) == 0);
	
	// clean up SDL
	SDL_Quit();

	return 0;
}