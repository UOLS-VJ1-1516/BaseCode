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
	
	
	if (!TextureManager::Instance()->load("playButton.bmp", "playbutton", Game::Instance()->getRender()))
	{
		
		return false;
	}
	if (!TextureManager::Instance()->load("Exit.bmp", "exitbutton", Game::Instance()->getRender()))
	{
		return false;
	}
	
	GameObject *menuButton = new MenuButton(new LoaderParams(200, 200, 250, 69, "playbutton",3), s_menuTOplay);
	if (menuButton == NULL) {
		return false;
	}
	m_gameObjects.push_back(menuButton);
	GameObject *menuButton2 = new MenuButton(new LoaderParams(200, 200, 250, 69, "exitbutton",3), s_exitMenu);
	if (menuButton2 == NULL) {
		return false;
	}
	m_gameObjects.push_back(menuButton2);


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
	Game::Instance()->quit(); 
}
