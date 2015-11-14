#include "PlayState.h"
#include "PauseState.h"
#include "Game.h"

void PlayState::update() {
	
	e->update(Game::Instance()->getScreenWidth());
	e2->update(Game::Instance()->getScreenWidth());
	e3->update(Game::Instance()->getScreenWidth());
	e4->update(Game::Instance()->getScreenWidth());
	p->update(Game::Instance()->getScreenWidth(), Game::Instance()->getScreenHeight());
	for (std::vector<GameObject*>::size_type i = 0; i < m_gobjects.size(); i++)
	{
		m_gobjects[i]->update();
	}

	InputHandler::Instance()->update();
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE) || InputHandler::Instance()->isExitRequired()) {
		//Game::Instance()->setflag(false);
		Game::Instance()->getGameStateMachine()->pushState(new PauseState());
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		p->incrementAccelerationX();
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		p->decrementAccelerationX();
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
		p->decrementAccelerationY();
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
		p->incrementAccelerationY();
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_A)) {
		p->impulseLeft();
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_S)) {
		p->impulseRight();
	}
	InputHandler::Instance()->clean();
};

void PlayState::render() {
	for (std::vector<GameObject*>::size_type i = 0; i < m_gobjects.size(); i++){
		m_gobjects[i]->draw();
	}
};

bool PlayState::onEnter() {
	p = new Player();
	o = new StaticObjects();
	e = new Enemy();
	e2 = new Enemy();
	e3 = new Enemy();
	e4 = new Enemy();
	//Cargamos los parámetros de cada uno.
	lp = new LoaderParams(0, 0, 70, 61, "Player",  8, 0, 0, 30, 0.1);
	lo = new LoaderParams(300, 500, 36, 64, "Key",  8, 0, 0, 0, 0.1);
	le = new LoaderParams(250, 150, 60, 35, "Tim", 3, 3, 0, 10, 0.1);

	//Ejemplo de player
	p->load(lp);
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
	m_gobjects.push_back(e4);

	if (!TextureManager::Instance()->load("player.bmp", "Player", Game::Instance()->getRender()) || !TextureManager::Instance()->load("llave.bmp", "Key", Game::Instance()->getRender()) || !TextureManager::Instance()->load("tim.bmp", "Tim", Game::Instance()->getRender())) {
		return false;
	}
	//Este método permitirá almacenar el tamaño del sprite de origen, para poder jugar con el tamaño del sprite final.
	TextureManager::Instance()->setSizeFrames("Player", 40, 31);
	TextureManager::Instance()->setSizeFrames("Key", 18, 32);
	TextureManager::Instance()->setSizeFrames("Tim", 26, 18);

	return true;
};

const std::string PlayState::s_menuID = "Play";

bool PlayState::onExit() {
	m_gobjects.clear();
	InputHandler::Instance()->clean();
	TextureManager::Instance()->clean("Player");
	TextureManager::Instance()->clean("Key");
	TextureManager::Instance()->clean("Tim");
	Game::Instance()->getGameStateMachine()->popState();
	return true;
};

std::string PlayState::getStateID() const {
	return PlayState::s_menuID;
};

std::vector<int> PlayState::theMiddle(int width, int height) {
	m_position = std::vector<int>(2, 0);
	m_position[0] = (Game::Instance()->getScreenWidth() / 2) - width / 2;
	m_position[1] = (Game::Instance()->getScreenHeight() / 2) - height / 2;

	return m_position;
};

