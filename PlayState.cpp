#include "PlayState.h"
#include "PauseState.h"
#include "StateParser.h"
#include "GameObjectFactory.h"
#include "MenuState.h"
#include "PlayState.h"
#include "LevelParser.h"
#include "Level.h"

//ID del estado
const std::string PlayState::s_playID = "PLAY";

//Función para cargar al entrar en el estado de Play donde se cargan y se crean los diferentes gameobjects
bool PlayState::onEnter()
{
	StateParser stateParser;
	//stateParser.parseState("xmljuego.xml", s_playID, &m_gameObjects, &m_textureIDList);

	LevelParser levelParser;
	pLevel = levelParser.parseLevel("mapa.tmx");
	std::cout << "entering PlayState\n";
	return true;
}

//Función que realiza el update de los diferentes gameobjects
void PlayState::update()
{
	pLevel->update();
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		Game::Instance()->getGameStateMachine()->pushState(new PauseState());
	}

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

//Función que printa los diferentes gameobjects constantemente
void PlayState::render()
{
	
	pLevel->render();
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

//Función para limpiar el estado de play al salir, los gameobjects y las texturas de estos
bool PlayState::onExit()
{

	for (size_t i = 0; i < m_gameObjects.size(); i++)
		 {
			m_gameObjects[i]->clean();
		}
	m_gameObjects.clear();

	return true;

}
