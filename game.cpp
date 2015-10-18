#include "game.h"




game::game()
{
}


game::~game()
{
}


//ahora añadimos las funciones declaradas en game.h y las rellenamos
bool game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	//en este caso añadimos el codigo que estaba incluido en el main.cpp
	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create our window
		g_pWindow = SDL_CreateWindow("Videjuegos 1 - Victor Cordobés",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			640, 480,
			SDL_WINDOW_SHOWN);

		// if the window creation succeeded create our renderer
		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
	}
	else
	{
		return 1; // sdl could not initialize
	}

};

void game::render() {


	SDL_SetRenderDrawColor(g_pRenderer, 0, 10, 40, 255);


	// clear the window to black
	SDL_RenderClear(g_pRenderer);

	// show the window
	SDL_RenderPresent(g_pRenderer);

	
};


void game::update() {


	SDL_Delay(9000);

};


void game::handleEvents() {


};


void game::clean() {


	// clean up SDL
	SDL_Quit();

};


bool game::isRunning() {

	//return running;


};



