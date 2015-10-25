#include "SDL.h"
#include "game.h"
#include <stdlib.h>
#include "TextureManager.h"
#include "SDL_image.h"

TextureManager* TextureManager::s_pInstance = 0;

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
		if (!TextureManager::Instance()->load("spritesheet.png", "imatge", g_lRenderer)) {
			return false;
		}
		running = true;
		return true;
	}
	
	void Game::render() {
		//va cambiando el color, en este caso aleatorio con la funcion rand()
		if ((mov==0)||(mov==150)||(mov==300)||(mov==450)||(mov == 650)||(mov==850)||(mov==1000)||(mov==1250)) {
			SDL_SetRenderDrawColor(g_lRenderer, rand() % 256, rand() % 256, rand() % 256, rand() % 256);
		}

		// clear the window to black
		SDL_RenderClear(g_lRenderer);

		//Mostrem la imatge
		//TextureManager::Instance()->draw("imatge", pos, 180, 97, 132, g_lRenderer, SDL_FLIP_NONE);
		TextureManager::Instance()->drawFrame("imatge", pos, 180, 97, 132, animacion, spriteNum, g_lRenderer, SDL_FLIP_NONE);
		
		mov = mov + 1; //incrementamos la posición para que la imagen se mueva

		if (mov < 650) { //primera animació
			pos = mov;
		}
		else {
			if (mov < 850) { //segona animació
				cont++;
				animacion = 2;
				pos = mov - 425;
				SDL_Delay(10);
				if (cont == 4) {
					pos = pos - 1;
				}
				if (cont == 5) {
					pos = pos - 1;
				}
				if (cont == 6) {
					pos = pos - 1;
					cont = 0;
				}
			}
			else {
				if (mov < 1250) { // tercera animació
					animacion = 3;
					pos = 275;
				}
				else { //fi de la tercera animació, tornem a la primera
					animacion = 1;
					mov = 0;
				}
			}
		}
		
		// show the window
		//SDL_RenderPresent(g_lRenderer);
		SDL_RenderPresent(g_lRenderer);

		// set a delay before quitting
		SDL_Delay(15);

	}
	void Game::update() {
		//Función para saber que sprite
		spriteNum = (int)((SDL_GetTicks() / 100) % 7);
	}
	void Game::handleEvents() {
		SDL_Event event;
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN) { //cuando nos pulsen una tecla
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