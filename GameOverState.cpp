#include "GameOverState.h"
#include "game.h"
#include "MenuState.h"
#include "PlayState.h"
#include "MenuButton.h"
#include "StateParser.h"
#include "SoundManager.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

GameOverState::GameOverState()
{
}

GameOverState::~GameOverState()
{
}

void GameOverState::update()
{
	for (int i = 0; i < m_gameObjectsGameOver.size(); i++)
	{
		m_gameObjectsGameOver[i]->update();
	}
}

void GameOverState::render()
{
	for (int i = 0; i < m_gameObjectsGameOver.size(); i++)
	{
		m_gameObjectsGameOver[i]->draw();
	}
}

void GameOverState::s_gameOverToMain()
{
	Game::Instance()->getStateMachine()->changeState(new MenuState());
}
void GameOverState::s_restartPlay()
{
	Game::Instance()->getStateMachine()->changeState(new PlayState());
}

bool GameOverState::onEnter()
{
	
	SoundManager::Instance()->playMusic("SongGameOver", -1);
	// parse the state
	SDL_Renderer* render;
	render = Game::Instance()->getRender();
	SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
	Game::Instance()->setRender(render);
	StateParser stateParser;
	stateParser.parseState("assets/images.xml", s_gameOverID, &m_gameObjectsGameOver, &m_textureIDList);
	m_callbacksGameOver.push_back(0); //pushback 0 callbackID start from 1
	m_callbacksGameOver.push_back(s_gameOverToMain);
	m_callbacksGameOver.push_back(s_restartPlay);
	// set the callbacks for menu items
	setCallbacks(m_callbacksGameOver);

	return true;
}

bool GameOverState::onExit()
{
	SoundManager::Instance()->stopMusic();
	for (int i = 0; i < m_gameObjectsGameOver.size(); i++) {
		m_gameObjectsGameOver[i]->clean();
	}
	m_gameObjectsGameOver.clear();
	// clear the texture manager
	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}

	// reset the mouse button states to false
	InputHandler::Instance()->reset();
	m_textureIDList.clear();
	return true;
}

void GameOverState::setCallbacks(const std::vector<Callback>&callbacks) {
	// go through the game objects
	for (int i = 0; i < m_gameObjectsGameOver.size(); i++)
	{
		// if they are of type MenuButton then assign a callback based on the id passed in from the file
		if (dynamic_cast<MenuButton*>(m_gameObjectsGameOver[i]))
		{
			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjectsGameOver[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}
