#include "MenuState.h"
#include "PlayState.h"
#include "StateParser.h"
#include "GameObjectFactory.h"

//ID del estado menu
const std::string MenuState::s_menuID = "MENU";

//Función para cuando se crea el estado menu que crea los game objects de este estado
bool MenuState::onEnter()
{
	StateParser stateParser;
	stateParser.parseState("xmljuego.xml", s_menuID, &m_gameObjects, &m_textureIDList);
	m_callbacks.push_back(0);
	m_callbacks.push_back(s_menuToPlay);
	m_callbacks.push_back(s_exitFromMenu);
	setCallbacks(m_callbacks);
	
	return true;
}

//Función para hacer el update de los game objects de este estado
void MenuState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

//Función para hacer el draw de los game objects de este estado
void MenuState::render()
{

	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

//Función para cuando se sale del menu state que limpia los gameobjects y sus texturas
bool MenuState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TheTextureManager->clearFromTextureMap(m_textureIDList[i]);
	}
	m_textureIDList.clear();

	return true;
}

//Callback para cambiar del estado del menu al estado del juego
void MenuState::s_menuToPlay()
{
	Game::Instance()->getGameStateMachine()->changeState(new PlayState());
}

//Callback para finalizar el juego que limpiar los diferentes estados
void MenuState::s_exitFromMenu()
{
	Game::Instance()->getGameStateMachine()->popState();
	Game::Instance()->getGameStateMachine()->deleteAllStates();
	Game::Instance()->exit();
}
void MenuState::setCallbacks(const std::vector<Callback>&callbacks)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		if (dynamic_cast<MenuButton*>(m_gameObjects[i]))
		{
			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}