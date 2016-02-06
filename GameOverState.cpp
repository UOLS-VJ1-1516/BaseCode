#include "GameOverState.h"
#include "Game.h"
#include "StateParser.h"


void GameOverState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void GameOverState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool GameOverState::onEnter() {

	StateParser stateParser;
	stateParser.parseState("./Data/Tiny.xml", s_gameOverID, &m_gameObjects, &m_TextureIDList);

	m_callbacks.push_back(0);
	m_callbacks.push_back(s_menuTOMain);

	setCallbacks(m_callbacksID);

	std::cout << "Entrada al menuState\n";
	return true;


}
bool GameOverState::onExit() {

	for (unsigned int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	for (unsigned int i = 0; i < m_TextureIDList.size(); i++)
	{
		TextureManager::Instance()->clearFromTextureMap(m_TextureIDList[i]);
	}
	m_TextureIDList.clear();



	std::cout << "Salida del PauseState\n";
	return true;
}

const std::string GameOverState::s_gameOverID = "GAMEOVER";

std::string GameOverState::getStateID() const {
	return GameOverState::s_gameOverID;
}

void GameOverState::s_menuTOMain() {
	Game::Instance()->getGameStateMachine()->changeState(new MenuState());
}

void GameOverState::setCallbacks(const std::vector<Callback>& callbacks)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		if (dynamic_cast<MenuButton*>(m_gameObjects[i]))
		{
			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallbacks(m_callbacks[pButton->getCallbackID()]);
		}
	}
}


