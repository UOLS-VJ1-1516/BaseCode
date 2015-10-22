#include "SDL.h"
#include "SDL_image.h"
#include "Game.h"
SDL_Window* win = 0;
SDL_Renderer* ren = 0;
SDL_Surface* bmp = NULL;
SDL_Texture* tex = NULL;
SDL_Rect dst;

const int P_ANC = 640;
const int P_ALT = 480;

Game::Game() {  //Constructor

}
Game::~Game() {

}

bool running = false;


bool Game::init(const char* title, int xpos, int
	ypos, int width, int height, bool fullscreen) {

	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create our window
		win = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		// if the window creation succeeded create our renderer
		if (win != 0)
		{
			ren = SDL_CreateRenderer(win, -1, 0);
		}

		//SESSIO 2! texture manager instance load

		if (ren != 0)
		{
			 bmp = SDL_LoadBMP("player.bmp");
			 tex= SDL_CreateTextureFromSurface(ren, bmp);
			 SDL_FreeSurface(bmp);
		}

		running = true;
		return true;

	}
	else
	{
		running = false;
		return false; // sdl could not initialize
	}

	// everything succeeded lets draw the window
	// set to black // This function expects Red, Green, Blue and
	// Alpha as color values

}


void Game::handleEvents() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		running = true;
		if (event.type == SDL_KEYUP)
		{
			running = false;
		}		
	}
}

//void Game::update() {

//}


void Game::render(int r, int g, int b) {

	SDL_RenderClear(ren);
	SDL_SetRenderDrawColor(ren, r, g, b, 255);
	

	dst.x = P_ANC / 2;
	dst.y = P_ALT / 2;

	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);

	SDL_RenderCopy(ren, tex, NULL, &dst);
	
	//SDL_SetRenderDrawColor(ren, r, g, b, 255);
	// clear the window to black
	//SDL_RenderClear(ren);
	// show the window
	SDL_RenderPresent(ren);
	// set a delay before quitting
	SDL_Delay(10);

}


void Game::clean() {
	SDL_DestroyTexture(tex);
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);

	// clean up SDL
	SDL_Quit();
}


bool Game::isRunning() {
	return running;
}



//GetAsyncKeyState(VK_ESCAPE) == 0)

