#include "GameOverState.h"
#include "game.h"
#include "SoundManager.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}

	InputHandler::Instance()->update();

	if (InputHandler::Instance()->isExitClicked() || InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
		Game::Instance()->setIsRunning(false);
		SoundManager::Instance()->stopMusic();
	}
}

void GameOverState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool GameOverState::onEnter() {
	StateParser::parseState("assets/xml/objects.xml", s_gameOverID, &m_gameObjects, &m_texturesIDList);
	SoundManager::Instance()->stopMusic();
	SoundManager::Instance()->playMusic("gameOver", 0);
	m_callbacks.push_back(0);
	m_callbacks.push_back(s_gameOverToMain);
	setCallbacks(m_callbacks);

	return true;
}

bool GameOverState::onExit() {
	for (unsigned int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	for (unsigned int i = 0; i < m_texturesIDList.size(); i++) {
		TextureManager::Instance()->clearFromTextureMap(m_texturesIDList[i]);
	}
	m_texturesIDList.clear();

	SoundManager::Instance()->stopMusic();

	return true;
}

std::string GameOverState::getStateID() const {
	return s_gameOverID;
}

void GameOverState::setCallbacks(const std::vector<Callback>& callbacks) {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		if (dynamic_cast<MenuButton*>(m_gameObjects[i])) {
			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}

void GameOverState::s_gameOverToMain() {
	Game::Instance()->getGameStateMachine()->changeState(new MenuState());
	SoundManager::Instance()->stopMusic();
}
