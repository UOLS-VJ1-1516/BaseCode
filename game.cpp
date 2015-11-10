#include "game.h"
#include "GameObject.h"
#include <stdlib.h>
#include "SDL_image.h"
#include <vector>
#include "Player.h"
#include "Dog.h"


std::vector<GameObject*> m_gameObjects;
TextureManager* TextureManager::s_pInstance = 0;
GameObject* player;
GameObject* dog;
std::vector<LoaderParams*> loader;
LoaderParams* l1;
LoaderParams* l2;
Game* Game::s_pInstanceG = 0;

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

		player = new Player();
		dog = new Dog();

		m_gameObjects.push_back(player);
		m_gameObjects.push_back(dog);

		l1 = new LoaderParams(0, 180, 97, 132, "imatge");
		l2 = new LoaderParams(0, 230, 64, 80, "imatge2");

		loader.push_back(l1);
		loader.push_back(l2);
		
		for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
		{
			m_gameObjects[i]->load(loader[i]);
		}
		running = true;
		return true;
	}
	
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
	void Game::update() {
		for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
		{
			m_gameObjects[i]->update();
		}
		
	}
	void Game::handleEvents() {
		InputHandler::Instance()->update();
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