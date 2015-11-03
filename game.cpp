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
		// Creamos ventana
		g_pWindow = SDL_CreateWindow(titulo, xpos, ypos, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
		// Crear imagen memoria
		if (g_pWindow != 0) imgRender = SDL_CreateRenderer(g_pWindow, -1, 0);
		// añadir imagen en lista
		TextureManager::Instance()->load("homer1.bmp", "homer", imgRender);
		running = true;

		//Parametros del LoaderParams
		GameObject *player = new Player();
		player->load(new LoaderParams(WINDOW_WIDTH / 2 - 60, WINDOW_HEIGHT / 2 + 80, 85, 200, "homer", 0, 6, 0));

		GameObject *player2 = new Player();
		player2->load(new LoaderParams(50, 150, 85, 200, "ryu", 0, 6, 0));

		GameObject *player3 = new Player();
		player3->load(new LoaderParams(350, 0, 87, 200, "homer2", 0, 6, 0));

		//Vector
		m_gameObjects.push_back(player);
		m_gameObjects.push_back(player2);
		m_gameObjects.push_back(player3);


		//Cargar imagen
		TextureManager::Instance()->load("homer1.bmp", "homer", imgRender);
		TextureManager::Instance()->load("Ryu.bmp", "ryu", imgRender);
		TextureManager::Instance()->load("homer2.bmp", "homer2", imgRender);


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
		if ((event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)) {
		running = false;
		}
	}
}


void Game::clean() {

	SDL_RenderClear(imgRender);
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(imgRender);
	SDL_Quit();
}


bool Game::isRunning() { return running; }