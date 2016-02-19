#include "PlayState.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "InputHandler.h"
#include "GameObject.h"
#include <iostream>
#include "GameObjectFactory.h"
#include "StateParser.h"
#include "LevelParser.h"
#include "SoundManager.h"
#include "Camera.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		SoundManager::Instance()->stopMusic();
		Game::Instance()->getStateMachine()->pushState(new PauseState());
	}
	Player* player = dynamic_cast<Player*>(pLevel->getPlayer());
	if (player->playerDies()) {
		SoundManager::Instance()->stopMusic();
		SoundManager::Instance()->playSound("dead", 0);
		Game::Instance()->getStateMachine()->pushState(new GameOverState());
	}
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	pLevel->update();
	
}
void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	
	pLevel->render();
	
}
bool PlayState::onEnter()
{
	LevelParser levelParser;
	pLevel = levelParser.parseLevel("finaltile.tmx");//("longtile.tmx");
	SoundManager::Instance()->playMusic("intro_music",-1);
	Camera::Instance()->setMaxPosition(
		(pLevel->getCollisionLayers()->at(0)->getTileWidth() *
			(pLevel->getCollisionLayers()->at(0)->getMapWidth()) - Game::Instance()->getVisibleWidth() / 2));
	
	return true;
}
bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();

	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}
	SoundManager::Instance()->stopMusic();
	return true;
}