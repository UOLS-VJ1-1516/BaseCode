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

int x,y, ancho, alto;
int desplazamiento = -200;
int desplazamientoizq = 300;
int desplazamientoizq2 = 2000;

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
		if (!(texturemanager.load("./images/nubes.png", "nubes", g_lRenderer))) { return false; }
		if (!(texturemanager.load("./images/nubes2.png", "nubes2", g_lRenderer))) { return false; }

		running = true;

	}
	else
	{
		return 1; // sdl could not initialize
	}

	return true;
}

void Game::update() {  //Actualitzara parametres diversos
	/*int x = rand()%255;
	int y = rand()%255;
	int z = rand()%255;*/// No utilitzare mes de un color
	int h = rand()%255;
	SDL_SetRenderDrawColor(g_lRenderer, 25, 158, 218, h);
	x = ((SDL_GetTicks() / 100) % 7);
	y = (alto / 2);
	desplazamiento = desplazamiento + 2;
	desplazamientoizq = desplazamientoizq - 2;
	desplazamientoizq2 = desplazamientoizq2 - 2;
	if (desplazamiento > ancho)desplazamiento = -200;
	if (desplazamientoizq < -1700)desplazamientoizq = 1600;
	if (desplazamientoizq2 < -1700)desplazamientoizq2 = 1600;
}
void Game::render() { //Actualitzara el buffer i mostrara per pantalla
	
	SDL_RenderClear(g_lRenderer); 
    texturemanager.drawFrame("bird", desplazamiento, y, 200, 180,1, x, g_lRenderer, SDL_FLIP_NONE);
    texturemanager.drawFrame("nubes", desplazamientoizq, y, 1900, 900, 1, 0, g_lRenderer, SDL_FLIP_NONE);
	texturemanager.drawFrame("nubes2", desplazamientoizq2, y, 1900, 900, 1, 0, g_lRenderer, SDL_FLIP_NONE);
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










