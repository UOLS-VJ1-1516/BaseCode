#include "Game.h"
#include "LoaderParams.h"


Game* Game::s_pInstance = 0;

Game::Game() {
	g_pWindow = 0;
	flag = true;
	g_pRenderer = 0;
	m_screenWidth = 800;
	m_screenHeight = 600;
	//Inicializamos los objetos.
	/*p = new Player();
	o = new StaticObjects();
	e = new Enemy();
	e2 = new Enemy();
	e3 = new Enemy();
	e4 = new Enemy();
	//Cargamos los parámetros de cada uno.
	lp = new LoaderParams(0, 0, 70, 61, "Player",  8, 0, 0, 30, 0.1); 
	lo = new LoaderParams(300, 500, 36, 64, "Key",  8, 0, 0, 0, 0.1); 
	le = new LoaderParams(250, 150, 60, 35, "Tim", 3, 3, 0, 10, 0.1);*/
	ps = new PlayState();
	ms = new MenuState();
	gsm = new GameStateMachine();
	TheTextureManager = TextureManager::Instance();
	TheInputHandler = InputHandler::Instance();
}

Game::~Game() {
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {

		if (fullscreen) {
			g_pWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_FULLSCREEN_DESKTOP);
			SDL_GetWindowSize(g_pWindow, &width, &height);
		}
		else {
			g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		}

		m_screenWidth = width;
		m_screenHeight = height;
		SDL_GetWindowSize(g_pWindow, &width, &height);
		
		if (g_pWindow != 0) {
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
			gsm->pushState(ms);
			//gsm->pushState(ps);
			//plstate->onEnter();
			//Ejemplo de player
			/*p->load(lp);
			m_gobjects.push_back(p);
			//Ejemplo de objeto estático
			o->load(lo);
			m_gobjects.push_back(o);
			//Ejemplo de enemigo	
			e->load(le);
			m_gobjects.push_back(e);
			le = new LoaderParams(500, 300, 60, 35, "Tim", 3, 8, 0, 10, 0.1);
			e2->load(le);
			m_gobjects.push_back(e2);
			le = new LoaderParams(500, 450, 60, 35, "Tim", 3, 10, 0, 10, 0.1);
			e3->load(le);
			m_gobjects.push_back(e3);
			le = new LoaderParams(500, 600, 60, 35, "Tim", 3, 5, 0, 10, 0.1);
			e4->load(le);
			m_gobjects.push_back(e4);*/
			

			/*if (!TheTextureManager->load("player.bmp", "Player", g_pRenderer) || !TheTextureManager->load("llave.bmp", "Key", g_pRenderer) || !TheTextureManager->load("tim.bmp", "Tim", g_pRenderer)) {
				return false;
			}
			//Este método permitirá almacenar el tamaño del sprite de origen, para poder jugar con el tamaño del sprite final.
			TheTextureManager->setSizeFrames("Player", 40, 31);
			TheTextureManager->setSizeFrames("Key", 18, 32);
			TheTextureManager->setSizeFrames("Tim", 26, 18);*/
		}

		return true;
	}
	else {
		return false;
	}
}

void Game::render() {
	//Vamos refrescando el fondo cuando renderizamos, para que no quede imagenes residuales. Ponemos color negro como fondo.
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(g_pRenderer);
	gsm->render();
	/*for (std::vector<GameObject*>::size_type i = 0; i < m_gobjects.size(); i++)
	{
		m_gobjects[i]->draw();
	}*/

	SDL_RenderPresent(g_pRenderer);
}

void Game::update() {
	//Recalculamos los valores de cada uno de los ojbetos de la pantalla.
	gsm->update();
	/*e->update(m_screenWidth);
	e2->update(m_screenWidth);
	e3->update(m_screenWidth);
	e4->update(m_screenWidth);
	p->update(m_screenWidth, m_screenHeight);
	for (std::vector<GameObject*>::size_type i = 0; i < m_gobjects.size(); i++)
	{
		m_gobjects[i]->update();
	}*/
}

void Game::handleEvents() {
	//if (TheInputHandler->getMouseButtonState(0) == true && ms->) {
		//flag = false;
	//	gsm->changeState(ps);
	//	TheInputHandler->clean();
	//}
	//TheInputHandler->update();
	//if (TheInputHandler->isKeyDown(SDL_SCANCODE_ESCAPE) || TheInputHandler->isExitRequired()) {
		//flag = false;
	//}
	/*if (TheInputHandler->isKeyDown(SDL_SCANCODE_RIGHT)) {
		p->incrementAccelerationX();
	}
	else if (TheInputHandler->isKeyDown(SDL_SCANCODE_LEFT)) {
		p->decrementAccelerationX();
	}
	if (TheInputHandler->isKeyDown(SDL_SCANCODE_UP)) {
		p->decrementAccelerationY();
	}
	else if (TheInputHandler->isKeyDown(SDL_SCANCODE_DOWN)) {
		p->incrementAccelerationY();
	}
	if (TheInputHandler->isKeyDown(SDL_SCANCODE_A)) {
		p->impulseLeft();
	}
	if (TheInputHandler->isKeyDown(SDL_SCANCODE_S)) {
		p->impulseRight();
	}
	TheInputHandler->clean();*/
}

void Game::clean() {
	//m_gobjects.clear();
	SDL_RenderClear(g_pRenderer);
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_Quit();
}

bool Game::isRunning() {
	return flag;
}

SDL_Renderer* Game::getRender() {
	return g_pRenderer;
};

int Game::getTicks() {
	return (int)(SDL_GetTicks());
};

int Game::getScreenWidth()
{
	return m_screenWidth;
}

int Game::getScreenHeight()
{
	return m_screenHeight;
}

void Game::setflag(bool b){
	flag = b;
};

bool Game::getflag(){
	return flag;
};

GameStateMachine* Game::getGameStateMachine() {
	return gsm;
};
