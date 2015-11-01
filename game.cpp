#include "game.h"
#include "TextureManager.h"
#include "LoaderParams.h"

const int WINDOW_HEIGHT = 800;
const int WINDOW_WIDTH = 800;

Game::Game()
{

	g_pWindow = 0;
	imgRender = 0;
	running = false;

}
Game * Game::s_pInstance = 0;


bool Game::init(const char* titulo, int xpos, int ypos, int typeWindow) {

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// Creo mi ventana
		g_pWindow = SDL_CreateWindow(titulo, xpos, ypos, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
		// Creo mi imagen en memoria
		if (g_pWindow != 0) imgRender = SDL_CreateRenderer(g_pWindow, -1, 0);
		// Añado mi imagen a mi lista de imagenes
		TextureManager::Instance()->load("hola.bmp", "hola", imgRender);
		// Indico que mi aplicación ha empezado
		running = true;

		//Parametros del LoaderParams
		GameObject *player = new Player();
		player->load(new LoaderParams(WINDOW_WIDTH / 2 - 60, WINDOW_HEIGHT / 2 - 100, 116, 200, "player", 0, 6, 0));
		
		GameObject *player2 = new Player();
		player2->load(new LoaderParams(20, 150, 125, 100, "vulture", 0, 6, 0));
		
		GameObject *player3 = new Player();
		player3->load(new LoaderParams(400, 0 , 300, 310, "dragon", 0, 8, 0));

		//Arrai
		m_gameObjects.push_back(player);
		m_gameObjects.push_back(player2);
		m_gameObjects.push_back(player3);


		//Carga la imagen
		TextureManager::Instance()->load("player1.bmp", "player", imgRender);
		TextureManager::Instance()->load("vulture_sprites.bmp", "vulture", imgRender);
		TextureManager::Instance()->load("dragon.bmp", "dragon", imgRender);


		return 0;
	}

	return 1;
}



void Game::render() {
	// Elijo el color con que voy a pintar la pantalla
	SDL_SetRenderDrawColor(imgRender, 255, 255, 255, 255);
	// Limpio la pantalla con el color seleccionado.
	SDL_RenderClear(imgRender);

	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw(imgRender);

		 
	}
	SDL_RenderPresent(imgRender);

}


void Game::update() {

	//Mostra bufer pintat
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	SDL_Delay(60);

}


void Game::handleEvents() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYUP) running = false;
	}
}


void Game::clean() {

	SDL_RenderClear(imgRender);
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(imgRender);
	SDL_Quit();
}


bool Game::isRunning() { return running; }