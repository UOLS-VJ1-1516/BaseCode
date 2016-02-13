#pragma once
#include <vector>
#include "Layer.h"
#include "TileLayer.h"

struct TileLayer;

class Level
{
public:
	
	void update();
	void render();
	std::vector<Tileset>* getTilesets()
	{
		return &m_tilesets;
	}
	std::vector<Layer*>* getLayers()
	{
		return &m_layers;
	}

	std::vector<TileLayer*>* getCollisionLayers() {
		return &m_CollisionsLayer;
	}

private:
	std::vector<Tileset> m_tilesets;
	std::vector<Layer*> m_layers;
	std::vector<TileLayer*> m_CollisionsLayer;
	friend class LevelParser;
	Level();
	


};
