#include "Game.h"

Game * Game::joc = 0;



Game::Game()
{
	Game::window = 0;
	Game::renderer = 0;
	Game::Running = true;
	Game::takeScreenshot = false;
}


void Game::ToggleFullscreen()
{
	Fullscreen = !Fullscreen;
	if (Fullscreen)
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
	else
		SDL_SetWindowFullscreen(window, SDL_WINDOW_BORDERLESS);
}

Game::~Game()
{
	entitats.clear();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
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
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);		
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
	
	int initFlags = IMG_INIT_PNG;
	if (!(IMG_Init(initFlags) & initFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());		
	}

	player = new Player();
	EntityParams * params = new EntityParams("player", 0, 0, 32, 32, 3, 6);
	player->Load(params, "Actor3.png");
	entitats.push_back(player);

	Enemy * enemy1 = new Enemy(IGNORE_ENEMY);
	EntityParams * enemy1Params = new EntityParams("enemy1", 150, 135, 32, 32, 3, 6);
	enemy1->Load(enemy1Params, "Monster1.png");
	entitats.push_back(enemy1);

	Enemy * enemy2 = new Enemy(FOLLOWER_ENEMY);
	EntityParams * enemy2Params = new EntityParams("enemy2", 150, 75, 32, 32, 3, 2);
	enemy2->Load(enemy2Params, "Monster1.png");
	entitats.push_back(enemy2);

	return true;
}

bool Game::IsRunning()
{
	return Running;
}

void Game::Clear()
{	
	Game::~Game();
}

void Game::EventHandler()
{
	delta = GetDeltaTime();
	/*std::string str = "FPS:";
	str.append(std::to_string(1000 / delta));
	SDL_SetWindowTitle(window, str.c_str());*/
	
	EventHandler::GetInstance()->HandleEvents();
}

void Game::Update()
{
	srand((int)time(NULL));
	r = rand() % 256;
	g = rand() % 256;
	b = rand() % 256;
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	for each (LivingEntity * var in entitats)
	{
		if (Enemy * en = dynamic_cast<Enemy *>(var)) {
			en->Update(player);
		}
		var->Update();
	}
	if (takeScreenshot)
	{
		takeScreenShot(width, height);
		takeScreenshot = false;
	}
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	for each (LivingEntity * var in entitats)
	{
		if (var->HaveAnimation())
			var->DrawFrame();
		else
			var->Draw();
	}
	
	SDL_RenderPresent(renderer);
}

void Game::Close()
{
	Running = false;
}
