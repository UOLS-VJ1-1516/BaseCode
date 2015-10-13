#include "Game.h"
#include <random>


Game::Game()
{
	g_pWindow = 0;
	g_pRenderer = 0;
	state = false;

}

Game::~Game(){}

bool Game::init(const char* tittle,int xPos, int yPos, int width, int height, int typeWindow)
{
	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		g_pWindow = SDL_CreateWindow(tittle,xPos, yPos,width, height,typeWindow);
		if (g_pWindow != 0) g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		state = true;	
	}
	return 1; // sdl could not initialize
}

void Game::render()
{
	// clear the window to black
	SDL_RenderClear(g_pRenderer);

	// show the window
	SDL_RenderPresent(g_pRenderer);
}

void Game::update(int delay)
{
	int r = rand() % 255 + 0;
	int g = rand() % 255 + 0;
	int b = rand() % 255 + 0;


	for (int a = 0; a < 255; a += 5) {
		
		SDL_SetRenderDrawColor(g_pRenderer, r, g, b, a);
		SDL_Delay(delay);
	}
	
}

void Game::handleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_MOUSEBUTTONDOWN) state = false;
		if (event.type == SDL_KEYUP) state = false;
	}	
}

void Game::clean()
{
	// clean up SDL
	SDL_Quit();
}


bool Game::isRunning()
{
	return state;
}
