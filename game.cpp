#include "SDL.h"
#include "SDL_image.h"
#include "game.h"
#include "time.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "texturemanager.h"
int currrentFrame = 0;
TextureManager texturemanager;

SDL_Window* g_lWindow = 0;
SDL_Renderer* g_lRenderer = 0;
SDL_Texture* texture;
SDL_Surface* img;
int x,y, ancho, alto;
int desplazamiento = -200;

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
		ancho = width;
		alto = height;

		// if the window creation succeeded create our renderer
		if (g_lWindow != 0)
		{
			g_lRenderer = SDL_CreateRenderer(g_lWindow, -1, 0);
		}	
		
		if (!(texturemanager.load("./images/bird.png", "bird", g_lRenderer))) { return false; }
		

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
	/*int x = rand()%255;
	int y = rand()%255;
	int z = rand()%255;*/ No utilitzare mes de un color
	int h = rand()%255;
	SDL_SetRenderDrawColor(g_lRenderer, 25, 158, 218, h);

}
void Game::render() { //Actualitzara el buffer i mostrara per pantalla
	
	SDL_RenderClear(g_lRenderer); 
	x = ((SDL_GetTicks() / 100) % 7);
	y = (alto / 2);
    texturemanager.drawFrame("bird", desplazamiento, y, 200, 180,1, x, g_lRenderer, SDL_FLIP_NONE);
	desplazamiento = desplazamiento + 2;
	if (desplazamiento > ancho)desplazamiento = -200;
	SDL_RenderCopy(g_lRenderer, texture, NULL,&dst);
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










