#include "game.h"
#include "MenuState.h"
#include "PlayState.h"
#include "GameObjectFactory.h"


Game* Game::g_pInstance = 0;
GameObjectFactory* GameObjectFactory::s_pInstance = 0;


Game::Game() {
	m_pGameStateMachine = new GameStateMachine();
};




Game::~Game() {};



//ahora añadimos las funciones declaradas en game.h y las rellenamos

//en este caso añadimos el codigo que estaba incluido en el main.cpp
// initialize SDL



bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{

		g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);


		if (g_pWindow != 0)
		{

			//TextureManager::Instance()->load("player1.bmp", "player", g_pRenderer);

			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}

		screenWidth = width;
		screenHeigth = height;


		//Se registran los botones que provienen de la factoria de objetos

		TheGameObjectFactory->Register("MenuButton", &MenuButton::Create);
		//cargamos la textura del jugador
		TheGameObjectFactory->Register("Player", &Player::Create);
		//cargamos la textura del enemigo
		TheGameObjectFactory->Register("Enemy", &Enemy::Create);

		m_pGameStateMachine->pushState(new MenuState());

		return 0;



	}
	else {

		return 1;
	}
};

void Game::render()
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



	SDL_SetRenderDrawColor(g_pRenderer, 200, 100, 255, 255);


	SDL_RenderClear(g_pRenderer);

	m_pGameStateMachine->render();

	//muestra la pantala
	SDL_RenderPresent(g_pRenderer);
};


void Game::update()
{
	m_pGameStateMachine->update();
};


void Game::handleEvents()
{
	InputHandler::Instance()->update();
};


void Game::clean()
{
	SDL_RenderClear(g_pRenderer);
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



//Se inicializan las diferentes funciones 

int Game::getTicks() {

	return (int)(SDL_GetTicks());



};






int Game::getScreenHeight() {
	return screenHeigth;








};


int Game::getScreenWidth() {
	return screenWidth;






};


void Game::exit() {
	running = false;







};


GameStateMachine* Game::getGameStateMachine() {

	return m_pGameStateMachine;





}