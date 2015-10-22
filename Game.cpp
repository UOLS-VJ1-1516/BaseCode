#include "SDL.h"
#include "SDL_image.h"
#include "Game.h"
#include "TextureManager.h"

SDL_Window* win = 0;
SDL_Renderer* ren = 0;
SDL_Surface* bmp = NULL;
SDL_Texture* tex = NULL;
SDL_Rect dst;
SDL_Rect clips[5];
TextureManager texture;

const int P_ANC = 1280;
const int P_ALT = 720;

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

		texture.load("monster.png", "monster", ren);

		//SESSIO 2! texture manager instance load

		//tex = SDL_CreateTextureFromSurface(ren, bmp);

		/*if (ren != 0)
		{
			 bmp = IMG_Load("monster.png");
			 
			 SDL_FreeSurface(bmp);



			/* int iW = 100, iH = 100;
			 int x = P_ALT / 2 - iW / 2;
			 int y = P_ANC / 2 - iH / 2;

			 
			 for (int i = 0; i < 6; ++i) {
				 clips[i].x = i / 2 * iW;
				 clips[i].y = i % 2 * iH;
				 clips[i].w = iW;
				 clips[i].h = iH;
			 }
		}*/

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
	



	int iW = 100, iH = 100;
	int x = P_ALT / 2;
	int y = P_ANC / 2;
	/*

	for (int i = 0; i < 6; ++i) {
	clips[i].x = i / 2 * iW;
	clips[i].y = i % 2 * iH;
	clips[i].w = iW;
	clips[i].h = iH;
	}*/

	int spriteNum = (int)((SDL_GetTicks() / 100) % 7);


	//dst.x =x;
	//dst.y = y;
	//dst.w = iW;
	//dst.h = iH;

	//texture.draw("monster", (P_ANC/2)-iW/2, (P_ALT/2)-iH/2, iW, iH, ren, SDL_FLIP_NONE);
	texture.drawFrame("monster", (P_ANC / 2) - iW / 2, (P_ALT / 2) - iH / 2, iW, iH, 1, spriteNum,ren, SDL_FLIP_NONE);


	//SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);


	//SDL_RenderCopy(ren, tex, NULL, &dst);
	
	
 	SDL_RenderPresent(ren);
	
	SDL_Delay(10);

	//spriteNum = (int)((SDL_GetTicks() / 100) % 8)

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

