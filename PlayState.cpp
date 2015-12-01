#include "PlayState.h"
#include <iostream>
#include "StateParser.h"


const std::string PlayState::s_playID = "PLAY";
void PlayState::update()
{
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}	
}
void PlayState::render()
{
	for (std::vector<GameObject*>::size_type i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
bool PlayState::onEnter()
{
	StateParser::parseState("game.xml", s_playID, &m_gameObjects, &m_textureIDList);

	return true;
}
bool PlayState::onExit()
{
	std::cout << "exiting PlayState" << std::endl;
	for (unsigned int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	for (unsigned int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::Instance()->clean(m_textureIDList[i]);
		
	}
	m_textureIDList.clear();

	return true;
}