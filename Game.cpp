

#include "Game.h"
#include "TextureManager.h"
#include "LoaderParams.h"



Game* Game::g_Instance = 0;

Game::Game() {
	g_pWindow = 0;
	flag = true;
	g_pRenderer = 0;
	p1 = new Player();
	p2 = new Player();
	p3 = new Player();
	lp = new LoaderParams(0, 0, 72.5, 91, "Player", 6);
	lp2 = new LoaderParams(100, 200, 64, 58, "pajarito", 4);
	lp3 = new LoaderParams(300, 200, 167, 90, "otro", 4);
	screenWidth = 0;
	screenHeigth = 0;
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

	SDL_RenderPresent(g_pRenderer);

}

void Game::update() {
	
	for (std::vector<Player*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void Game::handleEvents() {
	if (SDL_PollEvent(&event) == 1) {
		if ((event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)) {
			flag = false;
		}
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