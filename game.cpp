#include "game.h"
#include "cstdlib" //libreria para random
#include "SDL_image.h"




game::game()
{
};


game::~game()
{
};


//ahora añadimos las funciones declaradas en game.h y las rellenamos

//en este caso añadimos el codigo que estaba incluido en el main.cpp
// initialize SDL
bool game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {




	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create our window
		g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		// if the window creation succeeded create our renderer
		if (g_pWindow != 0){
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}



		//Creacion y carga de una textura

		textureSurface = SDL_LoadBMP("player1.bmp");

			texture = SDL_CreateTextureFromSurface(g_pRenderer, textureSurface);
			SDL_FreeSurface(textureSurface); //elimina surface

			//TextureManager::Instance()->load(player1.bmp)...
	  return 0;
	}
	else{
		return 1; // sdl could not initialize
	}

};

void game::render(int a, int b, int c) {
	   

	rectanguloFuente.x = PosicionSprite *100;
	rectanguloFuente.y = 0;
	rectanguloFuente.w = 100; //anchura de la imagen
	rectanguloFuente.h = 200; //altura de la imagen

	rectanguloDestino.x = 800 / 2 -100;
	rectanguloDestino.y = 600 /2 - 200;
	rectanguloDestino.w = 100;
	rectanguloDestino.h = 200;


	//a=rojo
	//b=verde
	//c=azul


	//TextureManager:: Instance()-> drawFrame("player")

	SDL_SetRenderDrawColor(g_pRenderer, a, b, c, rand() % 255);
	//PosicionSprite = (int)((SDL_GetTicks() / 100) % 6);


	// clear the window to black
	SDL_RenderClear(g_pRenderer);
	

	SDL_RenderCopy(g_pRenderer, texture, &rectanguloFuente, &rectanguloDestino);

	//show the window
	SDL_RenderPresent(g_pRenderer);


    SDL_Delay(10);

	
	
};


void game::update() {

	PosicionSprite = (int)((SDL_GetTicks() / 100) % 6);


}


void game::handleEvents() {


};


void game::clean() {

	SDL_DestroyWindow(g_pWindow);

	SDL_DestroyRenderer(g_pRenderer);

	// clean up SDL
	SDL_Quit();

};


bool game::isRunning() {

	return on;


};




