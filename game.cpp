#include "game.h"
#include "MenuState.h"
//#include "PauseState.h"

Game * Game::instance = 0;

Game::Game() {
	m_pWindow = 0;
	m_pRenderer = 0;
	red = 0;
	green = 0;
	blue = 0;
	alpha = 255;
}

Game::~Game() {}

SDL_Renderer * Game::getRenderer() {
	return m_pRenderer;
}

SDL_Window * Game::getWindow()
{
	return m_pWindow;
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		// if succeeded create our window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		// if the window creation succeeded create our renderer
		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			SDL_SetRenderDrawColor(m_pRenderer, red, green, blue, alpha);
		}
	}
	else {
		return false; // sdl could not initialize
	}
	running = true;
	gs_machine = new GameStateMachine();

	gs_machine->pushState(new MenuState());

	return true;
}

void Game::render() {
	// clear the window to black
	SDL_RenderClear(m_pRenderer);
	gs_machine->render();
	SDL_RenderPresent(m_pRenderer);
}

void Game::update() {
	gs_machine->update();
}

void Game::handleEvents() {
	SDL_Event event;
	
	while (SDL_PollEvent(&event)) {
		//OBJECTS
		gs_machine->handleEvents(event);
		//INTERFACE
	}
}

void Game::clean() {
	gs_machine->clean();
	SDL_Quit();
}

bool Game::isRunning() { return running; }

void Game::setRunning(bool running) {
	this->running = running;
}

GameStateMachine * Game::getGameStateMachine()
{
	return gs_machine;
}
