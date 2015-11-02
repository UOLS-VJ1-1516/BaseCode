	#include "game.h"
	#include "Player.h"
	#include "Enemy.h"
	#include "SDL_image.h"
	#include "TextureManager.h"
	#include "iostream"

	Player *player;
	Enemy *enemy;
	Enemy *enemy2;
	const LoaderParams* playerLoader;
	const LoaderParams* enemyLoader;
	const LoaderParams* enemy2Loader;

	bool running = true;
	int row=0;
	std::vector<GameObject*> m_gameObjects;

	Game* Game::g_pInstance = 0;

	Game::Game()
	{
		player = new Player();
		enemy = new Enemy();
		enemy2 = new Enemy();

		playerLoader = new LoaderParams(300, 320, 73, 58, 8, "player");
		enemyLoader = new LoaderParams(200, 400, 72, 34, 6, "bat");
		enemy2Loader = new LoaderParams(400, 300, 72, 64, 10, "mantis");
	}
	
	Game::~Game(){
		
	}
	
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
			TextureManager::Instance()->load("61933.bmp","player",m_pRenderer);
			
			TextureManager::Instance()->load("mantis.bmp", "mantis", m_pRenderer);
			
			TextureManager::Instance()->load("bat.bmp", "bat", m_pRenderer);

	
			player->load(playerLoader);
			m_gameObjects.push_back(player);
			
			
			enemy->load(enemyLoader);
			m_gameObjects.push_back(enemy);
	
			enemy2->load(enemy2Loader);
			m_gameObjects.push_back(enemy2);


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
	//	TextureManager::Instance()->draw("player", 73, 58, 73, 58,m_pRenderer);
	//	TextureManager::Instance()->drawFrame("player", 73, 58, 73, 58,
	//		row, spriteNum, m_pRenderer, SDL_FLIP_HORIZONTAL);
		for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
		{
			m_gameObjects[i]->draw();
		}
		// show the window
		SDL_RenderPresent(m_pRenderer);
	}
	
	void Game::update(){
		
		for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
		{
			m_gameObjects[i]->update();
		}

	}
	
	void Game::handleEvents(SDL_Event event){
		switch (event.type) {
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
				case SDLK_ESCAPE:
					running = false;
				case SDLK_UP:
				{
					row = row + 1;
					if (row > 8)row = 0;
				}
			}
			break;
		default:
			break;
		}
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
	};