#include "Game.h"
#include "TextureManager.h"

const int SIZE_WINDOW_HEIGHT = 500;
const int SIZE_WINDOW_WIDTH = 500;

Game::Game()
{
	g_pWindow = 0;
	g_pRenderer = 0;	
	state = false;
}

Game::~Game(){}

bool Game::init(const char* tittle,int xPos, int yPos, int typeWindow)
{
	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		g_pWindow = SDL_CreateWindow(tittle,xPos,yPos,SIZE_WINDOW_WIDTH, SIZE_WINDOW_HEIGHT,0);
		if (g_pWindow != 0) g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		state = true;				
		TextureManager::Instance()->load("majin.bmp", "img", g_pRenderer);	
		return 0;
	}
	return 1; 
}

void Game::render()
{	
	SDL_SetRenderDrawColor(g_pRenderer, 255, 255, 255, 255);
	SDL_RenderClear(g_pRenderer);
	sprit = (int)((SDL_GetTicks() / 100) % 4);
	TextureManager::Instance()->drawFrame("img", SIZE_WINDOW_WIDTH / 2 -40, SIZE_WINDOW_HEIGHT / 2 - 100, 81, 200, 0, sprit, g_pRenderer, SDL_FLIP_NONE);
}

void Game::update(int delay)
{		
	SDL_RenderPresent(g_pRenderer);
	SDL_Delay(delay);		
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
	SDL_RenderClear(g_pRenderer);
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_Quit();
}


bool Game::isRunning()
{
	return state;
}
