#include "PlayState.h"
#include "Game.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "StateParser.h"

void PlayState::update() {
	if (InputHandler::Instance()->isKeyDown(SDLK_ESCAPE)) Game::Instance()->getStateMachine()->pushState(new MenuStateOnPause());
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
};

void PlayState::render() {
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
};

bool PlayState::onEnter() {		
	StateParser::parseState("assets/game.xml", s_playID, &m_gameObjects,	&m_textureIDList);	
	m_callbacks.push_back(0);
	setCallbacks(m_callbacks);
	return true;
};

void PlayState::setCallbacks(const std::vector<Callback>& callbacks)
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



bool PlayState::onExit() {
	for (unsigned int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	for (unsigned int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}
	m_textureIDList.clear();	
	return true;
};

const std::string PlayState::s_playID = "PLAY";

std::string PlayState::getStateID() const {
	return PlayState::s_playID;
};