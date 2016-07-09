#include "PauseState.h"
#include "iostream"

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain()
{
	Game::Instance()->getStateMachine()->changeState(new MenuState());
}
void PauseState::s_resumePlay()
{
	Game::Instance()->getStateMachine()->popState();
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
	if (!TextureManager::Instance()->load("resume.png","resumebutton", Game::Instance()->getRender()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("mainMenu.png","mainbutton", Game::Instance()->getRender()))
	{
		return false;
	}

	GameObject* button1 = new MenuButton(s_pauseToMain);
	GameObject* button2 = new MenuButton(s_resumePlay);

	button1->load(new LoaderParams(500, 100, 200, 80, "mainbutton", 3, 0, 0));
	button2->load(new LoaderParams(500, 300, 200, 80, "resumebutton", 3, 0, 0));

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
	TextureManager::Instance()->clear("resumebutton");
	TextureManager::Instance()->clear("mainbutton");
	// reset the mouse button states to false
	InputHandler::Instance()->clean();
	std::cout << "exiting PauseState\n";
	return true;
}