#include "game.h"
#include <stdlib.h>



game::game()
{

	g_pWindow = 0;
	g_pRenderer = 0;
}


game::~game(){
	

}



bool game::init(const char * titulo, int xpos, int ypos, int width, int height, bool fullscreen) {

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create our window
		g_pWindow = SDL_CreateWindow(titulo,xpos, ypos,width, height,fullscreen);

		// if the window creation succeeded create our renderer
		if (g_pWindow != 0)	{

			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
			running = true;
		}
	}
	else
	{
		return 1; // sdl could not initialize
	}
}

void game::update() {

	int red = rand() % 255 + 1;
	int green = rand() % 255 + 1;
	int blue = rand() % 255 + 1;
	int alpha = rand() % 255 + 1;

	SDL_SetRenderDrawColor(g_pRenderer, red, green, blue, alpha);

	SDL_Delay(500);
	

}


void game::handleEvents() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {

			running = false;

		}
		}
}

void game::render() {
	// clear the window to black
	SDL_RenderClear(g_pRenderer);

	// show the window
	SDL_RenderPresent(g_pRenderer);
}

void game::clean() {
	SDL_Quit();
}


bool game::isRunning() {

	return running;
}