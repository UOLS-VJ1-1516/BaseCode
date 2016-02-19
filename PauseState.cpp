#include "PauseState.h"
#include "game.h"
#include "MenuState.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include <string>
#include "GameObjectFactory.h"
#include "StateParser.h"
#include "SoundManager.h"

const std::string PauseState::s_pauseID = "PAUSE";
void PauseState::s_pauseToMain()
{
	SoundManager::Instance()->stopMusic();
	SoundManager::Instance()->playSound("button_effect", 0);
	Game::Instance()->getStateMachine()->changeState(new MenuState());
}
void PauseState::s_resumePlay()
{
	SoundManager::Instance()->playMusic("intro_music", -1);
	SoundManager::Instance()->playSound("button_effect", 0);
	Game::Instance()->getStateMachine()->popState();
}
void PauseState::setCallbacks(const std::vector<Callback>& callbacks)
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
void PauseState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}
void PauseState::render()
{

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
bool PauseState::onEnter()
	{
		StateParser stateParser;
		stateParser.parseState("values.xml", s_pauseID, &m_gameObjects, &m_textureIDList);
		m_callbacks.push_back(0); //pushback 0 callbackID start from 1
		m_callbacks.push_back(s_resumePlay);
		m_callbacks.push_back(s_pauseToMain);
		// set the callbacks for menu items
		setCallbacks(m_callbacks);
		/*if (!TextureManager::Instance()->load("buttonmenu.bmp", "menu", Game::Instance()->getRenderer()))
		{
			return false;
		}
		if (!TextureManager::Instance()->load("buttonresume.bmp", "resume", Game::Instance()->getRenderer()))
		{
			return false;
		}
		GameObject *bResume = TheGameObjectFactory->CreateGameObject("MenuButton");
		bResume = new MenuButton(new LoaderParams(200, 200, 201, 72, 3, "resume"), s_resumePlay);
		m_gameObjects.push_back(bResume);

		GameObject *bMenu = TheGameObjectFactory->CreateGameObject("MenuButton");
		bMenu = new MenuButton(new LoaderParams(200, 300, 201, 72, 3, "menu"), s_pauseToMain);
		m_gameObjects.push_back(bMenu);
		std::cout << "entering PauseState\n";
		*/return true;
	}
bool PauseState::onExit()
	{
		for (int i = 0; i < m_textureIDList.size(); i++)
		{
			TextureManager::Instance()->
				clearFromTextureMap(m_textureIDList[i]);
		}
		return true;
}
