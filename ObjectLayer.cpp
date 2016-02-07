#include "ObjectLayer.h"
#include "CollisionManager.h"

void ObjectLayer::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
		
	}
	CollisionManager::Instance()->checkCollision(&m_gameObjects);
}
void ObjectLayer::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}