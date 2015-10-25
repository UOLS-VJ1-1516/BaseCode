#include "game.h"
#include "SDL_keycode.h"
#include "TextureManager.h"

#define SPRITE_HEIGHT 35
#define SPRITE_WIDHT 32

int r = 255;
int g = 0;
int b = 10;



Game::Game(){
//Nom de la classe :: Nom
	m_pWindow = 0;
	m_pRenderer = 0;
	

	
}
Game::~Game(){
	
}
bool Game::init(const char* title, int xpos, int
	ypos, int width, int height, bool fullscreen) {
	

	//inicialitzem el SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {

		// if succeeded create our window
		//Creeem la finestra i el renderer
		m_pWindow = SDL_CreateWindow("Videjuegos 1 - bachelor",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			640, 480,
			fullscreen);

		// if the window creation succeeded create our renderer
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			// Alpha as color values
			//SDL_SetRenderDrawColor(m_pRenderer, r, g, b, 255);
			
		}
	}

	else
	{
		return false; // sdl could not initialize
	}
	
		img = SDL_LoadBMP("kirby.bmp");
		create = SDL_CreateTextureFromSurface(m_pRenderer, img);
		SDL_FreeSurface(img);
		screen = SDL_CreateTexture(m_pRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 43, 65);
		
	//TextureManager::Instance()->load("Kirby.bmp", "img", m_pRenderer);

	
	return true;

	}
void Game::render() {
	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, create, &SrcI, &DestR);
	
	
	SrcI.x = 0;
	SrcI.y = 0;
	SrcI.w = 40; //anchura de la imagen
	SrcI.h = 100; //altura de la imagen

	DestR.x = 800 / 2 - 40;
	DestR.y = 600 / 2 - 100;
	DestR.w = 70;
	DestR.h = 64;

	//TextureManager::Instance()->drawFrame("img",0,0, SPRITE_WIDHT, SPRITE_HEIGHT, SPRITE_WIDHT, spriteNum,m_pRenderer, SDL_FLIP_HORIZONTAL);

	SDL_RenderPresent(m_pRenderer);
}

void Game::update() {

	SDL_SetRenderDrawColor(m_pRenderer, r, g, b, 255);
	r--;
	g++;
	b++;
	if (r<=0 && r>=255) {
		g--;
		b++;
	}
	if (g >= 255 && g<=0) {
		b--;
		r++;
	}
	if (b <=0 && b>=255) {
		r++;
		g++;
	}
	SDL_Delay(10);
	spriteNum = (int)((SDL_GetTicks() / 100) % 10);

}

void Game::handleEvents(SDL_Event event) {

	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym = SDLK_ESCAPE) {
			running = false;
		}
	}
	

}
	

void Game::clean() {
	
	SDL_Quit();
}

bool Game::isRunning() {
	return running;
}
