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
	
	
	menuButton = new MenuButton(new LoaderParams(mig(236, 75)[0], mig(236, 75)[1] - 50, 236, 75, "playButton.bmp", 3, 0, 0,0 , 0), s_menuTOplay);
	if (menuButton == NULL) {
		return false;
	}
	m_gameObjects.push_back(menuButton);
	menuButton2 = new MenuButton(new LoaderParams(mig(236, 75)[0], mig(236, 75)[1] - 50, 236, 75, "Exit.bmp", 3, 0, 0, 0, 0), s_exitMenu);
	if (menuButton2 == NULL) {
		return false;
	}
	m_gameObjects.push_back(menuButton2);


	std::cout << "Entrada al menuState\n";
	return true;
}

bool MenuState::onExit()
{
	m_gameObjects.clear();
	menuButton->clean();
	menuButton2->clean();
	
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
std::vector<int>MenuState::mig(int width, int height) {
	m_position = std::vector<int>(2, 0);
	
	return m_position;
}
