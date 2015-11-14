#include "Game.h"
#include "TextureManager.h"
#include "LoaderParams.h"
#include "MenuState.h"
#include "PlayState.h"

Game* Game::g_Instance = 0;

Game::Game() {
	g_pWindow = 0;
	flag = true;
	g_pRenderer = 0;
	p1 = new Player();
	p2 = new StaticObject();
	p3 = new Enemy();
	lp = new LoaderParams(350, 100, 72.5, 91, "Player", 6,0,0,35,0.1);
	lp2 = new LoaderParams(10, 300, 64, 58, "pajarito", 4,0, 0, 0, 0);
	lp3 = new LoaderParams(300, 200, 167, 90, "otro", 4, 4, 0, 4, 1);
	TheInputHandler = InputHandler::Instance();
	screenWidth = 800;
	screenHeigth = 600;
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
			
			p1->load(lp);
			m_gameObjects.push_back(p1);

			p2->load(lp2);
			m_gameObjects.push_back(p2);

			p3->load(lp3);
			m_gameObjects.push_back(p3);

			TextureManager::Instance()->load("animation1.png", "Player", g_pRenderer);
			TextureManager::Instance()->load("bird1.png", "pajarito", g_pRenderer);
			TextureManager::Instance()->load("pantera1.png", "otro", g_pRenderer);

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


	for (std::vector<Player*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	m_pGameStateMachine->render();

	SDL_RenderPresent(g_pRenderer);

}

void Game::update() {
	
	for (std::vector<Player*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	m_pGameStateMachine->update();
}

void Game::handleEvents() {
	
	TheInputHandler->update();
	if (TheInputHandler->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		p1->incrementAccelerationX();
	}
	if (TheInputHandler->isKeyDown(SDL_SCANCODE_LEFT))
	{
		p1->decrementAccelerationX();
	}

	if (TheInputHandler->Quit() || TheInputHandler->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		flag = false;
	}
	//
	TheInputHandler->update();
	if (TheInputHandler->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(new PlayState());
	}
	
}

void Game::clean() {
	m_gameObjects.clear();
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
int Game::getTicks() {
	return (int)(SDL_GetTicks());
};

int Game::getScreenWidth() {
	return screenWidth;
};

int Game::getScreenHeight() {
	return screenWidth;
};