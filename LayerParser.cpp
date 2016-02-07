#include "LayerParser.h"
#include "base64.h"
#include "zlib.h"
#include "TileLayer.h"
#include "Game.h"
#include "TextureManager.h"

std::vector<Tileset> LayerParser::m_tilesets = std::vector<Tileset>();

TileLayer * LayerParser::parseTileLayer(const char * inputFile)
{
	TiXmlDocument Document;
	Tileset ts;
	int m_width = 0;
	int m_height = 0;

	if (!Document.LoadFile(inputFile)) {
		return false;
	}
	TiXmlElement* pRoot = Document.RootElement();
	pRoot->Attribute("width", &m_width);
	pRoot->Attribute("height", &m_height);

	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("tileset"))
		{
			parseTileset(e, &ts);
		}
	}

	TileLayer* pTileLayer = new TileLayer(ts.tileWidth, ts.tileHeight, m_tilesets);
	std::vector<std::vector<int>> data;
	std::string decodedIDs;

	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("layer"))
		{
			for (TiXmlElement* c = e->FirstChildElement(); c !=
				NULL; c = c->NextSiblingElement())
			{
				if (c->Value() == std::string("data"))
				{
					for (TiXmlNode* pDataNode = c->FirstChild(); pDataNode != NULL; pDataNode =	pDataNode->NextSibling())
					{
						TiXmlText* text = pDataNode->ToText();
						std::string t = text->Value();
						decodedIDs = base64_decode(t);
						uLongf numGids = m_width * m_height * sizeof(int);
						std::vector<unsigned> gids(numGids);
						uncompress((Bytef*)&gids[0], &numGids, (const Bytef*)decodedIDs.c_str(), decodedIDs.size());
						std::vector<int> layerRow(m_width);
						for (int j = 0; j < m_height + 2; j++)
						{
							data.push_back(layerRow);
						}
						for (int rows = 0; rows < m_height; rows++)
						{
							for (int cols = 0; cols < m_width; cols++)
							{
								data[rows][cols] = gids[rows * m_width + cols];
							}
						}
						pTileLayer->setTileIDs(data);
					}

				}
			}
		}
	}

	return pTileLayer;
}



void LayerParser::parseTileset(TiXmlElement * pTilesetRoot, Tileset * pTileset)
{
	std::string file = "assets/" + std::string(pTilesetRoot->FirstChildElement()->Attribute("source"));
	TextureManager::Instance()->load(file.c_str(), pTilesetRoot->Attribute("name"), Game::Instance()->getRenderer());
	pTilesetRoot->Attribute("tilewidth", &pTileset->tileWidth);
	pTilesetRoot->Attribute("tileheight", &pTileset->tileHeight);
	pTilesetRoot->FirstChildElement()->Attribute("width", &pTileset->width);
	pTilesetRoot->FirstChildElement()->Attribute("height", &pTileset->height);
	pTilesetRoot->Attribute("firstgid", &pTileset->firstGridID);
	pTilesetRoot->Attribute("spacing", &pTileset->spacing);
	pTilesetRoot->Attribute("margin", &pTileset->margin);
	pTileset->name = pTilesetRoot->Attribute("name");
	pTileset->numColumns = pTileset->width / (pTileset->tileWidth + pTileset->spacing);

	m_tilesets.push_back(*pTileset);
}