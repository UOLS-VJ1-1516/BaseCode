#include "game.h"
#include "TextureManager.h"
#include "LoaderParams.h"

//#include "SDL_keycode.h"


//int r = 255;
//int g = 0;
//int b = 10;

Game * Game::s_pInstance = 0;

Game::Game() {
	//Nom de la classe :: Nom
	m_pWindow = 0;
	m_pRenderer = 0;
	p = new Player();
	e1 = new Player();
	e2 = new Player();
	l = new LoaderParams(0, 0, 35, 32, "player", 10);
	l2 = new LoaderParams(200, 200, 84, 62, "enemy1", 1);
	l3 = new LoaderParams(400, 300, 70, 64, "enemy2", 1);

}
Game::~Game() {

}
bool Game::init(const char* title, int xpos, int
	ypos, int width, int height, bool fullscreen) {


	//inicialitzem el SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {

		// if succeeded create our window
		//Creeem la finestra i el renderer
		m_pWindow = SDL_CreateWindow("Videjuegos 1 - bachelor",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			640, 480,
			fullscreen);

		// if the window creation succeeded create our renderer
		if (m_pWindow != 0)
		{

			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			p->load(l);
			m_gameObjects.push_back(p);

			e1->load(l2);
			m_gameObjects.push_back(e1);

			e2->load(l3);
			m_gameObjects.push_back(e2);

			TextureManager::Instance()->load("Kirby.bmp", "player", m_pRenderer);
			TextureManager::Instance()->load("Enemy1.bmp", "enemy1", m_pRenderer);
			TextureManager::Instance()->load("Enemy2.bmp", "enemy2", m_pRenderer);
		}
		TextureManager::Instance()->setSizeFrames("Player", 104, 151);
		TextureManager::Instance()->setSizeFrames("Key", 18, 32);
		TextureManager::Instance()->setSizeFrames("Tim", 26, 18);
	}

	else
	{
		return false; // sdl could not initialize
	}
	return true;

}
void Game::render() {
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(m_pRenderer);
	for (std::vector<Player*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	spriteNum = (int)((SDL_GetTicks() / 100) % 10);
	SDL_RenderPresent(m_pRenderer);
	//TextureManager::Instance()->drawFrame("player", 100, 100, 35, 32, 0, spriteNum, m_pRenderer, SDL_FLIP_NONE);
}

void Game::update() {
	for (std::vector<Player*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	
}

void Game::handleEvents(SDL_Event event) {

	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym = SDLK_ESCAPE) {
			running = false;
		}
	}


}


void Game::clean() {

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
