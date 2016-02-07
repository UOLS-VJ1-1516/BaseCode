#include "MenuStateOnPause.h"
#include "StateParser.h" //lee los xml

const std::string MenuStateOnPause::s_menuID = "PAUSE";



void MenuStateOnPause::update() {
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
};

void MenuStateOnPause::render() {
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
};

bool MenuStateOnPause::onEnter()
{
	StateParser::parseState("assets/game.xml", s_menuID, &m_gameObjects, &m_textureIDList);//para leer la conf del xml
	m_callbacks.push_back(0);
	m_callbacks.push_back(s_menuToPlay);
	m_callbacks.push_back(s_exitFromMenu);
	setCallbacks(m_callbacks);

	return true;

}

void MenuStateOnPause::setCallbacks(const std::vector<Callback>& callbacks)
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

bool MenuStateOnPause::onExit()
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

void MenuStateOnPause::s_menuToPlay()
{
	Game::Instance()->getStateMachine()->popState();
}

void MenuStateOnPause::s_exitFromMenu()
{
	Game::Instance()->getStateMachine()->changeState(new MenuState());
}
std::string MenuStateOnPause::getStateID() const {
	return s_menuID;
}