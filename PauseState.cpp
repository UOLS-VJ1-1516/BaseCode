#include "PauseState.h"
#include "MenuState.h"
#include "StateParser.h"

//ID del estado pause
const std::string PauseState::s_pauseID = "PAUSE";

//Callback para cuando se pulsa volver al estado de menu
void PauseState::s_pauseToMain()
{
	Game::Instance()->getGameStateMachine()->changeState(new MenuState());
}

//Callback para cuando se pulsa continuar jugando
void PauseState::s_resumePlay()
{
	Game::Instance()->getGameStateMachine()->popState();
}

//Función para que se hagan los updates de los game objects
void PauseState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

//Función para que se hagan los draw de los game objects
void PauseState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

//Función para cuando se entra al estado de pause donde se carga y se crean los game objects de este estado
bool PauseState::onEnter()
{
	StateParser stateParser;
	stateParser.parseState("tiny.xml", s_pauseID, &m_gameObjects, &m_textureIDList);
	m_callbacks.push_back(0);
	m_callbacks.push_back(s_pauseToMain);
	m_callbacks.push_back(s_resumePlay);
	setCallbacks(m_callbacks);
	return true;
}

//Función para cuando se sale del estado pause que se limpian los gameobjects creados en este estado como las texturas
bool PauseState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
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

//Función que crea los callbacks de ese estado
void PauseState::setCallbacks(const std::vector<Callback>&callbacks)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
			if (dynamic_cast<MenuButton*>(m_gameObjects[i]))
			{
				MenuButton* pButton =
					dynamic_cast<MenuButton*>(m_gameObjects[i]);
				pButton->setCallback(callbacks[pButton->getCallbackID()]);
			}
	}
}