#include "game.h"
#include "GameObject.h"
#include <stdlib.h>
#include "SDL_image.h"
#include <vector>
#include "Player.h"
#include "Dog.h"
#include "GameStateMachine.h"
#include "MenuButton.h"
#include "MenuState.h"
#include "PlayState.h"
#include "GameObjectFactory.h"


std::vector<GameObject*> m_gameObjects;
TextureManager* TextureManager::s_pInstance = 0;
GameObject* player;
GameObject* dog;
GameObject* menu;
std::vector<LoaderParams*> loader;
LoaderParams* l1;
LoaderParams* l2;
Game* Game::s_pInstanceG = 0;
GameStateMachine* m_pGameStateMachine;

	Game::Game(){
	}

	Game::~Game(){
	}

	Game* Game::Instance()
	{
		if (s_pInstanceG == 0)
		{
			s_pInstanceG = new Game();
		}
		return s_pInstanceG;
	}

	SDL_Renderer* Game::getRender() {
		return g_lRenderer;
	}

	bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
		// initialize SDL
		m_gameWidth = width;
		m_gameHeight = height;
		
		if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
		{
			// if succeeded create our window
			g_lWindow = SDL_CreateWindow(title,xpos, ypos,width, height,fullscreen);
			// if the window creation succeeded create our renderer
			if (g_lWindow != 0)
			{
				g_lRenderer = SDL_CreateRenderer(g_lWindow, -1, 0);
			}
		}
		else
		{
			return false; // sdl could not initialize
		}

		GameObjectFactory::Instance()->Register("MenuButton", MenuButton::Create);
		GameObjectFactory::Instance()->Register("Player", Player::Create);
		GameObjectFactory::Instance()->Register("Dog", Dog::Create);

		/*
		player = new Player();
		dog = new Dog();
		*/
		//menu = new MenuButton();
		m_pGameStateMachine = new GameStateMachine();
		//m_currentGameState = MENU;
		m_pGameStateMachine->changeState(new MenuState());
		/*
		m_gameObjects.push_back(player);
		m_gameObjects.push_back(dog);
		//m_gameObjects.push_back(menu);

		l1 = new LoaderParams(0, 180, 97, 132, "imatge");
		l2 = new LoaderParams(0, 230, 64, 80, "imatge2");

		loader.push_back(l1);
		loader.push_back(l2);
		
		
		for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
		{
			m_gameObjects[i]->load(loader[i]);
		}
		*/
		running = true;
		return true;
	}
	
	/*

	void Game::render() {
		SDL_SetRenderDrawColor(g_lRenderer, 255, 229, 204, 255);

		// clear the window to black
		SDL_RenderClear(g_lRenderer);

		//Mostrem les imatges
		
		for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
		{
			m_gameObjects[i]->draw();
		}
		
		// show the window
		//SDL_RenderPresent(g_lRenderer);
		SDL_RenderPresent(g_lRenderer);

		// set a delay before quitting
		SDL_Delay(15);

	}

	*/

	void Game::render()
	{
		SDL_SetRenderDrawColor(g_lRenderer, 255, 229, 204, 255);
		SDL_RenderClear(g_lRenderer);
		m_pGameStateMachine->render();
		SDL_RenderPresent(g_lRenderer);
	}

	/*
	void Game::update() {
		for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
		{
			m_gameObjects[i]->update();
		}
		
	}
	*/

	void Game::update()
	{
		m_pGameStateMachine->update();

		/*
		switch (m_currentState)
		{
		case MENU:
			m_gameObjects[2]->update();
			break;
		case PLAY:
			m_gameObjects[0]->update();
			m_gameObjects[1]->update();
			break;
		case GAMEOVER:
			// ...
		}
		*/
	}

	void Game::handleEvents() {
		InputHandler::Instance()->update();
		/*
		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
		{
			m_pGameStateMachine->changeState(new PlayState());
		}
		*/
	}
	void Game::clean() {
		
		for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
		{
			m_gameObjects[i]->clean();
		}
		
		SDL_DestroyWindow(g_lWindow);
		SDL_DestroyRenderer(g_lRenderer);
		SDL_Quit();
	}
	bool Game::isRunning() {
		return running;
	}
	
	GameStateMachine* Game::getStateMachine() {
		return m_pGameStateMachine;
	}

	int Game::getGameWidth()
	{
		return m_gameWidth;
	}

	int Game::getGameHeight()
	{
		return m_gameHeight;
	}
	