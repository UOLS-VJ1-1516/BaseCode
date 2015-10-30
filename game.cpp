#include "game.h"
#include "TextureManager.h"

//Instancias
Game* Game::g_pInstance = 0;

// Constructor donde se inicializan variables y los GameObjects
Game::Game(){
	player1 = new Player();
	params1 = new LoaderParams(500, 200, 103, 120, "player", "assets/sonic.bmp", 9, 0);
	enemy1 = new Enemy();
	params2 = new LoaderParams(800, 400, 110, 100, "enemy", "assets/enemy.bmp", 4, 0);
	enemy2 = new Enemy();
	params3 = new LoaderParams(600, 600, 65, 65, "xplosion", "assets/enemy2.bmp", 4, 0);
};
// Destructor
Game::~Game(){};

// Inicializamos el game
bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create our window
		g_pWindow = SDL_CreateWindow(title,	xpos, ypos,	width, height, fullscreen);

		// if the window creation succeeded create our renderer
		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}

		// Inicializamos GameObjects, los cargamos, y los guardamos en el vector de GameObjects
		player1->load(params1);
		m_gameObjects.push_back(player1);
		enemy1->load(params2);
		m_gameObjects.push_back(enemy1);
		enemy2->load(params3);
		m_gameObjects.push_back(enemy2);

		return 0;
	}
	else
	{
		return 1; // sdl could not initialize
	}
};

void Game::render(int r, int g, int b)
{
	// everything succeeded lets draw the window
	// set to black // This function expects Red, Green, Blue and
	// Alpha as color values
	SDL_SetRenderDrawColor(g_pRenderer, r, g, b, 255);

	// clear the window to black
	SDL_RenderClear(g_pRenderer);

	// Hacemos que todos los gamobjects se printen en pantalla
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

	// show the window
	SDL_RenderPresent(g_pRenderer);

	SDL_Delay(10);
};

void Game::update()
{
	// Hacemos que todos los gamobjects hagan sus respectivos updates
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
};

void Game::handleEvents(SDL_Event event)
{
	if (event.type == SDL_KEYDOWN)
		if (event.key.keysym.sym == SDLK_ESCAPE) 
			running = false;
};

void Game::clean()
{
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_Quit();
};

bool Game::isRunning()
{
	return running;
};

SDL_Renderer* Game::getRenderer()
{
	return g_pRenderer;
};

int Game::getTicks() {
	return (int)(SDL_GetTicks());
};
