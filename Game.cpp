#include "Game.h"

Game::Game() {
	g_pWindow = 0;
	flag = true;
	g_pRenderer = 0;
	tiempo = 0;
	lastTime = SDL_GetTicks();
	numeroPixelesDivision = 0;
	lastTime = SDL_GetTicks();
	pixelesDeAncho = new int(0);
	pixelesDeAlto = new int(0);
	blue = 0;
	green = 0;
	red = 255;
	marquesina = true;
}

Game::~Game() {
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_Quit();
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		*(pixelesDeAncho) = width;
		*(pixelesDeAlto) = height;
		if (fullscreen) {
			g_pWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_FULLSCREEN_DESKTOP);
		}
		else {
			g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		}

		SDL_GetWindowSize(g_pWindow, pixelesDeAncho, pixelesDeAlto);

		return true;
	}
	else {
		return false;
	}
}

void Game::render() {
	if (g_pWindow != 0) {
		g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		SDL_SetRenderDrawColor(g_pRenderer, red, green, blue, 255);
	}
}

void Game::update() {
	switch (marquesina)
	{
	case true:
		numeroDivisiones = 6;
		numeroPixelesDivision = *pixelesDeAncho / numeroDivisiones;
		pixel = 0;
		divisionActual = 0;

		tiempo += SDL_GetTicks() - lastTime;
		lastTime = SDL_GetTicks();

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

		break;

	case false:
		if (SDL_GetTicks() % 100 == 0) {
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
		}

		SDL_SetRenderDrawColor(g_pRenderer, red, green, blue, 255);
		break;
	}
	SDL_RenderPresent(g_pRenderer);
}

void Game::handleEvents() {
	if (SDL_PollEvent(&event) == 1) {
		if ((event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)) {
			flag = false;
		}
		else if (event.type == SDL_KEYDOWN) {
			if (marquesina) {
				marquesina = false;
				while (red < 255 && green > 0 && blue > 0) {
					if (red < 255)
						red++;
					if (green > 0)
						green--;
					if (blue > 0)
						blue--;
					SDL_RenderClear(g_pRenderer);
					SDL_SetRenderDrawColor(g_pRenderer, red, green, blue, 255);
					SDL_RenderPresent(g_pRenderer);
				}
			}
			else
				marquesina = true;
		}
	}

}

void Game::clean() {
	SDL_RenderClear(g_pRenderer);
}

bool Game::isRunning() {
	return flag;
}
