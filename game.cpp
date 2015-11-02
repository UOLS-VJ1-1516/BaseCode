#include "game.h"
#include "TextureManager.h"

Game* Game::s_pInstance = 0;

Game::Game() {
	m_pWindow = 0;
	m_pRenderer = 0;
	running = false;
	player1 = new Player();
	player2 = new Player();
	player3 = new Player();
	paramsPlayer1 = new LoaderParams(50, 50, 105, 156, "Player", 6);
	paramsPlayer2 = new LoaderParams(150, 300, 44, 40, "coin", 10);
	paramsPlayer3 = new LoaderParams(300, 50, 155, 204, "Shadow", 10);
}

Game::~Game() {

}

bool Game::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen) {
	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		// if succeeded create our window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, 0);

		// if the window creation succeeded create our renderer
		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		
			player1->load(paramsPlayer1);
			player2->load(paramsPlayer2);
			player3->load(paramsPlayer3);
			m_gameObjects.push_back(player1);
			m_gameObjects.push_back(player2);
			m_gameObjects.push_back(player3);

			//load img in my img list
			TextureManager::Instance()->load("frames.bmp", "Player", m_pRenderer);
			TextureManager::Instance()->load("coin.bmp", "coin", m_pRenderer);
			TextureManager::Instance()->load("shadow.bmp", "Shadow", m_pRenderer);
		}
		
		//app starts
		running = true;
		return 0;
	}
	else {
		return 1; // sdl could not initialize
	}
}

void Game::render() {
	//set color background
	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

	//clean screen
	SDL_RenderClear(m_pRenderer);

	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}

	//show print buffer
	SDL_RenderPresent(m_pRenderer);
}

void Game::update() {
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void Game::handleEvents() {
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYUP) {
			running = false;
		}
	}
}

void Game::clean() { 
	SDL_RenderClear(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	// clean up SDL
	SDL_Quit();
}

bool Game::isRunning() {
	return running;
}

SDL_Renderer* Game::getRender() {
	return m_pRenderer;
}

int Game::getTicks() {
	return (int) (SDL_GetTicks());
}