#include "Game.h"
#include "TextureManager.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "GameObjectFactory.h"



//#include "SDL_keycode.h"


//int r = 255;
//int g = 0;
//int b = 10;


Game * Game::s_pInstance = 0;

Game::Game() {
	//Nom de la classe :: Nom
	m_pWindow = 0;
	m_pRenderer = 0;
	/*player = new Player();
	enemy1 = new Zep();
	enemy2 = new Gordo();
	
	load = new LoaderParams(100, 100, 35, 32, "player", 10);
	load2 = new LoaderParams(200, 200, 89, 78, "zep", 4);
	load3 = new LoaderParams(400, 300, 50, 70, "gordo", 4);*/
	//playState = new PlayState();
//	menuState = new MenuState();
	m_pGameStateMachine = new GameStateMachine();
	tx = TextureManager::Instance();
	th = InputHandler::Instance();

}
Game::~Game() {

}
bool Game::init(const char* title, int xpos, int
	ypos, int width, int height, bool fullscreen) {
	m_gameWidth = width;
	m_gameHeight = height;

	
	//inicialitzem el SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		
		// if succeeded create our window
		//Creeem la finestra i el renderer
		m_pWindow = SDL_CreateWindow("Videjuegos 1 - bachelor",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			m_gameWidth, m_gameHeight,
			fullscreen);

		// if the window creation succeeded create our renderer
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			TheGameObjectFactory->Register("MenuButton", &MenuButton::Create);
			TheGameObjectFactory->Register("Player", &Player::Create);
			TheGameObjectFactory->Register("Zep", &Zep::Create);
			TheGameObjectFactory->Register("Gordo", &Gordo::Create);
			m_pGameStateMachine = new GameStateMachine();
			m_pGameStateMachine->changeState(new MenuState());
			//m_pGameStateMachine->pushState(menuState);
			
			
			
			
		/*	player->load(load);
			m_gameObjects.push_back(player);

			enemy1->load(load2);
			m_gameObjects.push_back(enemy1);

			enemy2->load(load3);
			m_gameObjects.push_back(enemy2);

			TextureManager::Instance()->load("Kirby.bmp", "player", m_pRenderer);
			TextureManager::Instance()->load("ZepS.bmp", "zep", m_pRenderer);
			TextureManager::Instance()->load("GordoS.bmp", "gordo", m_pRenderer);*/
			
			

			
		}

		return true;
	}
	else
	{
		return false; // sdl could not initialize
	}
}

void Game::render() {
	SDL_SetRenderDrawColor(m_pRenderer, 0, 61, 192, 232);
	SDL_RenderClear(m_pRenderer);
	/*for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}*/
	m_pGameStateMachine->render();
	SDL_RenderPresent(m_pRenderer);
	
}

void Game::update() {
	/*for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}*/
	
	m_pGameStateMachine->update();

	

}

void Game::handleEvents(SDL_Event event) {

	//InputHandler::Instance()->update();
	/*if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
		m_pGameStateMachine->changeState(new PlayState());
	}*/
	/*if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym = SDLK_ESCAPE) {
			running = false;
		}
	}*/

	
	


}


void Game::clean() {
	SDL_RenderClear(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
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

GameStateMachine * Game::getGameStateMachine() {
	return m_pGameStateMachine;
}
