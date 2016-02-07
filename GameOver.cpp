#include "GameOver.h"
#include "Game.h"
#include "TextureManager.h"
#include "StateParser.h"
#include "SoundManager.h"

void GameOver::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_R)) {
		Game::Instance()->getGameStateMachine()->pushState(new PlayState());
	}
};

void GameOver::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
};

bool GameOver::onEnter() {
	SoundManager::Instance()->playMusic("death", 1);
	StateParser::parseState("assets/myxml.xml", "GAMEOVER", &m_gameObjects, &m_textureIDList);
	m_callbacks.push_back(0); 
	m_callbacks.push_back(s_menuToPlay);
	m_callbacks.push_back(s_exitFromMenu);
	setCallbacks(m_callbacks);

	return true;
};

bool GameOver::onExit() {
	m_gameObjects.clear();
	for (int i = 0; i < m_textureIDList.size(); i++) {
		TextureManager::Instance()->clean(m_textureIDList[i]);
	}
	return true;
};

const std::string GameOver::s_menuID = "GameOver";

std::string GameOver::getStateID() const{

	return GameOver::s_menuID;
};

void GameOver::s_menuToPlay() {
	Game::Instance()->getGameStateMachine()->changeState(new PlayState());
};

void GameOver::s_exitFromMenu() {
	Game::Instance()->getGameStateMachine()->popState();
	Game::Instance()->getGameStateMachine()->voidAllOldStates();
	Game::Instance()->setflag(false);
}; 

void GameOver::setCallbacks(const std::vector<Callback>& callbacks)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		if (dynamic_cast<MenuButton*>(m_gameObjects[i]))
		{
			MenuButton* pButton = dynamic_cast< MenuButton* >(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}
