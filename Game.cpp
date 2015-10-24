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
			SDL_SetWindowFullscreen(window, SDL_WINDOW_BORDERLESS);
		break;
	case SDL_SCANCODE_F2:
		takeScreenshot = true;
		break;
	case SDL_SCANCODE_A:
		player.Move(-7);
		break;
	case SDL_SCANCODE_D:
		player.Move(7);
	}	
}

Game::Game()
{
	Game::window = 0;
	Game::renderer = 0;
	Game::Running = true;
	Game::takeScreenshot = false;
	player = Player("player", 32, 32, 3, 6);
}


Game::~Game()
{
	window = 0;
	renderer = 0;
	Running = NULL;
	takeScreenshot = NULL;
}

bool Game::Init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen)
{	
	this->width = width;
	this->height = height;
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		if (window != 0) 
			renderer = SDL_CreateRenderer(window, -1, 0);		
		if (fullscreen) {
			SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
			Fullscreen = true;
		}
		else {
			Fullscreen = false;
		}
	}
	if (window == 0 || renderer == 0)
	{		
		return false;
	}	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	player.SetPosY((height / 2) - (player.GetSize('h') / 2));
	TextureManager::GetInstance()->Load("assets/img/Actor1.bmp", player.GetId(), renderer);
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
	if (takeScreenshot)
	{
		takeScreenShot(width, height, renderer);
		takeScreenshot = false;
	}
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	if (player.HaveAnimation())
		TextureManager::GetInstance()->DrawFrame(&player, renderer);
	else
		TextureManager::GetInstance()->Draw(&player, renderer);
	SDL_RenderPresent(renderer);
}

void Game::Close()
{
	Running = false;
}
