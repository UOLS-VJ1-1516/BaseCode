#include "Game.h"

void Game::HandleKeys(SDL_Scancode code)
{
	switch (code) {
	case SDL_SCANCODE_ESCAPE:
		Close();
		break;
	case SDL_SCANCODE_F11:
		Fullscreen = !Fullscreen;
		if (Fullscreen)
			SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
		else
			SDL_SetWindowFullscreen(window, 0);
		break;
	}	
}

Game::Game()
{
	Game::window = 0;
	Game::renderer = 0;
	Game::Running = true;
}


Game::~Game()
{
		
}

bool Game::Init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen)
{	
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		if (window != 0) 
			renderer = SDL_CreateRenderer(window, -1, 0);		
		if (fullscreen) {
			SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
			Fullscreen = true;
		}
	}
	if (window == 0 || renderer == 0)
		return false;
	return true;
}

bool Game::IsRunning()
{
	return Running;
}

void Game::Clear()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	Game::~Game();
}

void Game::EventHandler()
{
	while (SDL_PollEvent(&event)) {
		if (&event == NULL)
			return;
		switch (event.type) {
		case SDL_KEYDOWN:
			HandleKeys(event.key.keysym.scancode);
			break;
		case SDL_KEYUP:
			break;
		case SDL_MOUSEBUTTONDOWN:
			break;
		default:
			break;
		}
	}
}

void Game::Update()
{
	srand(time(0));
	r = rand() % 256;
	g = rand() % 256;
	b = rand() % 256;
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void Game::Close()
{
	Running = false;
}
