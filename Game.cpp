#include "SDL.h"
#include "Game.h"


SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

Game::Game() {  //Constructor

}
Game::~Game() {

}

bool running = false;


bool Game::init(const char* title, int xpos, int
	ypos, int width, int height, bool fullscreen) {

	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create our window
		g_pWindow = SDL_CreateWindow(title,
			xpos, ypos,
			width, height, fullscreen);

		// if the window creation succeeded create our renderer
		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}

		//SESSIO 2! texture manager instance load

		running = true;
		return true;

	}
	else
	{
		running = false;
		return false; // sdl could not initialize
	}

	// everything succeeded lets draw the window
	// set to black // This function expects Red, Green, Blue and
	// Alpha as color values

}


void Game::handleEvents() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		running = true;
		if (event.type == SDL_KEYUP)
		{
			running = false;
		}		
	}
}

//void Game::update() {

//}


void Game::render(int r, int g, int b) {

	SDL_SetRenderDrawColor(g_pRenderer, r, g, b, 255);
	// clear the window to black
	SDL_RenderClear(g_pRenderer);
	// show the window
	SDL_RenderPresent(g_pRenderer);
	// set a delay before quitting
	SDL_Delay(10);

}


void Game::clean() {
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(g_pRenderer);

	// clean up SDL
	SDL_Quit();


}


bool Game::isRunning() {
	return running;
}



//GetAsyncKeyState(VK_ESCAPE) == 0)

