#include "Level.h"

void Level::render()
{
	for (int i = 0; i < m_layers.size(); i++)
	{
		m_layers[i]->render();
	}
}

Level::Level()
{
}

void Level::update()
{
	for (int i = 0; i < m_layers.size(); i++)
	{
		m_layers[i]->update();
	}
	CollisionManager::Instance()->checkCollision(m_Player,objectLayers);
	
}

