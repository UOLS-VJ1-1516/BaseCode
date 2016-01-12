#pragma once
#include "tinyxml.h"
#include "TileLayer.h"

class LayerParser
{
public:
	static TileLayer* parseTileLayer(const char* inputFile);
private:
	static void parseTileset(TiXmlElement* pTilesetRoot, Tileset* pTileset);
	static std::vector< Tileset > m_tilesets;
};