#include "MenuState.h"
#include "Game.h"



void MenuState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void MenuState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter()
{

	std::cout << "Entrada al menuState\n";
	return true;
}

bool MenuState::onExit()
{
	m_gameObjects.clear();
	std::cout << "Salida del MenuState\n";
	return true;
}
const std::string MenuState::s_menuID = "MENU";
/*std::string MenuState::getStateID() const {
	return MenuState::s_menuID;
}*/

void MenuState::s_menuTOplay() {
	Game::Instance()->getGameStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitMenu() {
	Game::Instance()->getGameStateMachine()->popState();
	Game::Instance()->getGameStateMachine()->AllStates();
	Game::Instance()->clean();
}
