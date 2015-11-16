#include "MenuState.h"
#include <iostream>
#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"
#include "GameObject.h"
#include "PlayState.h"

const std::string MenuState::s_menuID = "MENU";


void MenuState::s_menuToPlay()
{
	Game::Instance()->getStateMachine()->changeState(new PlayState());
}
void MenuState::s_exitFromMenu()
{
	Game::Instance()->quit();
}


void MenuState::update()
{
	for (size_t i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}
void MenuState::render()
{
	for (size_t i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
bool MenuState::onEnter()
{
	if (!TextureManager::Instance()->load("buttonstart.bmp", "start", Game::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject *bStart= new MenuButton(new LoaderParams(200, 200, 201, 72, 3, "start"), s_menuToPlay);
	m_gameObjects.push_back(bStart);


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

std::string MenuState::getStateID() const
{
	return s_menuID;
}
