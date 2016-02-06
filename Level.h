#pragma once
#include <vector>
#include "Layer.h"


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
private:
	std::vector<Tileset> m_tilesets;
	std::vector<Layer*> m_layers;
	friend class LevelParser;
	Level();
	


};
