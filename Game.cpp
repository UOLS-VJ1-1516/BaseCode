#include "Game.h"
#include "TextureManager.h"
#include "Params.h"
#include "InputHandler.h"



//Instancias
Game * Game::s_pInstance = 0;


// Constructor donde se inicializan variables y los GameObjects


Game::Game() {


	m_pWindow = 0;
	m_pRenderer = 0;
	player = new Player();
	enemigo = new Enemy();
	load = new Params(350, 350, 100, 200, "player", 4);
	load2 = new Params(0, 0, 110, 150,"enemigo", 4);
	
}

Game::~Game() {

}

//ahora añadimos las funciones declaradas en game.h y las rellenamos

//en este caso añadimos el codigo que estaba incluido en el main.cpp
// initialize SDL

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {

		m_pWindow = SDL_CreateWindow("Videojuegos VictorCordobes", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1800, 600, fullscreen);

		if (m_pWindow != 0) {


			//TextureManager::Instance()->load("player1.bmp", "player", g_pRenderer);

			m_pRenderer = SDL_CreateRenderer(m_pWindow, -100, 10);
			player->load(load);
			m_gameObjects.push_back(player);

			enemigo->load(load2);
			m_gameObjects.push_back(enemigo);


	        //cargamos la textura del jugador
			TextureManager::Instance()->load("Player.bmp", "player", m_pRenderer);
			//cargamos la textura del enemigo
			TextureManager::Instance()->load("Enemigo.bmp", "enemigo", m_pRenderer);
		
			
		}

		return true;
	}
	else
	{
		return false;
	}
}

void Game::render() {


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


	SDL_SetRenderDrawColor(m_pRenderer, 200, 100, 255, 255); //rosita 
	SDL_RenderClear(m_pRenderer);
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	// show the window
	SDL_RenderPresent(m_pRenderer);	
}

void Game::update() {
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

}

void Game::handleEvents(SDL_Event event) {
	InputHandler::Instance()->update();
}

void Game::clean() {
	SDL_Quit();
}

bool Game::isRunning() {
	return running;
}
SDL_Renderer* Game::getRender() {
	return m_pRenderer;
}

int Game::getTicks() {
	return (int)(SDL_GetTicks());
};
