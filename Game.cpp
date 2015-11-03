#include "SDL.h"
#include "SDL_image.h"
#include "Game.h"
#include "TextureManager.h"
#include "vector"
#include "GameObject.h"
#include "Player.h"
#include "LoaderParams.h"

Game* Game::s_pInstance = 0;
std::vector< GameObject* > m_gameObjects;

Game::Game() {  //Constructor
	running = false;
	p = new Player();
	ghost = new Ghost();
	//int x, int y, int width, int height,const char* textureID, int currentRow, int sprits, int flip)
	lp = new LoaderParams(500, 400, 100, 100, "monster", 1, 7, 0);
	loadghost = new LoaderParams(200, 300, 310, 245, "ghost", 1, 3, 0);
}
Game::~Game() {}


bool Game::init(const char* title, int xpos, int
	ypos, int width, int height, bool fullscreen) {

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

	

		p->load(lp);
		m_gameObjects.push_back(p);
		ghost->load(loadghost);
		m_gameObjects.push_back(ghost);
		TextureManager::Instance()->load("monster.png", "monster", ren);
		TextureManager::Instance()->load("ghost.png", "ghost", ren);
		

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

	if (SDL_PollEvent(&event) == 1) {
		if ((event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)) {
			running = false;
		}
	}
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
	

	//texture.draw("monster", (P_ANC/2)-iW/2, (P_ALT/2)-iH/2, iW, iH, ren, SDL_FLIP_NONE);

	//texture.drawFrame("monster", desp*2 , (P_ALT / 2) - iH / 2, iW, iH, 1, spriteNum,ren, SDL_FLIP_NONE);
	
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

 	SDL_RenderPresent(ren);
	
	SDL_Delay(10);
}


void Game::clean() {
	m_gameObjects.clear();
	SDL_DestroyTexture(tex);
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);

	// clean up SDL
	SDL_Quit();
}


bool Game::isRunning() {
	return running;
}

SDL_Renderer* Game::getRender() {
	return ren;
};