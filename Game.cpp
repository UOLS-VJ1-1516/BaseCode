#include "game.h"
//#include "SDL_keycode.h"


//int r = 255;
//int g = 0;
//int b = 10;




Game::Game() {
	//Nom de la classe :: Nom
	m_pWindow = 0;
	m_pRenderer = 0;



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
			TextureManager::Instance()->load("Kirby.bmp", "player", m_pRenderer);
		}
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

	spriteNum = (int)((SDL_GetTicks() / 100) % 10);
	TextureManager::Instance()->drawFrame("player", 100, 100, 35.7, 32, 0, spriteNum, m_pRenderer, SDL_FLIP_NONE);
}

void Game::update() {
	SDL_RenderPresent(m_pRenderer);
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
