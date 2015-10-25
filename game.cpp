#include "game.h"
#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include "TextureManager.h"


Game::Game()
{
	m_pRenderer = 0;
	m_pWindow = 0;
	quit = 0;
	
}

Game::~Game()
{}

bool Game::init(const char* title, int xpos, int
	ypos, int width, int height, bool fullscreen)

{

	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create our window
		m_pWindow = SDL_CreateWindow("Videojuegos 1 - bachelor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, fullscreen);
				
		// if the window creation succeeded create our renderer
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		TextureManager::Instance()->load("walker.bmp", "walker", m_pRenderer);
	}
	else
	{
		return false; // sdl could not initialize
	}

	return true;

}

void Game::render()
{

	// clear the window to black
	SDL_RenderClear(m_pRenderer);

	spriteNum = int((SDL_GetTicks() / 100) % 12);
	//printf("SpriteNum: %d \n", spriteNum);
	TextureManager::Instance()->drawFrame("walker", 58, 38, 58, 38, numRow, spriteNum, m_pRenderer, SDL_FLIP_NONE);

}

void Game::update()
{	
	
	spriteNum = int((SDL_GetTicks() / 100) % 12);
	numRow = int((SDL_GetTicks() / 1200) % 2);
	SDL_RenderPresent(m_pRenderer);
	
}

void Game::handleEvents()
{
	SDL_Event esc_event;

	while (SDL_PollEvent(&esc_event)) {
		switch (esc_event.type) {
		case SDL_KEYUP:
			switch (esc_event.key.keysym.sym) {
				case SDLK_ESCAPE:
					quit = 1;
					break;
			}				
		}
	}	
}

void Game::clean()
{
	// clean up SDL
	SDL_Quit();
}

bool Game::isRunning()
{
	if (quit != 0) {
		return false;
	}
	return true;
}