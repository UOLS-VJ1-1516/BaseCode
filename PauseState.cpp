#include "PauseState.h"
#include "MenuState.h"
#include <iostream>
const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain()
{
	Game::Instance()->getGameStateMachine()->changeState(new MenuState());
}

void PauseState::s_resumePlay()
{
	Game::Instance()->getGameStateMachine()->popState();
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
	if (!TextureManager::Instance()->load("assets/resumeButton.bmp","resumebutton", Game::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/mainMenuButton.bmp","mainbutton", Game::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* button1 = new MenuButton(new LoaderParams(200, 100,	300, 100, "mainbutton", "assets/mainMenuButton.bmp",0,0), s_pauseToMain);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 300,	300, 100, "resumebutton", "assets/resumeButton.bmp", 0, 0), s_resumePlay);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering PauseState\n";
	return true;
}

bool PauseState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TextureManager::Instance()->clearFromTextureMap("resumebutton");
	TextureManager::Instance()->clearFromTextureMap("mainbutton");
	std::cout << "exiting PauseState\n";
	return true;
}