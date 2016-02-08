
#include "game.h"
#include "GameObjectFactory.h"

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
		g_lWindow = SDL_CreateWindow(title, xpos, ypos, width, height, false);
		m_Ancho = width;
		m_Alto = height;
		

		// if the window creation succeeded create our renderer
		if (g_lWindow != 0)
		{
			
			
			/*play = new PlayState();
			menu = new MenuState();*/
			state = new GameStateMachine();
			
			GameObjectFactory::Instance()->Register("MenuButton", &MenuButton::Create);
			GameObjectFactory::Instance()->Register("Player", &Player::Create);
			GameObjectFactory::Instance()->Register("Enemy", &Enemy::Create);
			
			
			g_aRenderer = SDL_CreateRenderer(g_lWindow, -1, 0);
			state->changeState(new MenuState());
		
			

		}	
		

		running = true;

	}
	else
	{
		return false; // sdl could not initialize
		running = false;
	}

	return true;
}

void Game::update() {  //Actualitzara parametres diversos

	
	SDL_SetRenderDrawColor(g_aRenderer, 25, 158, 218, 255);
	state->update();
	
	
}
void Game::render() { //Actualitzara el buffer i mostrara per pantalla
	
	SDL_RenderClear(g_aRenderer); 
	
	state->render();
	SDL_RenderPresent(g_aRenderer);
	


}


void Game::clean() {
	//InputHandler::Instance()->clean();
	m_gameObjects.clear();
    SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(g_aRenderer);
	SDL_DestroyWindow(g_lWindow);
	SDL_Quit();




}


void Game::handleEvents() {
	InputHandler::Instance()->update();

	/*if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
		running = false;

	}*/
}
GameStateMachine* Game::getGameStateMachine() {
	return state;
};










