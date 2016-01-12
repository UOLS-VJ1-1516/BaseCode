#include "PlayState.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "PauseState.h"
#include "InputHandler.h"
#include "GameObject.h"
#include <iostream>
#include "GameObjectFactory.h"
#include "StateParser.h"
#include "LevelParser.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		Game::Instance()->getStateMachine()->pushState(new PauseState());
	}

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	pLevel->update();

}
void PlayState::render()
{
	
	
	pLevel->render();
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
bool PlayState::onEnter()
{
	LevelParser levelParser;
	pLevel = levelParser.parseLevel("longtile.tmx");
	return true;
}
bool PlayState::onExit()
{
	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::Instance()->
			clearFromTextureMap(m_textureIDList[i]);
	}
	return true;
}