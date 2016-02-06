#pragma once
#include "LevelParser.h"
#include "TileLayer.h"
#include "tinyxml.h"
class LevelParser
{
public:
	Level* parseLevel(const char* levelFile);
	LevelParser();
	~LevelParser();
private:
	void parseTilesets(TiXmlElement* pTilesetRoot, std::vector<Tileset>* pTilesets);
	void parseTileLayer(TiXmlElement* pTileElement, std::vector<Layer*> *pLayers, const std::vector<Tileset>* pTilesets);
	int m_tileSize;
	int m_width;
	int m_height;
	/*friend class LevelParser;
	Level();*/
};
