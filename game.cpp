#include "game.h"

Game* Game::s_pInstance = 0;

Game::Game() {
	m_pWindow = 0;
	m_pRenderer = 0;
	running = false;
	m_pGameStateMachine = new GameStateMachine();
	/*player1 = new Player();
	enemy1 = new Enemy();
	stObj1 = new StaticObject();
	paramsPlayer1 = new LoaderParams(0, 400, 100, 101, "Player", 6, 0, 0, 30, 0.1);
	paramsEnemy1 = new LoaderParams(350, 100, 256, 256, "Zombie", 6, 3, 0, 10, 0.1);
	paramsStObj1 = new LoaderParams(150, 50, 44, 40, "coin", 10, 0, 0, 0, 0);*/
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
		
			//m_pGameStateMachine->changeState(new PlayState());
			m_pGameStateMachine->pushState(new MenuState());

			/*player1->load(paramsPlayer1);
			enemy1->load(paramsEnemy1);
			stObj1->load(paramsStObj1);
			m_gameObjects.push_back(player1);
			m_gameObjects.push_back(enemy1);
			m_gameObjects.push_back(stObj1);

			//load img in my img list
			TextureManager::Instance()->load("buffon.bmp", "Player", m_pRenderer);
			TextureManager::Instance()->load("coin.bmp", "coin", m_pRenderer);
			TextureManager::Instance()->load("zombie1.bmp", "Zombie", m_pRenderer);*/
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

	/*for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}*/

	m_pGameStateMachine->render();

	//show print buffer
	SDL_RenderPresent(m_pRenderer);
}

void Game::update() {
	
	/*for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}*/

	m_pGameStateMachine->update();
}

void Game::handleEvents() {
	/*InputHandler::Instance()->update();

	if (InputHandler::Instance()->isExitClicked() || InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
		running = false;
	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		player1->incrementAcceleration();
	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		player1->decrementAcceleration();
	}

	InputHandler::Instance()->clean();*/
}

void Game::clean() { 
	//m_gameObjects.clear();
	SDL_RenderClear(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();

	running = false;
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