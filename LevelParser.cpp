#include "LevelParser.h"
#include "TextureManager.h"
#include "Game.h"
#include "base64.h"
#include "zlib.h"
#include "TileLayer.h"
#include "ObjectLayer.h"

Level* LevelParser::parseLevel(const char *levelFile)
{
	TiXmlDocument levelDocument;
	levelDocument.LoadFile(levelFile);

	Level* pLevel = new Level();

	TiXmlElement* pRoot = levelDocument.RootElement();
	pRoot->Attribute("tilewidth", &m_tileSizew);
	pRoot->Attribute("tileheight", &m_tileSizeh);
	pRoot->Attribute("width", &m_width);
	pRoot->Attribute("height", &m_height);

	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("tileset"))
		{
			parseTilesets(e, pLevel->getTilesets());
		}
		if (e->Value() == std::string("properties"))
		{
			TiXmlElement* pproperties = e;
			for (TiXmlElement* e = pproperties->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
			{
				if (e->Value() == std::string("property"))
				{
					parseTextures(e);
				}
			}
		}
		if (e->Value() == std::string("objectgroup") || e->Value() == std::string("layer"))
		{
			if (e->FirstChildElement()->Value() == std::string("object"))
			{
				parseObjectLayer(e, pLevel->getLayers(), pLevel);
			}
			else if (e->FirstChildElement()->Value() == std::string("data") || (e->FirstChildElement()->NextSiblingElement() != 0
				&& e ->FirstChildElement()->NextSiblingElement()->Value() == std::string("data")))
			{
				parseTileLayer(e, pLevel->getLayers(), pLevel->getTilesets(),
					pLevel->getCollisionLayers());
			}
		}
	}

	return pLevel;
}

void LevelParser::parseTilesets(TiXmlElement * pTilesetRoot, std::vector<Tileset>* pTilesets)
{
	TextureManager::Instance()->load(pTilesetRoot ->FirstChildElement()->Attribute("source"), 
		pTilesetRoot ->Attribute("name"), Game::Instance()->getRender());

	Tileset tileset;
	pTilesetRoot->FirstChildElement()->Attribute("width",
		&tileset.width);
	pTilesetRoot->FirstChildElement()->Attribute("height",
		&tileset.height);
	pTilesetRoot->Attribute("firstgid", &tileset.firstGridID);
	pTilesetRoot->Attribute("tilewidth", &tileset.tileWidth);
	pTilesetRoot->Attribute("tileheight", &tileset.tileHeight);
	pTilesetRoot->Attribute("spacing", &tileset.spacing);
	pTilesetRoot->Attribute("margin", &tileset.margin);
	tileset.name = pTilesetRoot->Attribute("name");
	tileset.numColumns = tileset.width / (tileset.tileWidth +
		tileset.spacing);
	pTilesets->push_back(tileset);
}

void LevelParser::parseTileLayer(TiXmlElement* pTileElement, std::vector<Layer*> *pLayers, const std::vector<Tileset>* pTilesets, std::vector<Layer*> *m_CollisionsLayer)
{
	TileLayer* pTileLayer = new TileLayer(m_tileSizew, m_tileSizeh, *pTilesets);
	bool collidable = false;

	std::vector<std::vector<int>> data;
	std::string decodedIDs;
	TiXmlElement* pDataNode;
	for (TiXmlElement* e = pTileElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("properties"))
		{
			for (TiXmlElement* property = e->FirstChildElement(); property
				!= NULL; property = property->NextSiblingElement())
			{
				if (property->Value() == std::string("property"))
				{
					if (property->Attribute("name") == std::string("collidable"))
					{
						collidable = true;
					}
				}
			}
		}
		if (e->Value() == std::string("data"))
		{
			pDataNode = e;
		}
	}
	for (TiXmlNode* e = pDataNode->FirstChild(); e != NULL; e = e->NextSibling())
	{
		TiXmlText* text = e->ToText();
		std::string t = text->Value();
		decodedIDs = base64_decode(t);
	}

	uLongf numGids = m_width * m_height * sizeof(int);
	std::vector<unsigned> gids(numGids);
	uncompress((Bytef*)&gids[0], &numGids, (const Bytef*)decodedIDs.c_str(), decodedIDs.size());
	std::vector<int> layerRow(m_width);
	for (int j = 0; j < m_height; j++)
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

	if (collidable)
	{
		m_CollisionsLayer->push_back(pTileLayer);
	}
	pTileLayer->setTileIDs(data);
	pLayers->push_back(pTileLayer);
}

void LevelParser::parseTextures(TiXmlElement * pTextureRoot)
{
	TextureManager::Instance()->load(pTextureRoot->Attribute("value"), pTextureRoot->Attribute("name"), Game::Instance()->getRender());
}

void LevelParser::parseObjectLayer(TiXmlElement * pObjectElement, std::vector<Layer*>* pLayers, Level* pLevel)
{
		ObjectLayer* pObjectLayer = new ObjectLayer();
		std::cout << pObjectElement->FirstChildElement()->Value();
		for (TiXmlElement* e = pObjectElement->FirstChildElement(); e !=
			NULL; e = e->NextSiblingElement())
		{
			std::cout << e->Value();
			if (e->Value() == std::string("object"))
			{
				int x, y, width, height, numSprites, speedX, speedY, maxSpeed, callbackId;
				double friction;
				char* textureID; 

				e->Attribute("x", &x);
				e->Attribute("y", &y);
				GameObject* pGameObject = GameObjectFactory::Instance()->CreateGameObject(e->Attribute("type"));

				for (TiXmlElement* properties = e->FirstChildElement();
				properties != NULL; properties = properties->NextSiblingElement())
				{
					if (properties->Value() == std::string("properties"))
					{
						for (TiXmlElement* property = properties->FirstChildElement(); property != NULL; property = property->NextSiblingElement())
						{
							if (property->Value() == std::string("property"))
							{
								if (property->Attribute("name") == std::string("textureWidth"))
								{
									property->Attribute("value", &width);
								}
								else if (property->Attribute("name") == std::string("textureHeight"))
								{
									property->Attribute("value", &height);
								}
								else if (property->Attribute("name") == std::string("speedY"))
								{
									property->Attribute("value", &speedY);
								}
								else if (property->Attribute("name") == std::string("textureID"))
								{
									const size_t len = strlen(property->Attribute("value"));
									textureID = new char[len + 1];
									strncpy(textureID, property->Attribute("value"), len);
									textureID[len] = '\0';
									//textureID = property->Attribute("value");
								}
								else if (property->Attribute("name") == std::string("speedX"))
								{
									property->Attribute("value", &speedX);
								}
								else if (property->Attribute("name") == std::string("numFrames"))
								{
									property->Attribute("value", &numSprites);
								}
								else if (property->Attribute("name") == std::string("maxSpeed"))
								{
									property->Attribute("value", &maxSpeed);
								}
								else if (property->Attribute("name") == std::string("callbackId"))
								{
									property->Attribute("value", &callbackId);
								}
								else if (property->Attribute("name") == std::string("friction"))
								{
									property->Attribute("value", &friction);
								}
							}
						}
					}
				}
				TextureManager::Instance()->setSizeFrames(textureID, width, height);
				pGameObject->load(new LoaderParams(x, y, width, height, textureID, numSprites, speedX, speedY, maxSpeed, friction, callbackId));
				if (textureID == "player")
				{
					pLevel->setPlayer(dynamic_cast<Player*>(pGameObject));
				}
				pObjectLayer->getGameObjects()->push_back(pGameObject);
			}
		}
		pLayers->push_back(pObjectLayer);
}
