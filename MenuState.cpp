#include "MenuState.h"
#include "Game.h"

const std::string MenuState::s_menuID = "MENU";

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
	
	GameObject *menuButton = new MenuButton(new LoaderParams(150, 150, 400, 100, "playbtn.bmp",3), s_menuTOplay);
	if (menuButton == NULL) {
		return false;
	}
	TextureManager::Instance()->load("playbtn.bmp", "playbtn.bmp", Game::Instance()->getRender());
	m_gameObjects.push_back(menuButton);
	GameObject* menuButton2 = new MenuButton(new LoaderParams(150, 300, 400, 100, "exitbtn.bmp",3), s_exitMenu);
	if (menuButton2 == NULL) {
		return false;
	}
	m_gameObjects.push_back(menuButton2);
	TextureManager::Instance()->load("exitbtn.bmp", "exitbtn.bmp", Game::Instance()->getRender());

	std::cout << "Entrada al menuState\n";
	return true;
}

bool MenuState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	
	
	
	std::cout << "Salida del MenuState\n";
	return true;
}



void MenuState::s_menuTOplay() {
	Game::Instance()->getGameStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitMenu() {
	Game::Instance()->getGameStateMachine()->popState();
	

	Game::Instance()->quit();
	
}
