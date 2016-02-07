#include "PlayState.h"
#include "LevelParser.h"
#include "SoundManager.h"
#include "Camera.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update() {
	level->update();
	InputHandler::Instance()->update();

	if (InputHandler::Instance()->isExitClicked() || InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
		Game::Instance()->setIsRunning(false);
		SoundManager::Instance()->stopMusic();
	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
		Game::Instance()->getGameStateMachine()->pushState(new PauseState());
	}
}

void PlayState::render() {
	level->render();
}

bool PlayState::onEnter() {
	SoundManager::Instance()->playMusic("intro", 0);
	LevelParser levp;
	level = levp.parseLevel("assets/mapBackground2.tmx");
	
	return true;
}

bool PlayState::onExit() {
	InputHandler::Instance()->clean();
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

std::string PlayState::getStateID() const{
	return s_playID;
}