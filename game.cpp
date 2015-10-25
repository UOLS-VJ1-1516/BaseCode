#include "game.h"
#include "TextureManager.h"

Game::Game() {
	m_pWindow = 0;
	m_pRenderer = 0;
	running = false;
}

Game::~Game() {

}

bool Game::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen) {
	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		// if succeeded create our window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, 0);

		// if the window creation succeeded create our renderer
		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
		
		//load img in my img list
		TextureManager::Instance()->load("frames.bmp", "frames", m_pRenderer);

		//app starts
		running = true;
		return 0;
	}
	else {
		return 1; // sdl could not initialize
	}
	
}

void Game::render() {
	//set color background
	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

	//clean screen
	SDL_RenderClear(m_pRenderer);

	//get a number 
	mov = (int)((SDL_GetTicks() / 100) % 6);

	//refresh img
	TextureManager::Instance()->drawFrame("frames", 300, 200, 104, 151, mov, m_pRenderer, SDL_FLIP_NONE);
}

void Game::update() {
	//show print buffer
	SDL_RenderPresent(m_pRenderer);
}

void Game::handleEvents() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYUP) {
			running = false;
		}
	}
}

void Game::clean() { 
	SDL_RenderClear(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	// clean up SDL
	SDL_Quit();
}

bool Game::isRunning() {
	return running;
}