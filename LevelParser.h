#pragma once
#ifndef LEVERPARSER_H
#define LEVERPARSER_H
#include "Level.h"
#include "tinyxml.h"

class LevelParser
{
public:
	Level* parseLevel(const char* levelFile);
private:
	/* parseTilesets(TiXmlElement* pTilesetRoot,
		std::vector<Tileset>* pTilesets);
	void parseTileLayer(TiXmlElement* pTileElement,
		std::vector<Layer*> *pLayers, const std::vector<Tileset>*
		pTilesets);
	void parseTextures(TiXmlElement* pTextureRoot);
	void parseObjectLayer(TiXmlElement* pObjectElement,
		std::vector<Layer*> *pLayers);
	int m_tileSizew;
	int m_tileSizeh;
	int m_width;
	int m_height;*/
	void parseTilesets(TiXmlElement* pTilesetRoot, std::vector<Tileset>* pTilesets);
	void parseTileLayer(TiXmlElement* pTileElement, std::vector<Layer*> *pLayers, const std::vector<Tileset>* pTilesets, std::vector<TileLayer*> *m_CollisionsLayer);
	void parseTextures(TiXmlElement* pTextureRoot);
	void parseObjectLayer(TiXmlElement * pObjectElement, std::vector<Layer*>* pLayers, Level* pLevel);
	int m_tileSizew;
	int m_tileSizeh;
	int m_width;
	int m_height;
};
#endif