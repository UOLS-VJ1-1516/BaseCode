#include "Game.h"

Game::Game() {
	pixelesDeAncho = new int(0);
	pixelesDeAlto = new int(0);
	running = true;
	numeroDivisiones = 1;
	numeroPixelesDivision = 0;
	lastTime = 0;
	tiempo = 0;
	paused = false;
}

Game::~Game() {
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0){
		*pixelesDeAncho = width;
		*pixelesDeAlto = height;
		if (fullscreen){ 
			g_pWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_FULLSCREEN_DESKTOP);
		}
		else{ 
			g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		}

		SDL_GetWindowSize(g_pWindow, pixelesDeAncho, pixelesDeAlto);

		if (g_pWindow != 0) {
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}

		numeroDivisiones = 6;
		numeroPixelesDivision = *pixelesDeAncho / numeroDivisiones;

		return true;
	}else{ 
		return false; 
	}
}

void Game::render() {


	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(g_pRenderer);



	int pixel = 0;
	int divisionActual = 0;

	for (pixel = 0; pixel < numeroPixelesDivision*(divisionActual + 1); pixel++) {
		SDL_SetRenderDrawColor(g_pRenderer, 255, (Uint8)(255 * (pixel - numeroPixelesDivision*divisionActual) / numeroPixelesDivision), 0, 255); //Rojo a Amarillo
		SDL_RenderDrawLine(g_pRenderer, (pixel + tiempo) % *pixelesDeAncho, 0, (pixel + tiempo) % *pixelesDeAncho, *pixelesDeAlto);
	}
	divisionActual++;
	for (; pixel < numeroPixelesDivision*(divisionActual + 1); pixel++) {
		SDL_SetRenderDrawColor(g_pRenderer, 255 - (Uint8)(255 * (pixel - numeroPixelesDivision*divisionActual) / numeroPixelesDivision), 255, 0, 255); //Amarillo a Verde
		SDL_RenderDrawLine(g_pRenderer, (pixel + tiempo) % *pixelesDeAncho, 0, (pixel + tiempo) % *pixelesDeAncho, *pixelesDeAlto);
	}
	divisionActual++;
	for (; pixel < numeroPixelesDivision*(divisionActual + 1); pixel++) {
		SDL_SetRenderDrawColor(g_pRenderer, 0, 255, (Uint8)(255 * (pixel - numeroPixelesDivision*divisionActual) / numeroPixelesDivision), 255); //Verde a Cyan
		SDL_RenderDrawLine(g_pRenderer, (pixel + tiempo) % *pixelesDeAncho, 0, (pixel + tiempo) % *pixelesDeAncho, *pixelesDeAlto);
	}
	divisionActual++;
	for (; pixel < numeroPixelesDivision*(divisionActual + 1); pixel++) {
		SDL_SetRenderDrawColor(g_pRenderer, 0, 255 - (Uint8)(255 * (pixel - numeroPixelesDivision*divisionActual) / numeroPixelesDivision), 255, 255); //Cyan a Blue
		SDL_RenderDrawLine(g_pRenderer, (pixel + tiempo) % *pixelesDeAncho, 0, (pixel + tiempo) % *pixelesDeAncho, *pixelesDeAlto);
	}
	divisionActual++;
	for (; pixel < numeroPixelesDivision*(divisionActual + 1); pixel++) {
		SDL_SetRenderDrawColor(g_pRenderer, (Uint8)(255 * (pixel - numeroPixelesDivision*divisionActual) / numeroPixelesDivision), 0, 255, 255); //Blue a Lila
		SDL_RenderDrawLine(g_pRenderer, (pixel + tiempo) % *pixelesDeAncho, 0, (pixel + tiempo) % *pixelesDeAncho, *pixelesDeAlto);
	}
	divisionActual++;
	for (; pixel < numeroPixelesDivision*(divisionActual + 1); pixel++) {
		SDL_SetRenderDrawColor(g_pRenderer, 255, 0, 255 - (Uint8)(255 * (pixel - numeroPixelesDivision*divisionActual) / numeroPixelesDivision), 255); //Lila a Rojo
		SDL_RenderDrawLine(g_pRenderer, (pixel + tiempo) % *pixelesDeAncho, 0, (pixel + tiempo) % *pixelesDeAncho, *pixelesDeAlto);
	}

	SDL_RenderPresent(g_pRenderer);

}

void Game::update() {
	tiempo += SDL_GetTicks() - lastTime;
	lastTime = SDL_GetTicks();
}

void Game::handleEvents() {
	if (SDL_PollEvent(&event) > 0 ) {
		if (event.type == SDL_KEYDOWN) {
			if (!paused) {
				paused = true;
			}
			else {
				lastTime = SDL_GetTicks(); //Si quitamos la pausa, ponemos el lastTime al momento del click, sino daria saltos la imagen al salir del pausa.
				paused = false;
			}
		}
		if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
			running = false;
			paused = true;
		}
	}
}

void Game::clean() {
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_Quit();
}

void Game::pause() {
	paused = true;
}

bool Game::isRunning() {
	return running;
}

bool Game::isPaused() {
	return paused;
}