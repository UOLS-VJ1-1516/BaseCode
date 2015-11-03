#include "game.h"
#include "TextureManager.h"

Game* Game::g_pInstance = 0;

Game::Game(){
	goku = new Player();
	p1 = new LoaderParams(400, 150, 103, 120, "Goku", "dgz.bmp", 4, 0);
	freezer = new Enemy();
	p2 = new LoaderParams(400, 300, 110, 100, "Freezer", "enemy.bmp", 4, 0);
	shenron = new Enemy();
	p3 = new LoaderParams(400, 400, 100, 110, "dragon", "dragon.bmp", 4, 0);
};

Game::~Game(){};

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		g_pWindow = SDL_CreateWindow(title,	xpos, ypos,	width, height, fullscreen);

		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}

		goku->load(p1);
		m_gameObjects.push_back(goku);
		freezer->load(p2);
		m_gameObjects.push_back(freezer);
		shenron->load(p3);
		m_gameObjects.push_back(shenron);

		return 0;
	}
	else
	{
		return 1;
	}
};

void Game::render(int r, int g, int b)
{
	SDL_SetRenderDrawColor(g_pRenderer, r, g, b, 255);

	SDL_RenderClear(g_pRenderer);

	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

	SDL_RenderPresent(g_pRenderer);

	SDL_Delay(10);
};

void Game::update()
{
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
};

void Game::handleEvents(SDL_Event event)
{
	if (event.type == SDL_KEYDOWN)
		if (event.key.keysym.sym == SDLK_ESCAPE) 
			running = false;
};

void Game::clean()
{
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_Quit();
};

bool Game::isRunning()
{
	return running;
};

SDL_Renderer* Game::getRenderer()
{
	return g_pRenderer;
};

int Game::getTicks() {
	return (int)(SDL_GetTicks());
};
