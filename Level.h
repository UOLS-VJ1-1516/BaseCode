#pragma once
#include "Tileset.h"
#include "Layer.h"
#include <string>
#include <vector>

class TileLayer;

class Level
{
	
public:
	virtual ~Level() {}
	void update();
	void render();
	std::vector<Tileset>* getTilesets() { return &m_tilesets; }
	std::vector<Layer*>* getLayers();
	std::vector<TileLayer* >* getCollisionLayers();
private:
	std::vector<Tileset> m_tilesets;
	std::vector<Layer*> m_layers;
	std::vector<TileLayer*> m_collisionLayers;
	friend class LevelParser;
	Level();
};