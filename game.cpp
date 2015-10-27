#include "game.h"
#include "TextureManager.h"
#include "stdio.h"

#define SPRITE_HEIGHT 155
#define SPRITE_WIDHT 132



Game::Game()
{

};

Game::~Game()
{

};

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create our window
		g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		// if the window creation succeeded create our renderer
		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}

		TextureManager::Instance()->load("corredor2.bmp", "player", g_pRenderer);

		return 0;
	}
	else
	{
		return 1; // sdl could not initialize
	}
};

void Game::render(int r, int g, int b)
{
	// everything succeeded lets draw the window
	// set to black // This function expects Red, Green, Blue and
	// Alpha as color values
	SDL_SetRenderDrawColor(g_pRenderer, r, g, b, 255);

	// clear the window to black
	SDL_RenderClear(g_pRenderer);
	
	TextureManager::Instance()->drawFrame("player", SPRITE_WIDHT, 0, SPRITE_WIDHT, SPRITE_HEIGHT, rowNum, spriteNum, g_pRenderer);
	// show the window
	SDL_RenderPresent(g_pRenderer);

	SDL_Delay(5);
};

void Game::update()
{

	if (rowNum == 0) {
		spriteNum = (int)((SDL_GetTicks() / 100) % 7);
		if (spriteNum == 6)
			rowNum++;
	}
	else if (rowNum == 1) {
		spriteNum = (int)((SDL_GetTicks() / 100) % 7);
		if (spriteNum == 6)
			rowNum++;
	}
	else if (rowNum == 2) {
		spriteNum = (int)((SDL_GetTicks() / 100) % 7);
		if (spriteNum == 6)
			rowNum++;
	}
	else if (rowNum == 3) {
		spriteNum = (int)((SDL_GetTicks() / 100) % 6);
		if (spriteNum == 5)
			rowNum = 0;
	}
	
	
};

void Game::handleEvents(SDL_Event event)
{
	if (event.type == SDL_KEYDOWN)
		if (event.key.keysym.sym == SDLK_ESCAPE)
			abierto = false;
};

void Game::clean()
{
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_Quit();
};

bool Game::isRunning()
{
	return abierto;
};