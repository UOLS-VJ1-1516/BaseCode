#include "Game.h"
#include "LoaderParams.h"

Game* Game::s_pInstance = 0;

Game::Game() {  //Constructor
	running = false;
	play = new PlayState();
	menu = new MenuState();
	state = new GameStateMachine();
}

Game::~Game() {}

bool Game::init(const char* title, int xpos, int
	ypos, int width, int height, bool fullscreen) {

	m_PANC = width;
	m_PALT = height;
	win = 0;
	ren = 0;
	bmp = NULL;
	tex = NULL;

	//m_pGameStateMachine = new GameStateMachine();
	//m_pGameStateMachine->changeState(new MenuState());

	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create our window
		win = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		// if the window creation succeeded create our renderer
		if (win != 0)
		{
			ren = SDL_CreateRenderer(win, -1, 0);
			state->pushState(menu);

			/*TextureManager::Instance()->load("play.png", "play", ren);
			GameObject *player = new Player();
			player->load(new LoaderParams(200, 150, 100, 100, "play", 1, 1, 0));
			m_gameObjects.push_back(player);

			TextureManager::Instance()->draw("play", 200, 200, 100, 100, ren, SDL_FLIP_NONE);*/

		}
		running = true;
		return true;
	}
	else
	{
		running = false;
		return false; 
	}

}


void Game::handleEvents() {

	TheInputHandler::Instance()->update();

}


void Game::update() {

	state->update();
}


void Game::render() {

	SDL_RenderClear(ren);
	//SDL_SetRenderDrawColor(ren, 200, 0, 0, 255);

	state->render();

 	SDL_RenderPresent(ren);	
	SDL_Delay(10);
}


void Game::clean() {

	TheInputHandler::Instance()->clean();
	m_gameObjects.clear();
	SDL_DestroyTexture(tex);
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);

}


bool Game::isRunning() {
	return running;
}

int Game::getP_ANC() {
	return  m_PANC;
}

int Game::getP_ALT() {
	return m_PALT;
}

SDL_Renderer* Game::getRender() {
	return ren;
}

void Game::quit() {
	running = false;
	SDL_Quit();
}

GameStateMachine* Game::getGameStateMachine() {
	return state;
};