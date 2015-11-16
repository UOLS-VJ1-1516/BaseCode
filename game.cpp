#include "game.h"

Game::Game()
{
	_isRunning = false;
	r = 255;
	g = 0;
	b = 0;
}


Game::~Game()
{
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create our window
		_window = SDL_CreateWindow(title,
			xpos, ypos,
			width, height,
			SDL_WINDOW_SHOWN);

		// if the window creation succeeded create our renderer
		if (_window != 0)
		{
			_renderer = SDL_CreateRenderer(_window, -1, 0);
			_isRunning = true;
		}
	}
	else
	{
		return false; // sdl could not initialize
	}
	return true;
}

void Game::render()
{
	SDL_SetRenderDrawColor(_renderer, r, g, b, 0);
	SDL_RenderClear(_renderer);
	SDL_RenderPresent(_renderer);
}

void Game::update()
{
	if (r == 255 && g < 255 && b == 0)
	{
		g++;
	}
	else if (r > 0 && g == 255 && b == 0) 
	{
		r--;
	}
	else if (r == 0 && g == 255 && b < 255)
	{
		b++;
	}
	else if (r == 0 && g > 0 && b == 255)
	{
		g--;
	}
	else if (r < 255 && g == 0 && b == 255)
	{
		r++;
	}
	else if (r == 255 && g == 0 && b > 0)
	{
		b--;
	}

	SDL_Delay(5);
}

void Game::handleEvents()
{
	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
         {
            switch (event.key.keysym.sym)
            {
               case SDLK_ESCAPE:
                  _isRunning = false;
                  break;
            }
         }
	}
}

void Game::clean()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

bool Game::isRunning()
{
	return _isRunning;
}