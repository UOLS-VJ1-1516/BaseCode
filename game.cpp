#include "Game.h"
#include "TextureManager.h"
#include "LoaderParams.h"
#include "InputHandler.h"

Game * Game::s_pInstance = 0;

Game::Game() {
	m_pWindow = 0;
	m_pRenderer = 0;
	player = new Player();
	enemy1 = new Enemy();
	enemy2 = new Enemy2();
	load = new LoaderParams(100, 200, 50, 100, "player", 4);
	load2 = new LoaderParams(200, 70, 70, 100, "enemy1", 4);
	load3 = new LoaderParams(450, 300, 60, 100, "borot", 4);
}

Game::~Game() {

}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		m_pWindow = SDL_CreateWindow("Videojuegos 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, fullscreen);

		if (m_pWindow != 0) {

			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			player->load(load);
			m_gameObjects.push_back(player);

			enemy1->load(load2);
			m_gameObjects.push_back(enemy1);

			enemy2->load(load3);
			m_gameObjects.push_back(enemy2);

			TextureManager::Instance()->load("Player.bmp", "player", m_pRenderer);
			TextureManager::Instance()->load("Enemy1.bmp", "enemy1", m_pRenderer);
			TextureManager::Instance()->load("Calvo.bmp", "borot", m_pRenderer);
			
		}

		return true;
	}
	else
	{
		return false;
	}
}

void Game::render() {
	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
	SDL_RenderClear(m_pRenderer);
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	
	SDL_RenderPresent(m_pRenderer);	
}

void Game::update() {
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

}

void Game::handleEvents(SDL_Event event) {
	InputHandler::Instance()->update();
}

void Game::clean() {
	SDL_Quit();
}

bool Game::isRunning() {
	return running;
}
SDL_Renderer* Game::getRender() {
	return m_pRenderer;
}

int Game::getTicks() {
	return (int)(SDL_GetTicks());
};
