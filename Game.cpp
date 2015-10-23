#include "SDL.h"
#include "SDL_image.h"
#include "Game.h"
#include "TextureManager.h"

SDL_Window* win = 0;
SDL_Renderer* ren = 0;
SDL_Surface* bmp = NULL;
SDL_Texture* tex = NULL;
SDL_Rect dst;
TextureManager texture;

const int P_ANC = 1280;
const int P_ALT = 720;
int desp = -50;
int r = 255;
int g = 0;
int b = 0;
int iW = 100, iH = 100;

bool running = false;


Game::Game() {  //Constructor

}
Game::~Game() {

}

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

		texture.load("monster.png", "monster", ren);

		running = true;
		return true;

	}
	else
	{
		running = false;
		return false; 
	}

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

void Game::update() {

		if ((r > 0) && (b == 0)) {
			r--;
			g++;
		}

		if ((g > 0) && (r == 0)) {
			g--;
			b++;
		}

		if ((g == 0) && (b > 0)) {
			b--;
			r++;
		}

		if (desp >(P_ANC/2)) {
			desp = -50;
		}
		desp++;
}


void Game::render() {

	SDL_RenderClear(ren);
	SDL_SetRenderDrawColor(ren, r, g, b, 255);
	

	int spriteNum = (int)((SDL_GetTicks() / 100) % 7);

	//texture.draw("monster", (P_ANC/2)-iW/2, (P_ALT/2)-iH/2, iW, iH, ren, SDL_FLIP_NONE);

	texture.drawFrame("monster", desp*2 , (P_ALT / 2) - iH / 2, iW, iH, 1, spriteNum,ren, SDL_FLIP_NONE);
	
 	SDL_RenderPresent(ren);
	
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