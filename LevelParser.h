#pragma once
#include "Level.h"
#include "tinyxml.h"
#include "TileLayer.h"
#include "ObjectLayer.h"
#include "base64.h"
#include "zlib.h"

class LevelParser
{
	public:
		Level* parseLevel(const char* levelFile);
	private:
		void parseTilesets(TiXmlElement* pTilesetRoot, std::vector<Tileset>* pTilesets);
		void parseTileLayer(TiXmlElement* pTileElement, std::vector<Layer*> *pLayers, const std::vector<Tileset>* pTilesets, std::vector<TileLayer*> *pCollisonlayers);
		void parseObjectLayer(TiXmlElement* pObjectElement, std::vector<Layer*> *pLayers, Level* parselevel);
		void parseTextures(TiXmlElement* pTextureRoot);
	int m_tileSize;
	int m_width;
	int m_height;
};
