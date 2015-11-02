#include "game.h"
#include "TextureManager.h"

//Instancias
game* game::g_pInstance = 0;

// Constructor donde se inicializan variables y los GameObjects
game::game() {
	player1 = new Player();
	params1 = new LoaderParams(1000, 1000, 50, 50, "player", "assets/player1.bmp", 8, 0);
	enemy1 = new enemy();
	params2 = new LoaderParams(800, 400, 110, 100, "enemy", "assets/enemy.bmp", 4, 0);
	enemy2 = new enemy();
	params3 = new LoaderParams(600, 600, 65, 65, "xplosion", "assets/enemy2.bmp", 4, 0);
};
// Destructor
game::~game() {};

// Inicializamos el game
bool game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create our window
		g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

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

void game::render(int r, int g, int b)
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

void game::update()
{
	// Hacemos que todos los gamobjects hagan sus respectivos updates
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
};

void game::handleEvents(SDL_Event event)
{
	if (event.type == SDL_KEYDOWN)
		if (event.key.keysym.sym == SDLK_ESCAPE)
			running = false;
};

void game::clean()
{
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_Quit();
};

bool game::isRunning()
{
	return running;
};

SDL_Renderer* game::getRenderer()
{
	return g_pRenderer;
};

int game::getTicks() {
	return (int)(SDL_GetTicks());
};