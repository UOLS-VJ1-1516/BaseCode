#include "Game.h"
#include "TextureManager.h"
#include "LoaderParams.h"
#include "InputHandler.h"

Game * Game::s_pInstance = 0;

Game::Game() {
	m_pWindow = 0;
	m_pRenderer = 0;
	m_pGameStateMachine = new GameStateMachine();
	tx = TextureManager::Instance();
	th = InputHandler::Instance();
}

Game::~Game() {

}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		m_pWindow = SDL_CreateWindow("Videjuegos 1 - bachelor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, fullscreen);

		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			m_pGameStateMachine = new GameStateMachine();
			m_pGameStateMachine->changeState(new MenuState());
		}
		return true;
	} else {
		return false;
	}
}

void Game::render() {
	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
	SDL_RenderClear(m_pRenderer);
	m_pGameStateMachine->render();
	SDL_RenderPresent(m_pRenderer);
}

void Game::update() {
	m_pGameStateMachine->update();
}

void Game::handleEvents(SDL_Event event) {
}

void Game::clean() {
	SDL_RenderClear(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
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

GameStateMachine * Game::getGameStateMachine() {
	return m_pGameStateMachine;
}