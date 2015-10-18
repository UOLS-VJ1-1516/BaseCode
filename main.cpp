#include "SDL.h"
#include "game.h"


int main(int argc, char* args[]){
	// initialize SDL
	

	// everything succeeded lets draw the window
	// set to black // This function expects Red, Green, Blue and
	// Alpha as color values

	game game;

	game.init("Videojuegos1", 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, true);

	    int a = 255;
		int b = 255;
		int c = 255;

		game.clean();

		return 0;
	
}
