#include "game.h"
#include "TextureManager.h"


//Nom de la clase::Constructor a implementar
Game::Game() {

g_pWindow = 0;
g_pRenderer = 0;

//Tecla Esc
tancar = true;

};

Game::~Game()
{
};

bool Game::init(const char* title, int xpos, int
	ypos, int width, int height, bool fullscreen)
{
	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create our window
		g_pWindow = SDL_CreateWindow("Videjuegos 1 - bachelor",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			640, 480,
			SDL_WINDOW_SHOWN);

		// if the window creation succeeded create our renderer
		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
			if (!TextureManager::Instance()->load("dgz.bmp", "A", g_pRenderer)) {
				return false;
			}
		}
	}
	else
	{
		return false;
	}
};

void Game::EventHandler()
{
	if (SDL_PollEvent(&event) == 1) {
		if (event.key.keysym.sym == SDLK_ESCAPE) {
			tancar = false;
		}
	}
};

void Game::Clear()
{

	SDL_DestroyRenderer(g_pRenderer);
	SDL_DestroyWindow(g_pWindow);
	SDL_Quit();
};

bool Game::IsRunning()
{

	return tancar;
};

void Game::Render() 
{
	// clear the window to black
	SDL_RenderClear(g_pRenderer);

	// show the window
	SDL_RenderPresent(g_pRenderer);

	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

	idImatg = (int)((SDL_GetTicks() / 100) % 6);
	TextureManager::Instance()->drawFrame("A", 300, 200, 104, 151, 0, idImatg, g_pRenderer, SDL_FLIP_NONE);
};

void Game::Update()
{

	//SDL_RenderClear(g_pRenderer);

	SDL_RenderPresent(g_pRenderer);
};
