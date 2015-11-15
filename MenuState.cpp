#include "MenuState.h"
#include "PlayState.h"
#include <iostream>

const std::string MenuState::s_menuID = "MENU";

bool MenuState::onEnter()
{
	if (!TextureManager::Instance()->load("assets/playButton.bmp","playbutton", Game::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/exitButton.bmp","exitbutton", Game::Instance()->getRenderer()))
	{
		return false;
	}

	button1 = new MenuButton(new LoaderParams(100, 100,	300, 100, "playbutton", "assets/playButton.bmp", 0, 0), s_menuToPlay);
	button2 = new MenuButton(new LoaderParams(100, 300, 300, 100, "exitbutton", "assets/exitButton.bmp", 0, 0), s_exitFromMenu);

	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering MenuState\n";
	return true;
}

void MenuState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void MenuState::render()
{
	
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TextureManager::Instance()->clearFromTextureMap("playbutton");
	TextureManager::Instance()->clearFromTextureMap("exitbutton");
	std::cout << "exiting MenuState\n";
	return true;
}

void MenuState::s_menuToPlay()
{
	Game::Instance()->getGameStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitFromMenu()
{
	Game::Instance()->getGameStateMachine()->popState();
	Game::Instance()->getGameStateMachine()->voidAllOldStates();
	Game::Instance()->exit();
}