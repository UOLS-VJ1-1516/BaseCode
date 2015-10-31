#include "Game.h"
#include "TextureManager.h"
#include "LoaderParams.h"


const int SIZE_WINDOW_HEIGHT = 500;
const int SIZE_WINDOW_WIDTH = 500;

Game * Game::s_pInstance = 0;
Game::Game()
{
	g_pWindow = 0;
	g_pRenderer = 0;	
	state = false;	
}


bool Game::init(const char* tittle,int xPos, int yPos, int typeWindow)
{
	
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		g_pWindow = SDL_CreateWindow(tittle,xPos,yPos,SIZE_WINDOW_WIDTH, SIZE_WINDOW_HEIGHT,0);
		if (g_pWindow != 0) g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		state = true;		
		
		GameObject *player = new Player();
		player->load(new LoaderParams(SIZE_WINDOW_WIDTH / 2 - 40, SIZE_WINDOW_HEIGHT / 2 - 100, 81, 200, "majin",0,4,0));
		GameObject *player2 = new Player();
		player2->load(new LoaderParams( 40, 100, 50, 70, "goku",0,12,0));
		GameObject *player3 = new Player();
		player3->load(new LoaderParams(90, 100, 50, 70, "vegueta", 70, 12,1));
		
		m_gameObjects.push_back(player);
		m_gameObjects.push_back(player2);
		m_gameObjects.push_back(player3);

		TextureManager::Instance()->load("fusion.bmp", "goku", g_pRenderer);
		TextureManager::Instance()->load("fusion.bmp", "vegueta", g_pRenderer);
		TextureManager::Instance()->load("majin.bmp", "majin", g_pRenderer);
		return 0;

	}
	return 1; 
}

void Game::render()
{	
	SDL_SetRenderDrawColor(g_pRenderer, 255, 255, 255, 255);
	SDL_RenderClear(g_pRenderer);

	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{		
		m_gameObjects[i]->draw(g_pRenderer);
	}		
}

void Game::update(int delay)
{		
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}	
	SDL_Delay(delay);		
}

void Game::handleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_MOUSEBUTTONDOWN) state = false;
		if (event.type == SDL_KEYUP) state = false;
	}	
}

void Game::clean()
{
	SDL_RenderClear(g_pRenderer);
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_Quit();
}


bool Game::isRunning()
{
	return state;
}
