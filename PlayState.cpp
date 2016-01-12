#include "PlayState.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update() {
	tl->update();
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void PlayState::render() {
	tl->render();
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter() {
	StateParser::parseState("assets/xml/objects.xml", s_playID, &m_gameObjects, &m_texturesIDList);
	LayerParser lp;
	tl = lp.parseTileLayer("assets/tilMap.tmx");
	return true;
}

bool PlayState::onExit() {
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