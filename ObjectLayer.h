#pragma once
#include "Layer.h"
#include <vector>
#include "GameObject.h"
#include "TileLayer.h"
class ObjectLayer : public Layer
{
public:
	
	virtual void render();
	virtual void update();
	std::vector< GameObject* >* getGameObjects()
	{
		return &m_gameObjects;
	}
private:
	std::vector< GameObject* > m_gameObjects;
	//const std::vector< Tileset > &m_tilesets; //tilesets owned by level
};
