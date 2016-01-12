#include "MenuState.h"
#include <iostream>
#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"
#include "GameObject.h"
#include "PlayState.h"
#include "GameObjectFactory.h"
#include "StateParser.h"

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
	StateParser stateParser;
	stateParser.parseState("values.xml", s_menuID, &m_gameObjects, &m_textureIDList);
	m_callbacks.push_back(0); //pushback 0 callbackID start from 1
	m_callbacks.push_back(s_menuToPlay);
	m_callbacks.push_back(s_exitFromMenu);
	// set the callbacks for menu items
	setCallbacks(m_callbacks);
	/*if (!TextureManager::Instance()->load("buttonexit.bmp", "exit", Game::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("buttonstart.bmp", "start", Game::Instance()->getRenderer()))
	{
		return false;
	}
	
	GameObject *bStart = TheGameObjectFactory->CreateGameObject("MenuButton");
	bStart = new MenuButton(new LoaderParams(200, 200, 201, 72, 3, "start"), s_menuToPlay);
	m_gameObjects.push_back(bStart);
	
	GameObject *bExit = TheGameObjectFactory->CreateGameObject("MenuButton");
	bExit = new MenuButton(new LoaderParams(200, 300, 201, 72, 3, "exit"), s_exitFromMenu);
	m_gameObjects.push_back(bExit);
	*/
	
	return true;
}
bool MenuState::onExit()
{
	std::cout << "exiting MenuState\n";
	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}
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

//sospecho que no funcionará
void MenuState::setCallbacks(const std::vector<Callback>& callbacks)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		if (dynamic_cast<MenuButton*>(m_gameObjects[i]))
		{
			MenuButton* pButton =
				dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}