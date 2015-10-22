#include "SDL.h"
#include "SDL_image.h"
#include "game.h"
#include "time.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

SDL_Window* g_lWindow = 0;
SDL_Renderer* g_lRenderer = 0;
SDL_Texture* texture;
SDL_Surface* img;


Game::Game() {  //Constructor

}
Game::~Game() {

}



bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {



	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{

		// if succeeded create our window
		g_lWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		// if the window creation succeeded create our renderer
		if (g_lWindow != 0)
		{
			g_lRenderer = SDL_CreateRenderer(g_lWindow, -1, 0);
		}
		


		//image = SDL_Displayf
		///DL_FreeSurface(temp);
		img= SDL_LoadBMP("./images/player.bmp");
		if (!img) return 1;
		texture = SDL_CreateTextureFromSurface(g_lRenderer, img);
		if (!texture) return 1;
		SDL_FreeSurface(img);

		running = true;

	}
	else
	{
		return 1; // sdl could not initialize
	}

	// everything succeeded lets draw the window
	// set to black // This function expects Red, Green, Blue and
	// Alpha as color values
	// Especifiquem el color amb que pintarem


	return true;
}

void Game::update() {  //Actualitzara el colors
	int x = rand();
	int y = rand();
	int z = rand();
	int h = rand();
	SDL_SetRenderDrawColor(g_lRenderer, x, y, z, h);

}
void Game::render() { //Actualitzara el buffer i mostrara per pantalla
	update();
	SDL_RenderClear(g_lRenderer);
	SDL_RenderCopy(g_lRenderer, texture, NULL, NULL);
	SDL_RenderPresent(g_lRenderer);


}


void Game::clean() {
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(g_lRenderer);
	SDL_DestroyWindow(g_lWindow);
	SDL_Quit();




}
bool Game::isRunning() { 
return running; 
}


int Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		running = true;
		if (event.type == SDL_KEYUP) {
			running = false;
		}
	}
	return 1;
}










