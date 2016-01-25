#include "Level.h"
#include "Vector2D.h"
#include <vector>
#include "Tileset.h"
#include "Layer.h"

Level::Level() {

}



std::vector<Layer*>* Level::getLayers() {
	return &m_layers;
}



std::vector<TileLayer*>* Level::getCollisionLayers()
{

	return &m_collisionLayers;
}

void Level::render()
{
	for (int i = 0; i < m_layers.size(); i++)
	{
		m_layers[i]->render();
	}
}


void Level::update()
{
	for (int i = 0; i < m_layers.size(); i++)
	{
		m_layers[i]->update();
	}
}
