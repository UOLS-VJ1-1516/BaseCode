#include "game.h"
#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>


Game::Game()
{
	m_pRenderer = 0;
	m_pWindow = 0;
	quit = 0;
	spriteNum = 0;
	SDL_Surface *load_Surf;
	SDL_Texture *player;
	SDL_Rect Src;
	SDL_Rect Dest;

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

		load_Surf = SDL_LoadBMP("./player.bmp");
		player = SDL_CreateTextureFromSurface(m_pRenderer, load_Surf);
		SDL_FreeSurface(load_Surf);

		//TextureManager::Instance()->load(…);
	}
	else
	{
		return false; // sdl could not initialize
	}

	return true;

}

void Game::render()
{

	Src.x = 0;
	Src.y = 0;
	Src.w = 58;
	Src.h = 61;

	Dest.x = 640 / 2 - 61 / 2;
	Dest.y = 480 / 2 - 61 / 2;
	Dest.w = 58;
	Dest.h = 61;

	// clear the window to black
	SDL_RenderClear(m_pRenderer);

	SDL_RenderCopy(m_pRenderer, player, &Src, &Dest);

	//TextureManager::Instance()->drawFrame(…);

	SDL_RenderPresent(m_pRenderer);

}

void Game::update()
{
	
	//spriteNum = ( int )( ( SDL_GetTicks() / 100 ) % 12 );

	SDL_Delay(20);
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