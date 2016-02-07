#include "GameOverState.h"
#include "game.h"
#include "MenuState.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include <string>
#include "GameObjectFactory.h"
#include "StateParser.h"
#include "SoundManager.h"
#include "PlayState.h"

const std::string GameOverState::s_pauseID = "PAUSE";
void GameOverState::s_overToMain()
{
	SoundManager::Instance()->stopMusic();
	SoundManager::Instance()->playSound("button_effect", 0);
	
	Game::Instance()->getStateMachine()->changeState(new MenuState());
}
void GameOverState::s_resumePlay()
{
	SoundManager::Instance()->playMusic("intro_music", -1);
	SoundManager::Instance()->playSound("button_effect", 0);
	Game::Instance()->getStateMachine()->changeState(new PlayState());
}
void GameOverState::setCallbacks(const std::vector<Callback>& callbacks)
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
void GameOverState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}
void GameOverState::render()
{

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
bool GameOverState::onEnter()
{
	StateParser stateParser;
	stateParser.parseState("values.xml", s_pauseID, &m_gameObjects, &m_textureIDList);
	m_callbacks.push_back(0); //pushback 0 callbackID start from 1
	m_callbacks.push_back(s_resumePlay);
	m_callbacks.push_back(s_overToMain);
	// set the callbacks for menu items
	setCallbacks(m_callbacks);
	SoundManager::Instance()->playMusic("over_music", 0);
	return true;
}
bool GameOverState::onExit()
{
	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::Instance()->
			clearFromTextureMap(m_textureIDList[i]);
	}
	return true;
}
