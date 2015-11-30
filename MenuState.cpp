#include "MenuState.h"
#include "StateParser.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
};

void MenuState::render() {
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
};

bool MenuState::onEnter()
{
	StateParser::parseState("assets/game.xml", s_menuID, &m_gameObjects, &m_textureIDList);
	m_callbacks.push_back(0);
	m_callbacks.push_back(s_menuToPlay);
	m_callbacks.push_back(s_exitFromMenu);
	setCallbacks(m_callbacks);

	return true;
}

void MenuState::setCallbacks(const std::vector<Callback>& callbacks)
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

bool MenuState::onExit()
{
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
}

void MenuState::s_menuToPlay()
{
	Game::Instance()->getStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitFromMenu()
{
	Game::Instance()->clean();
}

std::string MenuState::getStateID() const{
	return s_menuID;
}