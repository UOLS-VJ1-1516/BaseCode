
#include "game.h"
#include "texturemanager.h"
#include "LoadPar.h"
#include "InputHandler.h"




SDL_Window* g_lWindow = 0;
int i = 0;
int currrentFrame = 0;


SDL_Texture* texture;
Game * Game::s_pInstance = 0;

int x, y;

bool running = false;




bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {



	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{

		// if succeeded create our window
		g_lWindow = SDL_CreateWindow(title, xpos, ypos, 500, 500, false);
		m_Ancho = width;
		m_Alto = height;

		// if the window creation succeeded create our renderer
		if (g_lWindow != 0)
		{
			g_lRenderer = SDL_CreateRenderer(g_lWindow, -1, 0);
		}	
		
	


	//	flip=1->SDL_FLIP_NONE;  flip =2-> SDL_FLIP_HORIZONTAL; flip = 3 ->SDL_FLIP_VERTICAL;
		
		GameObject* player1 = new Player();
		player1->load(new LoadPar(200, 400, 200, 180, "bird1", 1, 7, 1,m_Ancho,m_Alto));


		GameObject* enemy1 = new Player();
		enemy1->load(new LoadPar(230, 160, 200, 220, "badbird", 3, 6, 1, m_Ancho, m_Alto));

		GameObject* enemy2 = new Enemy();
		enemy2->load(new LoadPar(100, 100, 200, 180, "badbird", 1, 7, 2, m_Ancho, m_Alto));

		GameObject* enemy3 = new Enemy();
		enemy3->load(new LoadPar(1200, 800, 200, 180, "badbird", 1, 7, 2, m_Ancho, m_Alto));

		GameObject* enemy4 = new Enemy();
		enemy4->load(new LoadPar(1500, 500, 200, 180, "badbird", 1, 7, 2, m_Ancho, m_Alto));

		GameObject* coin1 = new Enemy();
		coin1->load(new LoadPar(500, 300, 200, 200, "coin1", 1, 5, 2, m_Ancho, m_Alto));

	
		GameObject* fons = new Fons();
		fons->load(new LoadPar(0, 400, 1600, 850, "fons", 1, 1, 1, m_Ancho, m_Alto));

		GameObject* fons2 = new Fons();
		fons2->load(new LoadPar(1600, 400, 1600, 850, "fons", 1, 1, 1, m_Ancho, m_Alto));


		m_gameObjects.push_back(player1);
		m_gameObjects.push_back(enemy1);
		m_gameObjects.push_back(enemy2);
		m_gameObjects.push_back(enemy3);
		m_gameObjects.push_back(enemy4);
		m_gameObjects.push_back(coin1);
		m_gameObjects.push_back(fons);
		m_gameObjects.push_back(fons2);
		
		if (!TextureManager::Instance()->load("./images/bird.png", "bird1", g_lRenderer)) { return false; }
		if (!TextureManager::Instance()->load("./images/badbird.png", "badbird", g_lRenderer)) { return false; }
		if (!TextureManager::Instance()->load("./images/coin.png", "coin1", g_lRenderer)) { return false; }
		if (!TextureManager::Instance()->load("./images/nubes2.png", "fons", g_lRenderer)) { return false; }
		
		running = true;

	}
	else
	{
		return 1; // sdl could not initialize
	}

	return true;
}

void Game::update() {  //Actualitzara parametres diversos

	
	SDL_SetRenderDrawColor(g_lRenderer, 25, 158, 218, 255);

	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}

	
}
void Game::render() { //Actualitzara el buffer i mostrara per pantalla
	
	SDL_RenderClear(g_lRenderer); 
	
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {

		m_gameObjects[i]->draw(g_lRenderer);


	}
	SDL_RenderPresent(g_lRenderer);


}


void Game::clean() {
    SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(g_lRenderer);
	SDL_DestroyWindow(g_lWindow);
	SDL_Quit();




}


int Game::handleEvents() {
	//InputHandler::Instance()->update();

	/*if (SDL_SCANCODE_ESCAPE) {
		running = false;

	}*/

	return 1;
}










