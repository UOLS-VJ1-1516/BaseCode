#include "SDL.h"
#include "game.h"
#include <stdlib.h> 

SDL_Window* g_lWindow = 0;
SDL_Renderer* g_lRenderer = 0;
bool running;

	Game::Game(){
	}

	Game::~Game(){
	}

	bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
		// initialize SDL
		if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
		{
			// if succeeded create our window
			g_lWindow = SDL_CreateWindow(title,xpos, ypos,width, height,fullscreen);
			// if the window creation succeeded create our renderer
			if (g_lWindow != 0)
			{
				g_lRenderer = SDL_CreateRenderer(g_lWindow, -1, 0);
			}
		}
		else
		{
			return false; // sdl could not initialize
		}
		running = true;
	}
	
	void Game::render() {
		//eligo el color, en este caso aleatorio con la funcion rand()
		SDL_SetRenderDrawColor(g_lRenderer, rand() % 256, rand() % 256, rand() % 256, rand() % 256);

		// clear the window to black
		SDL_RenderClear(g_lRenderer);

		// show the window
		SDL_RenderPresent(g_lRenderer);

		// set a delay before quitting
		SDL_Delay(1000);

	}
	void Game::update() {

	}
	void Game::handleEvents() {
		SDL_Event event;
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN) {
				running = false;
			}
		}
	}
	void Game::clean() {
		SDL_DestroyWindow(g_lWindow);
		SDL_DestroyRenderer(g_lRenderer);
		SDL_Quit();
	}
	bool Game::isRunning() {
		return running;
	}
	