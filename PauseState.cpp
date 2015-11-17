#include "PauseState.h"
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
	buttonResume = new MenuButton(new LoaderParams(275.4, 200, 251, 67, "resume", 3, 0, 0, 0, 0),s_resumePlay);
	buttonMenu = new MenuButton(new LoaderParams(275.4, 300, 251, 67, "btnmenu", 3, 0, 0, 0, 0),s_pauseToMain);

	m_gameObjects.push_back(buttonResume);
	m_gameObjects.push_back(buttonMenu);

	TextureManager::Instance()->load("resume.png", "resume", Game::Instance()->getRender());
	TextureManager::Instance()->load("menu.png", "btnmenu", Game::Instance()->getRender());


	std::cout << "entering PlayState\n";
	return true;
}
bool PauseState::onExit()
{
	m_gameObjects.clear();

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