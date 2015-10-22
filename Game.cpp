#include "Game.h"
#include "TextureManager.h"

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
	red = 0;
	marquesina = true;
}

Game::~Game() {
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

		if (g_pWindow != 0) {
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
			//SDL_SetRenderDrawColor(g_pRenderer, red, green, blue, 255);
		}

		TextureManager::Instance()->load("tintin.bmp", "A", g_pRenderer);
		TextureManager::Instance()->load("tintin.bmp", "B", g_pRenderer);
		TextureManager::Instance()->load("tintin.bmp", "C", g_pRenderer);
		TextureManager::Instance()->load("tintin.bmp", "D", g_pRenderer);
		TextureManager::Instance()->load("tintin.bmp", "E", g_pRenderer);
		TextureManager::Instance()->load("tintin.bmp", "F", g_pRenderer);
		return true;
	}
	else {
		return false;
	}
}

void Game::render() {
	//TextureManager::Instance()->draw("A",0,0, 43, 61, g_pRenderer, SDL_FLIP_NONE);
	//TextureManager::Instance()->draw("B", 0, 0, 43, 61, g_pRenderer, SDL_FLIP_NONE);
	spriteNum = (int)((SDL_GetTicks() / 100) % 6);
	switch (spriteNum) {
		case 0: TextureManager::Instance()->drawFrame("A", 0, 0, 104, 152, 1, 0, g_pRenderer, SDL_FLIP_NONE); break;
		case 1: TextureManager::Instance()->drawFrame("B", 104, 0, 104, 152, 1, 1, g_pRenderer, SDL_FLIP_NONE); break;
		case 2: TextureManager::Instance()->drawFrame("C", 208, 0, 104, 152, 1, 0, g_pRenderer, SDL_FLIP_NONE); break;
		case 3: TextureManager::Instance()->drawFrame("D", 312, 0, 104, 152, 1, 1, g_pRenderer, SDL_FLIP_NONE);  break;
		case 4: TextureManager::Instance()->drawFrame("E", 416, 0, 104, 152, 1, 0, g_pRenderer, SDL_FLIP_NONE);  break;
		case 5: TextureManager::Instance()->drawFrame("F", 520, 0, 104, 152, 1, 1, g_pRenderer, SDL_FLIP_NONE); break;
	}
	
}

void Game::update() {
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
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_Quit();
}

bool Game::isRunning() {
	return flag;
}
