#include "MenuState.h"
#include "iostream"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void MenuState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter()
{
	if (!TextureManager::Instance()->load("play.png",
		"playbutton", Game::Instance()->getRender()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("exit.png",
		"exitbutton", Game::Instance()->getRender()))
	{
		return false;
	}
	GameObject *button1 = new MenuButton(new LoaderParams(100, 100, 400, 100, "playbutton", 3,0,0), s_menuToPlay);
	GameObject *button2 = new MenuButton(new LoaderParams(100, 300, 400, 100, "exitbutton", 3,0,0), s_exitFromMenu);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TextureManager::Instance()->clear("playbutton");
	TextureManager::Instance()->clear("exitbutton");
	std::cout << "exiting MenuState\n";

	return true;
}

void MenuState::s_menuToPlay()
{
	Game::Instance()->getStateMachine()->changeState(new PlayState());
}
void MenuState::s_exitFromMenu()
{
	Game::Instance()->getStateMachine()->popState();
	Game::Instance()->getStateMachine()->clearStates();
	Game::Instance()->clean();
}