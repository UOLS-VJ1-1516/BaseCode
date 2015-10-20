#include "game.h"
#include "SDL.h"

Game::Game()
{
	m_pRenderer = 0;
	m_pWindow = 0;
	r = 255;
	g = 0;
	b = 0;
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
	}
	else
	{
		return false; // sdl could not initialize
	}

	return true;

}

void Game::render()
{
	SDL_SetRenderDrawColor(m_pRenderer, r, g, b, 255);

	SDL_RenderPresent(m_pRenderer);

	// clear the window to black
	SDL_RenderClear(m_pRenderer);
}

void Game::update()
{
	
	if (r >= 255) {
		g++;
		r--;
		b = 0;
	}
	if (g >= 255) {
		b++;
		g--;
		r = 0;
	}
	if (b >= 255) {
		r++;
		b--;
		g = 0;
	}
	if (r >= 255) {
		g++;
		r--;
		b = 0;
	}

	r++;
	g++;
	b++;

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
	// set a delay before quitting
	//SDL_Delay(5000);

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