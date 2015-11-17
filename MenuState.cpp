#include "MenuState.h"
#include <iostream>
#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"
#include "GameObject.h"
#include "PlayState.h"

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
	std::cout << "enter MenuState\n";
	if (!TextureManager::Instance()->load("buttonexit.bmp", "exit", Game::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("buttonstart.bmp", "start", Game::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject *bStart = new MenuButton(new LoaderParams(200, 200, 201, 72, 3, "start"), s_menuToPlay);
	m_gameObjects.push_back(bStart);
	
	GameObject *bExit = new MenuButton(new LoaderParams(200, 300, 201, 72, 3, "exit"), s_exitFromMenu);
	
	m_gameObjects.push_back(bExit);
	
	
	return true;
}
bool MenuState::onExit()
{
	std::cout << "exiting MenuState\n";
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TextureManager::Instance()->clearFromTextureMap("start");
	TextureManager::Instance()->clearFromTextureMap("exit");
	return true;
}

std::string MenuState::getStateID() const
{
	return s_menuID;
}

void MenuState::s_menuToPlay()
{
	Game::Instance()->getStateMachine()->changeState(new PlayState());
}
void MenuState::s_exitFromMenu()
{
	Game::Instance()->getStateMachine()->popState();
	Game::Instance()->getStateMachine()->voidAllOldStates();
	Game::Instance()->quit();
}