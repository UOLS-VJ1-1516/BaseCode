#include "Game.h"
#include "TextureManager.h"
#include "LoaderParams.h"

Game* Game::s_pInstance = 0;

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

		SDL_GetWindowSize(g_pWindow, &width, &height);

		if (g_pWindow != 0) {
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
			LoaderParams* l = new LoaderParams(0, 0, 104, 152, "Player", 6);
			p = new Player();
			p->load(l);
			m_gameObjects.push_back(p);

			if (!TextureManager::Instance()->load("tintin.bmp", "Player", g_pRenderer)) {
				return false;
			}
			//Este método permitirá almacenar el tamaño del sprite de origen, para poder jugar con el tamaño del sprite final.
			//TextureManager::Instance()->setSizeFrames("A", 104, 151); Esta parte comentada para más adelante.
		}

		return true;
	}
	else {
		return false;
	}
}

void Game::render() {
	//Vamos refrescando el fondo cuando renderizamos, para que no quede imagenes residuales. Ponemos color negro como fondo.
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
	SDL_RenderClear(g_pRenderer);
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_Quit();
}

bool Game::isRunning() {
	return flag;
}

SDL_Renderer* Game::getRender() {
	return g_pRenderer;
};

int Game::getTicks() {
	return (int)(SDL_GetTicks());
};