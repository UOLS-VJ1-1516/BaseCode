#include "game.h"
#include "SDL_keycode.h"

int r = 255;
int g = 0;
int b = 10;

Game::Game(){
//Nom de la classe :: Nom
	m_pWindow = 0;
	m_pRenderer = 0;
	
	

	
}
Game::~Game(){
	
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

			// Alpha as color values
			SDL_SetRenderDrawColor(m_pRenderer, r, g, b, 255);
		}
	}
	else
	{
		return false; // sdl could not initialize
	}

	return true;

	}
void Game::render() {
	SDL_RenderClear(m_pRenderer);
	SDL_RenderPresent(m_pRenderer);
}

void Game::update() {

	SDL_SetRenderDrawColor(m_pRenderer, r, g, b, 255);
	r--;
	g++;
	b++;
	if (r<=0 && r>=255) {
		g--;
		b++;
	}
	if (g >= 255 && g<=0) {
		b--;
		r++;
	}
	if (b <=0 && b>=255) {
		r++;
		g++;
	}
	SDL_Delay(10);
	

}

void Game::handleEvents(SDL_Event event) {

	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym = SDLK_ESCAPE) {
			running = false;
		}
	}
	

}
	

void Game::clean() {
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

bool Game::isRunning() {
	return running;
}
