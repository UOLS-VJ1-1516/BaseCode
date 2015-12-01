#include "Game.h"
#include "TextureManager.h"
#include "LoaderParams.h"
#include "GameObjectFactory.h"


Game* Game::g_Instance = 0;

Game::Game() {
	g_pWindow = 0;
	flag = true;
	g_pRenderer = 0;

}

Game::~Game() {
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		if (fullscreen) {
			g_pWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_FULLSCREEN_DESKTOP);
		}
		else {
			g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		}

		screenWidth = width;
		screenHeigth = height;
		SDL_GetWindowSize(g_pWindow, &width, &height);

		if (g_pWindow != 0) {
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
			
			GameObjectFactory::Instance()->Register("Player", &Player::Create);
			GameObjectFactory::Instance()->Register("Enemy", &Enemy::Create);
			GameObjectFactory::Instance()->Register("StaticObject", &StaticObject::Create);
			GameObjectFactory::Instance()->Register("MenuButton", &MenuButton::Create);

			m_pGameStateMachine = new GameStateMachine();
			m_pGameStateMachine->changeState(new MenuState());
			
		}
		
		return true;
	}
	else {
		return false;
	}
}

void Game::render() {
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(g_pRenderer);


	m_pGameStateMachine->render();

	SDL_RenderPresent(g_pRenderer);

}

void Game::update() {
	
	m_pGameStateMachine->update();
}

void Game::handleEvents() {
	
	
	
}

void Game::clean() {
	flag = false;

	SDL_RenderClear(g_pRenderer);
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_Quit();
}

bool Game::isRunning() {
	return flag;
}

SDL_Renderer* Game::getRender(){

	return g_pRenderer;
}

void Game::setIsRunning(bool f) {
	flag = f;

}
int Game::getTicks() {
	return (int)(SDL_GetTicks());
};

int Game::getScreenWidth() {
	return screenWidth;
};

int Game::getScreenHeight() {
	return screenWidth;
};
GameStateMachine* Game::getStateMachine() {
	return m_pGameStateMachine;
};