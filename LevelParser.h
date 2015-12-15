#pragma once
#include "Level.h"
#include "tinyxml.h"
#include <vector>

class LevelParser
{

public:
	Level* parseLevel(const char* levelFile);

private:
	void parseTilesets(TiXmlElement* pTilesetRoot, std::vector<Tileset>* pTilesets);
	void parseTileLayer(TiXmlElement* pTileElement, std::vector<Layer*> *pLayers, const std::vector<Tileset>* pTilesets);

	int m_tileSize;
	int m_width;
	int m_height;

};