#include "MenuState.h"
#include "Game.h"
#include <iostream>


const std::string MenuState::s_menuID = "MENU";
void MenuState::update()
{
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}
void MenuState::render()
{
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
bool MenuState::onEnter()
{
	TheInputHandler = InputHandler::Instance();

	buttonInit = new MenuButton(new LoaderParams(275.4, 200, 251, 67, "play", 3, 0, 0, 0, 0), s_menuToPlay);
	buttonExit = new MenuButton(new LoaderParams(275.4, 300, 251, 67, "btnexit", 3, 0, 0, 0, 0), s_exitFromMenu);
	
	m_gameObjects.push_back(buttonInit);
	m_gameObjects.push_back(buttonExit);

	TextureManager::Instance()->load("play.png", "play", Game::Instance()->getRender());
	TextureManager::Instance()->load("exit.png", "btnexit", Game::Instance()->getRender());
	
	std::cout << "entering MenuState\n";
	return true;
}
bool MenuState::onExit()
{
	m_gameObjects.clear();

	std::cout << "exiting MenuState\n";
	return true;
}

std::string MenuState::getStateID() const
{
	return std::string();
}

void MenuState::s_menuToPlay()
{
	Game::Instance()->getStateMachine()->changeState(new PlayState);
}

void MenuState::s_exitFromMenu()
{
	Game::Instance()->setIsRunning(false);
	Game::Instance()->getStateMachine()->popState();
	Game::Instance()->clean();
}
