#include "game.h"
#include "GameObjectFactory.h"
#include "SoundManager.h"

Game* Game::s_pInstance = 0;

Game::Game() {
	m_pWindow = 0;
	m_pRenderer = 0;
	running = false;
	m_pGameStateMachine = new GameStateMachine();
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

			GameObjectFactory::Instance()->Register("Player", &Player::Create);
			GameObjectFactory::Instance()->Register("Enemy", &Enemy::Create);
			GameObjectFactory::Instance()->Register("StaticObject", &StaticObject::Create);
			GameObjectFactory::Instance()->Register("MenuButton", &MenuButton::Create);

			//Carga de sonidos
			SoundManager::Instance()->loadMusic("assets/sounds/intro.wav", "intro");
			SoundManager::Instance()->loadSound("assets/sounds/jump.wav", "jump");
			SoundManager::Instance()->loadMusic("assets/sounds/win.wav", "win");
			SoundManager::Instance()->loadMusic("assets/sounds/gameOver.wav", "gameOver");
			m_pGameStateMachine->pushState(new MenuState());
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
	SDL_SetRenderDrawColor(m_pRenderer, 162, 216, 255, 255);

	//clean screen
	SDL_RenderClear(m_pRenderer);

	m_pGameStateMachine->render();

	//show print buffer
	SDL_RenderPresent(m_pRenderer);
}

void Game::update() {

	m_pGameStateMachine->update();
}

void Game::handleEvents() {

}

void Game::clean() { 
	running = false;
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
	return (int) (SDL_GetTicks());
}

int Game::getWindowWidth() {
	return (SDL_GetWindowSurface(m_pWindow)->w);
}

int Game::getWindowHeight() {
	return (SDL_GetWindowSurface(m_pWindow)->h);
}

void Game::setIsRunning(bool run) {
	running = run;
}

GameStateMachine* Game::getGameStateMachine() {
	return m_pGameStateMachine;
}