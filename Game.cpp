

#include "Game.h"
#include "TextureManager.h"



Game* Game::g_Instance = 0;

Game::Game() {
	g_pWindow = 0;
	flag = true;
	g_pRenderer = 0;
	pixelesDeAncho = new int(0);
	pixelesDeAlto = new int(0);
}

Game::~Game() {
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		*(pixelesDeAncho) = width;
		*(pixelesDeAlto) = height;
		if (fullscreen) {
			g_pWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_FULLSCREEN_DESKTOP);
		}
		else {
			g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		}

		SDL_GetWindowSize(g_pWindow, pixelesDeAncho, pixelesDeAlto);

		if (g_pWindow != 0) {
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
			
			GO = new GameObject();
			GO->load(xpos, ypos, width, height, "Sprite");
			m_gameObjects.push_back(GO);

			TextureManager::Instance()->load("animation1.png", "Sprite", g_pRenderer);
			
		}
		
		//Game::Instance()->

		
		return true;
	}
	else {
		return false;
	}
}

void Game::render() {
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(g_pRenderer);

	//spriteNum = (int)((SDL_GetTicks() / 100) % 6);
	

	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
		
	}

}

void Game::update() {
	
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	SDL_RenderPresent(g_pRenderer);
}

void Game::handleEvents() {
	if (SDL_PollEvent(&event) == 1) {
		if ((event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)) {
			flag = false;
		}
	}

}

void Game::clean() {
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