#include "PlayState.h"
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

	return true;
};

const std::string PlayState::s_menuID = "Play";

bool PlayState::onExit() {

	return true;
};

std::string PlayState::getStateID() const {
	return PlayState::s_menuID;
};