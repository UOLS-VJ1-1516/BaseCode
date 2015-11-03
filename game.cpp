#include "game.h"
#include "cstdlib" //libreria para random
#include "TextureManager.h"
#include "SDL_image.h"


//Instancias
game* game::g_pInstance = 0;

// Constructor donde se inicializan variables y los GameObjects
game::game() {

	//sprite1
	player1 = new Player();
	para1 = new Param(1000, 500, 100, 200, "player", "player1.bmp", 6, 0);
	//sprite2
	enemy1 = new Enemy();
	para2 = new Param(800, 400, 115, 115, "enemy", "Enemy.bmp", 4, 0);
	//sprite3
	enemy2 = new Enemy();
	para3 = new Param(400, 600, 60, 140, "enemy2", "Enemy2.bmp", 4, 0);
};

game::~game() {};

bool game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	//ahora añadimos las funciones declaradas en game.h y las rellenamos

	//en este caso añadimos el codigo que estaba incluido en el main.cpp
	// initialize SDL

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if succeeded create our window
		g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		// if the window creation succeeded create our renderer
		if (g_pWindow != 0){
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);

	}

		//TextureManager::Instance()->load("player1.bmp", "player", g_pRenderer);

		//vector
		player1->load(para1);
		m_gameObjects.push_back(player1);
		enemy1->load(para2);
		m_gameObjects.push_back(enemy1);
		enemy2->load(para3);
		m_gameObjects.push_back(enemy2);

		return 0;
	}
	else
	{
		return 1; // sdl could not initialize
	}
};

void game::render(int a, int b, int c)
{
	// everything succeeded lets draw the window
	// set to black // This function expects Red, Green, Blue and
	// Alpha as color values

	/*
	rectanguloFuente.x = PosicionSprite *100;
	rectanguloFuente.y = 0;
	rectanguloFuente.w = 100; //anchura de la imagen
	rectanguloFuente.h = 200; //altura de la imagen

	rectanguloDestino.x = 800 / 2 -100;
	rectanguloDestino.y = 600 /2 - 200;
	rectanguloDestino.w = 100;
	rectanguloDestino.h = 200;

	*/

	//SDL_SetColorKey(texture, 1, SDL_MapRGB(texture->format, 255, 255, 255));

	SDL_SetRenderDrawColor(g_pRenderer, a, b, c, 100);

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



void game::clean()
{
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_Quit();
};

bool game::isRunning()
{
	return on;
};

SDL_Renderer* game::getRenderer()
{
	return g_pRenderer;
};

int game::getTicks() {
	return (int)(SDL_GetTicks());
};