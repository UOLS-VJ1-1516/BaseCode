#include "PauseState.h"
#include "game.h"
#include "MenuState.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include <string>

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
		if (!TextureManager::Instance()->load("buttonexit.bmp", "exit", Game::Instance()->getRenderer()))
		{
			return false;
		}
		if (!TextureManager::Instance()->load("buttonstart.bmp", "start", Game::Instance()->getRenderer()))
		{
			return false;
		}
		GameObject *bStart = new MenuButton(new LoaderParams(200, 200, 201, 72, 3, "start"), s_resumePlay);
		m_gameObjects.push_back(bStart);

		GameObject *bExit = new MenuButton(new LoaderParams(200, 300, 201, 72, 3, "exit"), s_pauseToMain);

		m_gameObjects.push_back(bExit);
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
		return true;
}
