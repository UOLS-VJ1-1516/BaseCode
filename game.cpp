#include "game.h"
#include "TextureManager.h"
#include "SDL.h"
#include "stdio.h"

#define SPRITE_HEIGHT 35
#define SPRITE_WIDHT 45

Game::Game()
{
	m_pRenderer = 0;
	m_pWindow = 0;
	a = 0;
	r = 255;
	g = 0;
	b = 0;
	
};

Game::~Game()
{

};

bool Game::init(const char* title, int xpos, int
	ypos, int width, int height, bool fullscreen)

{
	
	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create our window
		m_pWindow = SDL_CreateWindow("Videjuegos I - bachelor",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			640, 480,
			fullscreen);
		
		// if the window creation succeeded create our renderer
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			TextureManager::Instance()->load("bomberman.bmp", "player", m_pRenderer);
		}

		return 0;

	}
	else
	{
		return 1; // sdl could not initialize
	}
};

void Game::render()
{
	SDL_SetRenderDrawColor(m_pRenderer, r, g, b, 255);
	// clear the window to black
	SDL_RenderClear(m_pRenderer);
	pSprite = (int)((SDL_GetTicks() / 100) % 8); //moviment de l'sprite
	TextureManager::Instance()->drawFrame("player", 50, 100, 56, 60, 0, pSprite, m_pRenderer, SDL_FLIP_NONE);
	
};

void Game::update()
{
	SDL_RenderPresent(m_pRenderer);
	/*
	if (r == 255 && b == 0) {
		g++;
		if (g == 255) {
			r--;
		}
	}
	else if (g == 255 && b == 0) {
		r--;
		if (r == 0) {
			b++;
		}
	}
	else if (g == 255 && r == 0) {
		b++;
		if (b == 255) {
			g--;
		}
	}
	else if (b == 255 && r == 0) {
		g--;
		if (g == 0) {
			r++;
		}
	}
	else if (g == 0 && b == 255) {
		r++;
		if (r == 255) {
			b--;
		}
	}
	else {
		b--;
	}
	*/
	
	

	//SDL_Delay(10);
};

void Game::handleEvents()
{
	SDL_Event sortir;
		
	while (SDL_PollEvent(&sortir))
	{
			switch (sortir.type)
			{
				/* Look for a keypress */
			case SDL_KEYDOWN:
				/* Check the SDLKey values and move change the coords */
				switch (sortir.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					a = 1;
					break;
				case SDLK_UP:
					a = 0;
					break;
				default:
					
					break;
				}
			}
		}
};

void Game::clean()
{
	
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	// clean up SDL
	SDL_Quit();

	

};

bool Game::isRunning()
{
	if (a != 0) {
		return false;
	}
	
	return true;
	
	
};