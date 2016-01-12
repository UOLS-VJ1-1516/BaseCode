	#include "game.h"
	#include "Player.h"
	#include "Enemy.h"
	#include "SDL_image.h"
	#include "TextureManager.h"
	#include "iostream"
	#include "InputHandler.h"
	#include "MenuButton.h"
	#include "MenuState.h"
	#include "PlayState.h"
	#include "GameObjectFactory.h"

	Game* Game::g_pInstance = 0;

	Game::Game(){}
	Game::~Game(){}
	
	bool Game::init( const char* title , int xpos , int
		ypos , int width, int height , bool fullscreen )
	{
		if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
		{
			// if succeeded create our window
			m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
			// if the window creation succeeded create our renderer
			if(m_pWindow != 0)
			{
				m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

				SDL_SetRenderDrawColor(m_pRenderer, 0, 10, 40, 255);
			} 
			
			//afegir textura
			//Gameobject crear tots els gameobjects
			TheGameObjectFactory->Register("MenuButton", &MenuButton::Create);			TheGameObjectFactory->Register("Player", &Player::Create);			TheGameObjectFactory->Register("Enemy", &Enemy::Create);

			m_viewWidth = width;
			m_viewHeight = height;

			m_gameStateMachine = new GameStateMachine();
			m_gameStateMachine->changeState(new MenuState());
		}
		else
		{
			return false; // sdl could not initialize
		}
		return true;
	}
	void Game::render()
	{
		// clear the window to black
		SDL_RenderClear(m_pRenderer);

		m_gameStateMachine->render();

		SDL_RenderPresent(m_pRenderer);
	}
	
	void Game::update(){
		m_gameStateMachine->update();

	}
	
	void Game::handleEvents(){
		InputHandler::Instance()->update();
		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
		{
			//m_gameStateMachine->changeState(new PlayState());
		}
		/*switch (event.type) {
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
				case SDLK_ESCAPE:
					Game::quit();
			}
			break;
		default:
			break;
		}*/
	}
	
	void Game::clean(){
		// clean up SDL
		SDL_Quit();
	}
	
	bool Game::isRunning(){
		return running;
	}

	SDL_Renderer* Game::getRenderer()
	{
		return m_pRenderer;
	}
	GameStateMachine * Game::getStateMachine()
	{
		return m_gameStateMachine;
	}
	;