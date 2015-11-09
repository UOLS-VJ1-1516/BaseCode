#include "SDL.h"
#include "SDL_image.h"
#include "Game.h"
#include "TextureManager.h"
#include "vector"
#include "GameObject.h"
#include "Player.h"
#include "LoaderParams.h"
#include "InputHandler.h"

Game* Game::s_pInstance = 0;

Game::Game() {  //Constructor
	running = false;

}
Game::~Game() {}

bool Game::init(const char* title, int xpos, int
	ypos, int width, int height, bool fullscreen) {

	m_PANC = width;
	m_PALT = height;
	win = 0;
	ren = 0;
	bmp = NULL;
	tex = NULL;

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

		//Carguem sprits
		TextureManager::Instance()->load("monster.png", "monster", ren);
		TextureManager::Instance()->load("ghost.png", "ghost", ren);

		//Carguem parametres
		GameObject *player = new Player();
		player->load(new LoaderParams(200, 150, 100, 100, "monster", 1, 7, 0));

		GameObject *ghost = new Ghost();
		ghost->load(new LoaderParams(200, 350, 310, 245, "ghost", 1, 3, 0));

		//Afegim gameObjects
		m_gameObjects.push_back(player);
		m_gameObjects.push_back(ghost);

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

	TheInputHandler::Instance()->update();

}


void Game::update() {
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

}


void Game::render() {

	SDL_RenderClear(ren);
	SDL_SetRenderDrawColor(ren, 200, 0, 0, 255);

	
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

 	SDL_RenderPresent(ren);
	
	SDL_Delay(10);
}


void Game::clean() {

	TheInputHandler::Instance()->clean();
	m_gameObjects.clear();
	SDL_DestroyTexture(tex);
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);

}


bool Game::isRunning() {
	return running;
}

int Game::getP_ANC() {
	return  m_PANC;
}

int Game::getP_ALT() {
	return m_PALT;
}

SDL_Renderer* Game::getRender() {
	return ren;
};

void Game::quit() {
	running = false;
	SDL_Quit();
}