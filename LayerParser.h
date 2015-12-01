#pragma once
#include "tinyxml.h"

class LayerParser
{
public:
	static TileLayer* parseTileLayer(const char* inputFile);
private:
	static void parseTileset(TiXmlElement* pTilesetRoot, Tileset* pTileset);
};