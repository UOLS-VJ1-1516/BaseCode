#include "Level.h"
#include "CollisionManager.h"

void Level::update()
{
	for (int i = 0; i < m_layers.size(); i++)
	{
		m_layers[i]->update();
	}
	
	CollisionManager cm;
	cm.checkPlayerObjectsCollision(m_pPlayer, getGameObjects());
	//m_collisionManager.checkPlayerObjectsCollision(m_pPlayer, );
}

void Level::render()
{
	for (int i = 0; i < m_layers.size(); i++)
	{
		m_layers[i]->render();
	}
}