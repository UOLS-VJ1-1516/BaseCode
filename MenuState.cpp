#include "MenuState.h"
#include "Game.h"




const std::string MenuState::s_menuID = "MainMenu";

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

	GameObject *menuButton = new MenuButton(new Params(150, 150, 400, 100, "play.bmp", 3), s_Mplay);
	if (menuButton == NULL) {
		return false;

	}
	TextureManager::Instance()->load("play.bmp", "play.bmp", Game::Instance()->getRender());
	m_gameObjects.push_back(menuButton);
	GameObject* menuButton2 = new MenuButton(new Params(150, 300, 400, 100, "exit.bmp", 3), s_EMenu);
	if (menuButton2 == NULL) {
		return false;
	}
	m_gameObjects.push_back(menuButton2);
	TextureManager::Instance()->load("exit.bmp", "exit.bmp", Game::Instance()->getRender());

	return true;
}

bool MenuState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	return true;
}

	
