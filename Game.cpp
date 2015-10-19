#include "Game.h"

Game::Game() {
	g_pWindow = 0;
	g_pRenderer = 0;
	flag = false;
	red = 255;
	green = 0;
	blue = 0;
};

Game::~Game() {

};

bool Game::init(const char* title, int xpos, int
	ypos, int width, int height, bool fullscreen) {

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create our window
		if(fullscreen){ 
			g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_FULLSCREEN); 
		}
		else{
			g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		}
		
		// if the window creation succeeded create our renderer
		if (g_pWindow != 0){ 
			return false; 
		}
	}
	else
	{
		return false; // sdl could not initialize
	}
	return true;
}

void Game::render() {
	g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
}

void Game::update() {
	SDL_RenderPresent(g_pRenderer);
}

void Game::handleEvents() {
	if ((SDL_PollEvent(&events) == 1) && (events.type = SDL_QUIT)){
		flag = true;
	}
}

void Game::clean() {
	SDL_SetRenderDrawColor(g_pRenderer, red, green, blue, 255);
	SDL_Delay(10);
	if (red == 255) {
		if (green < 255)
			green++;
		if (blue > 0)
			blue--;
	}
	if (green == 255) {
		if (blue < 255)
			blue++;
		if (red > 0)
			red--;
	}
	if (blue == 255) {
		if (red < 255)
			red++;
		if (green > 0)
			green--;
	}
	SDL_RenderClear(g_pRenderer);
}

bool Game::isRunning() {
	//if (flag==false) { return false; }
	return true;
}
