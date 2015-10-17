#include "game.h"
#include <stdlib.h>

Game::Game() {
	m_pWindow = 0;
	m_pRenderer = 0;
	red = 0;
	green = 0;
	blue = 0;
	alpha = 0;
}

Game::~Game() {

}

bool Game::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen) {
	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		// if succeeded create our window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		// if the window creation succeeded create our renderer
		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			running = true;
		}
	}
	else {
		return 1; // sdl could not initialize
	}
	
}

void Game::update() {
	red = rand() % 255 + 1;
	green = rand() % 255 + 1;
	blue = rand() % 255 + 1;
	alpha = rand() % 255 + 1;

	SDL_SetRenderDrawColor(m_pRenderer, red, green, blue, alpha);
	// set a delay before quitting
	SDL_Delay(750);
}

void Game::handleEvents() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {
			running = false;
		}
	}
}

void Game::render() {
	// clear the window to black
	SDL_RenderClear(m_pRenderer);

	// show the window
	SDL_RenderPresent(m_pRenderer);

}

void Game::clean() { 
	// clean up SDL
	SDL_Quit();
}

bool Game::isRunning() {
	return running;
}