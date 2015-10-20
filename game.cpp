#include "game.h"
#include "SDL.h"
#include "stdio.h"

bool running = true;
int red = 255, green = 0, blue = 0;
int mostrar_r = 0, mostrar_g = 0, mostrar_b = 0;
int valor = 0;

Game::Game() {

}

Game::~Game() {


}

bool Game::init(const char* title, int xpos, int
	ypos, int width, int height, bool fullscreen){
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		// if succeeded create our window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		// if the window creation succeeded create our renderer
		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			SDL_SetRenderDrawColor(m_pRenderer, 0, 10, 40, 255);
		}
		else {

		}

	}
	else {
		return false;
	}
	return true;
}
void Game::render() {

	// posar pantalla negre
	SDL_RenderClear(m_pRenderer);

	// mostrar finestra tots els casos
	SDL_RenderPresent(m_pRenderer);

	if (red == 255 && green == 0 && blue == 0) {
		valor = 1;
		mostrar_g = 1;
		mostrar_b = 0;
	}

	if (green == 255 && blue == 0 && red == 0) {
		valor = 1;
		mostrar_b = 1;
		mostrar_r = 0;
		
	}

	if (blue == 255 && red == 0 && green == 0) {
		valor = 1;
		mostrar_r = 1;
		mostrar_g = 0;
		
	}

	if (red == 255 && green == 255 && blue == 0) {
		valor = -1;
		mostrar_r = 1;
		mostrar_g = 0;
		mostrar_b = 0;
	}
	if (green == 255 && blue == 255 && red == 0) {
		valor = -1;
		mostrar_g = 1;
		mostrar_b = 0;
		mostrar_r = 0;
	}
	if (blue == 255 && red == 255 && green == 0) {
		valor = -1;
		mostrar_b = 1;
		mostrar_r = 0;
		mostrar_g = 0;
	}

	if (mostrar_g == 1) {
		green = green + valor;
	}

	if (mostrar_b == 1) {
		blue = blue + valor;
	}

	if (mostrar_r == 1) {
		red = red + valor;
	}

	printf("operation R: %i \n", red);

	printf("operation G: %i \n", green);

	printf("operation B: %i \n", blue);

	SDL_SetRenderDrawColor(m_pRenderer, red, green, blue, 255);
	SDL_Delay(10);
}

void Game::update() {



}

void Game::handleEvents(SDL_Event event) {
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

void Game::clean() {
	// clean up SDL
	SDL_Quit();

}

bool Game::isRunning() {
	return running;
}