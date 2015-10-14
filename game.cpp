	#include "game.h"
	#include "SDL.h"
	#include "stdio.h"
	
	bool running = true;
	int r = 255, g = 0, b = 0;
	int enable_r = 0, enable_g = 0, enable_b = 0;
	int value = 0;
	Game::Game()
	{
		
	}
	
	Game::~Game(){
		
	}
	
	bool Game::init( const char* title , int xpos , int
		ypos , int width, int height , bool fullscreen )
	{
		if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
		{
			// if succeeded create our window
			m_pWindow = SDL_CreateWindow(title,
				xpos, ypos,
				width, height,
			fullscreen);

			// if the window creation succeeded create our renderer
			if(m_pWindow != 0)
			{
				m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

				SDL_SetRenderDrawColor(m_pRenderer, 0, 10, 40, 255);
			} else {

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

		// clear the window to black
		SDL_RenderClear(m_pRenderer);

		// show the window
		SDL_RenderPresent(m_pRenderer);
	
		if (r == 255 && g == 0 && b == 0) { value = 1; enable_g = 1; enable_b = 0; }
		if (g == 255 && b == 0 && r == 0) { value = 1; enable_b = 1; enable_r = 0; }
		if (b == 255 && r == 0 && g == 0) { value = 1; enable_r = 1; enable_g = 0; }
		if (r == 255 && g == 255 && b == 0) { value = -1; enable_r = 1; enable_g = 0; enable_b = 0; }
		if (g == 255 && b == 255 && r == 0) { value = -1; enable_g = 1; enable_b = 0; enable_r = 0; }
		if (b == 255 && r == 255 && g == 0) { value = -1; enable_b = 1; enable_r = 0; enable_g = 0; }
		if (enable_g == 1 ) g = g + value;
		if (enable_b == 1 ) b = b + value;
		if (enable_r == 1 ) r = r + value;
		printf("operation R: %i \n", r);
		printf("operation G: %i \n", g);
		printf("operation B: %i \n", b);
		printf("________________\n");
		SDL_SetRenderDrawColor(m_pRenderer, r, g, b, 255);
		SDL_Delay(10);
	}
	
	void Game::update(){


	}
	
	void Game::handleEvents(SDL_Event event){
		switch (event.type) {
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				running = false;
			}
			break;
		default:
			break;
		}
	}
	
	void Game::clean(){
		// clean up SDL
		SDL_Quit();
	}
	
	bool Game::isRunning(){
		return running;
	}