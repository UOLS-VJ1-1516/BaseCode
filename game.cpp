#include "game.h"
#include "InputHandler.h"
#include "MenuState.h"
#include "PlayState.h"

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

//Funci�n para printar el juego
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

//Funci�n para updatear el juego
void Game::update()
{
	m_pGameStateMachine->update();
};

//Funci�n para updatear las entradas del usuario
void Game::handleEvents()
{
	InputHandler::Instance()->update();
};

//Funci�n para limpiar el juego
void Game::clean()
{
	SDL_RenderClear(g_pRenderer);
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_Quit();
};

//Funci�n para controlar si se ha salido o no del juego
bool Game::isRunning()
{
	return running;
};

//Funci�n para devolver el render
SDL_Renderer* Game::getRenderer()
{
	return g_pRenderer;
};

//Funci�n para devolver los ticks
int Game::getTicks() {
	return (int)(SDL_GetTicks());
};

//Funci�n para devolver el alto de pantalla
int Game::getScreenHeight() {
	return screenHeigth;
};

//Funci�n para devolver el ancho de pantalla
int Game::getScreenWidth() {
	return screenWidth;
};

//Funci�n para salir del juego
void Game::exit() {
	running = false;
};

//Funci�n para devolver la maquina de estados
GameStateMachine* Game::getGameStateMachine() {
	return m_pGameStateMachine;
}