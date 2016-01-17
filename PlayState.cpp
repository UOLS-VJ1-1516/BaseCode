#include "PlayState.h"
#include "LevelParser.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update() {
	//tl->update();
	level->update();
	/*for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}*/
	InputHandler::Instance()->update();

	if (InputHandler::Instance()->isExitClicked() || InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
		Game::Instance()->setIsRunning(false);
	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
		Game::Instance()->getGameStateMachine()->pushState(new PauseState());
	}
}

void PlayState::render() {
	//tl->render();
	level->render();
	/*for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}*/
	
}

bool PlayState::onEnter() {
	//StateParser::parseState("assets/xml/objects.xml", s_playID, &m_gameObjects, &m_texturesIDList);
	//LayerParser lp;
	//tl = lp.parseTileLayer("assets/tilMap.tmx");
	LevelParser levp;
	level = levp.parseLevel("assets/mapBackground.tmx");
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

	return true;
}

std::string PlayState::getStateID() const{
	return s_playID;
}