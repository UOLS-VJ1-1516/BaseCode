#include "GameOverState.h"
#include "iostream"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

GameOverState::GameOverState()
{
}

GameOverState::~GameOverState()
{
}

void GameOverState::s_gameOverToMain()
{
	Game::Instance()->getStateMachine()->changeState(new MenuState());
}
void GameOverState::s_restartPlay()
{
	Game::Instance()->getStateMachine()->changeState(new PlayState());
}

void GameOverState::update()
{
}

void GameOverState::render()
{
}

bool GameOverState::onEnter()
{
	if (!TextureManager::Instance()->load("gameOver.png", "gameovertext", Game::Instance()->getRender()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("mainMenu.png", "mainbutton", Game::Instance()->getRender()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("restart.png",	"restartbutton", Game::Instance()->getRender()))
	{
		return false;
	}
	GameObject* gameOverText = new AnimatedGraphic(2);
	GameObject* button1 = new MenuButton(s_gameOverToMain);
	GameObject* button2 = new MenuButton(s_restartPlay);
	
	gameOverText->load(new	LoaderParams(200, 100, 190, 30, "gameovertext", 2, 0, 0));
	button1->load(new LoaderParams(200, 200, 200, 80, "mainbutton", 0, 6, 0));
	button2->load(new LoaderParams(200, 300,	200, 80, "restartbutton", 0, 6, 0));

	m_gameObjects.push_back(gameOverText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering PauseState\n";
	return true;
}

bool GameOverState::onExit()
{
	return false;
}
