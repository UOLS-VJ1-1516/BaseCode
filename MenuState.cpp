#include "MenuState.h"
#include "Game.h"
#include "StateParser.h"
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
	
	std::cout << "entering MenuState\n";
	StateParser::parseState("game.xml", s_menuID, &m_gameObjects, &m_textureIDList);
	m_callbacks.push_back(0);
	m_callbacks.push_back(s_menuToPlay);
	m_callbacks.push_back(s_exitFromMenu);
	setCallbacks(m_callbacks);
	return true;
}
bool MenuState::onExit()
{
	m_gameObjects.clear();
	for (unsigned int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::Instance()->clean(m_textureIDList[i]);

	}
	m_textureIDList.clear();

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
void MenuState::setCallbacks(const std::vector<Callback>& callbacks)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		if (dynamic_cast<MenuButton*>(m_gameObjects[i]))
		{
			MenuButton* pButton = dynamic_cast< MenuButton* >(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}