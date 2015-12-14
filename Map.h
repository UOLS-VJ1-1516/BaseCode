#pragma once
#include "Layer.h"
#include <string>
#include <vector>

struct Tileset
{
	int firstGridID;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	int width;
	int height;
	int numColumns;
	std::string name;
};

class Map
{
	public:
		friend class LayerParser;
		~Map() {}
		void update();
		void render();
		std::vector<Tileset>* getTilesets()	{ return &m_tilesets; }
		std::vector<Layer*>* getLayers() { return &m_layers; }
	private:
		Map();
		std::vector<Tileset> m_tilesets;
		std::vector<Layer*> m_layers;
};