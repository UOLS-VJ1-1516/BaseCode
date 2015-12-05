#pragma once
#include "tinyxml.h"
#include "TileLayer.h"
class LayerParser
{
public:
	static TileLayer* parseTileLayer(const char* inputFile);
private:
	static void parseTileset(TiXmlElement* pTilesetRoot, Tileset* pTileset);

	int m_tileSize;
	int m_width;
	int m_height;
};