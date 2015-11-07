#include "game.h"
#include "TextureManager.h"
#include "LoaderParams.h"
#include "InputHandler.h"

Game* Game::s_pInstance = 0;

Game::Game()
{

}

Game::~Game()
{}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create our window
		m_pWindow = SDL_CreateWindow("Videojuegos 1 - bachelor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, fullscreen);
				
		// if the window creation succeeded create our renderer
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		if (TextureManager::Instance()->load("walker.bmp", "walker", m_pRenderer)) {
			LoaderParams* load = new LoaderParams(300, 200, 60, 38, "walker", 12);
			p1 = new Player();
			p1->load(load);
			m_players.push_back(p1);
		}
		if (TextureManager::Instance()->load("kirby.bmp", "kirby", m_pRenderer)) {
			LoaderParams* load2 = new LoaderParams(50, 50, 30, 27, "kirby", 6);
			p2 = new Enemy();
			p2->load(load2);
			m_enemies.push_back(p2);
		}
		if (TextureManager::Instance()->load("tanooki.bmp", "tanooki", m_pRenderer)) {
			LoaderParams* load3 = new LoaderParams(550, 400, 37, 35, "tanooki", 4);
			p3 = new Enemy();
			p3->load(load3);
			m_enemies.push_back(p3);
		}

		return true;
	}
	return false;

}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);

	for (std::vector<Player*>::size_type i = 0; i != m_players.size(); i++)
	{
		m_players[i]->draw(m_pRenderer);
	}

	for (std::vector<Enemy*>::size_type i = 0; i != m_enemies.size(); i++)
	{
		m_enemies[i]->draw(m_pRenderer);
	}

	SDL_RenderPresent(m_pRenderer);
}


void Game::update()
{	

	for (std::vector<Player*>::size_type i = 0; i != m_players.size(); i++)
	{
		m_players[i]->update();
	}

	for (std::vector<Enemy*>::size_type i = 0; i != m_enemies.size(); i++)
	{
		m_enemies[i]->update();
	}
}

void Game::handleEvents()
{
	//InputHandler::Instance()->isKeyDown();
	SDL_Event esc_event;
	
	while (SDL_PollEvent(&esc_event)) {
		switch (esc_event.type) {
		case SDL_KEYUP:
			switch (esc_event.key.keysym.sym) {
				case SDLK_ESCAPE:
					quit = 1;
					break;
			}				
		}
	}	
}

void Game::clean()
{
	m_players.clear();
	m_enemies.clear();
	SDL_RenderClear(m_pRenderer);
	SDL_Quit();
}

bool Game::isRunning()
{
	if (quit != 0) {
		return false;
	}
	return true;
}

SDL_Renderer* Game::getRender() {
	return m_pRenderer;
};