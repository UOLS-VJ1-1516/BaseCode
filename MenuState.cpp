#include "MenuState.h"
#include "Game.h"

void MenuState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
};

void MenuState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
};

bool MenuState::onEnter() {
	mb = new MenuButton(new LoaderParams(150, 250, 135, 34, "playbtn.bmp", 3, 0, 0, 0, 0), s_menuToPlay);
	m_gameObjects.push_back(mb);
	mb2 = new MenuButton(new LoaderParams(150, 300, 135, 34, "exitbtn.bmp", 3, 0, 0, 0, 0), s_exitFromMenu);
	m_gameObjects.push_back(mb2);

	return true;
};

bool MenuState::onExit() {
	m_gameObjects.clear();
	return true;
};

const std::string MenuState::s_menuID = "Menu";

std::string MenuState::getStateID() const{

	return MenuState::s_menuID;
};

void MenuState::s_menuToPlay() {
	Game::Instance()->getGameStateMachine()->changeState(new   PlayState());
};

void MenuState::s_exitFromMenu() {
	Game::Instance()->getGameStateMachine()->popState();
	Game::Instance()->getGameStateMachine()->voidAllOldStates();
	Game::Instance()->clean();
}; 
