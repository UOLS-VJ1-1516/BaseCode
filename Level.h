#pragma once

#ifndef LEVEL_H
#define LEVEL_H
#include "string"
#include "vector"
#include "Layer.h"
/**/
struct Tileset
{
	int firstGridID;
	int tileWidth;
	int tileHeight;
	int width;
	int height;
	int spacing;
	int margin;
	int numColumns;
	const char* name;
};

class Level
{
public:
	~Level() {}
	void update();
	void render();

	std::vector<Layer*>* getLayers()
	{
		return &m_layers;
	}
	std::vector<Tileset>* getTilesets()
	{
		return &m_tilesets;
	}
private:
	std::vector<Tileset> m_tilesets;
	std::vector<Layer*> m_layers;
	friend class LevelParser;
	Level();
};



#endif
