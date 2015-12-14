#pragma once
#include "Map.h"
#include "tinyxml.h"
#include "TileLayer.h"
#include "base64.h"
#include "zlib.h"

class LayerParser
{
	public:
		Map* parseLevel(const char* levelFile);
	private:
		void parseTilesets(TiXmlElement* pTilesetRoot, std::vector<Tileset>* pTilesets);
		void parseTileLayer(TiXmlElement* pTileElement,	std::vector<Layer*> *pLayers, const std::vector<Tileset>* pTilesets);
		int m_tileSize;
		int m_width;
		int m_height;
};