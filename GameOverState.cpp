#pragma once
#include "GameOverState.h"
#include "Game.h"
#include "TextureManager.h"


const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::s_gameOverToMain()
{

	Game::Instance()->getStateMachine()->changeState(new MenuState());

}

void GameOverState::s_restartPlay()
{
	Game::Instance()->getStateMachine()->changeState(new	PlayState());
}

bool GameOverState::onEnter()
{
	if (!TextureManager::Instance()->load("assets/gameover.png","gameovertext", Game::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/main.png","mainbutton", Game::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TextureManager::Instance()->load("assets/restart.png",	"restartbutton", Game::Instance()->getRenderer()))
	{
		return false;
	}

	
	/*m_gameObjects.push_back(gameOverText);	
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);	*/

	return true;

}

void GameOverState::setCallbacks(const std::vector<Callback>& callbacks)
{
	
}

void GameOverState::update() {
	
};

void GameOverState::render() {
};

bool GameOverState::onExit() {
	return true;
};