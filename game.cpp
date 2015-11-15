#include "game.h"
#include "MenuState.h"
#include "PlayState.h"
#include <iostream>
//Instancias
Game* Game::g_pInstance = 0;

// Constructor donde se inicializan variables y los GameObjects
Game::Game() {
	m_pGameStateMachine = new GameStateMachine();
};
// Destructor
Game::~Game() {};

// Inicializamos el game
bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create our window
		g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		// if the window creation succeeded create our renderer
		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}

		screenWidth = width;
		screenHeigth = height;

		m_pGameStateMachine->pushState(new MenuState());

		return 0;
	}
	else
	{
		return 1; // sdl could not initialize
	}
};

void Game::render()
{
	// everything succeeded lets draw the window
	// set to black // This function expects Red, Green, Blue and
	// Alpha as color values
	SDL_SetRenderDrawColor(g_pRenderer, 255, 255, 255, 255);

	// clear the window to black
	SDL_RenderClear(g_pRenderer);

	m_pGameStateMachine->render();

	// show the window
	SDL_RenderPresent(g_pRenderer);
};

void Game::update()
{
	m_pGameStateMachine->update();
};

void Game::handleEvents()
{
	InputHandler::Instance()->update();
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		Game::Instance()->getGameStateMachine()->changeState(new PlayState());
	}
};

void Game::clean()
{
	SDL_RenderClear(g_pRenderer);
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_Quit();
};

bool Game::isRunning()
{
	return running;
};

SDL_Renderer* Game::getRenderer()
{
	return g_pRenderer;
};

int Game::getTicks() {
	return (int)(SDL_GetTicks());
};

int Game::getScreenHeight() {
	return screenHeigth;
};

int Game::getScreenWidth() {
	return screenWidth;
};

void Game::exit() {
	running = false;
};

GameStateMachine* Game::getGameStateMachine() {
	return m_pGameStateMachine;
}