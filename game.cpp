	#include "game.h"
	#include "SDL.h"
	#include "SDL_image.h"
	#include "TextureManager.h"
	#include "iostream"
	
	bool running = true;
	SDL_Surface* s_sprite;
	SDL_Texture* s_texture;

	SDL_PixelFormat* format;
	int spriteNum;
	int row=0;
	Game::Game()
	{
		
	}
	
	Game::~Game(){
		
	}
	
	bool Game::init( const char* title , int xpos , int
		ypos , int width, int height , bool fullscreen )
	{
		if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
		{
			// if succeeded create our window
			m_pWindow = SDL_CreateWindow(title,
				xpos, ypos,
				width, height,
			fullscreen);

			// if the window creation succeeded create our renderer
			if(m_pWindow != 0)
			{
				m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

				SDL_SetRenderDrawColor(m_pRenderer, 0, 10, 40, 255);
			} 

			//afegir textura
			TextureManager::Instance()->load("61933.bmp","player",m_pRenderer);

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
		TextureManager::Instance()->drawFrame("player", 73, 58, 73, 58,
			row, spriteNum, m_pRenderer);

		// show the window
		SDL_RenderPresent(m_pRenderer);
	}
	
	void Game::update(){
		spriteNum = (int)((SDL_GetTicks() / 100) % 8);

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