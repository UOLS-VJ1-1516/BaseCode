#include "PauseState.h"
#include "StateParser.h"
#include <iostream>

const std::string PauseState::s_pauseID = "PAUSE";
void PauseState::update()
{
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	TheInputHandler->update();
	
	if (TheInputHandler->Quit())
	{
		Game::Instance()->setIsRunning(false);
	}
	
}
void PauseState::render()
{
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
bool PauseState::onEnter()
{
	
	TheInputHandler = InputHandler::Instance();

	std::cout << "entering PlayState\n";
	StateParser::parseState("game.xml", s_pauseID, &m_gameObjects, &m_textureIDList);
	m_callbacks.push_back(0);
	m_callbacks.push_back(s_resumePlay);
	m_callbacks.push_back(s_pauseToMain);
	setCallbacks(m_callbacks);
	return true;
}
bool PauseState::onExit()
{
	m_gameObjects.clear();
	for (unsigned int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::Instance()->clean(m_textureIDList[i]);

	}
	m_textureIDList.clear();

	std::cout << "exiting PlayState\n";
	return true;
}

void PauseState::s_pauseToMain()
{

	Game::Instance()->getStateMachine()->changeState(new MenuState);
}

void PauseState::s_resumePlay()
{
	Game::Instance()->getStateMachine()->popState();
}

void PauseState::setCallbacks(const std::vector<Callback>& callbacks)
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