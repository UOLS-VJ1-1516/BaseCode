#include "Game.h"
#include "TextureManager.h"
#include "LoaderParams.h"


const int SIZE_WINDOW_HEIGHT = 600;
const int SIZE_WINDOW_WIDTH = 600;
const int FIXED_TIME = 35;
Game * Game::s_pInstance = 0;
Game::Game()
{
	g_pWindow = 0;
	g_pRenderer = 0;	
	state = false;	
}


bool Game::init(const char* tittle,int xPos, int yPos, int typeWindow)
{	
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		g_pWindow = SDL_CreateWindow(tittle,xPos,yPos,SIZE_WINDOW_WIDTH, SIZE_WINDOW_HEIGHT,0);
		if (g_pWindow != 0) g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		
		m_pGameStateMachine = new GameStateMachine();
		m_pGameStateMachine->changeState(new MenuState());
		state = true;			

		return 0;

	}
	return 1; 
}

void Game::render()
{	
	SDL_SetRenderDrawColor(g_pRenderer, 255, 255, 255, 255);
	SDL_RenderClear(g_pRenderer);
	m_pGameStateMachine->render();
	SDL_RenderPresent(g_pRenderer);
}

void Game::update(int delay)
{		
	m_pGameStateMachine->update();
	int frameStart = SDL_GetTicks();
	int frameEnd = SDL_GetTicks();
	int frameTime = frameEnd - frameStart;
	if(frameTime < FIXED_TIME)
	{
		SDL_Delay((int)(FIXED_TIME - frameTime));
	}			
}

void Game::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) InputHandler::Instance()->update(event.key.keysym.sym);
		if (event.type == SDL_KEYUP) InputHandler::Instance()->updateKeyUp(event.key.keysym.sym);
		if (event.type == SDL_MOUSEMOTION) InputHandler::Instance()->onMouseMotion(event.motion.x, event.motion.y);
		if (event.type == SDL_MOUSEBUTTONDOWN) InputHandler::Instance()->onMouseButtonDown(event.button.button);
		if (event.type == SDL_MOUSEBUTTONUP)InputHandler::Instance()->onMouseButtonUp(event.button.button);
	}
}

void Game::clean()
{
	state = false;
	SDL_RenderClear(g_pRenderer);
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_Quit();
}


bool Game::isRunning()
{
	return state;
}


int Game::getTicks() { return (int)(SDL_GetTicks()); };

const int Game::getwidthWindow() const
{
	return SIZE_WINDOW_WIDTH;
}