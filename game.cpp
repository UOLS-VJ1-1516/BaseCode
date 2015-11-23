
#include "game.h"
#include "texturemanager.h"
#include "LoadPar.h"



SDL_Renderer* g_lRenderer=0;
SDL_Renderer* Renderer = 0;
SDL_Window* g_lWindow = 0;
int i = 0;
int currrentFrame = 0;


SDL_Texture* texture;
Game * Game::s_pInstance = 0;

int x, y;

bool running = false;

Game::Game() {  //Constructor
	g_lRenderer = 0;
	textmanager = TextureManager::Instance();
	inputhan = InputHandler::Instance();
	m_pGameStateMachine = new GameStateMachine();
	
	
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
			m_pGameStateMachine = new GameStateMachine();
			m_pGameStateMachine->changeState(new MenuState());
		}	
		
		Renderer = GetRenderer();
		

	//	flip=1->SDL_FLIP_NONE;  flip =2-> SDL_FLIP_HORIZONTAL; flip = 3 ->SDL_FLIP_VERTICAL;
		
		
		
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
	
	m_pGameStateMachine->update();
	//SDL_SetRenderDrawColor(GetRenderer(), 50, 50, 50, 255);
	
	/*for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}*/

	
}
void Game::render() { //Actualitzara el buffer i mostrara per pantalla
	
	SDL_RenderClear(g_lRenderer); 
	
	/*for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {

		m_gameObjects[i]->draw(Renderer);


	}*/
	m_pGameStateMachine->render();
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


void Game::handleEvents() {
	/*bool exit=InputHandler::Instance()->Quit();

	if (exit) {
		running = false;

	}

	return 1;*/
}










