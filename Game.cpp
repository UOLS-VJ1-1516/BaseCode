#include "Game.h"
#include "TextureManager.h"
#include "LoaderParams.h"


const int SIZE_WINDOW_HEIGHT = 500;
const int SIZE_WINDOW_WIDTH = 500;
const int FIXED_TIME = 35;
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
		
		GameObject *enemy = new Enemy();
		enemy->load(new LoaderParams(40, 30, "enemy2", 120, 2, 0, *(new Vector2D(0, 50)), *(new Vector2D(2, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0))));

		m_gameObjects.push_back(enemy);
		TextureManager::Instance()->load("enemy.bmp", "enemy", g_pRenderer);

		GameObject *enemy2 = new Enemy();
		enemy2->load(new LoaderParams(40, 30, "enemy2", 80, 2, 0, *(new Vector2D(100,100)), *(new Vector2D(15, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0))));

		m_gameObjects.push_back(enemy2);
		TextureManager::Instance()->load("enemy.bmp", "enemy2", g_pRenderer);

		GameObject *enemy3 = new Enemy();
		enemy3->load(new LoaderParams(40, 30, "enemy3", 120, 2, 0, *(new Vector2D(0, 150)), *(new Vector2D(1, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0))));

		m_gameObjects.push_back(enemy3);
		TextureManager::Instance()->load("enemy.bmp", "enemy3", g_pRenderer);

		GameObject *enemy4 = new Enemy();
		enemy4->load(new LoaderParams(40, 30, "enemy4", 80, 2, 0, *(new Vector2D(50, 250)), *(new Vector2D(5, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0)), *(new Vector2D(0, 0))));

		m_gameObjects.push_back(enemy4);
		TextureManager::Instance()->load("enemy.bmp", "enemy4", g_pRenderer);

		GameObject *player = new Player();
		player->load(new LoaderParams(13, 30, "mario", 0, 2, 0, *(new Vector2D(300, 200)), *(new Vector2D(0, 0)), *(new Vector2D(15, 0)), *(new Vector2D(1, 0)), *(new Vector2D(1, 0))));

		m_gameObjects.push_back(player);
		TextureManager::Instance()->load("mario.bmp", "mario", g_pRenderer);

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
		m_gameObjects[i]->draw();
	}	
	SDL_RenderPresent(g_pRenderer);
}

void Game::update(int delay)
{		
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}	

	int frameStart = SDL_GetTicks();
	int frameEnd = SDL_GetTicks();
	int frameTime = frameEnd - frameStart;
	if(frameTime < FIXED_TIME)
	{
		SDL_Delay((int)(FIXED_TIME - frameTime));
	}			
}

void Game::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {
			InputHandler::Instance()->update(event.key.keysym.sym);
		}
		if (event.type == SDL_KEYUP) {
			if (event.key.keysym.sym == SDLK_ESCAPE) { state = false; break; }
			InputHandler::Instance()->updateKeyUp(event.key.keysym.sym);
		}
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


int Game::getTicks() { return (int)(SDL_GetTicks()); };

const int Game::getwidthWindow() const
{
	return SIZE_WINDOW_WIDTH;
}