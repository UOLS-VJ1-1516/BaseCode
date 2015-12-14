#include "PlayState.h"
#include "PauseState.h"
#include "StateParser.h"
#include "LayerParser.h"

//ID del estado
const std::string PlayState::s_playID = "PLAY";

//Función para cargar al entrar en el estado de Play donde se cargan y se crean los diferentes gameobjects
bool PlayState::onEnter()
{
	LayerParser levelParser;
	StateParser stateParser;
	map = levelParser.parseLevel("assets/map.tmx");
	stateParser.parseState("tiny.xml", s_playID, &m_gameObjects, &m_textureIDList);
	return true;
}

//Función que realiza el update de los diferentes gameobjects
void PlayState::update()
{
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		Game::Instance()->getGameStateMachine()->pushState(new PauseState());
	}

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	map->update();
}

//Función que printa los diferentes gameobjects constantemente
void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
	map->render();
}

//Función para limpiar el estado de play al salir, los gameobjects y las texturas de estos
bool PlayState::onExit()
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