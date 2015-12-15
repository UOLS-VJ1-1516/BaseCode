#pragma once
#include "Capa.h"
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

	~Map() {
	
	
	}

	void update();
	void render();

	//void update();
	//void render();


	std::vector<Tileset>* getTilesets() { return &m_tilesets; }
	std::vector<Capa*>* getLayers() { return &m_layers; }


	Map();

	std::vector<Tileset> m_tilesets;
	std::vector<Capa*> m_layers;
};