#include "LayerParser.h"
#include "zlib.h"
#include "base64.h"
#include "TileLayer.h"
#include "Game.h"
#include "TextureManager.h"
#include "GameObjectFactory.h"



TileLayer * LayerParser::parseTileLayer(const char * inputFile)
{
	TiXmlDocument tileDocument;
	tileDocument.LoadFile(inputFile);

	TileLayer * pTile = new TileLayer(m_height,m_width,pTile);

	TiXmlElement *pRoot = tileDocument.RootElement();

	pRoot->Attribute("tilewidth", &m_tileSize);
	pRoot->Attribute("width", &m_width);
	pRoot->Attribute("height", &m_height);

	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("tileset"))
		{
			parseTileLayer(e, pTile->getTilesetByID());
		}
	}





}

void LayerParser::parseTileset(TiXmlElement * pTilesetRoot, Tileset * pTileset)
{
	TextureManager::Instance()->load(pTilesetRoot->FirstChildElement()->Attribute("source"), pTilesetRoot->Attribute("name"), Game::Instance()->getRender());
	Tileset tileset;
	pTilesetRoot->FirstChildElement()->Attribute("width", &tileset.width);
	pTilesetRoot->FirstChildElement()->Attribute("height", &tileset.height);
	pTilesetRoot->Attribute("firstgid", &tileset.firstGridID);
	pTilesetRoot->Attribute("tilewidth", &tileset.tileWidth);
	pTilesetRoot->Attribute("tileheight", &tileset.tileHeight);
	pTilesetRoot->Attribute("spacing", &tileset.spacing);
	pTilesetRoot->Attribute("margin", &tileset.margin);
	tileset.name = pTilesetRoot->Attribute("name");
	tileset.numColumns = tileset.width / (tileset.tileWidth + tileset.spacing);
	pTileset->push_back(tileset);
}
