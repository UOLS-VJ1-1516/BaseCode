#pragma once
#include "Level.h"
#include "tinyxml.h"
#include "textureManager.h"
#include "Game.h"
#include "Tileset.h"
#include "TileLayer.h"
#include "zlib.h"
#include "base64.h"
#include <iostream>

using namespace std;

/*
este es el objeto en el cual construie el nivel
*/
class LevelParser
{
public:
	Level* parseLevel(const char* levelFile);
private:
	void parseTilesets(TiXmlElement* pTilesetRoot,
		std::vector<Tileset>* pTilesets);
	void parseTileLayer(TiXmlElement* pTileElement,
		std::vector<Layer*> *pLayers, const std::vector<Tileset>*
		pTilesets);
	int m_tileSize;
	int m_width;
	int m_height;
};