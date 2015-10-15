#include "Game.h"

Game::Game() {
	g_pWindow = 0;
	flag = true;
	g_pRenderer = 0;
	numeroDivisiones = 6;
	pixel = 0;
	divisionActual = 0;
	tiempo = 0;
}

Game::~Game() {
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_Quit();
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0){
		pixelesDeAncho = &width;
		pixelesDeAlto = &height;

		if (fullscreen){ 
			g_pWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_FULLSCREEN_DESKTOP); 
		}
		else{ 
			g_pWindow = SDL_CreateWindow(title, xpos, ypos, 640, 480, SDL_WINDOW_SHOWN); 
		}

		SDL_GetWindowSize(g_pWindow, pixelesDeAncho, pixelesDeAlto);

		return true;
	}else{ 
		return false; 
	}
}

void Game::render() {
	if (g_pWindow != 0) {
		g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
	}
}

void Game::update() {
	SDL_RenderPresent(g_pRenderer);
}

void Game::handleEvents() {
	if (SDL_PollEvent(&event) == 1 && (event.type == SDL_QUIT || event.type == SDL_KEYDOWN)) {
		flag = false;
	}
}

void Game::clean() {
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(g_pRenderer);

	//numeroPixelesDivision = *pixelesDeAncho / 6;
	//tiempo += SDL_GetTicks() - lastTime;
	//lastTime = SDL_GetTicks();
	//for (pixel = 0; pixel < numeroPixelesDivision*(divisionActual + 1); pixel++) {
	//	SDL_SetRenderDrawColor(g_pRenderer, 255, (Uint8)(255 * (pixel - numeroPixelesDivision*divisionActual) / numeroPixelesDivision), 0, 255); //Rojo a Amarillo
	//	SDL_RenderDrawLine(g_pRenderer, (pixel + tiempo) % *pixelesDeAncho, 0, (pixel + tiempo) % *pixelesDeAncho, *pixelesDeAlto);
	//}
	//divisionActual++;
	//for (; pixel < numeroPixelesDivision*(divisionActual + 1); pixel++) {
	//	SDL_SetRenderDrawColor(g_pRenderer, 255 - (Uint8)(255 * (pixel - numeroPixelesDivision*divisionActual) / numeroPixelesDivision), 255, 0, 255); //Amarillo a Verde
	//	SDL_RenderDrawLine(g_pRenderer, (pixel + tiempo) % *pixelesDeAncho, 0, (pixel + tiempo) % *pixelesDeAncho, *pixelesDeAlto);
	//}
	//divisionActual++;
	//for (; pixel < numeroPixelesDivision*(divisionActual + 1); pixel++) {
	//	SDL_SetRenderDrawColor(g_pRenderer, 0, 255, (Uint8)(255 * (pixel - numeroPixelesDivision*divisionActual) / numeroPixelesDivision), 255); //Verde a Cyan
	//	SDL_RenderDrawLine(g_pRenderer, (pixel + tiempo) % *pixelesDeAncho, 0, (pixel + tiempo) % *pixelesDeAncho, *pixelesDeAlto);
	//}
	//divisionActual++;
	//for (; pixel < numeroPixelesDivision*(divisionActual + 1); pixel++) {
	//	SDL_SetRenderDrawColor(g_pRenderer, 0, 255 - (Uint8)(255 * (pixel - numeroPixelesDivision*divisionActual) / numeroPixelesDivision), 255, 255); //Cyan a Blue
	//	SDL_RenderDrawLine(g_pRenderer, (pixel + tiempo) % *pixelesDeAncho, 0, (pixel + tiempo) % *pixelesDeAncho, *pixelesDeAlto);
	//}
	//divisionActual++;
	//for (; pixel < numeroPixelesDivision*(divisionActual + 1); pixel++) {
	//	SDL_SetRenderDrawColor(g_pRenderer, (Uint8)(255 * (pixel - numeroPixelesDivision*divisionActual) / numeroPixelesDivision), 0, 255, 255); //Blue a Lila
	//	SDL_RenderDrawLine(g_pRenderer, (pixel + tiempo) % *pixelesDeAncho, 0, (pixel + tiempo) % *pixelesDeAncho, *pixelesDeAlto);
	//}
	//divisionActual++;
	//for (; pixel < numeroPixelesDivision*(divisionActual + 1); pixel++) {
	//	SDL_SetRenderDrawColor(g_pRenderer, 255, 0, 255 - (Uint8)(255 * (pixel - numeroPixelesDivision*divisionActual) / numeroPixelesDivision), 255); //Lila a Rojo
	//	SDL_RenderDrawLine(g_pRenderer, (pixel + tiempo) % *pixelesDeAncho, 0, (pixel + tiempo) % *pixelesDeAncho, *pixelesDeAlto);
	//}

}

bool Game::isRunning() {
	return flag;
}
