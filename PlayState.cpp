#include "PlayState.h"
#include "Dog.h"
#include "Player.h"
#include "game.h"
#include "MenuState.h"
#include "StateParser.h"
#include "LevelParser.h"

const std::string PlayState::s_playID = "PLAY";
void PlayState::update()
{
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		Game::Instance()->getStateMachine()->pushState(new PauseState());
	}
	for (int i = 0; i < m_gameObjectsPlay.size(); i++)
	{
		m_gameObjectsPlay[i]->update();
	}
}
void PlayState::render()
{
	for (int i = 0; i < m_gameObjectsPlay.size(); i++)
	{
		m_gameObjectsPlay[i]->draw();
	}
	pLevel->render();
}
bool PlayState::onEnter()
{
	// parse the state
	StateParser stateParser;
	stateParser.parseState("assets/images.xml", s_playID, &m_gameObjectsPlay, &m_textureIDList);
	
	LevelParser levelParser;
	pLevel = levelParser.parseLevel("assets/mapaBueno.tmx");

	/*
	player = new Player();
	dog = new Dog();

	m_gameObjects.push_back(player);
	m_gameObjects.push_back(dog);

	l1 = new LoaderParams(0, 180, 97, 132, "imatge");
	l2 = new LoaderParams(0, 230, 64, 80, "imatge2");

	loader.push_back(l1);
	loader.push_back(l2);

	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->load(loader[i]);
	}
	*/

	return true;
}
bool PlayState::onExit()
{
	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}
	/*
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	*/
	return true;
}

void PlayState::s_playToPause()
{
	Game::Instance()->getStateMachine()->changeState(new PauseState());
}