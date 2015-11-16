
#include "game.h"
#include "texturemanager.h"
#include "LoadPar.h"
#include "InputHandler.h"



SDL_Renderer* g_lRenderer=0;
SDL_Renderer* Renderer = 0;
SDL_Window* g_lWindow = 0;
int i = 0;
int currrentFrame = 0;


SDL_Texture* texture;
Game * Game::s_pInstance = 0;

int x,y, ancho, alto;

bool running = false;

Game::Game() {  //Constructor
	g_lRenderer = 0;
}
Game::~Game() {

}




bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {



	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{

		// if succeeded create our window
		g_lWindow = SDL_CreateWindow(title, xpos, ypos, width, height, false);
		ancho = width;
		alto = height;

		// if the window creation succeeded create our renderer
		if (g_lWindow != 0)
		{
			g_lRenderer = SDL_CreateRenderer(g_lWindow, -1, 0);
		}	
		
		Renderer = GetRenderer();


	//	flip=1->SDL_FLIP_NONE;  flip =2-> SDL_FLIP_HORIZONTAL; flip = 3 ->SDL_FLIP_VERTICAL;
		
		GameObject* player1 = new Player();
		player1->load(new LoadPar(200, 400, 200, 180, "bird1", 1, 7, 1,ancho,alto));


		GameObject* enemy1 = new Player();
		enemy1->load(new LoadPar(230, 160, 200, 220, "badbird", 3, 6, 1, ancho, alto));

		GameObject* enemy2 = new Enemy();
		enemy2->load(new LoadPar(100, 100, 200, 180, "badbird", 1, 7, 2, ancho, alto));

		GameObject* enemy3 = new Enemy();
		enemy3->load(new LoadPar(1200, 800, 200, 180, "badbird", 1, 7, 2, ancho, alto));

		GameObject* enemy4 = new Enemy();
		enemy4->load(new LoadPar(1500, 500, 200, 180, "badbird", 1, 7, 2, ancho, alto));

		GameObject* coin1 = new Enemy();
		coin1->load(new LoadPar(500, 300, 200, 200, "coin1", 1, 5, 2, ancho, alto));

	
		GameObject* fons = new Fons();
		fons->load(new LoadPar(0, 400, 1600, 850, "fons", 1, 1, 1, ancho, alto));

		GameObject* fons2 = new Fons();
		fons2->load(new LoadPar(1600, 400, 1600, 850, "fons", 1, 1, 1, ancho, alto));

		GameObject* play = new Enemy();
		play->load(new LoadPar(200, 500, 500, 100, "play", 1, 3, 1, ancho, alto));


		m_gameObjects.push_back(player1);
		m_gameObjects.push_back(enemy1);
		m_gameObjects.push_back(enemy2);
		m_gameObjects.push_back(enemy3);
		m_gameObjects.push_back(enemy4);
		m_gameObjects.push_back(coin1);
		m_gameObjects.push_back(fons);
		m_gameObjects.push_back(fons2);
		m_gameObjects.push_back(play);
		
		if (!TextureManager::Instance()->load("./images/bird.png", "bird1", Renderer)) { return false; }
		if (!TextureManager::Instance()->load("./images/badbird.png", "badbird", Renderer)) { return false; }
		if (!TextureManager::Instance()->load("./images/coin.png", "coin1", Renderer)) { return false; }
		if (!TextureManager::Instance()->load("./images/nubes2.png", "fons", Renderer)) { return false; }
		if (!TextureManager::Instance()->load("./images/Play.png", "play", Renderer)) { return false; }
		
		running = true;

	}
	else
	{
		return 1; // sdl could not initialize
	}

	return true;
}

void Game::update() {  //Actualitzara parametres diversos

	
	SDL_SetRenderDrawColor(Renderer, 25, 158, 218, 255);

	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}

	
}
void Game::render() { //Actualitzara el buffer i mostrara per pantalla
	
	SDL_RenderClear(g_lRenderer); 
	
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {

		m_gameObjects[i]->draw(Renderer);


	}
	SDL_RenderPresent(g_lRenderer);


}


void Game::clean() {
    SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(g_lRenderer);
	SDL_DestroyWindow(g_lWindow);
	SDL_Quit();




}
bool Game::isRunning() { 
return running; 
}


int Game::handleEvents() {
	bool exit=InputHandler::Instance()->Quit();

	if (exit) {
		running = false;

	}

	return 1;
}










