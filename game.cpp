#include "game.h"

Game::Game() {
	m_pWindow = 0;
	m_pRenderer = 0;
	red = 0;
	green = 0;
	blue = 0;
	alpha = 255;
	spriteNum = 0;
}

Game::~Game() {}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		// if succeeded create our window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		// if the window creation succeeded create our renderer
		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			SDL_SetRenderDrawColor(m_pRenderer, red, green, blue, alpha);
		}
	}
	else {
		return false; // sdl could not initialize
	}
	running = true;
	TextureManager::getInstance()->load("assets/images/sprite.bmp", "player", m_pRenderer);
	return true;
}

void Game::render() {
	// clear the window to black
	SDL_RenderClear(m_pRenderer);

	TextureManager::getInstance()->drawFrame(
		"player",
		(SDL_GetWindowSurface(m_pWindow)->w / 2),
		(SDL_GetWindowSurface(m_pWindow)->h / 2),
		128/4,
		48,
		0,
		spriteNum,
		m_pRenderer
	);

	// show the window
	SDL_RenderPresent(m_pRenderer);
}

void Game::update() {

	//SPRITENUMS
	spriteNum = (int)((SDL_GetTicks() / 120) % 4);
	
	//RED
	if(red < maxColorValue && green == 0 && blue == 0 || red < maxColorValue && green == 0 && blue == maxColorValue){
		red++;
	}
	else {
		if (red > 0 && green == maxColorValue && blue == 0) red--;
	}
	//GREEN
	if (red == maxColorValue && green < maxColorValue && blue == 0) {
		green++;
	}
	else {
		if (red == 0 && green > 0 && blue == maxColorValue) green--;
	}
	//BLUE
	if (red == 0 && green == maxColorValue && blue < maxColorValue) {
		blue++;
	}
	else {
		if (red == maxColorValue && green == 0 && blue > 0) blue--;
	}
	SDL_SetRenderDrawColor(m_pRenderer, red, green, blue, alpha);
	SDL_Delay(8);
}

void Game::handleEvents() {
	SDL_Event event;
	
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYUP) running = false;
	}
}

void Game::clean() {
	SDL_Quit();
}

bool Game::isRunning() { return running; }