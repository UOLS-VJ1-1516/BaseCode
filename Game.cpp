#include "Game.h"
#include "TextureManager.h"
#include "LoaderParams.h"

Game* Game::s_pInstance = 0;

Game::Game() {
	g_pWindow = 0;
	flag = true;
	g_pRenderer = 0;
	screenWidth = 0;
	screenHeigth = 0;
	//Inicializamos los objetos.
	p = new Player();
	o = new StaticObjects();
	e = new Enemy();
	//Cargamos los parámetros de cada uno.
	lp = new LoaderParams(0, 0, 100, 91, "Player", 8, +7); //Los dos últimos parámetros son cantidad de sprites que tenemos del objeto y velocidad de desplazamiento.
	lo = new LoaderParams(300, 500, 36, 64, "Key", 8, 0); //Velocidad 0 es que no se mueve el objeto.
	le = new LoaderParams(500, 300, 120, 70, "Tim", 3, -5); //Velocidad positiva o negativa solo afecta a la dirección del movimiento.
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
			screenWidth = width;
			screenHeigth = height;
			
			//Ejemplo de player
			p->load(lp);
			m_gobjects.push_back(p);
			//Ejemplo de objeto estático
			o->load(lo);
			m_gobjects.push_back(o);

			//Ejemplo de enemigo
			e->load(le);
			m_gobjects.push_back(e);

			if (!TextureManager::Instance()->load("player.bmp", "Player", g_pRenderer) || !TextureManager::Instance()->load("llave.bmp", "Key", g_pRenderer) || !TextureManager::Instance()->load("tim.bmp", "Tim", g_pRenderer)) {
				return false;
			}
			//Este método permitirá almacenar el tamaño del sprite de origen, para poder jugar con el tamaño del sprite final.
			TextureManager::Instance()->setSizeFrames("Player", 40, 31);
			TextureManager::Instance()->setSizeFrames("Key", 18, 32);
			TextureManager::Instance()->setSizeFrames("Tim", 26, 18);
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

	for (std::vector<GameObject*>::size_type i = 0; i < m_gobjects.size(); i++)
	{
		m_gobjects[i]->draw();
	}

	SDL_RenderPresent(g_pRenderer);
}

void Game::update() {
	//Recalculamos los valores de cada uno de los ojbetos de la pantalla.
	for (std::vector<GameObject*>::size_type i = 0; i < m_gobjects.size(); i++)
	{
		m_gobjects[i]->update();
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
	m_gobjects.clear();
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

int Game::getScreenWidth() {
	return screenWidth;
};

int Game::getScreenHeight() {
	return screenWidth;
};