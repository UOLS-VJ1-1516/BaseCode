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
#include "ObjectLayer.h"
#include "Camera.h"
using namespace std;

/*
este es el objeto en el cual construie el nivel
*/
class LevelParser
{
public:
	Level* parseLevel(const char* levelFile);
private:
	void parseTilesets(TiXmlElement* pTilesetRoot, std::vector<Tileset>* pTilesets);
	void parseTileLayer(TiXmlElement* pTileElement, std::vector<Layer*> *pLayers, const std::vector<Tileset>*pTilesets, std::vector<TileLayer*> *pCollisionLayers);
	void parseTextures(TiXmlElement* pTextureRoot);
	void parseObjectLayer(TiXmlElement* pObjectElement, std::vector<Layer*> *pLayers, Level *pLevel);
	int m_tileSize;
	int m_width;
	int m_height;
	int m_spriteNum;
	std::string file;
	int m_fileName;
};